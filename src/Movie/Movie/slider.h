#pragma once
#include "widget.h"
#include "button.h"
class Slider : public Widget {
public:
	//central_x in this class takes the place of the x value of the first point
	//central_y in this class takes the place of the y value of the first point
	//width in this class takes the place of the x value of the second point
	//height in this class takes the place of the y value of second point
	Slider();
	Slider(float central_x, float central_y, float width, float height, graphics::Brush br, char buttonPosition);
	~Slider();
	void draw() /*override*/;
	void update()/*override*/;
	void init()/*override*/;
	void addActionCallback(std::function<void()> cb);
	graphics::Brush brsaver;
	Button* slidersButton;
	Button* afterB;
	char buttonPosition;
};