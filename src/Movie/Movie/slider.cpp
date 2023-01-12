#include "slider.h"

Slider::Slider()
{
}

Slider::Slider(float central_x, float central_y, float width, float height, graphics::Brush br, char buttonPosition, int lowestLimit, int highestLimit)
{
	this->central_x = central_x;
	this->central_y = central_y;
	this->width = width;
	this->height = height;
	this->br = br;
	this->buttonPosition = buttonPosition;
	this->lowestLimit = lowestLimit;
	this->highestLimit = highestLimit;
	//chose where to "start", from the beginning(s) or the end(f)
	switch (buttonPosition)
	{
	case 's':
		slidersButton = new Button(this->central_x, this->central_y, CANVAS_WIDTH / 64.0f, 1.6f * CANVAS_HEIGTH / 32.0f, this->br);
		this->displaybleValue = lowestLimit;
		prev_loc = this->central_x;
		break;
	case 'f':
		slidersButton = new Button(this->width, this->height, CANVAS_WIDTH / 64.0f, 1.6f * CANVAS_HEIGTH / 32.0f, this->br);
		this->displaybleValue = highestLimit;
		prev_loc = this->width;
		break;
	}
	//separate evenly the slider
	int difference = highestLimit - lowestLimit;
	if (difference == 0) { return; }
	spaces = (this->width - this->central_x) / difference;
}

void Slider::addActionCallback(std::function<void(void*)> cb)
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
		if (ms.button_left_pressed) {
			graphics::playSound(std::string(ASSET_PATH) + "button.wav", 1.0f);
		}
		//if current mouse_pos is left or right, compare to the current pos of the button, and make button follow (draw) mouse 
		if (ms.button_left_down) {
			if (mx > pmx && mx>this->central_x && mx<this->width) {
				this->slidersButton->central_x = mx;
				if (mx > prev_loc) {
					this->displaybleValue += 1;
					prev_loc += spaces;
					if (this->displaybleValue > this->highestLimit) {
						this->displaybleValue == this->highestLimit;
					}
					s_button_state = SLIDER_ACTIVATED;
				}
				action_callback(nullptr);
			}
			if (mx < pmx && mx > this->central_x && mx < this->width) {
				this->slidersButton->central_x = mx;
				if (mx < prev_loc) {
					this->displaybleValue -= 1;
					prev_loc -= spaces;
					if (this->displaybleValue < this->lowestLimit) {
						this->displaybleValue == this->lowestLimit;
					}
					s_button_state = SLIDER_ACTIVATED;
				}
				action_callback(nullptr);
			}
		}
		if (ms.button_left_released) {
			s_button_state = SLIDER_ACTIVATED;
			graphics::playSound(std::string(ASSET_PATH) + "button.wav", 1.0f);
		}
	}
}

void Slider::init()
{
	s_button_state = SLIDER_IDLE;
	switch (this->buttonPosition)
	{
	case 's':
		slidersButton->central_x = this->central_x;
		slidersButton->central_y = this->central_y;
		this->displaybleValue = lowestLimit;
		prev_loc = this->central_x;
		break;
	case 'f':
		slidersButton->central_x = this->width;
		slidersButton->central_y = this->height;
		this->displaybleValue = highestLimit;
		prev_loc = this->width;
		break;
	}
}
