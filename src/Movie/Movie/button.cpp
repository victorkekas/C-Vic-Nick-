#include "button.h"


Button::~Button()
{
}

Button::Button()
{
}

Button::Button(float central_x, float central_y, float width, float height, graphics::Brush br)
{
	this->central_x = central_x;
	this->central_y = central_y;
	this->width = width;
	this->height = height;
	this->br = br;
}

void Button::addActionCallback(std::function<void(void*)> cb)
{
	action_callback = cb;
}

void Button::draw ()
{
	graphics::drawRect(this->central_x, this->central_y, this->width, this->height, this->br);
}

void Button::update()
{

	ContainerBox boundries(this->central_x, this->central_y, this->width, this->height);
	graphics::MouseState ms;
	graphics::getMouseState(ms);
	float mx = graphics::windowToCanvasX((float)ms.cur_pos_x);
	float my = graphics::windowToCanvasY((float)ms.cur_pos_y);
	bool in_bounds = boundries.contained(mx, my);
	if (in_bounds) {
		m_button_state = BUTTON_HIGHLIGHTED;
		if (ms.button_left_pressed) {
			m_button_state = BUTTON_PRESSED;
			graphics::playSound(std::string(ASSET_PATH) + "button.wav", 1.0f);
			action_callback(nullptr);
		}
		if (ms.button_left_released) {
			m_button_state = BUTTON_IDLE;
		}
		return;
	}
}

void Button::init()
{
}