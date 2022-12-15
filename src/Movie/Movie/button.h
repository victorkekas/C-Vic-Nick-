#pragma once
#include "widget.h"


class Button : public Widget {
protected:
	enum button_state_t {BUTTON_PRESSED, BUTTON_IDLE, BUTTON_HIGHLIGHTED};
	button_state_t m_button_state = BUTTON_IDLE;
	std::string m_text;
	int m_id;
	std::function<void(void*, int id)> m_callback_pressed = nullptr;
	std::function<void(void*, int id)> m_callback_released = nullptr;
	void* m_pressed_data = nullptr;
	void* m_released_data = nullptr;

	std::vector<std::vector<std::string>>* vec_ptr_images;
	std::vector<Movie>* vec_ptr_movies;
	int* index;
	char movement;

public:
	//Button(float cx, float cy, float w, float h, std::string text, int ID);
	Button();
	Button(float central_x, float central_y, float width, float height, graphics::Brush br, std::vector<std::vector<std::string>>* vec_ptr_images, std::vector<Movie>* vec_ptr_movies, int* index,char movement);
	~Button();
	void addActionCallback(std::function<void(int, void*)> cb);
	void ButtonAction_Index(int evt, void* data);
	void draw() override;
	void update()override;
	void init()override;
};