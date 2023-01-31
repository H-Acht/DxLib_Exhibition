#include "player.h"
#include "game.h"
#include <math.h>

player::player() :
	m_posX(0),
	m_posY(0),
	m_dir(0),
	prev(0),
	m_inputX(0),
	m_inputY(0)
{
}

player::~player()
{
}

void player::init()
{
	m_posX = Game::kScreenWidth / 2;
	m_posY = Game::kScreenHeight / 2;

	for (int i = 0; i < SHOT; i++)
	{
		shotFlag = false;
		m_shotX = m_posX;
		m_shotY = m_posY;
	
	}

	bool prevShotFlag = false;

}

void player::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (padState & PAD_INPUT_UP)//��
	{
		m_dir = 0;
		prev = m_dir;
	}
	if (padState & PAD_INPUT_DOWN)//��
	{
		m_dir = 1;
		prev = m_dir;
	}
	if (padState & PAD_INPUT_LEFT)//��
	{
		m_dir = 2;
		prev = m_dir;
	}
	if (padState & PAD_INPUT_RIGHT)//�E
	{
		m_dir = 3;
		prev = m_dir;
	}
	if (padState & PAD_INPUT_UP && padState & PAD_INPUT_RIGHT)//�E��
	{
		m_dir = 4;
		prev = m_dir;
	}
	if (padState & PAD_INPUT_RIGHT && padState & PAD_INPUT_DOWN )//�E��
	{
		m_dir = 5;
		prev = m_dir;
	}
	if (padState & PAD_INPUT_DOWN && padState & PAD_INPUT_LEFT)//����
	{
		m_dir = 6;
		prev = m_dir;
	}
	if (padState & PAD_INPUT_LEFT && padState & PAD_INPUT_UP)//����
	{
		m_dir = 7;
		prev = m_dir;
	}

	if (padState & PAD_INPUT_1)
	{
		// �ei����ʏ�ɂłĂ��Ȃ��ꍇ�͂��̒e����ʂɏo��
		if (shotFlag == false)
		{
			// �ei�͌����_�������đ��݂���̂ŁA���ݏ�Ԃ�ێ�����ϐ���true��������
			shotFlag = true;
		}
	}

	if (shotFlag == true)
	{
		if (prev == 0)
		{
			m_shotY -= 16;
		}
		else if (prev == 1)
		{
			m_shotY += 16;
		}
		else if (prev == 2)
		{
			m_shotX -= 16;
		}
		else if (prev == 3)
		{
			m_shotX += 16;
		}
		else if (prev == 4)
		{
			m_shotX += 8;
			m_shotY -= 8;
		}
		else if (prev == 5)
		{
			m_shotX += 8;
			m_shotY += 8;
		}
		else if (prev == 6)
		{
			m_shotX -= 8;
			m_shotY += 8;
		}
		else if (prev == 7)
		{
			m_shotX -= 8;
			m_shotY -= 8;
		}

		DrawCircle(m_shotX, m_shotY, 10, GetColor(255, 255, 255),true);

		// ��ʊO�ɏo�Ă��܂����ꍇ�͑��ݏ�Ԃ�ێ����Ă���ϐ���false(���݂��Ȃ�)��������
		if (m_shotY < 0 || m_shotY > 720 || m_shotX < 0 || m_shotX > 1280)
		{
			shotFlag = false;
			m_shotX = m_posX;
			m_shotY = m_posY;
		}
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

#endif



#if true

	DrawFormatString(0, 0, GetColor(255, 255, 255), "direction = %d", prev);

	DrawFormatString(20, 20, GetColor(255, 255, 255), "X���͒l(��:�E�A��:��) : %d", m_inputX);
	DrawFormatString(20, 40, GetColor(255, 255, 255), "Y���͒l(��:���A��:��) : %d", m_inputY);

	if (prev == 0)
	{
		DrawString(20, 60, "��", GetColor(255, 255, 255), true);
	}
	else if (prev == 1)
	{
		DrawString(20, 60, "��", GetColor(255, 255, 255), true);
	}
	else if (prev == 2)
	{
		DrawString(20, 60, "��", GetColor(255, 255, 255), true);
	}
	else if (prev == 3)
	{
		DrawString(20, 60, "�E", GetColor(255, 255, 255), true);
	}
	else if (prev == 4)
	{
		DrawString(20, 60, "�E��", GetColor(255, 255, 255), true);
	}
	else if (prev == 5)
	{
		DrawString(20, 60, "�E��", GetColor(255, 255, 255), true);
	}
	else if (prev == 6)
	{
		DrawString(20, 60, "����", GetColor(255, 255, 255), true);
	}
	else if (prev == 7)
	{
		DrawString(20, 60, "����", GetColor(255, 255, 255), true);
	}
#endif
}
