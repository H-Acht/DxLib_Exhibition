#include "player.h"
#include "enemy.h"
#include "torch.h"

#include "game.h"
#include "SceneMain.h"

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
	shotFlag(),
	moveFlag(false),
	pHP(0),
	damageFlag(false),
	push(0),
	m_shotHandle(),
	Shot(0),
	shotAnimation(0),
	PI(0),
	Hit(0),
	hitAnimation(0),
	hitFlag(false),
	hitPosX(0),
	hitPosY(0),
	m_hitHandle(),
	bombFlag(false),
	m_bPosX(),
	m_bPosY(),
	bPI(),
	num(1),
	damageEffect(false),
	Bomb(0),
	m_bombHandle(),
	bombAnimation(0),
	remainingBomb(0),
	shotSound(0),
	enemyDamageSound(0),
	bombSound(),
	playerHandle()
{
}

player::~player()
{
	for (int i = 0; i < 8; i++)
	{
		DeleteGraph(m_hitHandle[i]);
	}
	for (int i = 0; i < 21; i++)
	{
		DeleteGraph(m_shotHandle[i]);
	}
	for (int i = 0; i < 45; i++)
	{
		DeleteGraph(m_bombHandle[i]);
	}
	for (int i = 0; i < 24; i++)
	{
		DeleteGraph(playerHandle[i]);
	}

	DeleteSoundMem(shotSound);
	DeleteSoundMem(enemyDamageSound);
}

void player::init()
{
	m_posX = (Game::kScreenWidth + 500) / 2;
	m_posY = Game::kScreenHeight / 2;
	m_posR = 10;

	m_drawPosX = m_posX - 10;
	m_drawPosY = m_posY - 10;

	shotFlag = false;
	
	remainingBomb = 3;

	m_sPosX = m_posX;
	m_sPosY = m_posY;
	m_sPosR = 8;
	
	for (int i = 0; i < 8; i++)
	{
		m_bPosX[i] = m_posX;
		m_bPosY[i] = m_posY;
	}
	moveFlag = true;

	pHP = 3;
	LoadDivGraph("Data/player.png", 24, 6, 4, 20, 28, playerHandle);
	LoadDivGraph("Data/ShotEffect.png", 21, 21, 1, 100, 100, m_shotHandle);
	LoadDivGraph("Data/HitEffect.png", 8, 8, 1, 32, 32, m_hitHandle);
	LoadDivGraph("Data/BombEffect.png", 45, 45, 1, 64, 64, m_bombHandle);

	shotSound = LoadSoundMem("Data/Sound/attack.mp3");
	enemyDamageSound = LoadSoundMem("Data/Sound/enemyHit.mp3");
	bombSound = LoadSoundMem("Data/Sound/bomb.mp3");
}

void player::update()
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

	if (damageFlag == true)
	{
		pHP--;
		damageEffect = true;
		damageFlag = false;
	}
}

