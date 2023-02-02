#pragma once
#include "game.h"

class player;

class enemy
{
public:
	enemy();
	~enemy();

	void init(player &Player);
	void update(player &Player);
	void draw();

	int m_ePosX[ENEMY];
	int m_ePosY[ENEMY];
	int m_ePosR;
	int eDirection;
	
	bool deadFlag[ENEMY];

private:

	bool existFlag;
	bool moveFlag;

};
