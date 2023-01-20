#include "player.h"
#include "game.h"

player::player() :
	posX(0),
	posY(0),
	direction(0),
	shield(0),
	prev(0),
	DshotFlag(false),
	UshotFlag(false),
	LshotFlag(false),
	RshotFlag(false),
	visibleFlag(false),
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

	//方向入力
	if (padState & PAD_INPUT_DOWN)
	{
		direction = 0;
		prev = direction;
	}
	if (padState & PAD_INPUT_UP)
	{
		direction = 1;
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

	//shot関連
	if (prev == 0)
	{
		if (padState & PAD_INPUT_1)
		{
			shotFlag = true;
			sPosY += 3;
		}
	}
	else if (prev == 1)
	{
		if (padState & PAD_INPUT_1)
		{
			shotFlag = true;
			sPosY -= 3;
		}
	}
	else if (prev == 2)
	{
		if (padState & PAD_INPUT_1)
		{
			shotFlag = true;
			sPosX -= 3;
		}
	}
	else if (prev == 3)
	{
		if (padState & PAD_INPUT_1)
		{
			shotFlag = true;
			sPosX += 3;
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

	if (shotFlag == true)
	{
		DrawCircle(sPosX, sPosY, 10, GetColor(100, 100, 100), true);
	}


#if true

	DrawFormatString(0, 0, GetColor(255, 255, 255), "direction = %d", prev);

	if (prev == 0)
	{
		DrawString(20, 20, "下", GetColor(255, 255, 255), true);
	}
	else if (prev == 1)
	{
		DrawString(20, 20, "上", GetColor(255, 255, 255), true);
	}
	else if (prev == 2)
	{
		DrawString(20, 20, "左", GetColor(255, 255, 255), true);
	}
	else if (prev == 3)
	{
		DrawString(20, 20, "右", GetColor(255, 255, 255), true);
	}

#endif
}
