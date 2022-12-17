#pragma once
#include "graphics.h"
#include "config.h"
#include "movie.h"
#include "container_box.h"

class Widget {
public:
	bool active;
	float central_x, central_y, width, height;
	graphics::Brush br;
	bool requestFocus();
	bool releasedFocus();
	std::function<void(int, void*)> action_callback;

	Widget();
	~Widget();
	virtual void draw();
	virtual void update();
	virtual void init();
};