#include "glowing_button.h"

GlowingButton::GlowingButton()
{
}

GlowingButton::GlowingButton(float central_x, float central_y, float width, float height, graphics::Brush br)
{
	this->central_x = central_x;
	this->central_y = central_y;
	this->width = width;
	this->height = height;
	this->br = br;
	this->tempbr = br;
}

GlowingButton::~GlowingButton()
{
}

void GlowingButton::draw()
{
	if (isactivated()) {
		br.outline_color[0] = 1.0f;
		br.outline_color[1] = 1.0f;
		br.outline_color[2] = 1.0f;
		br.outline_width = 1.2f;
		br.outline_opacity = 1.0f;
		br.texture = br.texture;
	}
	else {
		br.outline_color[0] = tempbr.outline_color[0];
		br.outline_color[1] = tempbr.outline_color[1];
		br.outline_color[2] = tempbr.outline_color[2];
		br.outline_width = tempbr.outline_width;
		br.outline_opacity = tempbr.outline_opacity;
		br.texture = tempbr.texture;
	}
	

	graphics::drawRect(this->central_x, this->central_y, this->width, this->height, this->br);
}

void GlowingButton::update()
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
			if (isactivated()) {
				this->activated = false;
			}
			else {
				this->activated = true;
			}
			graphics::playSound(std::string(ASSET_PATH) + "button.wav", 1.0f);
			action_callback(nullptr);
		}
		if (ms.button_left_released) {
			m_button_state = BUTTON_IDLE;
		}
		return;
	}
}

void GlowingButton::init()
{
	this->activated = false;
}

bool GlowingButton::isactivated()
{
	return this->activated;
}
