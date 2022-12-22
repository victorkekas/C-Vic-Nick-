#include "widget.h"

bool Widget::requestFocus()
{
	return false;
}

bool Widget::releasedFocus()
{
	return false;
}

Widget::Widget()
{
}

Widget::~Widget()
{
	std::cout<< "Widget" << endl;
}

void Widget::draw()
{
}

void Widget::update()
{
}

void Widget::init()
{
}
