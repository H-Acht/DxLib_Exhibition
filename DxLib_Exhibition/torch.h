#pragma once
#include "game.h"
#include "enemy.h"

class player;

class torch
{
public:
	torch();
	~torch();

	void init(player &Player);
	void update(enemy &Enemy);
	void draw();

private:
	int m_tPosX[4];
	int m_tPosY[4];
	int m_tPosR;
};

