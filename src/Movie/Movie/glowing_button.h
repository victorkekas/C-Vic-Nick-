#pragma once
#include "button.h"

class GlowingButton :public Button {
public:
	GlowingButton();
	GlowingButton(float central_x, float central_y, float width, float height, graphics::Brush br);
	~GlowingButton();
	void draw() override;
	void update() override;
	void init() override;
private:
	bool isactivated();
	graphics::Brush tempbr;
	bool activated = false;
};