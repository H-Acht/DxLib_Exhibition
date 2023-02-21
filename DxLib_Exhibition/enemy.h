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
	void update2(player &Player);

	void draw();

	float m_ePosX[DIR][ENEMY]; //[����][�ԍ�]
	float m_ePosY[DIR][ENEMY];
	int m_ePosR;
	
	bool deadFlag[DIR][ENEMY];//

	int deadCount;

	int eDirection[ENEMY];
	int enemyKinds[ENEMY];
private:
	bool moveFlag[ENEMY];
};
 