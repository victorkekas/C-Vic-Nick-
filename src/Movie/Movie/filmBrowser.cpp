#include "filmBrowser.h"
#include "graphics.h"
#include "config.h"

void FilmBrowser::update()
{
}

void FilmBrowser::draw()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "ANewHope.png";
	br.outline_opacity = 0.0f;

	graphics::drawRect(CANVAS_WIDTH/2, CANVAS_HEIGTH/2, CANVAS_WIDTH, CANVAS_WIDTH, br);
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
