#include "player.h"
#include "game.h"

player::player() :
	posX(0),
	posY(0),
	direction(0),
	shield(0),
	prev(0),
	shotFlag(false),
	sPosX(0),
	sPosY(0)
{
}

player::~player()
{
}

void player::init()
{
	posX = Game::kScreenWidth / 2;
	posY = Game::kScreenHeight / 2;
	direction = 0;
	shield = 0;

	sPosX = posX;
	sPosY = posY;
}

void player::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//ï˚å¸ì¸óÕ
	if (padState & PAD_INPUT_UP)
	{
		direction = 1;
		prev = direction;
	}
	if (padState & PAD_INPUT_DOWN)
	{
		direction = 0;
		prev = direction;
	}
	if (padState & PAD_INPUT_LEFT)
	{
		direction = 2;
		prev = direction;
	}
	if (padState & PAD_INPUT_RIGHT)
	{
		direction = 3;
		prev = direction;
	}

	//shotä÷òA
	if (padState & PAD_INPUT_1)
	{
		shotFlag = true;
		if (prev == 0)
		{
			sPosX += 2;
		}
	}
}

void player::draw()
{
	if (prev == 0)
	{
		DrawBox(posX, posY, posX + 20, posY + 20, GetColor(255, 0, 0), true);
	}
	else if (prev == 1)
	{
		DrawBox(posX, posY, posX + 20, posY + 20, GetColor(0, 0, 255), true);
	}
	else if (prev == 2)
	{
		DrawBox(posX, posY, posX + 20, posY + 20, GetColor(0, 255, 0), true);
	}
	else if (prev == 3)
	{
		DrawBox(posX, posY, posX + 20, posY + 20, GetColor(255, 255, 255), true);
	}


#if true

	DrawFormatString(0, 0, GetColor(255, 255, 255), "direction = %d", prev);

	if (prev == 0)
	{
		DrawString(20, 20, "â∫", GetColor(255, 255, 255), true);
	}
	else if (prev == 1)
	{
		DrawString(20, 20, "è„", GetColor(255, 255, 255), true);
	}
	else if (prev == 2)
	{
		DrawString(20, 20, "ç∂", GetColor(255, 255, 255), true);
	}
	else if (prev == 3)
	{
		DrawString(20, 20, "âE", GetColor(255, 255, 255), true);
	}

#endif
}
