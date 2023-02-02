#include "torch.h"

torch::torch() :
	tPosX(),
	tPosY()
{
}

torch::~torch()
{
}

void torch::init()
{
	tPosX[0] = Game::kScreenWidth / 2 - 40;
	tPosY[0] = Game::kScreenHeight / 2 - 40;

	tPosX[1] = Game::kScreenWidth / 2 + 40;
	tPosY[1] = Game::kScreenHeight / 2 - 40;

	tPosX[2] = Game::kScreenWidth / 2 + 40;
	tPosY[2] = Game::kScreenHeight / 2 + 40;

	tPosX[3] = Game::kScreenWidth / 2 - 40;
	tPosY[3] = Game::kScreenHeight / 2 + 40;

}

void torch::update()
{
}

void torch::draw()
{
	for (int i = 0; i < 4; i++)
	{
		DrawBox(tPosX[i], tPosY[i], tPosX[i] + 10, tPosY[i] + 20, GetColor(255, 0, 0), true);
	}
}
