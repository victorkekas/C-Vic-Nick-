#include "filmBrowser.h"
#include "graphics.h"
#include "config.h"
#include "movie.h"
#include "button.h"
#include "slider.h"
#include "movies_list.h"
//#include "text_container.h"

MoviesList displayableMovies;
Button* b1_left,* b1_right,* b2_left,* b2_right,* b_reset,* b_action,* b_drama, * b_adventure, * b_fantasy, * b_history, * b_crime, * b_scifi;
std::vector<Button*> buttons;
Slider* testslider;

void FilmBrowser::update()
{
	if (!(displayableMovies.filtersOn)) {
		b2_left->addActionCallback(std::bind(&Movie::previousShot, &displayableMovies.movies[displayableMovies.getMovieIndex()]));
		b2_right->addActionCallback(std::bind(&Movie::nextShot, &displayableMovies.movies[displayableMovies.getMovieIndex()]));
	}
	else if (displayableMovies.filtersOn) {
		b2_left->addActionCallback(std::bind(&Movie::previousShot, &displayableMovies.filteredMovies[displayableMovies.getMovieIndex()]));
		b2_right->addActionCallback(std::bind(&Movie::nextShot, &displayableMovies.filteredMovies[displayableMovies.getMovieIndex()]));
	}
	
	for (auto button : buttons) {
		button->update();
	}
	testslider->update();
}

void FilmBrowser::init()
{
	// "load" the movies
	displayableMovies.init();

	//button for movies (main image)
	graphics::Brush br_button_type_1;
	br_button_type_1.texture = std::string(ASSET_PATH) + "arrow.png";
	br_button_type_1.outline_color[0] = 0.0f;
	br_button_type_1.outline_color[1] = 0.0f;
	br_button_type_1.outline_color[2] = 0.0f;
	br_button_type_1.outline_width = 0.0f;
	br_button_type_1.outline_opacity = 0.0f;
	br_button_type_1.fill_color[0] = 0.0f;
	br_button_type_1.fill_color[1] = 0.0f;
	br_button_type_1.fill_color[2] = 0.0f;

	// left button for changing movie !!!!!DELETE THE BUTTONS LATER PLEASE 
	b1_left = new Button(1.2f*CANVAS_WIDTH / 16, CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 15.0f, CANVAS_HEIGTH / 10.3f, br_button_type_1);
	b1_left->addActionCallback(std::bind(&MoviesList::previousMovie, &displayableMovies) ); 


	// right button for changing movie !!!!!DELETE THE BUTTONS LATER PLEASE
	b1_right = new Button(10.55f * CANVAS_WIDTH / 16.0f, CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 15.0f, CANVAS_HEIGTH / 10.3f, br_button_type_1);
	b1_right->addActionCallback(std::bind(&MoviesList::nextMovie, &displayableMovies) );


	//button for movies (secondary images)

	// left button for changing movie's images
	b2_left = new Button(3.2 * CANVAS_WIDTH / 4.0f - CANVAS_WIDTH / 7.0f, 3 * CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 15.0f, CANVAS_HEIGTH / 10.3f, br_button_type_1);
	//b2_left->addActionCallback(std::bind(&Movie::previousShot, &displayableMovies.movies[displayableMovies.getMovieIndex()]));

	// right button for changing movie's images
	graphics::setOrientation(180);
	b2_right = new Button(3.2 * CANVAS_WIDTH / 4.0f + CANVAS_WIDTH / 7.0f, 3 * CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 15.0f, CANVAS_HEIGTH / 10.3f, br_button_type_1);
	//b2_right->addActionCallback(std::bind(&Movie::nextShot, &displayableMovies.movies[displayableMovies.getMovieIndex()]) );

	//reset br 
	graphics::setOrientation(0);
	buttons.push_back(b1_left);
	buttons.push_back(b1_right);
	buttons.push_back(b2_left);
	buttons.push_back(b2_right);

	br_button_type_1.texture = std::string(ASSET_PATH) + "square.png";
	b_reset = new Button(13.5f * CANVAS_WIDTH / 16, 2*CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 16.6f, CANVAS_HEIGTH / 16.6f, br_button_type_1);
	b_reset->addActionCallback(std::bind(&MoviesList::resetFilters, &displayableMovies));

	b_action = new Button(12.0f * CANVAS_WIDTH / 16, 1.5 * CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 16.6f, CANVAS_HEIGTH / 16.6f, br_button_type_1);
	b_action->addActionCallback(std::bind(&MoviesList::setFilterAction, &displayableMovies));

	b_drama = new Button(13.5f * CANVAS_WIDTH / 16, 1.5 * CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 16.6f, CANVAS_HEIGTH / 16.6f, br_button_type_1);
	b_drama->addActionCallback(std::bind(&MoviesList::setFilterDrama, &displayableMovies));

	b_adventure = new Button(15.0f * CANVAS_WIDTH / 16, 1.5 * CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 16.6f, CANVAS_HEIGTH / 16.6f, br_button_type_1);
	b_adventure->addActionCallback(std::bind(&MoviesList::setFilterAdventure, &displayableMovies));

	b_fantasy = new Button(12.0f * CANVAS_WIDTH / 16, 1.0 * CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 16.6f, CANVAS_HEIGTH / 16.6f, br_button_type_1);
	b_fantasy->addActionCallback(std::bind(&MoviesList::setFilterFantasy, &displayableMovies));

	b_history = new Button(13.5f * CANVAS_WIDTH / 16, 1.0 * CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 16.6f, CANVAS_HEIGTH / 16.6f, br_button_type_1);
	b_history->addActionCallback(std::bind(&MoviesList::setFilterHistory, &displayableMovies));

	b_crime = new Button(15.0f * CANVAS_WIDTH / 16, 1.0 * CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 16.6f, CANVAS_HEIGTH / 16.6f, br_button_type_1);
	b_crime->addActionCallback(std::bind(&MoviesList::setFilterCrime, &displayableMovies));

	b_scifi = new Button(13.5f * CANVAS_WIDTH / 16, 0.5 * CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 16.6f, CANVAS_HEIGTH / 16.6f, br_button_type_1);
	b_scifi->addActionCallback(std::bind(&MoviesList::setFilterSciFi, &displayableMovies));

	buttons.push_back(b_reset);
	buttons.push_back(b_action);
	buttons.push_back(b_drama);
	buttons.push_back(b_adventure);
	buttons.push_back(b_fantasy);
	buttons.push_back(b_history);
	buttons.push_back(b_crime);
	buttons.push_back(b_scifi);

	br_button_type_1.fill_color[0] = 0.0f;
	br_button_type_1.fill_color[1] = 0.0f;
	br_button_type_1.fill_color[2] = 0.0f;
	br_button_type_1.fill_opacity = 1.0f;
	br_button_type_1.fill_secondary_color[0] = 0.0f;
	br_button_type_1.fill_secondary_color[1] = 0.0f;
	br_button_type_1.fill_secondary_color[2] = 0.0f;
	br_button_type_1.fill_secondary_opacity = 1.0f;
	br_button_type_1.gradient = true;
	br_button_type_1.outline_opacity = 1.0f;
	br_button_type_1.outline_width = 1.0f;
	testslider = new Slider(CANVAS_WIDTH / 4.0f, CANVAS_HEIGTH / 2.0f, 3.0f * CANVAS_WIDTH / 4.0f, CANVAS_HEIGTH / 2.0f, br_button_type_1);
	testslider->init();
}

