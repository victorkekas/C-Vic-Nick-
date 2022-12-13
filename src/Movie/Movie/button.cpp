#include "button.h"


Button::~Button()
{
}
Button::Button()
{
}

void Button::draw()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "arrow.png";
	br.outline_color[0] = 255.0f;
	br.outline_color[1] = 0.0f;
	br.outline_color[2] = 0.0f;
	br.outline_width = 0.0f;
	br.outline_opacity = 0.0f;
	br.fill_color[0] = 0.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;
	// left button for changing movie
	graphics::drawRect(CANVAS_WIDTH / 4.0f, CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 15.0f, CANVAS_HEIGTH / 10.3f, br); // main image
	// right button for changing movie
	graphics::setOrientation(180);
	graphics::drawRect(3 * CANVAS_WIDTH / 4.0f, CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 15.0f, CANVAS_HEIGTH / 10.3f, br); // main image
	graphics::setOrientation(0);

	//graphics::drawRect(3.2 * CANVAS_WIDTH / 4.0f, 3 * CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 3.0f, CANVAS_HEIGTH / 3.0f, br2); // secondary images
	graphics::setScale(0.66f, 0.66f);
	br.outline_color[0] = 255.0f;
	br.outline_color[1] = 0.0f;
	br.outline_color[2] = 0.0f;
	br.outline_width = 0.0f;
	br.outline_opacity = 0.0f;
	br.fill_color[0] = 255.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;
	// left button for changing movie's images
	graphics::drawRect(3.2 * CANVAS_WIDTH / 4.0f - CANVAS_WIDTH / 7.0f, 3 * CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 15.0f, CANVAS_HEIGTH / 10.3f, br); // main image
	// right button for changing movie's images
	graphics::setOrientation(180);
	graphics::drawRect(3.2 * CANVAS_WIDTH / 4.0f + CANVAS_WIDTH / 7.0f, 3 * CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 15.0f, CANVAS_HEIGTH / 10.3f, br); // main image
	graphics::setOrientation(0);
	graphics::setScale(1.0f, 1.0f);

	// container on bottom left of the screen
}

void Button::update()
{
	/*if (!m_visible)
		return;
	*/
	graphics::MouseState ms;
	graphics::getMouseState(ms);
	float mx = graphics::windowToCanvasX((float)ms.cur_pos_x);
	float my = graphics::windowToCanvasY((float)ms.cur_pos_y);
	//glm::vec2 coord(mx,my);
	//bool in_bounds = m_bounds.contains(coords);
	
	/*if (in_bounds) {
		if (ms.button_left_pressed) {
			if (!requestFocus()) {
				return;
			}
			m_button_state = BUTTON_PRESSED;
			graphics::playSound(m_asset_path + "button.aav", 0.7f);
			if (m_callback_pressed)
				m_callback_pressed(m_pressed_data, m_id);
		}
		if (ms.button_left_released) {
			m_button_state = BUTTON_IDLE;
			if (m_callback_released)
				m_callback_released(m_released_data, m_id);
			releasedFocus();
			return;
		}
	}*/
	
}

void Button::init()
{
}
