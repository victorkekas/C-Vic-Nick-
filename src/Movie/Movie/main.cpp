#include "graphics.h"
#include "filmBrowser.h"
#include "config.h"
#include <iostream>

void update(float ms)
{
    FilmBrowser* films =  reinterpret_cast<FilmBrowser*>(graphics::getUserData());
    films->update();
}

void draw()
{
    FilmBrowser* films = reinterpret_cast<FilmBrowser*>(graphics::getUserData());
    films->draw();
}

int main()
{
    FilmBrowser myfilms;
    graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGTH, "JUICY");

    graphics::setUserData(&myfilms);

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);

    graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGTH);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

    graphics::setFont("assets\orange juice 2.0.ttf");

    myfilms.init();
    graphics::startMessageLoop();

    return 0;
}