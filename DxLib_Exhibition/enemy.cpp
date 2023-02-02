#include "enemy.h"
#include "player.h"
#include "game.h"

enemy::enemy() :
	m_ePosX(),
	m_ePosY(),
	m_ePosR(0),
	eDirection(0),
	existFlag(false),
	moveFlag(false),
	deadFlag()
{
}

enemy::~enemy()
{
}

void enemy::init(player &Player)
{
	m_ePosR = 10;
	moveFlag = true;

#if true
	
	m_ePosX[0] = Game::kScreenWidth / 2;
	m_ePosY[0] = 20;

	m_ePosX[1] = Game::kScreenWidth / 2;
	m_ePosY[1] = Game::kScreenHeight - 20;

	m_ePosX[2] = 20;
	m_ePosY[2] = Game::kScreenHeight / 2;

	m_ePosX[3] = Game::kScreenWidth - 20;
	m_ePosY[3] = Game::kScreenHeight / 2;

	m_ePosX[4] = Game::kScreenWidth - 20;
	m_ePosY[4] = 20;

	m_ePosX[5] = Game::kScreenWidth - 20;
	m_ePosY[5] = Game::kScreenHeight - 20;

	m_ePosX[6] = 20;
	m_ePosY[6] = Game::kScreenHeight - 20;

	m_ePosX[7] = 20;
	m_ePosY[7] = 20;

#endif

#if false
	eDirection = GetRand(8 - 1);

	ePosX[0] = Game::kScreenWidth / 2;
	ePosY[0] = -20;

	ePosX[1] = Game::kScreenWidth / 2;
	ePosY[1] = Game::kScreenHeight + 20;

	ePosX[2] = -20;
	ePosY[2] = Game::kScreenHeight / 2;

	ePosX[3] = Game::kScreenWidth + 20;
	ePosY[3] = Game::kScreenHeight / 2;

	ePosX[4] = Game::kScreenWidth + 20;
	ePosY[4] = -20;

	ePosX[5] = Game::kScreenWidth + 20;
	ePosY[5] = Game::kScreenHeight + 20;

	ePosX[6] = -20;
	ePosY[6] = Game::kScreenHeight + 20;

	ePosX[7] = -20;
	ePosY[7] = -20;
#endif
}

void enemy::update(player &Player)
{
	if (moveFlag == true)
	{
		eDirection = GetRand(8 - 1);
	}

	m_ePosX[eDirection];
	m_ePosY[eDirection];

	if (eDirection == 0)
	{
		moveFlag = false;
		existFlag = true;
		
		m_ePosY[0] += 2;	
		
		if (deadFlag[0] == true)
		{
			//位置をリセット
			m_ePosY[0] = 20;

			existFlag = false;
			moveFlag = true;
			deadFlag[0] = false;
		}
	}
	else if (eDirection == 1)
	{
		moveFlag = false;
		existFlag = true;
		
		m_ePosY[1] -= 2;
		
		if (deadFlag[1] == true)
		{
			//位置をリセット
			m_ePosY[1] = Game::kScreenHeight - 20;

			existFlag = false;
			moveFlag = true;
			deadFlag[1] = false;
		}
	}
	else if (eDirection == 2)
	{
		moveFlag = false;
		existFlag = true;
		
		m_ePosX[2] += 2;
		
		if (deadFlag[2] == true)
		{
			//位置をリセット
			m_ePosX[2] = 20;

			existFlag = false;
			moveFlag = true;
			deadFlag[2] = false;
		}
	}
	else if (eDirection == 3)
	{
		moveFlag = false;
		existFlag = true;
		
		m_ePosX[3] -= 2;
		
		if (deadFlag[3] == true)
		{
			//位置をリセット
			m_ePosX[3] = Game::kScreenWidth - 20;

			existFlag = false;
			moveFlag = true;
			deadFlag[3] = false;
		}
	}
	else if (eDirection == 4)
	{
		moveFlag = false;
		existFlag = true;
		
		m_ePosX[4] -= 2;
		m_ePosY[4] += 2;
		
		if (deadFlag[4] == true)
		{
			//位置をリセット
			m_ePosX[4] = Game::kScreenWidth - 20;
			m_ePosY[4] = 20;

			existFlag = false;
			moveFlag = true;
			deadFlag[4] = false;
		}
	}
	else if (eDirection == 5)
	{
		moveFlag = false;
		existFlag = true;
		
		m_ePosX[5] -= 2;
		m_ePosY[5] -= 2;
		
		if (deadFlag[5] == true)
		{
			//位置をリセット
			m_ePosX[5] = Game::kScreenWidth - 20;
			m_ePosY[5] = Game::kScreenHeight - 20;

			existFlag = false;
			moveFlag = true;
			deadFlag[5] = false;
		}
	}
	else if (eDirection == 6)
	{
		moveFlag = false;
		existFlag = true;
		
		m_ePosX[6] += 2;
		m_ePosY[6] -= 2;
		
		if (deadFlag[6] == true)
		{
			//位置をリセット
			m_ePosX[6] = 20;
			m_ePosY[6] = Game::kScreenHeight - 20;

			existFlag = false;
			moveFlag = true;
			deadFlag[6] = false;
		}
	}
	else if (eDirection == 7)
	{
		moveFlag = false;
		existFlag = true;
		
		m_ePosX[7] += 2;
		m_ePosY[7] += 2;
		
		if (deadFlag[7] == true)
		{
			//位置をリセット
			m_ePosX[7] = 20;
			m_ePosY[7] = 20; 

			existFlag = false;
			moveFlag = true;
			deadFlag[7] = false;
		}
	}

	//プレイヤーとエネミーの当たり判定
	float pdx = Player.m_posX - m_ePosX[eDirection];
	float pdy = Player.m_posY - m_ePosY[eDirection];
	float pdr = pdx * pdx + pdy * pdy;

	float par = Player.m_posR + m_ePosR;
	float pdl = par * par;
	if (pdr < pdl)
	{
		deadFlag[eDirection] = true;

	}
}

void enemy::draw()
{
	if (existFlag == true)
	{
		for (int i = 0; i < ENEMY; i++)
		{
			DrawCircle(m_ePosX[i], m_ePosY[i], m_ePosR, GetColor(255, 255, 255), true);
		}
	}
#if true
	DrawFormatString(20, 80, GetColor(255, 255, 255), "eDirection = %d", eDirection);
#endif
}
