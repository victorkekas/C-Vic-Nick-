#include "slider.h"

Slider::Slider()
{
}

Slider::Slider(float central_x, float central_y, float width, float height, graphics::Brush br)
{
	this->central_x = central_x;
	this->central_y = central_y;
	this->width = width;
	this->height = height;
	this->br = br;

	//here or in the init function,if the button's possition is changing,then a certain value is changing (namely increasing or decreasing)
	//so we must create a function for that either in this class or the moviesList class 
}

Slider::~Slider()
{
}

void Slider::draw()
{
	graphics::drawLine(this->central_x,this->central_y,this->width,this->height,this->br);
	slidersButton->draw();
}

void Slider::update()
{
	ContainerBox boundries(this->central_x, this->central_y, CANVAS_WIDTH / 64.0f, 1.6f * CANVAS_HEIGTH / 32.0f);
	graphics::MouseState ms;
	graphics::getMouseState(ms);
	float mx = graphics::windowToCanvasX((float)ms.cur_pos_x);
	float my = graphics::windowToCanvasY((float)ms.cur_pos_y);
	bool in_bounds = boundries.contained(mx, my);
	if (in_bounds) {
		//if mouse_left_pressed->make sound and change button's color
		if (ms.button_left_pressed) {
			afterB->draw();

			graphics::playSound(std::string(ASSET_PATH) + "button.wav", 1.0f);
		}
		//if mouse_left_down->
		//if current mouse_pos is left or right, compare to the current pos of the button, draw button there
		if (ms.button_left_down) {
	
		}
		//if mouse_left_released->make sound and change button's color to the original one 
		if (ms.button_left_released) {
			graphics::playSound(std::string(ASSET_PATH) + "button.wav", 1.0f);
		}
	}
	
}

void Slider::init()
{
	slidersButton = new Button(this->central_x, this->central_y, CANVAS_WIDTH / 64.0f, 1.6f * CANVAS_HEIGTH / 32.0f, this->br);
	brsaver.fill_color[0] = 0.5f;
	brsaver.fill_color[1] = 0.5f;
	brsaver.fill_color[2] = 0.5f;
	afterB = new Button(this->central_x, this->central_y, CANVAS_WIDTH / 64.0f, 1.6f * CANVAS_HEIGTH / 32.0f, brsaver);
}
