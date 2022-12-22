#include "filmBrowser.h"
#include "graphics.h"
#include "config.h"
#include "movie.h"
#include "button.h"
#include "movies_list.h"
//#include "text_container.h"

MoviesList displayableMovies;
Button* b1_left;
Button* b1_right;
Button* b2_left;
Button* b2_right;
std::vector<Button*> buttons;

void FilmBrowser::update()
{
	b2_left->addActionCallback(std::bind(&Movie::previousShot, &displayableMovies.movies[displayableMovies.getMovieIndex()]));
	b2_right->addActionCallback(std::bind(&Movie::nextShot, &displayableMovies.movies[displayableMovies.getMovieIndex()]));
	for (auto button : buttons) {
		button->update();
	}
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