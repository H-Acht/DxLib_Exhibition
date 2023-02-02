#pragma once
#include "game.h"

class torch
{
public:
	torch();
	~torch();

	void init();
	void update();
	void draw();

private:
	int tPosX[4];
	int tPosY[4];

};

