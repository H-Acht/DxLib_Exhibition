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

	int ePosX[ENEMY];
	int ePosY[ENEMY];
	int ePosR;
	bool existFlag;
	int eDirection;
	bool moveFlag;
	
	bool deadFlag[ENEMY];

private:


};

