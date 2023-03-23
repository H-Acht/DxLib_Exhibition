#pragma once
#include "game.h"
#include "enemy.h"

class player;

class torch
{
public:
	torch();
	virtual ~torch();

	void init(player &Player);
	void update(enemy &Enemy);
	void draw();

	bool burnFlag[TORCH];
	int R, G, B;

	int torchCount;

private:
	int m_tPosX[TORCH];
	int m_tPosY[TORCH];
	int m_tPosR[TORCH];

	int m_torchHandle[7];
	int Torch;
	int torchAnimation;

	int breakSound;
};