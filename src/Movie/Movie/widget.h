#pragma once
#include "graphics.h"
#include "config.h"
#include "movie.h"

class Widget {
protected:
	bool active;
	int mouse_posx, mouse_posy, width, height;
	bool requestFocus();
	bool releasedFocus();
public:
	virtual void draw();
	virtual void update();
	virtual void init();
};