#include "player.h"
#include "game.h"
#include "enemy.h"

player::player() :
	m_posX(0),
	m_posY(0),
	m_posR(0),
	m_dir(0),
	prev(0),
	m_inputX(0),
	m_inputY(0),
	m_sPosX(0),
	m_sPosY(0),
	m_sPosR(0),
	m_drawPosX(0),
	m_drawPosY(0),
	shotFlag(false),
	moveFlag(false)
{
}

player::~player()
{
}

void player::init()
{

	m_posX = Game::kScreenWidth / 2 ;
	m_posY = Game::kScreenHeight / 2;
	m_posR = 10;

	m_drawPosX = m_posX - 10;
	m_drawPosY = m_posY - 10;

	shotFlag = false;
	m_sPosX = m_posX;
	m_sPosY = m_posY;
	m_sPosR = 10;

	bool prevShotFlag = false;
	moveFlag = true;
}

void player::update(enemy &Enemy)
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (moveFlag == true)
	{
		if (padState & PAD_INPUT_UP)//上
		{
			m_dir = 0;
			prev = m_dir;
		}
		if (padState & PAD_INPUT_DOWN)//下
		{
			m_dir = 1;
			prev = m_dir;
		}
		if (padState & PAD_INPUT_LEFT)//左
		{
			m_dir = 2;
			prev = m_dir;
		}
		if (padState & PAD_INPUT_RIGHT)//右
		{
			m_dir = 3;
			prev = m_dir;
		}
		if (padState & PAD_INPUT_UP && padState & PAD_INPUT_RIGHT)//右上
		{
			m_dir = 4;
			prev = m_dir;
		}
		if (padState & PAD_INPUT_RIGHT && padState & PAD_INPUT_DOWN)//右下
		{
			m_dir = 5;
			prev = m_dir;
		}
		if (padState & PAD_INPUT_DOWN && padState & PAD_INPUT_LEFT)//左下
		{
			m_dir = 6;
			prev = m_dir;
		}
		if (padState & PAD_INPUT_LEFT && padState & PAD_INPUT_UP)//左上
		{
			m_dir = 7;
			prev = m_dir;
		}
	}
	if (padState & PAD_INPUT_1)
	{
		if (shotFlag == false)
		{
			shotFlag = true;
			moveFlag = false;
		}
	}
	if (shotFlag == true)
	{
		if (prev == 0)
		{
			m_sPosY -= 16;
		}
		else if (prev == 1)
		{
			m_sPosY += 16;
		}
		else if (prev == 2)
		{
			m_sPosX -= 16;
		}
		else if (prev == 3)
		{
			m_sPosX += 16;
		}
		else if (prev == 4)
		{
			m_sPosX += 10;
			m_sPosY -= 10;
		}
		else if (prev == 5)
		{
			m_sPosX += 10;
			m_sPosY += 10;
		}
		else if (prev == 6)
		{
			m_sPosX -= 10;
			m_sPosY += 10;
		}
		else if (prev == 7)
		{
			m_sPosX -= 10;
			m_sPosY -= 10;
		}

		DrawCircle(m_sPosX, m_sPosY, m_sPosR, GetColor(255, 255, 255),true);

		


		//弾とエネミーの当たり判定
		float dx = m_sPosX - Enemy.m_ePosX[Enemy.eDirection];
		float dy = m_sPosY - Enemy.m_ePosY[Enemy.eDirection];
		float dr = dx * dx + dy * dy;

		float ar = m_sPosR + Enemy.m_ePosR;
		float dl = ar * ar;
		if (dr < dl)
		{
			Enemy.deadFlag[Enemy.eDirection] = true;

			shotFlag = false;
			moveFlag = true;
			m_sPosX = m_posX;
			m_sPosY = m_posY;
		}

		// 画面外に出てしまった場合
		if (m_sPosY < 0 || m_sPosY > Game::kScreenHeight ||
			m_sPosX < 0 || m_sPosX > Game::kScreenWidth)
		{
			shotFlag = false;
			moveFlag = true;
			m_sPosX = m_posX;
			m_sPosY = m_posY;
		}
	}
}


void player::draw()
{
#if true

	if (prev == 0)
	{
		DrawBox(m_drawPosX, m_drawPosY, m_drawPosX + 20, m_drawPosY + 20, GetColor(255, 0, 0), true);
	}
	else if (prev == 1)
	{
		DrawBox(m_drawPosX, m_drawPosY, m_drawPosX + 20, m_drawPosY + 20, GetColor(0, 0, 255), true);
	}
	else if (prev == 2)
	{
		DrawBox(m_drawPosX, m_drawPosY, m_drawPosX + 20, m_drawPosY + 20, GetColor(0, 255, 0), true);
	}
	else if (prev == 3)
	{
		DrawBox(m_drawPosX, m_drawPosY, m_drawPosX + 20, m_drawPosY + 20, GetColor(255, 255, 255), true);
	}
	else if (prev == 4)
	{
		DrawBox(m_drawPosX, m_drawPosY, m_drawPosX + 20, m_drawPosY + 20, GetColor(255, 0, 255), true);
	}
	else if (prev == 5)
	{
		DrawBox(m_drawPosX, m_drawPosY, m_drawPosX + 20, m_drawPosY + 20, GetColor(0, 156, 209), true);
	}
	else if (prev == 6)
	{
		DrawBox(m_drawPosX, m_drawPosY, m_drawPosX + 20, m_drawPosY + 20, GetColor(255, 255, 0), true);
	}
	else if (prev == 7)
	{
		DrawBox(m_drawPosX, m_drawPosY, m_drawPosX + 20, m_drawPosY + 20, GetColor(125, 125, 125), true);
	}

#endif



#if true

	DrawFormatString(20, 40, GetColor(255, 255, 255), "direction = %d", prev);

	if (prev == 0)
	{
		DrawString(20, 60, "上", GetColor(255, 255, 255), true);
	}
	else if (prev == 1)
	{
		DrawString(20, 60, "下", GetColor(255, 255, 255), true);
	}
	else if (prev == 2)
	{
		DrawString(20, 60, "左", GetColor(255, 255, 255), true);
	}
	else if (prev == 3)
	{
		DrawString(20, 60, "右", GetColor(255, 255, 255), true);
	}
	else if (prev == 4)
	{
		DrawString(20, 60, "右上", GetColor(255, 255, 255), true);
	}
	else if (prev == 5)
	{
		DrawString(20, 60, "右下", GetColor(255, 255, 255), true);
	}
	else if (prev == 6)
	{
		DrawString(20, 60, "左下", GetColor(255, 255, 255), true);
	}
	else if (prev == 7)
	{
		DrawString(20, 60, "左上", GetColor(255, 255, 255), true);
	}
#endif
}


