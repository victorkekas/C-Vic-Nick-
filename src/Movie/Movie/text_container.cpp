#include "text_container.h"

textContainer::textContainer(float central_x, float central_y, float width, float height, graphics::Brush br){
	this->central_x = central_x;
	this->central_y = central_y;
	this->width = width;
	this->height = height;
	this->br = br;
}

void textContainer::addActionCallback(std::function<void(void*)> cb)
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
		char c = readChar();
		if (c != 0) {//prevent from inserting null input 
			text += c;
			if (c == 8) {//if you press backspace, resize the text by 2 characters 
				if (text.size() - 1 > 0) {
					text.resize(text.size() - 2);
				}
				else {
					text.resize(0);
				}
			}
			setText(text);
			std::string temp=getText();
			action_callback(&temp);
			return;
		}

	}
}

void textContainer::init() {
	text = "";
}

char textContainer::readChar() {//change comments 
	static float delay = 0.0f;
	static int prev = 0;
	char ascii = 0;
	delay += graphics::getDeltaTime();

	for (int i = graphics::SCANCODE_A; i <= graphics::SCANCODE_SPACE; i++) {
		if (graphics::getKeyState((graphics::scancode_t)i)) {//if you press any key 
			if (prev == i && delay < 200) {//doesn't let user to spam letter or numbers 
				continue;
			}
			else {
				prev = i;
				delay = 0;

				if (i >= graphics::SCANCODE_A && i <= graphics::SCANCODE_Z) {//if letter convert to char 
					ascii = (char)(i + 93);
					if (graphics::getKeyState(graphics::SCANCODE_RSHIFT) || graphics::getKeyState(graphics::SCANCODE_LSHIFT)) {//if you want capital letter
						ascii -= 32;
					}
				}
				if (i >= graphics::SCANCODE_1 && i <= graphics::SCANCODE_0) {//if number covert to char 
					if (i == graphics::SCANCODE_0) {//special treatment for 0 (ascii table)
						ascii = (char)(48);
					}
					else {
						ascii = (char)(i + 19);
					}
				}
				if (i == graphics::SCANCODE_BACKSPACE) {
					ascii = (char)(8); 

				}
				if (i == graphics::SCANCODE_SPACE) {
					ascii = (char)(32);
				}
			}
		}
	}
	return ascii;
}

void textContainer::narrowText()
{
	static float delay = 0.0f;
	delay += graphics::getDeltaTime();
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
	if (delay > 700) {
		delay = 0;
	}
	else if(delay>480){
		displayableText += "|";
	}
	
}

void textContainer::setDisplayableText(std::string text) {
	this->displayableText = text;
}

void textContainer::setText(std::string text)
{
	this->text = text;
}

string textContainer::getText()
{
	return this->text;
}