void FilmBrowser::draw()
{
	//background
	graphics::Brush br;
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 0.5f;
	br.fill_color[2] = 0.0f;
	br.fill_opacity = 1.0f;
	br.fill_secondary_color[0] = 0.0f;
	br.fill_secondary_color[1] = 0.6f;
	br.fill_secondary_color[2] = 0.8f;
	br.fill_secondary_opacity = 1.0f;
	br.gradient = true;

	br.outline_opacity = 0.0f;

	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGTH / 2, CANVAS_WIDTH, CANVAS_WIDTH, br);
	//end background 

	// draw the movies
	displayableMovies.draw();

	// left button for changing movie
	graphics::setScale(0.8f, 0.8f);
	b1_left->draw();

	// left button for changing movie's images
	graphics::setScale(0.66f, 0.66f);
	b2_left->draw();

	//
	graphics::setOrientation(180);
	// right button for changing movie
	graphics::setScale(0.8f, 0.8f);
	b1_right->draw();

	// right button for changing movie's images
	graphics::setScale(0.66f, 0.66f);
	b2_right->draw();
	
	//reset br 
	graphics::setOrientation(0);
	graphics::setScale(1.0f, 1.0f);

	b_reset->draw();
	b_action->draw();
	b_drama->draw();
	b_adventure->draw();
	b_fantasy->draw();
	b_history->draw();
	b_crime->draw();
	b_scifi->draw();
	testslider->draw();

	br.fill_color[0] = 0.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;
	br.outline_opacity = 1.0f;
	br.outline_width = 1.0f;
	//graphics::drawLine(CANVAS_WIDTH / 4.0f, CANVAS_HEIGTH / 2.0f, 3.0f * CANVAS_WIDTH / 4.0f, CANVAS_HEIGTH / 2.0f, br);
}



FilmBrowser::FilmBrowser()
{

}

FilmBrowser::~FilmBrowser()
{
	std::cout << "FilmBrowser" << endl;
	for (auto button : buttons) {
		delete button;
	}
}