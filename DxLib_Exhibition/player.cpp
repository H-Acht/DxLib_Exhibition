#include "player.h"
#include "game.h"
#include <math.h>

player::player() :
	m_posX(0),
	m_posY(0),
	m_direction(0),
	prev(0),
	m_inputX(0),
	m_inputY(0),
	m_shotX(0),
	m_shotY(0),
	m_DshotFlag(0),
	m_shotFlag(false)
{
}

player::~player()
{
}

void player::init()
{
	m_posX = Game::kScreenWidth / 2;
	m_posY = Game::kScreenHeight / 2;

	m_shotX = Game::kScreenWidth / 2;
	m_shotY = Game::kScreenHeight / 2;
}

void player::update()
{
	int padState = GetJoypadAnalogInput(&m_inputX, &m_inputY, DX_INPUT_KEY_PAD1);

	if (m_inputY == -1000) // 上
	{
		m_direction = 0;
		prev = m_direction;
	}
	if (m_inputY == 1000) // 下
	{
		m_direction = 1;
		prev = m_direction;
	}
	if (m_inputX == -1000) // 左
	{
		m_direction = 2;
		prev = m_direction;
	}
	if (m_inputX == 1000) // 右
	{
		m_direction = 3;
		prev = m_direction;
	}
	if (m_inputX > 0 && m_inputX < 1000)
	{
		if (m_inputY < 0 && m_inputY > -1000) // 右上
		{
			m_direction = 4;
			prev = m_direction;
		}
		else if (m_inputY > 0 && m_inputY < 1000) // 右下
		{
			m_direction = 5;
			prev = m_direction;
		}
	}
	if (m_inputX < 0 && m_inputX > -1000)
	{
		if (m_inputY > 0 && m_inputY < 1000) // 左下
		{
			m_direction = 6;
			prev = m_direction;
		}
		else if (m_inputY < 0 && m_inputY > -1000) // 左上
		{
			m_direction = 7;
			prev = m_direction;
		}
	}

	if (padState & KEY_INPUT_1)
	{
		if (m_shotFlag == false)
		{		
			m_shotFlag = true;
		}
	}
	else
	{
		m_shotX += 3;
		m_shotFlag = false;
	}
}

void player::draw()
{
#if true
	if (prev == 0)
	{
		DrawBox(m_posX, m_posY, m_posX + 20, m_posY + 20, GetColor(255, 0, 0), true);
	}
	else if (prev == 1)
	{
		DrawBox(m_posX, m_posY, m_posX + 20, m_posY + 20, GetColor(0, 0, 255), true);
	}
	else if (prev == 2)
	{
		DrawBox(m_posX, m_posY, m_posX + 20, m_posY + 20, GetColor(0, 255, 0), true);
	}
	else if (prev == 3)
	{
		DrawBox(m_posX, m_posY, m_posX + 20, m_posY + 20, GetColor(255, 255, 255), true);
	}
	else if (prev == 4)
	{
		DrawBox(m_posX, m_posY, m_posX + 20, m_posY + 20, GetColor(255, 0, 255), true);
	}
	else if (prev == 5)
	{
		DrawBox(m_posX, m_posY, m_posX + 20, m_posY + 20, GetColor(0, 156, 209), true);
	}
	else if (prev == 6)
	{
		DrawBox(m_posX, m_posY, m_posX + 20, m_posY + 20, GetColor(255, 255, 0), true);
	}
	else if (prev == 7)
	{
		DrawBox(m_posX, m_posY, m_posX + 20, m_posY + 20, GetColor(125, 125, 125), true);
	}

	if (m_shotFlag == true)
	{
		//DrawCircle(m_shotX, m_shotY, 20, GetColor(255, 255, 255), true);

		DrawString(20, 80, "shotFlag = 0", GetColor(255, 255, 255));
	}
	else
	{
		DrawString(20, 80, "shotFlag = 1", GetColor(255, 255, 255));
	}

#endif



#if true

	DrawFormatString(0, 0, GetColor(255, 255, 255), "direction = %d", prev);

	DrawFormatString(20, 20, GetColor(255, 255, 255), "X入力値(正:右、負:左) : %d", m_inputX);
	DrawFormatString(20, 40, GetColor(255, 255, 255), "Y入力値(正:下、負:上) : %d", m_inputY);

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
