#pragma once
class ContainerBox {
public:
	float side_00, side_x0, side_0y, side_xy;
public:
	ContainerBox(float center_x, float center_y, float width, float height); // give as variables the coordinates of an button (rectangle)
	~ContainerBox();
	bool contained(float mouse_pos_x, float mouse_pos_y/*dedomena tou mouse position*/); //return true if mouse is in the container box
};