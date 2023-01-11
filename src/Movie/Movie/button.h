#pragma once
#include "widget.h"
#include "movies_list.h";


class Button : public Widget {
protected:
	enum button_state_t {BUTTON_PRESSED, BUTTON_IDLE, BUTTON_HIGHLIGHTED, BUTTON_ACTIVATED};
public:
	button_state_t m_button_state = BUTTON_IDLE;
	Button();
	Button(float central_x, float central_y, float width, float height, graphics::Brush br);
	~Button();
	void addActionCallback(std::function<void()> cb);
	void draw() override;
	void update()override;
	void init()override;
	
};