#pragma once
#include "widget.h"


class textContainer : public Widget {
public:
	textContainer(float central_x, float central_y, float width, float height, graphics::Brush br);
	void addActionCallback(std::function<void(void*)> cb);
	~textContainer();
	void draw()override;
	void update()override;
	void init()override;
	std::string getText();
private:
	std::string text="";
	std::string displayableText = "";
	char readChar();
	void narrowText();
	void setDisplayableText(std::string text);
	void setText(std::string text);
};