void player::shot(enemy& Enemy)
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//1ボタンでショット
	if (padState & PAD_INPUT_1)
	{
		if (shotFlag == false)
		{
			PlaySoundMem(shotSound, DX_PLAYTYPE_BACK, true);
			shotFlag = true;
			moveFlag = false;
		}
	}
	if (shotFlag == true)
	{
		if (prev == 0)
		{
			m_sPosY -= 16;

			PI = 4.7;
		}
		else if (prev == 1)
		{
			m_sPosY += 16;

			PI = 1.5;
		}
		else if (prev == 2)
		{
			m_sPosX -= 16;

			PI = 3.14;
		}
		else if (prev == 3)
		{
			m_sPosX += 16;

			PI = 0;
		}
		else if (prev == 4)
		{
			m_sPosX += 16;
			m_sPosY -= 13.091;

			PI = 5.3;
		}
		else if (prev == 5)
		{
			m_sPosX += 16;
			m_sPosY += 13.091;

			PI = 0.7;
		}
		else if (prev == 6)
		{
			m_sPosX -= 16;
			m_sPosY += 13.091;
			PI = 2.3;
		}
		else if (prev == 7)
		{
			m_sPosX -= 16;
			m_sPosY -= 13.091;
			PI = 3.7;
		}
	}

	//弾とエネミーの当たり判定
	for (int i = 0; i < ENEMY; i++)
	{
		float dx = m_sPosX - Enemy.m_ePosX[Enemy.eDirection[i]][i];
		float dy = m_sPosY - Enemy.m_ePosY[Enemy.eDirection[i]][i];
		float dr = dx * dx + dy * dy;

		float ar = m_sPosR + Enemy.m_ePosR;
		float dl = ar * ar;

		if (dr < dl)
		{
			hitFlag = true;

			PlaySoundMem(enemyDamageSound, DX_PLAYTYPE_BACK, true);

			Enemy.dFlag[Enemy.eDirection[i]][i] = true;
			Enemy.deathPosX[Enemy.eDirection[i]][i] = Enemy.m_ePosX[Enemy.eDirection[i]][i];
			Enemy.deathPosY[Enemy.eDirection[i]][i] = Enemy.m_ePosY[Enemy.eDirection[i]][i];

			Enemy.deadFlag[Enemy.eDirection[i]][i] = true;

			hitPosX = m_sPosX;
			hitPosY = m_sPosY;

			shotFlag = false;
			moveFlag = true;
			m_sPosX = m_posX;
			m_sPosY = m_posY;
		}
	}

	// 画面外に出てしまった場合
	if (m_sPosY < 0 || m_sPosY > Game::kScreenHeight ||
		m_sPosX < 500 || m_sPosX > Game::kScreenWidth)
	{
		shotFlag = false;
		moveFlag = true;
		m_sPosX = m_posX;
		m_sPosY = m_posY;
	}
}

void player::bomb(enemy& Enemy)
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//2ボタンでボム
	if (remainingBomb > 0)
	{
		if (padState & PAD_INPUT_2)
		{
			if (push == 0)
			{
				if (bombFlag == false)
				{
					PlaySoundMem(bombSound, DX_PLAYTYPE_BACK, true);

					bombFlag = true;
					moveFlag = false;
					remainingBomb -= 1;
				}
			}
			push = 1;
		}
		else
		{
			push = 0;
		}
	}

	if (bombFlag == true)
	{
		m_bPosY[0] -= 6;
		bPI[0] = 4.7;

		m_bPosY[1] += 6;
		bPI[1] = 1.5;

		m_bPosX[2] -= 7;
		bPI[2] = 3.14;

		m_bPosX[3] += 7;
		bPI[3] = 0;

		m_bPosX[4] += 7;
		m_bPosY[4] -= 5.727;
		bPI[4] = 5.3;

		m_bPosX[5] += 7;
		m_bPosY[5] += 5.727;
		bPI[5] = 0.7;

		m_bPosX[6] -= 7;
		m_bPosY[6] += 5.727;
		bPI[6] = 2.3;

		m_bPosX[7] -= 7;
		m_bPosY[7] -= 5.727;
		bPI[7] = 3.7;
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			m_bPosX[i] = m_posX;
			m_bPosY[i] = m_posY;
		}
	}

	//ボム当たり判定
	for (int i = 0; i < ENEMY; i++)
	{
		for (int b = 0; b < 8; b++)
		{
			float dx = m_bPosX[b] - Enemy.m_ePosX[Enemy.eDirection[i]][i];
			float dy = m_bPosY[b] - Enemy.m_ePosY[Enemy.eDirection[i]][i];
			float dr = dx * dx + dy * dy;

			float ar = m_sPosR + Enemy.m_ePosR;
			float dl = ar * ar;

			if (dr < dl)
			{
				hitFlag = true;

				PlaySoundMem(enemyDamageSound, DX_PLAYTYPE_BACK, true);

				Enemy.dFlag[Enemy.eDirection[i]][i] = true;
				Enemy.deathPosX[Enemy.eDirection[i]][i] = Enemy.m_ePosX[Enemy.eDirection[i]][i];
				Enemy.deathPosY[Enemy.eDirection[i]][i] = Enemy.m_ePosY[Enemy.eDirection[i]][i];

				Enemy.deadFlag[Enemy.eDirection[i]][i] = true;

				hitPosX = m_bPosX[b];
				hitPosY = m_bPosY[b];
			}

			//ボムが外に出たら
			if (m_bPosY[b] < 0 || m_bPosY[b] > Game::kScreenHeight ||
				m_bPosX[b] < 500 || m_bPosX[b] > Game::kScreenWidth)
			{
				bombFlag = false;
				moveFlag = true;
			}
			
		}
	}

	if (Enemy.deadCount % (30 * num) == 0 && Enemy.deadCount != 0)
	{
		if (remainingBomb < 3)
		{
			remainingBomb += 1;
			num += 1;
		}
	}
}

