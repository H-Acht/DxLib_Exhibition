#include "enemy.h"
#include "game.h"
#define ENEMY 8

enemy::enemy() :
	ePosX(),
	ePosY(),
	ePosR(0),
	eDirection(0),
	existFlag(false),
	moveFlag(false),
	deadFlag()
{
}

enemy::~enemy()
{
}

void enemy::init()
{
	ePosR = 10;
	moveFlag = true;

#if true
	
	ePosX[0] = Game::kScreenWidth / 2;
	ePosY[0] = 20;

	ePosX[1] = Game::kScreenWidth / 2;
	ePosY[1] = Game::kScreenHeight - 20;

	ePosX[2] = 20;
	ePosY[2] = Game::kScreenHeight / 2;

	ePosX[3] = Game::kScreenWidth - 20;
	ePosY[3] = Game::kScreenHeight / 2;

	ePosX[4] = Game::kScreenWidth - 20;
	ePosY[4] = 20;

	ePosX[5] = Game::kScreenWidth - 20;
	ePosY[5] = Game::kScreenHeight - 20;

	ePosX[6] = 20;
	ePosY[6] = Game::kScreenHeight - 20;

	ePosX[7] = 20;
	ePosY[7] = 20;

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

void enemy::update()
{
	if (moveFlag == true)
	{
		eDirection = GetRand(8 - 1);
	}

	ePosX[eDirection];
	ePosY[eDirection];

	if (eDirection == 0)
	{
		moveFlag = false;
		existFlag = true;
		ePosY[0] += 3;	
		if (ePosY[0] > Game::kScreenHeight / 2 || deadFlag[0] == true)
		{
			ePosY[0] = 20;
			existFlag = false;
			moveFlag = true;
			deadFlag[0] = false;
		}
	}
	else if (eDirection == 1)
	{
		moveFlag = false;
		existFlag = true;
		ePosY[1] -= 3;
		if (ePosY[1] < Game::kScreenHeight / 2 || deadFlag[1] == true)
		{
			ePosY[1] = Game::kScreenHeight - 20;
			existFlag = false;
			moveFlag = true;
			deadFlag[1] = false;
		}
	}
	else if (eDirection == 2)
	{
		moveFlag = false;
		existFlag = true;
		ePosX[2] += 3;
		if (ePosX[2] > Game::kScreenWidth / 2 || deadFlag[2] == true)
		{
			ePosX[2] = 20;
			existFlag = false;
			moveFlag = true;
			deadFlag[2] = false;
		}
	}
	else if (eDirection == 3)
	{
		moveFlag = false;
		existFlag = true;
		ePosX[3] -= 3;
		if (ePosX[3] < Game::kScreenWidth / 2 || deadFlag[3] == true)
		{
			ePosX[3] = Game::kScreenWidth - 20;
			existFlag = false;
			moveFlag = true;
			deadFlag[3] = false;
		}
	}
	else if (eDirection == 4)
	{
		moveFlag = false;
		existFlag = true;
		ePosX[4] -= 3;
		ePosY[4] += 3;
		if (ePosX[4] < Game::kScreenWidth / 2 && ePosY[4] > Game::kScreenHeight / 2
			|| deadFlag[4] == true)
		{
			ePosX[4] = Game::kScreenWidth - 20;
			ePosY[4] = 20;
			existFlag = false;
			moveFlag = true;
			deadFlag[4] = false;
		}
	}
	else if (eDirection == 5)
	{
		moveFlag = false;
		existFlag = true;
		ePosX[5] -= 3;
		ePosY[5] -= 3;
		if (ePosX[5] < Game::kScreenWidth / 2 && ePosY[5] < Game::kScreenHeight / 2
			|| deadFlag[5] == true)
		{
			ePosX[5] = Game::kScreenWidth - 20;
			ePosY[5] = Game::kScreenHeight - 20;
			existFlag = false;
			moveFlag = true;
			deadFlag[5] = false;
		}
	}
	else if (eDirection == 6)
	{
		moveFlag = false;
		existFlag = true;
		ePosX[6] += 3;
		ePosY[6] -= 3;
		if (ePosX[6] > Game::kScreenWidth / 2 && ePosY[6] < Game::kScreenHeight / 2
			|| deadFlag[6] == true)
		{
			ePosX[6] = 20;
			ePosY[6] = Game::kScreenHeight - 20;
			existFlag = false;
			moveFlag = true;
			deadFlag[6] = false;
		}
	}
	else if (eDirection == 7)
	{
		moveFlag = false;
		existFlag = true;
		ePosX[7] += 3;
		ePosY[7] += 3;
		if (ePosX[7] > Game::kScreenWidth / 2 && ePosY[7] > Game::kScreenHeight / 2
			|| deadFlag[7] == true)
		{
			ePosX[7] = 20;
			ePosY[7] = 20; 
			existFlag = false;
			moveFlag = true;
			deadFlag[7] = false;
		}
	}
}

void enemy::draw()
{
	if (existFlag == true)
	{
		for (int i = 0; i < ENEMY; i++)
		{
			DrawCircle(ePosX[i], ePosY[i], ePosR, GetColor(255, 255, 255), true);
		}
	}
#if true
	DrawFormatString(20, 80, GetColor(255, 255, 255), "eDirection = %d", eDirection);
#endif
}
