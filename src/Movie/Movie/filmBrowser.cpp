#include "filmBrowser.h"
#include "graphics.h"
#include "config.h"
#include "movie.h"
#include "button.h"
#include "glowing_button.h"
#include "slider.h"
#include "movies_list.h"
#include "text_container.h"

MoviesList displayableMovies;
Button* b1_left,* b1_right,* b2_left,* b2_right,* b_reset,* b_action,* b_drama, * b_adventure, * b_fantasy, * b_history, * b_crime, * b_scifi;
std::vector<Widget*> widgets;
Slider* fromYearSlider, * toYearSlider;
textContainer* txtCont; 
void FilmBrowser::update()
{
	displayableMovies.textTitle = txtCont->getText();
	if (!(displayableMovies.filtersOn)) {
		b2_left->addActionCallback(std::bind(&Movie::previousShot, &displayableMovies.movies[displayableMovies.getMovieIndex()]));
		b2_right->addActionCallback(std::bind(&Movie::nextShot, &displayableMovies.movies[displayableMovies.getMovieIndex()]));
	}
	else if (displayableMovies.filtersOn) {
		b2_left->addActionCallback(std::bind(&Movie::previousShot, &displayableMovies.filteredMovies[displayableMovies.getMovieIndex()]));
		b2_right->addActionCallback(std::bind(&Movie::nextShot, &displayableMovies.filteredMovies[displayableMovies.getMovieIndex()]));
	}
	
	if (b_reset->m_button_state == 0) {
		fromYearSlider->init();
		toYearSlider->init();
		fromYearSlider->addActionCallback(std::bind(&MoviesList::fillFilteredMovies, &displayableMovies));
		toYearSlider->addActionCallback(std::bind(&MoviesList::fillFilteredMovies, &displayableMovies));
		txtCont->init();
		for (auto widget : widgets) {
			widget->init();
		}
	}
	if (fromYearSlider->s_button_state == 0 || toYearSlider->s_button_state == 0) {
		displayableMovies.changeFromYear(fromYearSlider->displaybleValue);
		displayableMovies.changeToYear(toYearSlider->displaybleValue);
		fromYearSlider->addActionCallback(std::bind(&MoviesList::fillFilteredMovies, &displayableMovies));
		toYearSlider->addActionCallback(std::bind(&MoviesList::fillFilteredMovies, &displayableMovies));
	}

	for (auto widget : widgets) {
		widget->update();
	}
	displayableMovies.textTitle = txtCont->getText();
	//std::cout << displayableMovies.textTitle << std::endl;
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
	b2_left = new Button(3.2 * CANVAS_WIDTH / 4.0f - CANVAS_WIDTH / 7.0f, 3 * CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 20.0f, CANVAS_HEIGTH / 10.3f, br_button_type_1);
	//b2_left->addActionCallback(std::bind(&Movie::previousShot, &displayableMovies.movies[displayableMovies.getMovieIndex()]));

	// right button for changing movie's images
	graphics::setOrientation(180);
	b2_right = new Button(3.2 * CANVAS_WIDTH / 4.0f + CANVAS_WIDTH / 7.0f, 3 * CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 20.0f, CANVAS_HEIGTH / 10.3f, br_button_type_1);
	//b2_right->addActionCallback(std::bind(&Movie::nextShot, &displayableMovies.movies[displayableMovies.getMovieIndex()]) );

	//reset br 
	graphics::setOrientation(0);
	widgets.push_back(b1_left);
	widgets.push_back(b1_right);
	widgets.push_back(b2_left);
	widgets.push_back(b2_right);
	
	

	br_button_type_1.texture = std::string(ASSET_PATH) + "action.png";
	b_action = new GlowingButton(12.0f * CANVAS_WIDTH / 16, 1.8f * CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 16.6f, CANVAS_HEIGTH / 16.6f, br_button_type_1);
	b_action->addActionCallback(std::bind(&MoviesList::setFilterAction, &displayableMovies));

	br_button_type_1.texture = std::string(ASSET_PATH) + "drama.png";
	b_drama = new GlowingButton(13.5f * CANVAS_WIDTH / 16, 1.8 * CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 16.6f, CANVAS_HEIGTH / 16.6f, br_button_type_1);
	b_drama->addActionCallback(std::bind(&MoviesList::setFilterDrama, &displayableMovies));

	br_button_type_1.texture = std::string(ASSET_PATH) + "adventure.png";
	b_adventure = new GlowingButton(15.0f * CANVAS_WIDTH / 16, 1.4 * CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 16.6f, CANVAS_HEIGTH / 16.6f, br_button_type_1);
	b_adventure->addActionCallback(std::bind(&MoviesList::setFilterAdventure, &displayableMovies));

	br_button_type_1.texture = std::string(ASSET_PATH) + "fantasy.png";
	b_fantasy = new GlowingButton(12.0f * CANVAS_WIDTH / 16, 1.4 * CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 16.6f, CANVAS_HEIGTH / 16.6f, br_button_type_1);
	b_fantasy->addActionCallback(std::bind(&MoviesList::setFilterFantasy, &displayableMovies));

	br_button_type_1.texture = std::string(ASSET_PATH) + "history.png";
	b_history = new GlowingButton(13.5f * CANVAS_WIDTH / 16, 1.4 * CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 16.6f, CANVAS_HEIGTH / 16.6f, br_button_type_1);
	b_history->addActionCallback(std::bind(&MoviesList::setFilterHistory, &displayableMovies));

	br_button_type_1.texture = std::string(ASSET_PATH) + "crime.png";
	b_crime = new GlowingButton(15.0f * CANVAS_WIDTH / 16, 1.0 * CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 16.6f, CANVAS_HEIGTH / 16.6f, br_button_type_1);
	b_crime->addActionCallback(std::bind(&MoviesList::setFilterCrime, &displayableMovies));

	br_button_type_1.texture = std::string(ASSET_PATH) + "Sci-fi.png";
	b_scifi = new GlowingButton(13.5f * CANVAS_WIDTH / 16, 1.0 * CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 16.6f, CANVAS_HEIGTH / 16.6f, br_button_type_1);
	b_scifi->addActionCallback(std::bind(&MoviesList::setFilterSciFi, &displayableMovies));

	br_button_type_1.texture = std::string(ASSET_PATH) + "reset.png";
	b_reset = new Button(15.0f * CANVAS_WIDTH / 16, 1.8f * CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 16.6f, CANVAS_HEIGTH / 16.6f, br_button_type_1);
	b_reset->addActionCallback(std::bind(&MoviesList::resetFilters, &displayableMovies));

	widgets.push_back(b_reset);
	widgets.push_back(b_action);
	widgets.push_back(b_drama);
	widgets.push_back(b_adventure);
	widgets.push_back(b_fantasy);
	widgets.push_back(b_history);
	widgets.push_back(b_crime);
	widgets.push_back(b_scifi);

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
	fromYearSlider = new Slider(2.88f * CANVAS_WIDTH / 4.0f,0.4f * CANVAS_HEIGTH / 4.0f, 3.88f * CANVAS_WIDTH / 4.0f, 0.4f * CANVAS_HEIGTH / 4.0f, br_button_type_1, 's',displayableMovies.getOldestYear(), displayableMovies.getNewestYear());
	toYearSlider = new Slider(2.88f * CANVAS_WIDTH / 4.0f,0.75f * CANVAS_HEIGTH / 4.0f, 3.88f * CANVAS_WIDTH / 4.0f, 0.75f * CANVAS_HEIGTH / 4.0f, br_button_type_1, 'f', displayableMovies.getOldestYear(), displayableMovies.getNewestYear());
	fromYearSlider->addActionCallback(std::bind(&MoviesList::fillFilteredMovies, &displayableMovies));
	toYearSlider->addActionCallback(std::bind(&MoviesList::fillFilteredMovies, &displayableMovies));
	fromYearSlider->init();
	toYearSlider->init();

	widgets.push_back(fromYearSlider);
	widgets.push_back(toYearSlider);

	br_button_type_1.texture = "";
	br_button_type_1.fill_color[0] = 1.0f;
	br_button_type_1.fill_color[1] = 1.0f;
	br_button_type_1.fill_color[2] = 1.0f;
	br_button_type_1.gradient = false;
	br_button_type_1.outline_width=0.2;

	txtCont= new textContainer(4.22*CANVAS_WIDTH/5, 2.2f * CANVAS_HEIGTH / 4.0f, 0.25 * CANVAS_WIDTH, 0.05 * CANVAS_HEIGTH, br_button_type_1);
	txtCont->addActionCallback(std::bind(&MoviesList::fillFilteredMovies, &displayableMovies));
	

	widgets.push_back(txtCont);
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
	fromYearSlider->draw();
	toYearSlider->draw();
	txtCont->draw();
	
	br.fill_color[0] = 0.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;
	br.fill_secondary_color[0] = 0.0f;
	br.fill_secondary_color[1] = 0.0f;
	br.fill_secondary_color[2] = 0.0f;
	br.outline_opacity = 1.0f;
	br.outline_width = 1.0f;
	br.texture = "From: " + to_string(fromYearSlider->displaybleValue);
	graphics::drawText(2.67f * CANVAS_WIDTH / 4.0f, 0.25f * CANVAS_HEIGTH / 4.0f,13.0f,br.texture,br);
	br.texture = "To: " + to_string(toYearSlider->displaybleValue);
	graphics::drawText(2.75f * CANVAS_WIDTH / 4.0f, 0.6f * CANVAS_HEIGTH / 4.0f, 13.0f, br.texture, br);
	br.texture = "Year";
	graphics::drawText(3.3f * CANVAS_WIDTH / 4.0f, 0.15f * CANVAS_HEIGTH / 4.0f, 13.0f, br.texture, br);
	br.texture = "Genre";
	graphics::drawText(11.7f * CANVAS_WIDTH / 16, 1.0 * CANVAS_HEIGTH / 4.0f, 13.0f, br.texture, br);
	br.texture = "Search by title:";
	graphics::drawText(10.0f * CANVAS_WIDTH / 16, 2.23 * CANVAS_HEIGTH / 4.0f, 13.0f, br.texture, br);
}

FilmBrowser::FilmBrowser()
{

}

FilmBrowser::~FilmBrowser()
{
	std::cout << "FilmBrowser" << endl;
	for (auto widget : widgets) {
		delete widget;
	}
}