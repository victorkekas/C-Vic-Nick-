#pragma once
#include "widget.h"
#include "button.h"
class Slider : public Widget {
public:
	//central_x in this class takes the place of the x value of the first point
	//central_y in this class takes the place of the y value of the first point
	//width in this class takes the place of the x value of the second point
	//height in this class takes the place of the y value of second point
	enum slider_state_t { SLIDER_ACTIVATED, SLIDER_IDLE, SLIDER_HIGHLIGHTED, SLIDER_PRESSED};
	slider_state_t s_button_state = SLIDER_IDLE;
	Slider();
	Slider(float central_x, float central_y, float width, float height, graphics::Brush br, char buttonPosition, int lowestLimit, int highestLimit);
	~Slider();
	void draw() override;
	void update()override;
	void init()override;
	void addActionCallback(std::function<void()> cb);
	void separator();
	graphics::Brush brsaver;
	Button* slidersButton;
	Button* afterB;
	char buttonPosition;
	int lowestLimit, highestLimit, displaybleValue;
	float spaces, prev_loc;
};