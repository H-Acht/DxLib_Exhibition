#include "enemy.h"
#include "player.h"
#include "game.h"
#include <cmath>

enemy::enemy() :
	m_ePosX(),
	m_ePosY(),
	m_ePosR(0),
	eDirection(),
	moveFlag(),
	deadFlag(),
	deadCount(0),
	enemyKinds()
{
}

enemy::~enemy()
{
}

void enemy::init(player &Player)
{
	m_ePosR = 10;
	for (int i = 0; i < 3; i++)
	{
		moveFlag[i] = true;
	}

#if true

	for (int i = 0; i < 3; i++)
	{
	
		m_ePosX[0][i] = (Game::kScreenWidth + 500) / 2;
		m_ePosY[0][i] = 20.0f;

		m_ePosX[1][i] = (Game::kScreenWidth + 500) / 2;
		m_ePosY[1][i] = Game::kScreenHeight - 20;

		m_ePosX[2][i] = 520.0f;
		m_ePosY[2][i] = Game::kScreenHeight / 2; 
		m_ePosX[3][i] = Game::kScreenWidth - 20;
		m_ePosY[3][i] = Game::kScreenHeight / 2;

		m_ePosX[4][i] = Game::kScreenWidth - 20;
		m_ePosY[4][i] = 20.0f;

		m_ePosX[5][i] = Game::kScreenWidth - 20;
		m_ePosY[5][i] = Game::kScreenHeight - 20;

		m_ePosX[6][i] = 520.0f;
		m_ePosY[6][i] = Game::kScreenHeight - 20;

		m_ePosX[7][i] = 520.0f;
		m_ePosY[7][i] = 20.0f;
	}

#endif

#if false

	ePosX[0] = Game::kScreenWidth / 2;
	ePosY[0] = -20;

	ePosX[1] = Game::kScreenWidth / 2;
	ePosY[1] = Game::kScreenHeight + 20;

	ePosX[2] = -20;
	ePosY[2] = Game::kScreenHeight / 2;

	ePosX[3] = Game::kScreenWidth + 20;
	ePosY[3] = Game::kScreenHeight / 2;

	ePosX[4] = Game::kScreenWidth + 20;
	ePosY[4] = -20;

	ePosX[5] = Game::kScreenWidth + 20;
	ePosY[5] = Game::kScreenHeight + 20;

	ePosX[6] = -20;
	ePosY[6] = Game::kScreenHeight + 20;

	ePosX[7] = -20;
	ePosY[7] = -20;
#endif
}

