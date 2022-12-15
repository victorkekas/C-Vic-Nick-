#include "button.h"


Button::~Button()
{
}

Button::Button()
{
}

Button::Button(float central_x, float central_y, float width, float height, graphics::Brush br, std::vector<std::vector<std::string>>* vec_ptr_images, std::vector<Movie>* vec_ptr_movies, int* index, char movement)
{
	this->central_x = central_x;
	this->central_y = central_y;
	this->width = width;
	this->height = height;
	this->br = br;
	this->vec_ptr_images = vec_ptr_images;
	this->vec_ptr_movies = vec_ptr_movies;
	this->index = index;
	this->movement = movement;
}

void Button::addActionCallback(std::function<void(int, void*)> cb)
{
	action_callback = cb;
}

void Button::ButtonAction_Index(int evt, void* data)
{
	switch (this->movement) {
	case 'f1':
		if (index == (*vec_ptr_images).size()-1) {
			index = 0;
			break;
		}
		index++;
		break;
	case 'b1':
		if (index == 0) {
			index = (*vec_ptr_images).size() - 1;
			break;
		}
		index--;
		break;
	case 'f2':
		if (index == (*vec_ptr_movies).size() - 1) {
			index = 0;
			break;
		}
		break;
	case 'b2':
		if (index == 0) {
			index = (*vec_ptr_movies).size() - 1;
			break;
		}
		index--;
		break;
}
}


void Button::draw ()
{
	graphics::drawRect(this->central_x, this->central_y, this->width, this->height, this->br);
}

void Button::update()
{
	/*if (!m_visible)
		return;
	*/
	ContainerBox boundries(this->central_x, this->central_y, this->width, this->height);
	graphics::MouseState ms;
	graphics::getMouseState(ms);
	float mx = graphics::windowToCanvasX((float)ms.cur_pos_x);
	float my = graphics::windowToCanvasY((float)ms.cur_pos_y);
	bool in_bounds = boundries.contained(mx, my);
	if (!in_bounds) {
		return;
	}

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
