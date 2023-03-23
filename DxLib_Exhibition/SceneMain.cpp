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
	gameoverEffect(false),
	backGround(),
	volume(0)
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

	for (int i = 0; i < 4; i++)
	{
		DeleteGraph(backGround[i]);
	}
}

void SceneMain::init()
{
	m_pPlayer->init();
	m_pEnemy->init(*m_pPlayer);
	m_pTorch->init(*m_pPlayer);
	m_pScore->init();

	backGround[0] = LoadGraph("Data/background1.png");
	backGround[1] = LoadGraph("Data/background2.png");
	backGround[2] = LoadGraph("Data/background3.png");
	backGround[3] = LoadGraph("Data/background4a.png");

	PlayMusic("Data/Sound/mainBGM.mp3", DX_PLAYTYPE_LOOP);
}

SceneBase* SceneMain::update()
{
	SetVolumeMusic(volume);

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	switch (num)
	{
	case 0:
		m_pTorch->R += 5;
		m_pTorch->G += 5;
		m_pTorch->B += 5;
		volume += 3;
		if (m_pTorch->B >= 255 && volume >= 160)
		{
			num = 1;
		}
		break;
	case 1:
		m_pPlayer->update();
		m_pPlayer->shot(*m_pEnemy);
		m_pPlayer->bomb(*m_pEnemy);
		m_pTorch->update(*m_pEnemy);
		m_pScore->update();

		if (m_pEnemy->deadCount < 10)
		{
			m_pEnemy->update1(*m_pPlayer);	//ã¶‰EA‰EãA¶ã
			m_pScore->Level = 1;
		}
		if (m_pEnemy->deadCount >= 10 && m_pEnemy->deadCount < 20)
		{
			m_pEnemy->update2(*m_pPlayer);  //”ª•ûŒü
			m_pScore->Level = 2;
		}
		if (m_pEnemy->deadCount >= 20 && m_pEnemy->deadCount < 30)
		{
			m_pEnemy->update3(*m_pPlayer); //ã‰º¶‰E‚©‚çŠm—¦‚Å‘‚¢“G
			m_pScore->Level = 3;
		}
		if (m_pEnemy->deadCount >= 30 && m_pEnemy->deadCount < 40)
		{
			m_pEnemy->update4(*m_pPlayer); //”ª•ûŒü‚©‚çŠm—¦‚Å‘‚¢“G
			m_pScore->Level = 4;
		}
		if (m_pEnemy->deadCount >= 40 && m_pEnemy->deadCount < 90)
		{
			m_pEnemy->update5(*m_pPlayer); //”ª•ûŒü‚©‚ç“G‚ª“ñ‘Ì“¯Žž‚ÉŒü‚©‚Á‚Ä‚­‚é
			m_pScore->Level = 5;
		}
		if (m_pEnemy->deadCount >= 90 && m_pEnemy->deadCount < 150)
		{
			m_pEnemy->update6(*m_pPlayer); //”ª•ûŒü‚©‚ç“G‚ªŽO‘Ì“¯Žž‚ÉŒü‚©‚Á‚Ä‚­‚é
			m_pScore->Level = 6;
		}

		if (m_pEnemy->deadCount >= 150)
		{
			m_pTorch->R -= 5;
			m_pTorch->G -= 5;
			m_pTorch->B -= 5;
			volume -= 3;
			if (m_pTorch->R <= 0 && m_pTorch->G <= 0 && m_pTorch->B <= 0)
			{
				StopMusic();
				return (new SceneClear);
			}
		}

		if (m_pPlayer->pHP == 0)
		{
			gameoverEffect = true;

			m_pTorch->R -= 4;
			m_pTorch->G -= 4;
			m_pTorch->B -= 4;
			volume -= 3;
			if (m_pTorch->R <= 0 && m_pTorch->G <= 0 && m_pTorch->B <= 0)
			{
				StopMusic();
				gameoverEffect = false;
				return (new SceneGameover);
			}
		}

		if(m_pTorch->torchCount == 0)
		{
			m_pTorch->R -= 4;
			m_pTorch->G -= 4;
			m_pTorch->B -= 4;
			volume -= 3;
			if (m_pTorch->R <= 0 && m_pTorch->G <= 0 && m_pTorch->B <= 0)
			{
				StopMusic();
				return (new SceneGameover);
			}
		}

#ifdef _DEBUG
		if (padState & PAD_INPUT_4)
		{
			m_pEnemy->deadCount += 2;
		}
		if (padState & PAD_INPUT_3)
		{
			StopMusic();
			return (new SceneGameover);
		}
#endif
		break;
	default:
		break;
	}

	return this;
}

void SceneMain::draw()
{
	SetDrawBright(m_pTorch->R, m_pTorch->G, m_pTorch->B);

	DrawGraph(0, 0, backGround[0], true);
	DrawGraph(0, 0, backGround[1], true);
	DrawGraph(0, 0, backGround[2], true);
	DrawGraph(0, 0, backGround[3], true);

	m_pPlayer->draw(*m_pTorch);
	m_pEnemy->draw();
	m_pTorch->draw();
	m_pScore->draw(*m_pPlayer, *m_pEnemy, *m_pTorch);

	if (gameoverEffect == true)
	{
		DrawBox(0, 0, 1600, 900, GetColor(255, 0, 0), true);
	}
}
