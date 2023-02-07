#include "torch.h"
#include "player.h"
#include"enemy.h"

torch::torch() :
	m_tPosX(),
	m_tPosY(),
	m_tPosR(),
	burnFlag()
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
	m_tPosY[1] = Player.m_drawPosY + 50;
	
	m_tPosX[2] = Player.m_drawPosX + 50; //右下
	m_tPosY[2] = Player.m_drawPosY + 50;

	m_tPosX[3] = Player.m_drawPosX + 50; //右上
	m_tPosY[3] = Player.m_drawPosY - 40;


	for (int i = 0; i < TORCH; i++)
	{
		burnFlag[i] = true;
		m_tPosR[i] = 10;
	}
}

void torch::update(enemy &Enemy)
{
	//たいまつとエネミーの当たり判定
	for (int i = 0; i < TORCH; i++)
	{
		float dx = m_tPosX[i] - Enemy.m_ePosX[Enemy.eDirection];
		float dy = m_tPosY[i] - Enemy.m_ePosY[Enemy.eDirection];
		float dr = dx * dx + dy * dy;

		float ar = m_tPosR[i] + Enemy.m_ePosR;
		float dl = ar * ar;
		if (dr < dl)
		{
			Enemy.deadFlag[Enemy.eDirection] = true;
			burnFlag[i] = false;
		}

		if (burnFlag[i] == false)
		{
			m_tPosR[i] = -10;
		}

	}
}

void torch::draw()
{
	
	for (int i = 0; i < TORCH; i++)
	{
		if (burnFlag[i] == true)
		{
			DrawBox(m_tPosX[i] -4, m_tPosY[i], m_tPosX[i]+5, m_tPosY[i] + 20, GetColor(255, 0, 0), true);
			DrawCircle(m_tPosX[i], m_tPosY[i], m_tPosR[i], GetColor(255, 20, 20), false);
		}
	}
}
