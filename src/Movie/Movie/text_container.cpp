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
		if (ms.button_left_pressed) {
			graphics::playSound(std::string(ASSET_PATH) + "button.wav", 1.0f);
			text += readChar();
			if (graphics::getKeyState(graphics::SCANCODE_BACKSPACE)) {
				string tempstring;
				std::cout << text << endl;
				for (int i = 0; i < text.length() - 1; i++) {
					//tempstring += text[i];
					std::cout<< text[i] << endl;
				}
				//text = tempstring;
				//text = "a";
			}
			//action_callback();
		}
		if (ms.button_left_released) {
			
		}
		return;
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

