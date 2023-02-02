#include "torch.h"
#include "player.h"
#include"enemy.h"

torch::torch() :
	m_tPosX(),
	m_tPosY(),
	m_tPosR()
{
}

torch::~torch()
{
}

void torch::init(player &Player)
{
	m_tPosX[0] = Player.m_drawPosX - 40; //左上
	m_tPosY[0] = Player.m_drawPosY - 40;

	m_tPosX[1] = Player.m_drawPosX - 40; //左下
	m_tPosY[1] = Player.m_drawPosY + 40;
	
	m_tPosX[2] = Player.m_drawPosX + 40; //右下
	m_tPosY[2] = Player.m_drawPosY + 40;

	m_tPosX[3] = Player.m_drawPosX + 40; //右上
	m_tPosY[3] = Player.m_drawPosY - 40;

	m_tPosR = 10;
}

void torch::update(enemy &Enemy)
{
	//たいまつとエネミーの当たり判定
	for (int i = 0; i < TORCH; i++)
	{
		float dx = m_tPosX[i] - Enemy.m_ePosX[Enemy.eDirection];
		float dy = m_tPosY[i] - Enemy.m_ePosY[Enemy.eDirection];
		float dr = dx * dx + dy * dy;

		float ar = m_tPosR + Enemy.m_ePosR;
		float dl = ar * ar;
		if (dr < dl)
		{
			Enemy.deadFlag[Enemy.eDirection] = true;
		}
	}
}

void torch::draw()
{
	for (int i = 0; i < 2; i++)
	{
		DrawBox(m_tPosX[i], m_tPosY[i], m_tPosX[i] + 10, m_tPosY[i] + 20, GetColor(255, 0, 0), true);
	}
	for (int j = 2; j < 4; j++)
	{
		DrawBox(m_tPosX[j] + 10, m_tPosY[j], m_tPosX[j] + 20, m_tPosY[j] + 20, GetColor(255, 0, 0), true);
	}
}
