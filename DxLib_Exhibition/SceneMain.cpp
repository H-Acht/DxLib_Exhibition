#include "game.h"

#include "SceneMain.h"

#include "player.h"
#include "enemy.h"
#include "torch.h"
#include "ScoreBoard.h"

SceneMain::SceneMain() :
	num(1),
	select(0),
	textPosX(0),
	textPosX2(0),
	textPosX3(0),
	circlePosY(0),
	prev(0)
{
	m_isEnd = false;

	m_pPlayer = new player;
	m_pEnemy = new enemy;
	m_pTorch = new torch;
	m_pScore = new ScoreBoard;
}

SceneMain::~SceneMain()
{
	m_pPlayer = nullptr;
	m_pEnemy = nullptr;
	m_pTorch = nullptr;
	m_pScore = nullptr;

	delete m_pPlayer;
	delete m_pEnemy;
	delete m_pTorch;
	delete m_pScore;
}

void SceneMain::init()
{
	m_pPlayer->init();
	m_pEnemy->init(*m_pPlayer);
	m_pTorch->init(*m_pPlayer);
	m_pScore->init();

	textPosX = 200;
	textPosX2 = 200;
	textPosX3 = 200;

	circlePosY = 270;

	m_pTorch->R = 255;
	m_pTorch->G = 255;
	m_pTorch->B = 255;
}

SceneBase* SceneMain::update()
{
	switch (num)
	{
	case 0:
		SceneMain::init();
		gameoverUpdate();
		gameoverDraw();
		break;
	case 1:
		mainUpdate1();
		mainDraw1();
		break;
	case 2:
		SceneMain::init();
		clearUpdate1();
		clearDraw1();
		break;
	default:
		break;
	}
	return this;
}

void SceneMain::draw()
{
}

void SceneMain::gameoverUpdate()
{
	m_pPlayer->pHP = 3;
	for (int i = 0; i < TORCH; i++)
	{
		m_pTorch->burnFlag[i] = true;
	}

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	static int push = 0;


	if (padState & PAD_INPUT_2)
	{
		if (push == 0)
		{
			num = 1;
		}
		push = 1;
	}
	else
	{
		push = 0;
	}


}

void SceneMain::gameoverDraw()
{
	SetDrawBright(255, 255, 255);

	DrawString(200, 200, "ゲームオーバー", GetColor(255, 255, 255));
	DrawString(200, 250, "やり直す -> ボタン2", GetColor(255, 255, 255));
}

void SceneMain::mainUpdate1()
{
	m_pPlayer->update();
	m_pPlayer->shot(*m_pEnemy);
	m_pTorch->update(*m_pEnemy);

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_4)
	{
		m_pEnemy->deadCount += 2;
	}

	if (m_pEnemy->deadCount <= 20)
	{
		m_pEnemy->update1(*m_pPlayer);
	}
	if (m_pEnemy->deadCount >= 20 && m_pEnemy->deadCount <= 40)
	{
		m_pEnemy->update2(*m_pPlayer);
	}
	if (m_pEnemy->deadCount >= 40 && m_pEnemy->deadCount <= 70)
	{
		m_pEnemy->update3(*m_pPlayer);
	}
	if (m_pEnemy->deadCount >= 70 && m_pEnemy->deadCount <= 100)
	{
		m_pEnemy->update4(*m_pPlayer);
	}
	if (m_pEnemy->deadCount >= 100 && m_pEnemy->deadCount <= 140)
	{
		m_pEnemy->update5(*m_pPlayer);
	}

	if (m_pPlayer->pHP <= 0 || m_pTorch->torchCount == 0)
	{
		num = 0;
	}
}

void SceneMain::mainDraw1()
{
	m_pPlayer->draw(*m_pTorch);
	m_pEnemy->draw();
	m_pTorch->draw();
	m_pScore->draw(*m_pPlayer, *m_pEnemy, *m_pTorch);
}

void SceneMain::clearUpdate1()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	m_pEnemy->deadCount = 0;

	prev = select;

	if (prev == 0)
	{
		textPosX = 250;
		textPosX2 = 200;
		textPosX3 = 200;

		circlePosY = 250;

		static int push = 0;

		if (padState & PAD_INPUT_DOWN)
		{
			if (push == 0)
			{
				select = 1;
			}
			push = 1;
		}
		else if(padState & PAD_INPUT_UP)
		{
			if (push == 0)
			{
				select = 2;
			}
			push = 1;
		}
		else
		{
			push = 0;
		}

		if (padState & PAD_INPUT_2)
		{
			num = 3;
		}
	}
	if (prev == 1)
	{
		textPosX = 200;
		textPosX2 = 250;
		textPosX3 = 200;

		circlePosY = 300;

		static int push = 0;

		if (padState & PAD_INPUT_UP)
		{
			if (push == 0)
			{
				select = 0;
			}
			push = 1;
		}
		else if (padState & PAD_INPUT_DOWN)
		{
			if (push == 0)
			{
				select = 2;
			}
			push = 1;
		}
		else
		{
			push = 0;
		}

		if (padState & PAD_INPUT_2)
		{
			num = 1;
		}
	}

	if (prev == 2)
	{
		textPosX = 200;
		textPosX2 = 200;
		textPosX3 = 250;

		circlePosY = 350;

		static int push = 0;

		if (padState & PAD_INPUT_UP)
		{
			if (push == 0)
			{
				select = 1;
			}
			push = 1;
		}
		else if (padState & PAD_INPUT_DOWN)
		{
			if (push == 0)
			{
				select = 0;
			}
			push = 1;
		}
		else
		{
			push = 0;
		}

		if (padState & PAD_INPUT_2)
		{
			num = -1;
		}
	}
}

void SceneMain::clearDraw1()
{
	SetDrawBright(255, 255, 255);

	DrawString(200, 200, "ステージ1クリア", GetColor(255, 255, 255));

	DrawCircle(200, circlePosY, 10, GetColor(255, 0, 0), true);
	DrawString(textPosX, 250, "次のステージへ", GetColor(255, 255, 255));
	DrawString(textPosX2, 300, "もう一度同じステージへ", GetColor(255, 255, 255));
	DrawString(textPosX3, 350, "ショップへ", GetColor(255, 255, 255));

	DrawFormatString(200, 500, GetColor(255, 255, 255), "現在 %d", select);
}