void enemy::update(player &Player)
{
	if (moveFlag[0] == true)
	{
		eDirection[0] = GetRand(8 - 1);
	}

	m_ePosX[eDirection[0]];
	m_ePosY[eDirection[0]];

	if (eDirection[0] == 0)//上
	{
		moveFlag[0] = false;
		
		m_ePosY[0][0] += 3;
		
		if (deadFlag[0][0] == true)
		{
			//位置をリセット
			m_ePosX[0][0] = static_cast<float>((Game::kScreenWidth + 500)) / 2;
			m_ePosY[0][0] = 20.0f;

			moveFlag[0] = true;
			deadFlag[0][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 1)//下
	{
		moveFlag[0] = false;
		
		m_ePosY[1][0] -= 3;
		
		if (deadFlag[1][0] == true)
		{
			//位置をリセット
			m_ePosX[1][0] = static_cast<float>((Game::kScreenWidth + 500)) / 2;
			m_ePosY[1][0] = Game::kScreenHeight - 20;

			moveFlag[0] = true;
			deadFlag[1][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 2)//左
	{
		moveFlag[0] = false;
		
		m_ePosX[2][0] += 3;
		
		if (deadFlag[2][0] == true)
		{
			//位置をリセット
			m_ePosX[2][0] = 520.0f;
			m_ePosY[2][0] = static_cast<float>(Game::kScreenHeight) / 2;

			moveFlag[0] = true;
			deadFlag[2][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 3)//右
	{
		moveFlag[0] = false;
		
		m_ePosX[3][0] -= 3;
		
		if (deadFlag[3][0] == true)
		{
			//位置をリセット
			m_ePosX[3][0] = Game::kScreenWidth - 20;
			m_ePosY[3][0] = static_cast<float>(Game::kScreenHeight) / 2;

			moveFlag[0] = true;
			deadFlag[3][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 4)//右上
	{
		moveFlag[0] = false;
		
		m_ePosX[4][0] -= 3;
		m_ePosY[4][0] += 2.455;
		
		if (deadFlag[4][0] == true)
		{
			//位置をリセット
			m_ePosX[4][0] = Game::kScreenWidth - 20;
			m_ePosY[4][0] = 20;

			moveFlag[0] = true;
			deadFlag[4][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 5)//右下
	{
		moveFlag[0] = false;
		
		m_ePosX[5][0] -= 3;
		m_ePosY[5][0] -= 2.455;
		
		if (deadFlag[5][0] == true)
		{
			//位置をリセット
			m_ePosX[5][0] = Game::kScreenWidth - 20;
			m_ePosY[5][0] = Game::kScreenHeight - 20;

			moveFlag[0] = true;
			deadFlag[5][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 6)//左下
	{
		moveFlag[0] = false;
		
		m_ePosX[6][0] += 3;
		m_ePosY[6][0] -= 2.455;
		
		if (deadFlag[6][0] == true)
		{
			//位置をリセット
			m_ePosX[6][0] = 520.0f;
			m_ePosY[6][0] = Game::kScreenHeight - 20;

			moveFlag[0] = true;
			deadFlag[6][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 7)//左上
	{
		moveFlag[0] = false;
		
		m_ePosX[7][0] += 3;
		m_ePosY[7][0] += 2.455;
		
		if (deadFlag[7][0] == true)
		{
			//位置をリセット
			m_ePosX[7][0] = 520.0f;
			m_ePosY[7][0] = 20.0f;

			moveFlag[0] = true;
			deadFlag[7][0] = false;
			deadCount++;
		}
	}

	//プレイヤーとエネミーの当たり判定
	float dx = static_cast<int>(Player.m_posX) - static_cast<int>(m_ePosX[eDirection[0]][0]);
	float dy = Player.m_posY - m_ePosY[eDirection[0]][0];
	float dr = dx * dx + dy * dy;

	float ar = Player.m_posR + m_ePosR;
	float dl = ar * ar;
	if (dr < dl)
	{
		deadFlag[eDirection[0]][0] = true;// ここでプレイヤーにぶつかった際に撃破数が増える、要修正
		deadCount--;// ↑の仮修正
		Player.damageFlag = true;
	}

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_4)
	{
		deadCount = 15;
	}
}


////////////////////main2////////////////////

void enemy::update2(player& Player)
{
	if (moveFlag[0] == true)
	{
		eDirection[0] = GetRand(8 - 1);
		enemyKinds[0] = GetRand(2 - 1);
	}

	m_ePosX[eDirection[0]][0];
	m_ePosY[eDirection[0]][0];

	if (eDirection[0] == 0) //上
	{
		moveFlag[0] = false;

		if (enemyKinds[0] == 0)
		{
			m_ePosY[0][0] += 3;
		}
		if (enemyKinds[0] == 1)
		{
			m_ePosY[0][0] += 5;
		}

		if (deadFlag[0][0] == true)
		{
			//位置をリセット
			m_ePosY[0][0] = 20;
			moveFlag[0] = true;
			deadFlag[0][0] = false;
			deadCount++;
		}
	}

	else if (eDirection[0] == 1) //下
	{
		moveFlag[0] = false;

		if (enemyKinds[0] == 0)
		{
			m_ePosY[1][0] -= 3;
		}
		if (enemyKinds[0] == 1)
		{
			m_ePosY[1][0] -= 5;
		}

		if (deadFlag[1][0] == true)
		{
			//位置をリセット
			m_ePosY[1][0] = Game::kScreenHeight - 20;

			moveFlag[0] = true;
			deadFlag[1][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 2) //左
	{
		moveFlag[0] = false;

		if (enemyKinds[0] == 0)
		{
			m_ePosX[2][0] += 3;
		}
		if (enemyKinds[0] == 1)
		{
			m_ePosX[2][0] += 5;
		}

		if (deadFlag[2][0] == true)
		{
			//位置をリセット
			m_ePosX[2][0] = 520.0f;
			moveFlag[0] = true;
			deadFlag[2][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 3) //右
	{
		moveFlag[0] = false;

		if (enemyKinds[0] == 0)
		{
			m_ePosX[3][0] -= 3;
		}

		if (enemyKinds[0] == 1)
		{
			m_ePosX[3][0] -= 5;
		}

		if (deadFlag[3][0] == true)
		{
			//位置をリセット
			m_ePosX[3][0] = Game::kScreenWidth - 20;
			moveFlag[0] = true;
			deadFlag[3][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 4) //右上
	{
		moveFlag[0] = false;

		if (enemyKinds[0] == 0)
		{
			m_ePosX[4][0] -= 3;
			m_ePosY[4][0] += 2.455;
		}

		if (enemyKinds[0] == 1)
		{
			m_ePosX[4][0] -= 5;
			m_ePosY[4][0] += 4.091;
		}

		if (deadFlag[4][0] == true)
		{
			//位置をリセット
			m_ePosX[4][0] = Game::kScreenWidth - 20;
			m_ePosY[4][0] = 20;
			moveFlag[0] = true;
			deadFlag[4][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 5) //右下
	{
		moveFlag[0] = false;

		if (enemyKinds[0] == 0)
		{
			m_ePosX[5][0] -= 3;
			m_ePosY[5][0] -= 2.455;
		}
		if (enemyKinds[0] == 1)
		{
			m_ePosX[5][0] -= 5;
			m_ePosY[5][0] -= 4.091;
		}

		if (deadFlag[5][0] == true)
		{
			//位置をリセット
			m_ePosX[5][0] = Game::kScreenWidth - 20;
			m_ePosY[5][0] = Game::kScreenHeight - 20;
			moveFlag[0] = true;
			deadFlag[5][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 6) //左下
	{
		moveFlag[0] = false;

		if (enemyKinds[0] == 0)
		{
			m_ePosX[6][0] += 3;
			m_ePosY[6][0] -= 2.455;
		}
		if (enemyKinds[0] == 1)
		{
			m_ePosX[6][0] += 5;
			m_ePosY[6][0] -= 4.091;
		}

		if (deadFlag[6][0] == true)
		{
			//位置をリセット
			m_ePosX[6][0] = 520.0f;
			m_ePosY[6][0] = Game::kScreenHeight - 20;
			moveFlag[0] = true;
			deadFlag[6][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 7) //左上
	{
		moveFlag[0] = false;

		if (enemyKinds[0] == 0)
		{
			m_ePosX[7][0] += 3;
			m_ePosY[7][0] += 2.455;
		}
		if (enemyKinds[0] == 1)
		{
			m_ePosX[7][0] += 5;
			m_ePosY[7][0] += 4.091;
		}

		if (deadFlag[7][0] == true)
		{
			//位置をリセット
			m_ePosX[7][0] = 520.0f;
			m_ePosY[7][0] = 20;
			moveFlag[0] = true;
			deadFlag[7][0] = false;
			deadCount++;
		}
	}

	//プレイヤーとエネミーの当たり判定

	float dx = Player.m_posX - m_ePosX[eDirection[0]][0];
	float dy = Player.m_posY - m_ePosY[eDirection[0]][0];
	float dr = dx * dx + dy * dy;

	float ar = Player.m_posR + m_ePosR;
	float dl = ar * ar;
	if (dr < dl)
	{
		deadFlag[eDirection[0]][0] = true;
		deadCount--;
		Player.damageFlag = true;
	}

	//////////////////敵2//////////////////

	if (moveFlag[1] == true)
	{
		eDirection[1] = GetRand(8 - 1);
		enemyKinds[1] = GetRand(2 - 1);
	}

	m_ePosX[eDirection[1]][1];
	m_ePosY[eDirection[1]][1];

	if (eDirection[1] == 0) //上
	{
		moveFlag[1] = false;

		if (enemyKinds[1] == 0)
		{
			m_ePosY[0][1] += 3;
		}
		if (enemyKinds[1] == 1)
		{
			m_ePosY[0][1] += 5;
		}

		if (deadFlag[0][1] == true)
		{
			//位置をリセット
			m_ePosY[0][1] = 20;
			moveFlag[1] = true;
			deadFlag[0][1] = false;
			deadCount++;
		}
	}

	else if (eDirection[1] == 1) //下
	{
		moveFlag[1] = false;

		if (enemyKinds[1] == 0)
		{
			m_ePosY[1][1] -= 3;
		}
		if (enemyKinds[1] == 1)
		{
			m_ePosY[1][1] -= 5;
		}

		if (deadFlag[1][1] == true)
		{
			//位置をリセット
			m_ePosY[1][1] = Game::kScreenHeight - 20;

			moveFlag[1] = true;
			deadFlag[1][1] = false;
			deadCount++;
		}
	}
	else if (eDirection[1] == 2) //左
	{
		moveFlag[1] = false;

		if (enemyKinds[1] == 0)
		{
			m_ePosX[2][1] += 3;
		}
		if (enemyKinds[1] == 1)
		{
			m_ePosX[2][1] += 5;
		}

		if (deadFlag[2][1] == true)
		{
			//位置をリセット
			m_ePosX[2][1] = 520.0f;
			moveFlag[1] = true;
			deadFlag[2][1] = false;
			deadCount++;
		}
	}
	else if (eDirection[1] == 3) //右
	{
		moveFlag[1] = false;

		if (enemyKinds[1] == 0)
		{
			m_ePosX[3][1] -= 3;
		}

		if (enemyKinds[1] == 1)
		{
			m_ePosX[3][1] -= 5;
		}

		if (deadFlag[3][1] == true)
		{
			//位置をリセット
			m_ePosX[3][1] = Game::kScreenWidth - 20;
			moveFlag[1] = true;
			deadFlag[3][1] = false;
			deadCount++;
		}
	}
	else if (eDirection[1] == 4) //右上
	{
		moveFlag[1] = false;

		if (enemyKinds[1] == 0)
		{
			m_ePosX[4][1] -= 3;
			m_ePosY[4][1] += 2.455;
		}

		if (enemyKinds[1] == 1)
		{
			m_ePosX[4][1] -= 5;
			m_ePosY[4][1] += 4.091;
		}

		if (deadFlag[4][1] == true)
		{
			//位置をリセット
			m_ePosX[4][1] = Game::kScreenWidth - 20;
			m_ePosY[4][1] = 20;
			moveFlag[1] = true;
			deadFlag[4][1] = false;
			deadCount++;
		}
	}
	else if (eDirection[1] == 5) //右下
	{
		moveFlag[1] = false;

		if (enemyKinds[1] == 0)
		{
			m_ePosX[5][1] -= 3;
			m_ePosY[5][1] -= 2.455;
		}
		if (enemyKinds[1] == 1)
		{
			m_ePosX[5][1] -= 5;
			m_ePosY[5][1] -= 4.091;
		}

		if (deadFlag[5][1] == true)
		{
			//位置をリセット
			m_ePosX[5][1] = Game::kScreenWidth - 20;
			m_ePosY[5][1] = Game::kScreenHeight - 20;
			moveFlag[1] = true;
			deadFlag[5][1] = false;
			deadCount++;
		}
	}
	else if (eDirection[1] == 6) //左下
	{
		moveFlag[1] = false;

		if (enemyKinds[1] == 0)
		{
			m_ePosX[6][1] += 3;
			m_ePosY[6][1] -= 2.455;
		}
		if (enemyKinds[1] == 1)
		{
			m_ePosX[6][1] += 5;
			m_ePosY[6][1] -= 4.091;
		}

		if (deadFlag[6][1] == true)
		{
			//位置をリセット
			m_ePosX[6][1] = 520.0f;
			m_ePosY[6][1] = Game::kScreenHeight - 20;
			moveFlag[1] = true;
			deadFlag[6][1] = false;
			deadCount++;
		}
	}
	else if (eDirection[1] == 7) //左上
	{
		moveFlag[1] = false;

		if (enemyKinds[1] == 0)
		{
			m_ePosX[7][1] += 3;
			m_ePosY[7][1] += 2.455;
		}
		if (enemyKinds[1] == 1)
		{
			m_ePosX[7][1] += 5;
			m_ePosY[7][1] += 4.091;
		}

		if (deadFlag[7][1] == true)
		{
			//位置をリセット
			m_ePosX[7][1] = 520.0f;
			m_ePosY[7][1] = 20;
			moveFlag[1] = true;
			deadFlag[7][1] = false;
			deadCount++;
		}
	}

	//プレイヤーとエネミーの当たり判定

	float dx2 = Player.m_posX - m_ePosX[eDirection[1]][1];
	float dy2 = Player.m_posY - m_ePosY[eDirection[1]][1];
	float dr2 = dx2 * dx2 + dy2 * dy2;

	float ar2 = Player.m_posR + m_ePosR;
	float dl2 = ar2 * ar2;
	if (dr2 < dl2)
	{
		deadFlag[eDirection[1]][1] = true;
		deadCount--;
		Player.damageFlag = true;
	}
}

void enemy::draw()
{
#if true
	for (int i = 0; i < DIR; i++)
	{
		if (enemyKinds[0] == 0)
		{
			DrawCircle(m_ePosX[i][0], m_ePosY[i][0], m_ePosR, GetColor(255, 255, 255), true);
		}
		if (enemyKinds[0] == 1)
		{
			DrawCircle(m_ePosX[i][0], m_ePosY[i][0], m_ePosR, GetColor(255, 0, 0), true);
		}

		if (enemyKinds[1] == 0)
		{
			DrawCircle(m_ePosX[i][1], m_ePosY[i][1], m_ePosR, GetColor(255, 255, 255), true);
		}
		if (enemyKinds[1] == 1)
		{
			DrawCircle(m_ePosX[i][1], m_ePosY[i][1], m_ePosR, GetColor(255, 0, 0), true);
		}
	}

#endif
}