void player::draw(torch &Torch)
{
	Shot++;
	if (Shot % 2 == 0)
	{
		shotAnimation++;
		if (shotAnimation == 21)
		{
			shotAnimation = 0;
		}
		Shot = 0;
	}

	Bomb++;
	if (Bomb % 2 == 0)
	{
		bombAnimation++;
		if (bombAnimation == 45)
		{
			bombAnimation = 0;
		}
		Bomb = 0;
	}

	if (shotFlag == true) //ショットアニメーション
	{
		DrawCircle(m_sPosX, m_sPosY, m_sPosR, GetColor(255, 255, 255), false);
		DrawRotaGraph(m_sPosX, m_sPosY, 1.0, PI, m_shotHandle[shotAnimation], true, false);
	}

	if (bombFlag == true)
	{
		for (int i = 0; i < 8; i++)
		{
			//ボムアニメーション
			DrawRotaGraph(m_bPosX[i], m_bPosY[i], 1.0, bPI[i], m_bombHandle[bombAnimation], true, false);
#ifdef _DEBUG
			DrawCircle(m_bPosX[i], m_bPosY[i], m_sPosR, GetColor(255, 255, 255), false);
#endif
		}
	}

	if (prev == 0)
	{
		for (int i = 18; i < 21; i++)
		{
			DrawRotaGraph(m_drawPosX+10, m_drawPosY, 2.0, 0, playerHandle[i], true, false);
		}
	}
	else if (prev == 1)
	{
		for (int i = 0; i < 3; i++)
		{
			DrawRotaGraph(m_drawPosX + 10, m_drawPosY, 2.0, 0, playerHandle[i], true, false);
		}
	}
	else if (prev == 2)
	{
		for (int i = 6; i < 9; i++)
		{
			DrawRotaGraph(m_drawPosX + 10, m_drawPosY, 2.0, 0, playerHandle[i], true, false);
		}
	}
	else if (prev == 3)
	{
		for (int i = 12; i < 15; i++)
		{
			DrawRotaGraph(m_drawPosX + 10, m_drawPosY, 2.0, 0, playerHandle[i], true, false);
		}
	}
	else if (prev == 4)
	{
		for (int i = 21; i < 24; i++)
		{
			DrawRotaGraph(m_drawPosX + 10, m_drawPosY, 2.0, 0, playerHandle[i], true, false);
		}
	}
	else if (prev == 5)
	{
		for (int i = 9; i < 12; i++)
		{
			DrawRotaGraph(m_drawPosX + 10, m_drawPosY, 2.0, 0, playerHandle[i], true, false);
		}
	}
	else if (prev == 6)
	{
		for (int i = 3; i < 6; i++)
		{
			DrawRotaGraph(m_drawPosX + 10, m_drawPosY, 2.0, 0, playerHandle[i], true, false);
		}
	}
	else if (prev == 7)
	{
		for (int i = 15; i < 18; i++)
		{
			DrawRotaGraph(m_drawPosX + 10, m_drawPosY, 2.0, 0, playerHandle[i], true, false);
		}
	}
	
	if (hitFlag == true)
	{
		Hit++;
		DrawRotaGraph(hitPosX, hitPosY, 2.0, 0, m_hitHandle[hitAnimation], true, false);
		
		if (Hit % 2 == 0)
		{
			hitAnimation++;
			
			if (hitAnimation == 8)
			{
				hitAnimation = 0;
				hitFlag = false;
			}
			Hit = 0;
		}
	}

	if (damageEffect == true)
	{
		DrawBox(0, 0, 1600, 900, GetColor(255, 0, 0), true);
		damageEffect = false;
	}


}


