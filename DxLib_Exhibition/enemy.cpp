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
	enemyKinds(),
	batAnimation(0),
	eyeAnimation(0),
	skeletonAnimation(0),
	mushAnimation(0),
	deathAnimation(0),
	Skeleton(0),
	Eye(0),
	Bat(0),
	Mush(0),
	Death(0),
	m_skeletonHandle(),
	m_skeletonDeathHandle(),
	m_batHandle(),
	m_batDeathHandle(),
	m_mushHandle(),
	m_mushDeathHandle(),
	m_eyeHandle(),
	m_eyeDeathHandle(),
	dFlag(),
	deathPosX(),
	deathPosY(),
	bDeathAnimation(0),
	bDeath(0),
	Portal(0),
	portalAnimation(0),
	damageSound(),
	kindFlag(),
	portal1(),
	portal2()
{
}

enemy::~enemy()
{
	for (int i = 0; i < 8; i++)
	{
		DeleteGraph(m_mushHandle[i]);
		DeleteGraph(m_eyeHandle[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		DeleteGraph(m_batHandle[i]);
		DeleteGraph(m_skeletonHandle[i]);
		DeleteGraph(m_skeletonDeathHandle[i]);
		DeleteGraph(m_mushDeathHandle[i]);
		DeleteGraph(m_eyeDeathHandle[i]);
	}
	for (int i = 0; i < 5; i++)
	{
		DeleteGraph(m_batDeathHandle[i]);
	}
	for (int i = 0; i < 15; i++)
	{
		DeleteGraph(portal1[i]);
		DeleteGraph(portal2[i]);
	}
}

void enemy::init(player &Player)
{
	m_ePosR = 10;
	for (int i = 0; i < 3; i++)
	{
		moveFlag[i] = true;
	}

	deadCount = 0;

	LoadDivGraph("Data/WhiteBatFlight.png", 4, 4, 1, 128, 128, m_batHandle);
	LoadDivGraph("Data/WhitebatDeath.png", 5, 5, 1, 128, 128, m_batDeathHandle);
	LoadDivGraph("Data/EyeFlight.png", 8, 8, 1, 150, 150, m_eyeHandle);
	LoadDivGraph("Data/EyeDeath.png", 4, 4, 1, 150, 150, m_eyeDeathHandle);
	LoadDivGraph("Data/SkeletonWalk.png", 4, 4, 1, 150, 150, m_skeletonHandle);
	LoadDivGraph("Data/SkeletonDeath.png", 4, 4, 1, 150, 150, m_skeletonDeathHandle);
	LoadDivGraph("Data/MushRun.png", 8, 8, 1, 150, 150, m_mushHandle);
	LoadDivGraph("Data/MushDeath.png", 4, 4, 1, 150, 150, m_mushDeathHandle);

	LoadDivGraph("Data/portal1.png", 15, 5, 3, 192, 192, portal1);
	LoadDivGraph("Data/portal2.png", 15, 5, 3, 192, 192, portal2);


	damageSound = LoadSoundMem("Data/Sound/damage.mp3");

#if true

	for (int i = 0; i < 3; i++)
	{
		m_ePosX[0][i] = (Game::kScreenWidth + 500) / 2;
		m_ePosY[0][i] = -20.0f;

		m_ePosX[1][i] = (Game::kScreenWidth + 500) / 2;
		m_ePosY[1][i] = Game::kScreenHeight + 20;

		m_ePosX[2][i] = 480.0f;
		m_ePosY[2][i] = Game::kScreenHeight / 2; 
	
		m_ePosX[3][i] = Game::kScreenWidth + 20;
		m_ePosY[3][i] = Game::kScreenHeight / 2;

		m_ePosX[4][i] = Game::kScreenWidth + 20;
		m_ePosY[4][i] = -20.0f;

		m_ePosX[5][i] = Game::kScreenWidth + 20;
		m_ePosY[5][i] = Game::kScreenHeight + 20;

		m_ePosX[6][i] = 480.0f;
		m_ePosY[6][i] = Game::kScreenHeight + 20;

		m_ePosX[7][i] = 480.0f;
		m_ePosY[7][i] = -20.0f;
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

void enemy::update1(player &Player)
{
	if (moveFlag[0] == true)
	{
		eDirection[0] = GetRand(8 - 1);
	}

	if (eDirection[0] == 0)//上
	{
		moveFlag[0] = false;
		
		m_ePosY[0][0] += 2;
		
		if (deadFlag[0][0] == true)
		{
			//位置をリセット
			m_ePosX[0][0] = static_cast<float>((Game::kScreenWidth + 500)) / 2;
			m_ePosY[0][0] = -20.0f;

			moveFlag[0] = true;
			deadFlag[0][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 2)//左
	{
		moveFlag[0] = false;

		m_ePosX[2][0] += 2;

		if (deadFlag[2][0] == true)
		{
			//位置をリセット
			m_ePosX[2][0] = 480.0f;
			m_ePosY[2][0] = static_cast<float>(Game::kScreenHeight) / 2;

			moveFlag[0] = true;
			deadFlag[2][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 3)//右
	{
		moveFlag[0] = false;

		m_ePosX[3][0] -= 2;

		if (deadFlag[3][0] == true)
		{
			//位置をリセット
			m_ePosX[3][0] = Game::kScreenWidth + 20;
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
			m_ePosX[4][0] = Game::kScreenWidth + 20;
			m_ePosY[4][0] = -20;

			moveFlag[0] = true;
			deadFlag[4][0] = false;
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
			m_ePosX[7][0] = 480.0f;
			m_ePosY[7][0] = -20.0f;

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
		PlaySoundMem(damageSound, DX_PLAYTYPE_BACK, true);
		deadFlag[eDirection[0]][0] = true;// ここでプレイヤーにぶつかった際に撃破数が増える、要修正
		deadCount--;// ↑の仮修正
		Player.damageFlag = true;
	}
}

void enemy::update2(player& Player)
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

		m_ePosY[0][0] += 2;

		if (deadFlag[0][0] == true)
		{
			//位置をリセット
			m_ePosX[0][0] = static_cast<float>((Game::kScreenWidth + 500)) / 2;
			m_ePosY[0][0] = -20.0f;

			moveFlag[0] = true;
			deadFlag[0][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 1)//下
	{
		moveFlag[0] = false;

		m_ePosY[1][0] -= 2;

		if (deadFlag[1][0] == true)
		{
			//位置をリセット
			m_ePosX[1][0] = static_cast<float>((Game::kScreenWidth + 500)) / 2;
			m_ePosY[1][0] = Game::kScreenHeight + 20;

			moveFlag[0] = true;
			deadFlag[0][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 2)//左
	{
		moveFlag[0] = false;

		m_ePosX[2][0] += 2;

		if (deadFlag[2][0] == true)
		{
			//位置をリセット
			m_ePosX[2][0] = 480.0f;
			m_ePosY[2][0] = static_cast<float>(Game::kScreenHeight) / 2;

			moveFlag[0] = true;
			deadFlag[2][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 3)//右
	{
		moveFlag[0] = false;

		m_ePosX[3][0] -= 2;

		if (deadFlag[3][0] == true)
		{
			//位置をリセット
			m_ePosX[3][0] = Game::kScreenWidth + 20;
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
			m_ePosX[4][0] = Game::kScreenWidth + 20;
			m_ePosY[4][0] = -20;

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
			m_ePosX[5][0] = Game::kScreenWidth + 20;
			m_ePosY[5][0] = Game::kScreenHeight + 20;

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
			m_ePosX[6][0] = 480.0f;
			m_ePosY[6][0] = Game::kScreenHeight + 20;

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
			m_ePosX[7][0] = 480.0f;
			m_ePosY[7][0] = -20.0f;

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
		PlaySoundMem(damageSound, DX_PLAYTYPE_BACK, true);

		deadFlag[eDirection[0]][0] = true;// ここでプレイヤーにぶつかった際に撃破数が増える、要修正
		deadCount--;// ↑の仮修正
		Player.damageFlag = true;
	}

}

void enemy::update3(player& Player)
{
	for (int i = 0; i < 8; i++)
	{
		if (moveFlag[0] == true && dFlag[i][0] == false)
		{
			eDirection[0] = GetRand(8 - 1);
			enemyKinds[0] = GetRand(2 - 1);
		}
	}
	m_ePosX[eDirection[0]];
	m_ePosY[eDirection[0]];

	if (eDirection[0] == 0) //上
	{
		moveFlag[0] = false;

		if (enemyKinds[0] == 0)
		{
			m_ePosY[0][0] += 2;
		}
		if (enemyKinds[0] == 1)
		{
			m_ePosY[0][0] += 5;
		}

		if (deadFlag[0][0] == true)
		{
			//位置をリセット
			m_ePosY[0][0] = -20;
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
			m_ePosY[1][0] -= 2;
		}
		if (enemyKinds[0] == 1)
		{
			m_ePosY[1][0] -= 5;
		}

		if (deadFlag[1][0] == true)
		{
			//位置をリセット
			m_ePosY[1][0] = Game::kScreenHeight + 20;

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
			m_ePosX[2][0] += 2;
		}
		if (enemyKinds[0] == 1)
		{
			m_ePosX[2][0] += 5;
		}

		if (deadFlag[2][0] == true)
		{
			//位置をリセット
			m_ePosX[2][0] = 480.0f;
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
			m_ePosX[3][0] -= 2;
		}

		if (enemyKinds[0] == 1)
		{
			m_ePosX[3][0] -= 5;
		}

		if (deadFlag[3][0] == true)
		{
			//位置をリセット
			m_ePosX[3][0] = Game::kScreenWidth + 20;

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
			enemyKinds[0] = 0;
		}

		if (deadFlag[4][0] == true)
		{
			//位置をリセット
			m_ePosX[4][0] = Game::kScreenWidth + 20;
			m_ePosY[4][0] = -20;
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
			enemyKinds[0] = 0;
		}

		if (deadFlag[5][0] == true)
		{
			//位置をリセット
			m_ePosX[5][0] = Game::kScreenWidth + 20;
			m_ePosY[5][0] = Game::kScreenHeight + 20;
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
			enemyKinds[0] = 0;
		}

		if (deadFlag[6][0] == true)
		{
			//位置をリセット
			m_ePosX[6][0] = 480.0f;
			m_ePosY[6][0] = Game::kScreenHeight + 20;
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
			enemyKinds[0] = 0;
		}

		if (deadFlag[7][0] == true)
		{
			//位置をリセット
			m_ePosX[7][0] = 480.0f;
			m_ePosY[7][0] = -20;
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
		PlaySoundMem(damageSound, DX_PLAYTYPE_BACK, true);

		deadFlag[eDirection[0]][0] = true;
		deadCount--;
		Player.damageFlag = true;
	}
}

void enemy::update4(player& Player)
{
	for (int i = 0; i < 8; i++)
	{
		if (moveFlag[0] == true && dFlag[i][0] == false)
		{
			eDirection[0] = GetRand(8 - 1);
			enemyKinds[0] = GetRand(2 - 1);
		}
	}

	m_ePosX[eDirection[0]];
	m_ePosY[eDirection[0]];

	if (eDirection[0] == 0) //上
	{
		moveFlag[0] = false;

		if (enemyKinds[0] == 0)
		{
			m_ePosY[0][0] += 2;
		}
		if (enemyKinds[0] == 1)
		{
			m_ePosY[0][0] += 5;
		}

		if (deadFlag[0][0] == true)
		{
			//位置をリセット
			m_ePosY[0][0] = -20;

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
			m_ePosY[1][0] -= 2;
		}
		if (enemyKinds[0] == 1)
		{
			m_ePosY[1][0] -= 5;
		}

		if (deadFlag[1][0] == true)
		{
			//位置をリセット
			m_ePosY[1][0] = Game::kScreenHeight + 20;

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
			m_ePosX[2][0] += 2;
		}
		if (enemyKinds[0] == 1)
		{
			m_ePosX[2][0] += 5;
		}

		if (deadFlag[2][0] == true)
		{
			//位置をリセット
			m_ePosX[2][0] = 480.0f;
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
			m_ePosX[3][0] -= 2;
		}

		if (enemyKinds[0] == 1)
		{
			m_ePosX[3][0] -= 5;
		}

		if (deadFlag[3][0] == true)
		{
			//位置をリセット
			m_ePosX[3][0] = Game::kScreenWidth + 20;
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
			m_ePosX[4][0] = Game::kScreenWidth + 20;
			m_ePosY[4][0] = -20;
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
			m_ePosX[5][0] = Game::kScreenWidth + 20;
			m_ePosY[5][0] = Game::kScreenHeight + 20;
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
			m_ePosX[6][0] = 480.0f;
			m_ePosY[6][0] = Game::kScreenHeight + 20;
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
			m_ePosX[7][0] = 480.0f;
			m_ePosY[7][0] = -20;
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
		PlaySoundMem(damageSound, DX_PLAYTYPE_BACK, true);

		deadFlag[eDirection[0]][0] = true;
		deadCount--;
		Player.damageFlag = true;
	}
}

void enemy::update5(player& Player)
{
	for (int i = 0; i < 8; i++)
	{
		if (moveFlag[0] == true && dFlag[i][0] == false)
		{
			eDirection[0] = GetRand(8 - 1);
			enemyKinds[0] = GetRand(2 - 1);
		}
	}

	m_ePosX[eDirection[0]][0];
	m_ePosY[eDirection[0]][0];

	if (eDirection[0] == 0) //上
	{
		moveFlag[0] = false;

		if (enemyKinds[0] == 0)
		{
			m_ePosY[0][0] += 2;
		}
		if (enemyKinds[0] == 1)
		{
			m_ePosY[0][0] += 5;
		}

		if (deadFlag[0][0] == true)
		{
			//位置をリセット
			m_ePosY[0][0] = -20;
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
			m_ePosY[1][0] -= 2;
		}
		if (enemyKinds[0] == 1)
		{
			m_ePosY[1][0] -= 5;
		}

		if (deadFlag[1][0] == true)
		{
			//位置をリセット
			m_ePosY[1][0] = Game::kScreenHeight + 20;

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
			m_ePosX[2][0] += 2;
		}
		if (enemyKinds[0] == 1)
		{
			m_ePosX[2][0] += 5;
		}

		if (deadFlag[2][0] == true)
		{
			//位置をリセット
			m_ePosX[2][0] = 480.0f;
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
			m_ePosX[3][0] -= 2;
		}

		if (enemyKinds[0] == 1)
		{
			m_ePosX[3][0] -= 5;
		}

		if (deadFlag[3][0] == true)
		{
			//位置をリセット
			m_ePosX[3][0] = Game::kScreenWidth + 20;
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
			m_ePosX[4][0] = Game::kScreenWidth + 20;
			m_ePosY[4][0] = -20;
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
			m_ePosX[5][0] = Game::kScreenWidth + 20;
			m_ePosY[5][0] = Game::kScreenHeight + 20;
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
			m_ePosX[6][0] = 480.0f;
			m_ePosY[6][0] = Game::kScreenHeight + 20;
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
			m_ePosX[7][0] = 480.0f;
			m_ePosY[7][0] = -20;
			moveFlag[0] = true;
			deadFlag[7][0] = false;
			deadCount++;
		}
	}

	//////////////////敵2//////////////////
	for (int i = 0; i < 8; i++)
	{
		if (moveFlag[1] == true && dFlag[i][1] == false)
		{
			eDirection[1] = GetRand(8 - 1);
			enemyKinds[1] = GetRand(2 - 1);
		}
	}
	m_ePosX[eDirection[1]][1];
	m_ePosY[eDirection[1]][1];

	if (eDirection[1] == 0) //上
	{
		moveFlag[1] = false;

		if (enemyKinds[1] == 0)
		{
			m_ePosY[0][1] += 2;
		}
		if (enemyKinds[1] == 1)
		{
			m_ePosY[0][1] += 5;
		}

		if (deadFlag[0][1] == true)
		{
			//位置をリセット
			m_ePosY[0][1] = -20;
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
			m_ePosY[1][1] -= 2;
		}
		if (enemyKinds[1] == 1)
		{
			m_ePosY[1][1] -= 5;
		}

		if (deadFlag[1][1] == true)
		{
			//位置をリセット
			m_ePosY[1][1] = Game::kScreenHeight + 20;

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
			m_ePosX[2][1] += 2;
		}
		if (enemyKinds[1] == 1)
		{
			m_ePosX[2][1] += 5;
		}

		if (deadFlag[2][1] == true)
		{
			//位置をリセット
			m_ePosX[2][1] = 480.0f;
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
			m_ePosX[3][1] -= 2;
		}

		if (enemyKinds[1] == 1)
		{
			m_ePosX[3][1] -= 5;
		}

		if (deadFlag[3][1] == true)
		{
			//位置をリセット
			m_ePosX[3][1] = Game::kScreenWidth + 20;
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
			m_ePosX[4][1] = Game::kScreenWidth + 20;
			m_ePosY[4][1] = -20;
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
			m_ePosX[5][1] = Game::kScreenWidth + 20;
			m_ePosY[5][1] = Game::kScreenHeight + 20;
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
			m_ePosX[6][1] = 480.0f;
			m_ePosY[6][1] = Game::kScreenHeight + 20;
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
			m_ePosX[7][1] = 480.0f;
			m_ePosY[7][1] = -20;
			moveFlag[1] = true;
			deadFlag[7][1] = false;
			deadCount++;
		}
	}

	//プレイヤーとエネミーの当たり判定
	for (int i = 0; i < 2; i++)
	{
		float dx = Player.m_posX - m_ePosX[eDirection[i]][i];
		float dy = Player.m_posY - m_ePosY[eDirection[i]][i];
		float dr = dx * dx + dy * dy;

		float ar = Player.m_posR + m_ePosR;
		float dl = ar * ar;
		if (dr < dl)
		{
			PlaySoundMem(damageSound, DX_PLAYTYPE_BACK, true);

			deadFlag[eDirection[i]][i] = true;
			deadCount--;
			Player.damageFlag = true;
		}
	}
}

void enemy::update6(player& Player)
{
	for (int i = 0; i < 8; i++)
	{
		if (moveFlag[0] == true && dFlag[i][0] == false)
		{
			eDirection[0] = GetRand(8 - 1);
			enemyKinds[0] = GetRand(2 - 1);
		}
	}

	m_ePosX[eDirection[0]][0];
	m_ePosY[eDirection[0]][0];

	if (eDirection[0] == 0) //上
	{
		moveFlag[0] = false;

		if (enemyKinds[0] == 0)
		{
			m_ePosY[0][0] += 2;
		}
		if (enemyKinds[0] == 1)
		{
			m_ePosY[0][0] += 5;
		}

		if (deadFlag[0][0] == true)
		{
			//位置をリセット
			m_ePosY[0][0] = -20;
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
			m_ePosY[1][0] -= 2;
		}
		if (enemyKinds[0] == 1)
		{
			m_ePosY[1][0] -= 5;
		}

		if (deadFlag[1][0] == true)
		{
			//位置をリセット
			m_ePosY[1][0] = Game::kScreenHeight + 20;

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
			m_ePosX[2][0] += 2;
		}
		if (enemyKinds[0] == 1)
		{
			m_ePosX[2][0] += 5;
		}

		if (deadFlag[2][0] == true)
		{
			//位置をリセット
			m_ePosX[2][0] = 480.0f;
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
			m_ePosX[3][0] -= 2;
		}

		if (enemyKinds[0] == 1)
		{
			m_ePosX[3][0] -= 5;
		}

		if (deadFlag[3][0] == true)
		{
			//位置をリセット
			m_ePosX[3][0] = Game::kScreenWidth + 20;
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
			m_ePosX[4][0] = Game::kScreenWidth + 20;
			m_ePosY[4][0] = -20;
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
			m_ePosX[5][0] = Game::kScreenWidth + 20;
			m_ePosY[5][0] = Game::kScreenHeight + 20;
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
			m_ePosX[6][0] = 480.0f;
			m_ePosY[6][0] = Game::kScreenHeight + 20;
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
			m_ePosX[7][0] = 480.0f;
			m_ePosY[7][0] = -20;
			moveFlag[0] = true;
			deadFlag[7][0] = false;
			deadCount++;
		}
	}

	//////////////////敵2//////////////////
	for (int i = 0; i < 8; i++)
	{
		if (moveFlag[1] == true && dFlag[i][1] == false)
		{
			eDirection[1] = GetRand(8 - 1);
			enemyKinds[1] = GetRand(2 - 1);
		}
	}

	m_ePosX[eDirection[1]][1];
	m_ePosY[eDirection[1]][1];

	if (eDirection[1] == 0) //上
	{
		moveFlag[1] = false;

		if (enemyKinds[1] == 0)
		{
			m_ePosY[0][1] += 2;
		}
		if (enemyKinds[1] == 1)
		{
			m_ePosY[0][1] += 5;
		}

		if (deadFlag[0][1] == true)
		{
			//位置をリセット
			m_ePosY[0][1] = -20;
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
			m_ePosY[1][1] -= 2;
		}
		if (enemyKinds[1] == 1)
		{
			m_ePosY[1][1] -= 5;
		}

		if (deadFlag[1][1] == true)
		{
			//位置をリセット
			m_ePosY[1][1] = Game::kScreenHeight + 20;

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
			m_ePosX[2][1] += 2;
		}
		if (enemyKinds[1] == 1)
		{
			m_ePosX[2][1] += 5;
		}

		if (deadFlag[2][1] == true)
		{
			//位置をリセット
			m_ePosX[2][1] = 480.0f;
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
			m_ePosX[3][1] -= 2;
		}

		if (enemyKinds[1] == 1)
		{
			m_ePosX[3][1] -= 5;
		}

		if (deadFlag[3][1] == true)
		{
			//位置をリセット
			m_ePosX[3][1] = Game::kScreenWidth + 20;
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
			m_ePosX[4][1] = Game::kScreenWidth + 20;
			m_ePosY[4][1] = -20;
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
			m_ePosX[5][1] = Game::kScreenWidth + 20;
			m_ePosY[5][1] = Game::kScreenHeight + 20;
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
			m_ePosX[6][1] = 480.0f;
			m_ePosY[6][1] = Game::kScreenHeight + 20;
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
			m_ePosX[7][1] = 480.0f;
			m_ePosY[7][1] = -20;
			moveFlag[1] = true;
			deadFlag[7][1] = false;
			deadCount++;
		}
	}

	//////////////////敵3//////////////////
	for (int i = 0; i < 8; i++)
	{
		if (moveFlag[2] == true && dFlag[i][2] == false)
		{
			eDirection[2] = GetRand(8 - 1);
			enemyKinds[2] = GetRand(2 - 1);
		}
	}

	m_ePosX[eDirection[2]][2];
	m_ePosY[eDirection[2]][2];

	if (eDirection[2] == 0) //上
	{
		moveFlag[2] = false;

		if (enemyKinds[2] == 0)
		{
			m_ePosY[0][2] += 2;
		}
		if (enemyKinds[2] == 1)
		{
			m_ePosY[0][2] += 5;
		}

		if (deadFlag[0][2] == true)
		{
			//位置をリセット
			m_ePosY[0][2] = -20;
			moveFlag[2] = true;
			deadFlag[0][2] = false;
			deadCount++;
		}
	}

	else if (eDirection[2] == 1) //下
	{
		moveFlag[2] = false;

		if (enemyKinds[2] == 0)
		{
			m_ePosY[1][2] -= 2;
		}
		if (enemyKinds[2] == 1)
		{
			m_ePosY[1][2] -= 5;
		}

		if (deadFlag[1][2] == true)
		{
			//位置をリセット
			m_ePosY[1][2] = Game::kScreenHeight + 20;

			moveFlag[2] = true;
			deadFlag[1][2] = false;
			deadCount++;
		}
	}
	else if (eDirection[2] == 2) //左
	{
		moveFlag[2] = false;

		if (enemyKinds[2] == 0)
		{
			m_ePosX[2][2] += 2;
		}
		if (enemyKinds[2] == 1)
		{
			m_ePosX[2][2] += 5;
		}

		if (deadFlag[2][2] == true)
		{
			//位置をリセット
			m_ePosX[2][2] = 480.0f;
			moveFlag[2] = true;
			deadFlag[2][2] = false;
			deadCount++;
		}
	}
	else if (eDirection[2] == 3) //右
	{
		moveFlag[2] = false;

		if (enemyKinds[2] == 0)
		{
			m_ePosX[3][2] -= 2;
		}

		if (enemyKinds[2] == 1)
		{
			m_ePosX[3][2] -= 5;
		}

		if (deadFlag[3][2] == true)
		{
			//位置をリセット
			m_ePosX[3][2] = Game::kScreenWidth + 20;
			moveFlag[2] = true;
			deadFlag[3][2] = false;
			deadCount++;
		}
	}
	else if (eDirection[2] == 4) //右上
	{
		moveFlag[2] = false;

		if (enemyKinds[2] == 0)
		{
			m_ePosX[4][2] -= 3;
			m_ePosY[4][2] += 2.455;
		}

		if (enemyKinds[2] == 1)
		{
			m_ePosX[4][2] -= 5;
			m_ePosY[4][2] += 4.091;
		}

		if (deadFlag[4][2] == true)
		{
			//位置をリセット
			m_ePosX[4][2] = Game::kScreenWidth + 20;
			m_ePosY[4][2] = -20;
			moveFlag[2] = true;
			deadFlag[4][2] = false;
			deadCount++;
		}
	}
	else if (eDirection[2] == 5) //右下
	{
		moveFlag[2] = false;

		if (enemyKinds[2] == 0)
		{
			m_ePosX[5][2] -= 3;
			m_ePosY[5][2] -= 2.455;
		}
		if (enemyKinds[2] == 1)
		{
			m_ePosX[5][2] -= 5;
			m_ePosY[5][2] -= 4.091;
		}

		if (deadFlag[5][2] == true)
		{
			//位置をリセット
			m_ePosX[5][2] = Game::kScreenWidth + 20;
			m_ePosY[5][2] = Game::kScreenHeight + 20;
			moveFlag[2] = true;
			deadFlag[5][2] = false;
			deadCount++;
		}
	}
	else if (eDirection[2] == 6) //左下
	{
		moveFlag[2] = false;

		if (enemyKinds[2] == 0)
		{
			m_ePosX[6][2] += 3;
			m_ePosY[6][2] -= 2.455;
		}
		if (enemyKinds[2] == 1)
		{
			m_ePosX[6][2] += 5;
			m_ePosY[6][2] -= 4.091;
		}

		if (deadFlag[6][2] == true)
		{
			//位置をリセット
			m_ePosX[6][2] = 480.0f;
			m_ePosY[6][2] = Game::kScreenHeight + 20;
			moveFlag[2] = true;
			deadFlag[6][2] = false;
			deadCount++;
		}
	}
	else if (eDirection[2] == 7) //左上
	{
		moveFlag[2] = false;

		if (enemyKinds[2] == 0)
		{
			m_ePosX[7][2] += 3;
			m_ePosY[7][2] += 2.455;
		}
		if (enemyKinds[2] == 1)
		{
			m_ePosX[7][2] += 5;
			m_ePosY[7][2] += 4.091;
		}

		if (deadFlag[7][2] == true)
		{
			//位置をリセット
			m_ePosX[7][2] = 480.0f;
			m_ePosY[7][2] = -20;
			moveFlag[2] = true;
			deadFlag[7][2] = false;
			deadCount++;
		}
	}

	//プレイヤーとエネミーの当たり判定
	for (int i = 0; i < 3; i++)
	{
		float dx = Player.m_posX - m_ePosX[eDirection[i]][i];
		float dy = Player.m_posY - m_ePosY[eDirection[i]][i];
		float dr = dx * dx + dy * dy;

		float ar = Player.m_posR + m_ePosR;
		float dl = ar * ar;
		if (dr < dl)
		{
			PlaySoundMem(damageSound, DX_PLAYTYPE_BACK, true);

			deadFlag[eDirection[i]][i] = true;
			deadCount--;
			Player.damageFlag = true;
		}
	}
}

void enemy::draw()
{
	Bat++;
	if (Bat % 6 == 0)
	{
		batAnimation++;
		Bat = 0;
		if (batAnimation == 4)
		{
			batAnimation = 0;
		}
	}

	Eye++;
	if (Eye % 3 == 0)
	{
		eyeAnimation++;
		Eye = 0;
		if (eyeAnimation == 8)
		{
			eyeAnimation = 0;
		}
	}

	Skeleton++;
	if (Skeleton % 10 == 0)
	{
		skeletonAnimation++;
		Skeleton = 0;
		if (skeletonAnimation == 4)
		{
			skeletonAnimation = 0;
		}
	}

	Mush++;
	if (Mush % 5 == 0)
	{
		mushAnimation++;
		Mush = 0;
		if (mushAnimation == 8)
		{
			mushAnimation = 0;
		}
	}

	Portal++;
	if (Portal % 3 == 0)
	{
		portalAnimation++;
		Portal = 0;
		if (portalAnimation == 15)
		{
			portalAnimation = 0;
		}
	}

	for (int i = 0; i < DIR; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (enemyKinds[j] == 0)
			{
				if (i == 1 || i == 3)
				{
					DrawRotaGraph(m_ePosX[i][j], m_ePosY[i][j], 1.5, 0, m_skeletonHandle[skeletonAnimation], true, true);

					if (dFlag[i][j] == true)
					{
						Death++;
						DrawRotaGraph(deathPosX[i][j], deathPosY[i][j], 1.5, 0, m_skeletonDeathHandle[deathAnimation], true, true);

						if (Death % 5 == 0)
						{
							deathAnimation++;
							Death = 0;
							if (deathAnimation == 4)
							{
								deathAnimation = 0;
								dFlag[i][j] = false;
							}
						}
					}
				}
				if (i == 0 || i == 2)
				{
					DrawRotaGraph(m_ePosX[i][j], m_ePosY[i][j], 1.5, 0, m_skeletonHandle[skeletonAnimation], true, false);

					if (dFlag[i][j] == true)
					{
						Death++;
						DrawRotaGraph(deathPosX[i][j], deathPosY[i][j], 1.5, 0, m_skeletonDeathHandle[deathAnimation], true, false);

						if (Death % 5 == 0)
						{
							deathAnimation++;
							Death = 0;
							if (deathAnimation == 4)
							{
								deathAnimation = 0;
								dFlag[i][j] = false;
							}
						}
					}
				}

				if (i == 4 || i == 5)
				{
					DrawRotaGraph(m_ePosX[i][j], m_ePosY[i][j], 1.0, 0, m_batHandle[batAnimation], true, true);

					if (dFlag[i][j] == true)
					{
						bDeath++;
						DrawRotaGraph(deathPosX[i][j], deathPosY[i][j], 1.5, 0, m_batDeathHandle[bDeathAnimation], true, true);

						if (bDeath % 5 == 0)
						{
							bDeathAnimation++;
							bDeath = 0;
							if (bDeathAnimation == 4)
							{
								bDeathAnimation = 0;
								dFlag[i][j] = false;
							}
						}
					}
				}
				if (i == 7 || i == 6)
				{
					DrawRotaGraph(m_ePosX[i][j], m_ePosY[i][j], 1.0, 0, m_batHandle[batAnimation], true, false);

					if (dFlag[i][j] == true)
					{
						bDeath++;
						DrawRotaGraph(deathPosX[i][j], deathPosY[i][j], 1.5, 0, m_batDeathHandle[bDeathAnimation], true, false);

						if (bDeath % 5 == 0)
						{
							bDeathAnimation++;
							bDeath = 0;
							if (bDeathAnimation == 4)
							{
								bDeathAnimation = 0;
								dFlag[i][j] = false;
							}
						}
					}
				}


			}
			else if (enemyKinds[j] == 1)
			{
				if (i == 1 || i == 3)
				{
					DrawRotaGraph(m_ePosX[i][j], m_ePosY[i][j], 1.5, 0, m_mushHandle[mushAnimation], true, true);
					
					if (dFlag[i][j] == true)
					{
						Death++;
						DrawRotaGraph(deathPosX[i][j], deathPosY[i][j], 1.5, 0, m_mushDeathHandle[deathAnimation], true, true);

						if (Death % 5 == 0)
						{
							deathAnimation++;
							Death = 0;
							if (deathAnimation == 4)
							{
								deathAnimation = 0;
								dFlag[i][j] = false;
							}
						}
					}
				}
				if (i == 0 || i == 2)
				{
					DrawRotaGraph(m_ePosX[i][j], m_ePosY[i][j], 1.5, 0, m_mushHandle[mushAnimation], true, false);
					
					if (dFlag[i][j] == true)
					{
						Death++;
						DrawRotaGraph(deathPosX[i][j], deathPosY[i][j], 1.5, 0, m_mushDeathHandle[deathAnimation], true, false);

						if (Death % 5 == 0)
						{
							deathAnimation++;
							Death = 0;
							if (deathAnimation == 4)
							{
								deathAnimation = 0;
								dFlag[i][j] = false;
							}
						}
					}
				}

				if (i == 4 || i == 5)
				{
					DrawRotaGraph(m_ePosX[i][j], m_ePosY[i][j], 2.0, 0, m_eyeHandle[eyeAnimation], true, true);
					
					if (dFlag[i][j] == true)
					{
						Death++;
						DrawRotaGraph(deathPosX[i][j], deathPosY[i][j], 1.5, 0, m_eyeDeathHandle[deathAnimation], true, true);

						if (Death % 5 == 0)
						{
							deathAnimation++;
							Death = 0;
							if (deathAnimation == 4)
							{
								deathAnimation = 0;
								dFlag[i][j] = false;
							}
						}
					}
				}
				if (i == 7 || i == 6)
				{
					DrawRotaGraph(m_ePosX[i][j], m_ePosY[i][j], 2.0, 0, m_eyeHandle[eyeAnimation], true, false);
					
					if (dFlag[i][j] == true)
					{
						Death++;
						DrawRotaGraph(deathPosX[i][j], deathPosY[i][j], 1.5, 0, m_eyeDeathHandle[deathAnimation], true, false);

						if (Death % 5 == 0)
						{
							deathAnimation++;
							Death = 0;
							if (deathAnimation == 4)
							{
								deathAnimation = 0;
								dFlag[i][j] = false;
							}
						}
					}
				}
			}
		}
	}
	
	DrawRotaGraph((Game::kScreenWidth + 500) / 2, 20.0f, 1.0, 0, portal1[portalAnimation], true, false);
	DrawRotaGraph((Game::kScreenWidth + 500) / 2, Game::kScreenHeight - 20, 1.0, 0, portal1[portalAnimation], true, false);
	DrawRotaGraph(520.0f, Game::kScreenHeight / 2, 1.0, 0, portal1[portalAnimation], true, true);
	DrawRotaGraph(Game::kScreenWidth - 20, Game::kScreenHeight / 2, 1.0, 0, portal1[portalAnimation], true, false);
	DrawRotaGraph(Game::kScreenWidth - 20, 20.0f, 1.0, 0, portal2[portalAnimation], true, false);
	DrawRotaGraph(Game::kScreenWidth - 20, Game::kScreenHeight - 20, 1.0, 0, portal2[portalAnimation], true, false);
	DrawRotaGraph(520.0f, Game::kScreenHeight - 20, 1.0, 0, portal2[portalAnimation], true, false);
	DrawRotaGraph(520.0f, 20.0f, 1.0, 0, portal2[portalAnimation], true, true);


}