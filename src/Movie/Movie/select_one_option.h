#pragma once
#include "widget.h"
#include "button.h"

class SelectOneOption : public Widget {//or public Button
public:
	SelectOneOption();
	SelectOneOption(float central_x, float central_y, float width, float height, graphics::Brush br, std::vector<std::string> options);
	~SelectOneOption();
	void draw() /*override*/;
	void update()/*override*/;
	void init()/*override*/;
	void nextOption();
	void previousOption();
	std::string getOption();

	std::vector<std::string> options;
	int chosen;
	Button* upButton;
	Button* downButton;
};