#include "container_box.h"

ContainerBox::ContainerBox(float center_x, float center_y, float width, float height)
{
	this->side_00 = center_x - (width / 2);
	this->side_x0 = center_x + (width / 2);
	this->side_0y = center_y - (height / 2);
	this->side_xy = center_y + (height / 2);
}

ContainerBox::~ContainerBox()
{
}

bool ContainerBox::contained(float mouse_pos_x, float mouse_pos_y)
{
	if (side_00 <= mouse_pos_x && mouse_pos_x<=side_x0 && side_0y<=mouse_pos_y && mouse_pos_y <= side_xy) {
		return true;
	}
	return false;
}