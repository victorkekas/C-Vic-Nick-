#include "select_one_option.h"

SelectOneOption::SelectOneOption()
{
}

SelectOneOption::SelectOneOption(float central_x, float central_y, float width, float height, graphics::Brush br, std::vector<std::string> options)
{
	this->central_x = central_x;
	this->central_y = central_y;
	this->width = width;
	this->height = height;
	this->br = br;
	this->options = options;

	//change the location relatable to the above sone
	//now take care of the br->make it black
	upButton = new Button(this->central_x + (this->width / 2) + (CANVAS_WIDTH / 64), this->central_y - (this->height / 2), this->width / 5, this->height / 2 , this->br);
	downButton = new Button(this->central_x + (this->width / 2) + (CANVAS_WIDTH / 64), this->central_y + (this->height / 2), this->width / 5, this->height / 2 , this->br);
}

SelectOneOption::~SelectOneOption()
{
	delete	upButton;
	delete	downButton;
}

void SelectOneOption::draw()
{
	graphics::drawRect(central_x, central_y, width, height, br);
	graphics::drawText(central_x, central_y, width, options[chosen], br);
	upButton->draw();
	downButton->draw();
}

void SelectOneOption::update()
{
}

void SelectOneOption::init()
{
	//not here-> in filmbrowser 
	//upButton->addActionCallback(std::bind(&SelectOneOption::previousOption, &SelectOneOption));
	//downButton->addActionCallback(std::bind(&SelectOneOption::nextOption, &SelectOneOption));
}

void SelectOneOption::nextOption()
{
	if (options.size() == 1) {
		return;
	}
	else {
		if (chosen == options.size() - 1) {
			chosen = 0;
		}
		else {
			chosen++;
		}
	}
}

void SelectOneOption::previousOption()
{
	if (options.size() == 1) {
		return;
	}
	else {
		if (chosen == 0) {
			chosen = options.size() - 1;
		}
		else {
			chosen-=1;
		}
	}
}

std::string SelectOneOption::getOption()
{
	return this->options[chosen];
}
