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
	
	//��ʖ��x
	int R, G, B;

	//�����̐�
	int torchCount;

private:
	//�����ʒu
	float m_tPosX[TORCH];
	float m_tPosY[TORCH];
	float m_tPosR[TORCH];

	//�����\���֘A
	int m_torchHandle[7];
	int Torch;
	int torchAnimation;

	//������Ƃ��̉�
	int breakSound;
};