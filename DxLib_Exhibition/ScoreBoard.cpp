#include "ScoreBoard.h"
#include "game.h"

#include "player.h"
#include "enemy.h"
#include "torch.h"

ScoreBoard::ScoreBoard():
	boardPosX(),
	boardPosY()
{
}

ScoreBoard::~ScoreBoard()
{
}

void ScoreBoard::init()
{
	boardPosX = 500;
	boardPosY = 900;
}

void ScoreBoard::update()
{
}

void ScoreBoard::draw(player& Player, enemy& Enemy, torch& Torch)
{
	DrawBox(0, 0, boardPosX, boardPosY, GetColor(100, 100, 100), true);

#if true

	DrawFormatString(20, 20, GetColor(255, 255, 255), "direction = %d", Player.prev);

	if (Player.prev == 0)
	{
		DrawString(20, 40, "上", GetColor(255, 255, 255), true);
	}
	else if (Player.prev == 1)
	{
		DrawString(20, 40, "下", GetColor(255, 255, 255), true);
	}
	else if (Player.prev == 2)
	{
		DrawString(20, 40, "左", GetColor(255, 255, 255), true);
	}
	else if (Player.prev == 3)
	{
		DrawString(20, 40, "右", GetColor(255, 255, 255), true);
	}
	else if (Player.prev == 4)
	{
		DrawString(20, 40, "右上", GetColor(255, 255, 255), true);
	}
	else if (Player.prev == 5)
	{
		DrawString(20, 40, "右下", GetColor(255, 255, 255), true);
	}
	else if (Player.prev == 6)
	{
		DrawString(20, 40, "左下", GetColor(255, 255, 255), true);
	}
	else if (Player.prev == 7)
	{
		DrawString(20, 40, "左上", GetColor(255, 255, 255), true);
	}

	DrawFormatString(20, 60, GetColor(255, 255, 255), "HP = %d", Player.pHP);

	DrawFormatString(20, 80, GetColor(255, 255, 255), "eDirection[0] = %d", Enemy.eDirection[0]);

	DrawFormatString(20, 100, GetColor(255, 255, 255), "eDirection[1] = %d", Enemy.eDirection[1]);

	DrawFormatString(20, 120, GetColor(255, 255, 255), "撃破数 = %d", Enemy.deadCount);

	DrawFormatString(20, 140, GetColor(255, 255, 255), "松明 = %d", Torch.torchCount);

	DrawFormatString(20, 160, GetColor(255, 255, 255), "ボム = %d", Player.remainingBomb);

	DrawFormatString(20, 180, GetColor(255, 255, 255), "RGB = %d, %d, %d", Torch.R, Torch.G, Torch.B);


#endif
}
