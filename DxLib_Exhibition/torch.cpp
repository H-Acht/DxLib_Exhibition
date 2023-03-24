#include "torch.h"
#include "player.h"
#include"enemy.h"

torch::torch() :
	m_tPosX(),
	m_tPosY(),
	m_tPosR(),
	burnFlag(),
	R(0),
	G(0),
	B(0),
	torchCount(4),
	m_torchHandle(),
	Torch(0),
	torchAnimation(0),
	breakSound()
{
}

torch::~torch()
{
	for (int i = 0; i < 7; i++)
	{
		DeleteGraph(m_torchHandle[i]);
	}

	DeleteSoundMem(breakSound);
}

void torch::init(player &Player)
{
	m_tPosX[0] = Player.m_drawPosX - 40; //左上
	m_tPosY[0] = Player.m_drawPosY - 20;

	m_tPosX[1] = Player.m_drawPosX - 40; //左下
	m_tPosY[1] = Player.m_drawPosY + 30;
	
	m_tPosX[2] = Player.m_drawPosX + 50; //右下
	m_tPosY[2] = Player.m_drawPosY + 30;

	m_tPosX[3] = Player.m_drawPosX + 50; //右上
	m_tPosY[3] = Player.m_drawPosY - 20;


	for (int i = 0; i < TORCH; i++)
	{
		burnFlag[i] = true;
		m_tPosR[i] = 10;
	}

	LoadDivGraph("Data/Torch.png", 7, 7, 1, 32, 32, m_torchHandle);
	breakSound = LoadSoundMem("Data/Sound/torch.mp3");
}

void torch::update(enemy &Enemy)
{
	//たいまつとエネミーの当たり判定
	for (int i = 0; i < TORCH; i++)
	{
		for (int j = 0; j < ENEMY; j++)
		{
			float dx = m_tPosX[i] - Enemy.m_ePosX[Enemy.eDirection[j]][j];
			float dy = m_tPosY[i] - Enemy.m_ePosY[Enemy.eDirection[j]][j];
			float dr = dx * dx + dy * dy;

			float ar = m_tPosR[i] + Enemy.m_ePosR;
			float dl = ar * ar;
			if (dr < dl)
			{
				Enemy.deadFlag[Enemy.eDirection[j]][j] = true; // たいまつに当たった時、撃破数が増えるバグ
				Enemy.deadCount--; // ↑の仮修正
				burnFlag[i] = false;
				PlaySoundMem(breakSound, DX_PLAYTYPE_BACK, false);
				torchCount--;

				R -= 30;
				G -= 30;
				B -= 30;
			}
		}
		if (burnFlag[i] == false)
		{
			m_tPosR[i] = -10;
		}
	}
	
	//松明アニメーション
	Torch++;
	if (Torch % 5 == 0)
	{
		torchAnimation++;
		if (torchAnimation == 7)
		{
			torchAnimation = 0;
		}
		Torch = 0;
	}

}

void torch::draw()
{
	
	for (int i = 0; i < TORCH; i++)
	{
		if (burnFlag[i] == true)
		{
			DrawRotaGraph(m_tPosX[i], m_tPosY[i], 1.5, 0, m_torchHandle[torchAnimation], true, false);
		}
	}

}
