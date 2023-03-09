#include "game.h"

#include "SceneMain.h"
#include "SceneTitle.h"
#include "player.h"
#include "enemy.h"
#include "torch.h"
#include "ScoreBoard.h"
#include "SceneClear.h"
#include "SceneGameover.h"

SceneMain::SceneMain() :
	m_isEnd(false),
	rgb(0),
	brightFlag(true),
	num(0),
	gameoverEffect(false)
{
	m_pPlayer = new player;
	m_pEnemy = new enemy;
	m_pTorch = new torch;
	m_pScore = new ScoreBoard;

	m_isEnd = false;
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
}

SceneBase* SceneMain::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	switch (num)
	{
	case 0:
		m_pTorch->R += 5;
		m_pTorch->G += 5;
		m_pTorch->B += 5;
		if (m_pTorch->B >= 255)
		{
			num = 1;
		}
		break;
	case 1:
		m_pPlayer->update();
		m_pPlayer->shot(*m_pEnemy);
		m_pPlayer->bomb(*m_pEnemy);
		m_pTorch->update(*m_pEnemy);
		
		if (padState & PAD_INPUT_4)
		{
			m_pEnemy->deadCount += 2;
		}

		if (m_pEnemy->deadCount < 20)
		{
			m_pEnemy->update1(*m_pPlayer);	//ã¶‰EA‰EãA¶ã
		}
		if (m_pEnemy->deadCount >= 20 && m_pEnemy->deadCount < 40)
		{
			m_pEnemy->update2(*m_pPlayer);  //”ª•ûŒü
		}
		if (m_pEnemy->deadCount >= 40 && m_pEnemy->deadCount < 70)
		{
			m_pEnemy->update3(*m_pPlayer); //ã‰º¶‰E‚©‚çŠm—¦‚Å‘‚¢“G
		}
		if (m_pEnemy->deadCount >= 70 && m_pEnemy->deadCount < 100)
		{
			m_pEnemy->update4(*m_pPlayer); //”ª•ûŒü‚©‚çŠm—¦‚Å‘‚¢“G
		}
		if (m_pEnemy->deadCount >= 100 && m_pEnemy->deadCount < 150)
		{
			m_pEnemy->update5(*m_pPlayer); //”ª•ûŒü‚©‚ç“G‚ª“ñ‘Ì“¯Žž‚ÉŒü‚©‚Á‚Ä‚­‚é
		}
		if (m_pEnemy->deadCount >= 150 && m_pEnemy->deadCount < 230)
		{
			m_pEnemy->update6(*m_pPlayer); //”ª•ûŒü‚©‚ç“G‚ªŽO‘Ì“¯Žž‚ÉŒü‚©‚Á‚Ä‚­‚é
		}

		if (m_pEnemy->deadCount >= 230)
		{
			m_pTorch->R -= 5;
			m_pTorch->G -= 5;
			m_pTorch->B -= 5;
			if (m_pTorch->R <= 0 && m_pTorch->G <= 0 && m_pTorch->B <= 0)
			{
				return (new SceneClear);
			}
		}

		if (m_pPlayer->pHP == 0)
		{
			gameoverEffect = true;

			m_pTorch->R -= 4;
			m_pTorch->G -= 4;
			m_pTorch->B -= 4;
			if (m_pTorch->R <= 0 && m_pTorch->G <= 0 && m_pTorch->B <= 0)
			{
				return (new SceneGameover);
			}
		}

		if(m_pTorch->torchCount == 0)
		{
			m_pTorch->R -= 4;
			m_pTorch->G -= 4;
			m_pTorch->B -= 4;
			if (m_pTorch->R <= 0 && m_pTorch->G <= 0 && m_pTorch->B <= 0)
			{
				return (new SceneGameover);
			}
		}

		break;
	default:
		break;
	}

	return this;
}

void SceneMain::draw()
{
	SetDrawBright(m_pTorch->R, m_pTorch->G, m_pTorch->B);

	m_pPlayer->draw(*m_pTorch);
	m_pEnemy->draw();
	m_pTorch->draw();
	m_pScore->draw(*m_pPlayer, *m_pEnemy, *m_pTorch);

	if (gameoverEffect == true)
	{
		DrawBox(0, 0, 1600, 900, GetColor(255, 0, 0), true);
	}
}
