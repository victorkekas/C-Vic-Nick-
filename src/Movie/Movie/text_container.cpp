#include "text_container.h"


textContainer::textContainer(float central_x, float central_y, float width, float height, graphics::Brush br){
	this->central_x = central_x;
	this->central_y = central_y;
	this->width = width;
	this->height = height;
	this->br = br;
}

void textContainer::addActionCallback(std::function<void()> cb)
{
	action_callback = cb;
}

textContainer::~textContainer(){

}

void textContainer::draw() {
	graphics::drawRect( this->central_x, this->central_y, this->width, this->height, this->br);
	br.fill_color[0] = 0;
	br.fill_color[1] = 0;
	br.fill_color[2] = 0;

	//call function that makes tha displayable text (narrow down the ammount of characters of the text)
	narrowText();

	graphics::drawText(	central_x-(width/2)+ (central_x/256), this->central_y+ (this->central_y/128), 12,displayableText,this->br);
	br.fill_color[0] = 1;
	br.fill_color[1] = 1;
	br.fill_color[2] = 1;
}

void textContainer::update() {

	ContainerBox boundries(this->central_x, this->central_y, this->width, this->height);
	graphics::MouseState ms;
	graphics::getMouseState(ms);
	float mx = graphics::windowToCanvasX((float)ms.cur_pos_x);
	float my = graphics::windowToCanvasY((float)ms.cur_pos_y);
	bool in_bounds = boundries.contained(mx, my);
	if (in_bounds) {
		//graphics::playSound(std::string(ASSET_PATH) + "button.wav", 1.0f);
		char c = readChar();
		if (c != 0) {
			text += c;
			if (c == 8) {
				if (text.size() - 1 > 0) {
					text.resize(text.size() - 2);
				}
				else {
					text.resize(0);
				}
			}

			//action_callback();

			if (ms.button_left_released) {

			}
			return;
		}

	}
}


void textContainer::init() {
	text = "";
}

char textContainer::readChar() {
	static float delay = 0.0f;
	static int prev = 0;
	char ascii = 0;
	delay += graphics::getDeltaTime();

	for (int i = graphics::SCANCODE_A; i <= graphics::SCANCODE_Z; i++) {
		if (graphics::getKeyState((graphics::scancode_t)i)) {
			if (prev==i && delay <200) {
				continue;
			}
			else {
				prev = i;
				delay = 0;
				ascii = (char)(i + 93);
			}
			
			if (graphics::getKeyState((graphics::scancode_t)graphics::SCANCODE_RSHIFT)|| graphics::getKeyState((graphics::scancode_t)graphics::SCANCODE_LSHIFT)) {
				ascii -= 32;
			}
			return ascii;
		}
	}
	if (graphics::getKeyState((graphics::scancode_t)graphics::SCANCODE_SPACE)) {
		return 32;
	}
	if (graphics::getKeyState((graphics::scancode_t)graphics::SCANCODE_BACKSPACE)) {
		return 8;
	}
	
}

void textContainer::narrowText()
{
	//make displayableText a string of 31 character (the latest of the text)
	if (text.length() <31) {
		displayableText = text;
	}
	else{
		displayableText = "";
		for (int i = 30; i > 0; i--) {
			displayableText += text[text.length()-i];
		}
	}
}

void textContainer::setText(string text) {
	this->displayableText = text;
}

