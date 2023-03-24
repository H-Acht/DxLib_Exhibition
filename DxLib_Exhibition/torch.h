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
	
	//画面明度
	int R, G, B;

	//松明の数
	int torchCount;

private:
	//松明位置
	float m_tPosX[TORCH];
	float m_tPosY[TORCH];
	float m_tPosR[TORCH];

	//松明表示関連
	int m_torchHandle[7];
	int Torch;
	int torchAnimation;

	//消えるときの音
	int breakSound;
};