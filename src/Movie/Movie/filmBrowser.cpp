#include "filmBrowser.h"
#include "graphics.h"
#include "config.h"
#include "movie.h"

void FilmBrowser::update()
{
}

void FilmBrowser::draw()
{
	graphics::Brush br;
	br.fill_color[0] = 0.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;
	br.fill_opacity = 0.8f;
	br.fill_secondary_color[0] = 255.0f;
	br.fill_secondary_color[1] = 0.0f;
	br.fill_secondary_color[2] = 0.0f;
	br.fill_secondary_opacity = 0.5f;
	br.gradient = true;
	br.gradient_dir_u = 0.0f;
	br.gradient_dir_v = 4.0f;
	br.outline_opacity = 0.0f;

	graphics::drawRect(CANVAS_WIDTH/2, CANVAS_HEIGTH/2, CANVAS_WIDTH, CANVAS_WIDTH, br);

	Movie movie1;
	std::vector<string> images;
	images.push_back("FightClub.png");
	images.push_back("shot-FightClubV1.png");
	movie1.draw(images);
}

void FilmBrowser::init()
{
}

FilmBrowser::FilmBrowser()
{
}

FilmBrowser::~FilmBrowser()
{
}
