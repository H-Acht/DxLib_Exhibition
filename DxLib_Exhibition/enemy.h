#pragma once
#include "game.h"
#define ENEMY 8

class enemy
{
public:
	enemy();
	~enemy();

	void init();
	void update();
	void draw();

private:

	int ePosX[ENEMY];
	int ePosY[ENEMY];

	int eDirection;

	bool existFlag;

	bool moveFlag;
};

