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
	shotFlag(false),
	moveFlag(false),
	pHP(0),
	damageFlag(false),
	weapon(0),
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
	m_hitHandle()

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
}

void player::init()
{
	m_posX = (Game::kScreenWidth + 500) / 2;
	m_posY = Game::kScreenHeight / 2;
	m_posR = 10;

	m_drawPosX = m_posX - 10;
	m_drawPosY = m_posY - 10;

	shotFlag = false;
	m_sPosX = m_posX;
	m_sPosY = m_posY;
	m_sPosR = 8;

	moveFlag = true;

	pHP = 3;
	LoadDivGraph("Data/ShotEffect.png", 21, 21, 1, 100, 100, m_shotHandle);
	LoadDivGraph("Data/HitEffect.png", 8, 8, 1, 32, 32, m_hitHandle);
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

	if (padState & PAD_INPUT_2) //武器チェンジ
	{
		if (push == 0)
		{
			if (weapon == 0)
			{
				weapon = 1;
			}
			else if (weapon == 1)
			{
				weapon = 0;
			}
		}
		push = 1;
	}
	else
	{
		push = 0;
	}
}

void player::shot(enemy &Enemy)
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	
	//1ボタンでショット
	if (weapon == 0)
	{
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
				m_sPosX += 10;
				m_sPosY -= 8.182;	//(16 : 9) = (10 : 5.6)

				PI = 5.3;
			}
			else if (prev == 5)
			{
				m_sPosX += 10;
				m_sPosY += 8.182;

				PI = 0.7;
			}
			else if (prev == 6)
			{
				m_sPosX -= 10;
				m_sPosY += 8.182;
				PI = 2.3;
			}
			else if (prev == 7)
			{
				m_sPosX -= 10;
				m_sPosY -= 8.182;
				PI = 3.7;
			}
		}

		//弾とエネミーの当たり判定
		for (int i = 0; i < ENEMY; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				float dx = m_sPosX - Enemy.m_ePosX[Enemy.eDirection[i]][i];
				float dy = m_sPosY - Enemy.m_ePosY[Enemy.eDirection[i]][i];
				float dr = dx * dx + dy * dy;

				float ar = m_sPosR + Enemy.m_ePosR;
				float dl = ar * ar;

				if (dr < dl)
				{
					hitFlag = true;

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

		if (damageFlag == true)
		{
			pHP--;
			damageFlag = false;
		}
	}

	if (weapon == 1) //武器2
	{
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
				m_sPosX += 10;
				m_sPosY -= 8.182;	//(16 : 9) = (10 : 5.6)
				PI = 5.3;
			}
			else if (prev == 5)
			{
				m_sPosX += 10;
				m_sPosY += 8.182;
				PI = 0.7;
			}
			else if (prev == 6)
			{
				m_sPosX -= 10;
				m_sPosY += 8.182;
				PI = 2.3;
			}
			else if (prev == 7)
			{
				m_sPosX -= 10;
				m_sPosY -= 8.182;
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
				Enemy.deadFlag[Enemy.eDirection[i]][i] = true;
				
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

		if (damageFlag == true)
		{
			pHP--;
			damageFlag = false;
		}
	}
}

void player::draw(torch &Torch)
{
#if true
	Shot++;
	if (Shot % 2 == 0)
	{
		shotAnimation++;
		if (shotAnimation == 8)
		{
			shotAnimation = 0;
		}
		Shot = 0;
	}

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
	
	if (shotFlag == true)
	{
		DrawCircle(m_sPosX, m_sPosY, m_sPosR, GetColor(255, 255, 255), false);
		DrawRotaGraph(m_sPosX, m_sPosY, 1.0, PI, m_shotHandle[shotAnimation], true, false);
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

#endif

	SetDrawBright(Torch.R, Torch.G, Torch.B);

#if true

#endif
}


