#include "slider.h"

Slider::Slider()
{
}

Slider::Slider(float central_x, float central_y, float width, float height, graphics::Brush br, char buttonPosition)
{
	this->central_x = central_x;
	this->central_y = central_y;
	this->width = width;
	this->height = height;
	this->br = br;
	this->buttonPosition = buttonPosition;
	switch (buttonPosition)
	{
	case 's':
		slidersButton = new Button(this->central_x, this->central_y, CANVAS_WIDTH / 64.0f, 1.6f * CANVAS_HEIGTH / 32.0f, this->br);
		break;
	case 'f':
		slidersButton = new Button(this->width, this->height, CANVAS_WIDTH / 64.0f, 1.6f * CANVAS_HEIGTH / 32.0f, this->br);
		break;
	}
	//here or in the init function,if the button's possition is changing,then a certain value is changing (namely increasing or decreasing)
	//so we must create a function for that either in this class or the moviesList class 
}

void Slider::addActionCallback(std::function<void()> cb)
{
	action_callback = cb;
}

Slider::~Slider()
{
	delete slidersButton;
}

void Slider::draw()
{
	graphics::drawLine(this->central_x,this->central_y,this->width,this->height,this->br);
	slidersButton->draw();
}

void Slider::update()
{
	ContainerBox boundries(this->slidersButton->central_x, this->slidersButton->central_y, CANVAS_WIDTH / 64.0f, 1.6f * CANVAS_HEIGTH / 32.0f);
	graphics::MouseState ms;
	graphics::getMouseState(ms);
	float mx = graphics::windowToCanvasX((float)ms.cur_pos_x);
	float my = graphics::windowToCanvasY((float)ms.cur_pos_y);
	float pmx = graphics::windowToCanvasX((float)ms.prev_pos_x);
	float pmy = graphics::windowToCanvasY((float)ms.prev_pos_y);
	bool in_bounds = boundries.contained(mx, my);
	if (in_bounds) {
		//if mouse_left_pressed->make sound and change button's color
		if (ms.button_left_pressed) {
			graphics::playSound(std::string(ASSET_PATH) + "button.wav", 1.0f);
		}
		//if mouse_left_down->
		//if current mouse_pos is left or right, compare to the current pos of the button, draw button there
		if (ms.button_left_down) {
			if (mx > pmx && mx>this->central_x && mx<this->width) {
				this->slidersButton->central_x = mx;
				action_callback();
			}
			if (mx < pmx && mx > this->central_x && mx < this->width) {
				this->slidersButton->central_x = mx;
				action_callback();
			}
		}
		//if mouse_left_released->make sound and change button's color to the original one 
		if (ms.button_left_released) {
			s_button_state = SLIDER_ACTIVATED;
			graphics::playSound(std::string(ASSET_PATH) + "button.wav", 1.0f);
		}
	}
	
}

void Slider::init()
{
	switch (this->buttonPosition)
	{
	case 's':
		slidersButton->central_x = this->central_x;
		slidersButton->central_y = this->central_y;
		break;
	case 'f':
		slidersButton->central_x = this->width;
		slidersButton->central_y = this->height;
		break;
	}
}
