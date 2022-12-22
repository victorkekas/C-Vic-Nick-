#include "button.h"


Button::~Button()
{
	std::cout << "Button" << endl;
}

Button::Button()
{
}

Button::Button(float central_x, float central_y, float width, float height, graphics::Brush br, int limit,/*std::vector<std::vector<std::string>>* vec_ptr_images, std::vector<Movie>* vec_ptr_movies,*/  int* index, char movement)
{
	this->central_x = central_x;
	this->central_y = central_y;
	this->width = width;
	this->height = height;
	this->br = br;
	//this->vec_ptr_images = vec_ptr_images;
	//this->vec_ptr_movies = vec_ptr_movies;
	this->limit = limit;
	this->index = index;
	this->movement = movement;
}

void Button::addActionCallback(std::function<void()> cb)
{
	action_callback = cb;
}

void Button::ButtonAction_Index()
{
	switch (this->movement) {
	case 'f':
		if (*index == (limit - 1)) {
			*index = 0;
			break;
		}
		*index += 1;
		break;
	case 'b':
		if (*index == 0) {
			*index = (limit - 1);
			break;
		}
		*index -= 1;
		break;
	}
}

void Button::ButtonAction_Index_except0()
{
	switch (this->movement) {
	case 'f':
		if (*index == (limit - 1)) {
			*index = 1;
			break;
		}
		*index += 1;
		break;
	case 'b':
		if (*index == 1) {
			*index = (limit - 1);
			break;
		}
		*index -= 1;
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
	//std::cout<< boundries.side_00<< "___"<< boundries.side_x0 << "___" << boundries.side_0y << "___" << boundries.side_xy << "___" << in_bounds<<endl;
	//std::cout<< mx << " " << my << endl;
	/*
	if (!in_bounds) {
		return;
	}

	//auto edw thelei ftiajimo to apo panw doyleuei--mhn jexnas to widget <3
	if (ms.button_left_pressed) {
		graphics::playSound(std::string(ASSET_PATH) + "button.wav", 1.0f);
		std::cout<< "mixalis" << endl;
		return;
	}
	*/
	if (in_bounds) {
		if (ms.button_left_pressed) {
			graphics::playSound(std::string(ASSET_PATH) + "button.wav", 1.0f);
			action_callback();
			return;
		}
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

char Button::getMovement()
{
	return this->movement;
}
