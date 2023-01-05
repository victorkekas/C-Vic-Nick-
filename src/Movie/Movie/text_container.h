#pragma once
#include "widget.h"


class textContainer : public Widget {
public:
	string text="";
	textContainer(float central_x, float central_y, float width, float height, graphics::Brush br);
	void addActionCallback(std::function<void()> cb);
	~textContainer();
	void draw();
	void update();
	void init();
	char readChar();

};

