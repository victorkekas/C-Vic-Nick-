#pragma once
#include "graphics.h"
#include "config.h"
#include "movie.h"
#include "container_box.h"

class Widget {
protected:
	bool active;
	float width, height;
	graphics::Brush br;
	std::function<void(void*)>action_callback;
public:
	float central_x, central_y;
	Widget();
	~Widget();
	virtual void draw();
	virtual void update();
	virtual void init();
};