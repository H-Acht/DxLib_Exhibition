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
	m_mushHandle(),
	m_mushDeathHandle(),
	m_eyeHandle(),
	m_eyeDeathHandle(),
	dFlag(),
	deathPosX(),
	deathPosY(),
	bossHP(0),
	zako(true),
	count(0),
	flag(false),
	zakoHP(0)
{
}

enemy::~enemy()
{
	for (int i = 0; i < 8; i++)
	{
		DeleteGraph(m_batHandle[i]);
		DeleteGraph(m_mushHandle[i]);
		DeleteGraph(m_eyeHandle[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		DeleteGraph(m_skeletonHandle[i]);
		DeleteGraph(m_skeletonDeathHandle[i]);
		DeleteGraph(m_mushDeathHandle[i]);
		DeleteGraph(m_eyeDeathHandle[i]);
	}
}

void enemy::init(player &Player)
{
	m_ePosR = 10;
	for (int i = 0; i < 3; i++)
	{
		moveFlag[i] = true;
	}

	zakoHP = 3;
	bossHP = 30;

	LoadDivGraph("Data/Bat_spritesheet.png", 8, 3, 3, 256, 256, m_batHandle);
	LoadDivGraph("Data/EyeFlight.png", 8, 8, 1, 150, 150, m_eyeHandle);
	LoadDivGraph("Data/EyeDeath.png", 4, 4, 1, 150, 150, m_eyeDeathHandle);
	LoadDivGraph("Data/SkeletonWalk.png", 4, 4, 1, 150, 150, m_skeletonHandle);
	LoadDivGraph("Data/SkeletonDeath.png", 4, 4, 1, 150, 150, m_skeletonDeathHandle);
	LoadDivGraph("Data/MushRun.png", 8, 8, 1, 150, 150, m_mushHandle);
	LoadDivGraph("Data/MushDeath.png", 4, 4, 1, 150, 150, m_mushDeathHandle);


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

void enemy::update1(player &Player)
{
	if (moveFlag[0] == true)
	{
		eDirection[0] = GetRand(8 - 1);
	}

	m_ePosX[eDirection[0]];
	m_ePosY[eDirection[0]];

	if (eDirection[0] == 0)//��
	{
		moveFlag[0] = false;
		
		m_ePosY[0][0] += 2;
		
		if (deadFlag[0][0] == true)
		{
			//�ʒu�����Z�b�g
			m_ePosX[0][0] = static_cast<float>((Game::kScreenWidth + 500)) / 2;
			m_ePosY[0][0] = 20.0f;

			moveFlag[0] = true;
			deadFlag[0][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 2)//��
	{
		moveFlag[0] = false;

		m_ePosX[2][0] += 2;

		if (deadFlag[2][0] == true)
		{
			//�ʒu�����Z�b�g
			m_ePosX[2][0] = 520.0f;
			m_ePosY[2][0] = static_cast<float>(Game::kScreenHeight) / 2;

			moveFlag[0] = true;
			deadFlag[2][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 3)//�E
	{
		moveFlag[0] = false;

		m_ePosX[3][0] -= 2;

		if (deadFlag[3][0] == true)
		{
			
			//�ʒu�����Z�b�g
			m_ePosX[3][0] = Game::kScreenWidth - 20;
			m_ePosY[3][0] = static_cast<float>(Game::kScreenHeight) / 2;

			moveFlag[0] = true;
			deadFlag[3][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 4)//�E��
	{
		moveFlag[0] = false;
		
		m_ePosX[4][0] -= 3;
		m_ePosY[4][0] += 2.455;
		
		if (deadFlag[4][0] == true)
		{
			/*dFlag[3] = true;

			deathPosX[3][0] = m_ePosX[3][0];
			deathPosY[3][0] = m_ePosY[3][0];*/

			//�ʒu�����Z�b�g
			m_ePosX[4][0] = Game::kScreenWidth - 20;
			m_ePosY[4][0] = 20;

			moveFlag[0] = true;
			deadFlag[4][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 7)//����
	{
		moveFlag[0] = false;
		
		m_ePosX[7][0] += 3;
		m_ePosY[7][0] += 2.455;
		
		if (deadFlag[7][0] == true)
		{
			//�ʒu�����Z�b�g
			m_ePosX[7][0] = 520.0f;
			m_ePosY[7][0] = 20.0f;

			moveFlag[0] = true;
			deadFlag[7][0] = false;
			deadCount++;
		}
	}

	//�v���C���[�ƃG�l�~�[�̓����蔻��
	float dx = static_cast<int>(Player.m_posX) - static_cast<int>(m_ePosX[eDirection[0]][0]);
	float dy = Player.m_posY - m_ePosY[eDirection[0]][0];
	float dr = dx * dx + dy * dy;

	float ar = Player.m_posR + m_ePosR;
	float dl = ar * ar;
	if (dr < dl)
	{
		deadFlag[eDirection[0]][0] = true;// �����Ńv���C���[�ɂԂ������ۂɌ��j����������A�v�C��
		deadCount--;// ���̉��C��
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

	if (eDirection[0] == 0)//��
	{
		moveFlag[0] = false;

		m_ePosY[0][0] += 2;

		if (deadFlag[0][0] == true)
		{
			//�ʒu�����Z�b�g
			m_ePosX[0][0] = static_cast<float>((Game::kScreenWidth + 500)) / 2;
			m_ePosY[0][0] = 20.0f;

			moveFlag[0] = true;
			deadFlag[0][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 1)//��
	{
		moveFlag[0] = false;

		m_ePosY[1][0] -= 2;

		if (deadFlag[1][0] == true)
		{
			//�ʒu�����Z�b�g
			m_ePosX[1][0] = static_cast<float>((Game::kScreenWidth + 500)) / 2;
			m_ePosY[1][0] = Game::kScreenHeight - 20;

			moveFlag[0] = true;
			deadFlag[0][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 2)//��
	{
		moveFlag[0] = false;

		m_ePosX[2][0] += 2;

		if (deadFlag[2][0] == true)
		{
			//�ʒu�����Z�b�g
			m_ePosX[2][0] = 520.0f;
			m_ePosY[2][0] = static_cast<float>(Game::kScreenHeight) / 2;

			moveFlag[0] = true;
			deadFlag[2][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 3)//�E
	{
		moveFlag[0] = false;

		m_ePosX[3][0] -= 2;

		if (deadFlag[3][0] == true)
		{
			//�ʒu�����Z�b�g
			m_ePosX[3][0] = Game::kScreenWidth - 20;
			m_ePosY[3][0] = static_cast<float>(Game::kScreenHeight) / 2;

			moveFlag[0] = true;
			deadFlag[3][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 4)//�E��
	{
		moveFlag[0] = false;

		m_ePosX[4][0] -= 3;
		m_ePosY[4][0] += 2.455;

		if (deadFlag[4][0] == true)
		{
			//�ʒu�����Z�b�g
			m_ePosX[4][0] = Game::kScreenWidth - 20;
			m_ePosY[4][0] = 20;

			moveFlag[0] = true;
			deadFlag[4][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 5)//�E��
	{
		moveFlag[0] = false;

		m_ePosX[5][0] -= 3;
		m_ePosY[5][0] -= 2.455;

		if (deadFlag[5][0] == true)
		{
			//�ʒu�����Z�b�g
			m_ePosX[5][0] = Game::kScreenWidth - 20;
			m_ePosY[5][0] = Game::kScreenHeight - 20;

			moveFlag[0] = true;
			deadFlag[5][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 6)//����
	{
		moveFlag[0] = false;

		m_ePosX[6][0] += 3;
		m_ePosY[6][0] -= 2.455;

		if (deadFlag[6][0] == true)
		{
			//�ʒu�����Z�b�g
			m_ePosX[6][0] = 520.0f;
			m_ePosY[6][0] = Game::kScreenHeight - 20;

			moveFlag[0] = true;
			deadFlag[6][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 7)//����
	{
		moveFlag[0] = false;

		m_ePosX[7][0] += 3;
		m_ePosY[7][0] += 2.455;

		if (deadFlag[7][0] == true)
		{
			//�ʒu�����Z�b�g
			m_ePosX[7][0] = 520.0f;
			m_ePosY[7][0] = 20.0f;

			moveFlag[0] = true;
			deadFlag[7][0] = false;
			deadCount++;
		}
	}

	//�v���C���[�ƃG�l�~�[�̓����蔻��
	float dx = static_cast<int>(Player.m_posX) - static_cast<int>(m_ePosX[eDirection[0]][0]);
	float dy = Player.m_posY - m_ePosY[eDirection[0]][0];
	float dr = dx * dx + dy * dy;

	float ar = Player.m_posR + m_ePosR;
	float dl = ar * ar;
	if (dr < dl)
	{
		deadFlag[eDirection[0]][0] = true;// �����Ńv���C���[�ɂԂ������ۂɌ��j����������A�v�C��
		deadCount--;// ���̉��C��
		Player.damageFlag = true;
	}

}

void enemy::update3(player& Player)
{
	if (moveFlag[0] == true)
	{
		eDirection[0] = GetRand(8 - 1);
		enemyKinds[0] = GetRand(2 - 1);
	}

	m_ePosX[eDirection[0]];
	m_ePosY[eDirection[0]];

	if (eDirection[0] == 0) //��
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
			//�ʒu�����Z�b�g
			m_ePosY[0][0] = 20;
			moveFlag[0] = true;
			deadFlag[0][0] = false;
			deadCount++;
		}
	}

	else if (eDirection[0] == 1) //��
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
			//�ʒu�����Z�b�g
			m_ePosY[1][0] = Game::kScreenHeight - 20;

			moveFlag[0] = true;
			deadFlag[1][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 2) //��
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
			//�ʒu�����Z�b�g
			m_ePosX[2][0] = 520.0f;
			moveFlag[0] = true;
			deadFlag[2][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 3) //�E
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
			//�ʒu�����Z�b�g
			m_ePosX[3][0] = Game::kScreenWidth - 20;
			moveFlag[0] = true;
			deadFlag[3][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 4) //�E��
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
			//�ʒu�����Z�b�g
			m_ePosX[4][0] = Game::kScreenWidth - 20;
			m_ePosY[4][0] = 20;
			moveFlag[0] = true;
			deadFlag[4][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 5) //�E��
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
			//�ʒu�����Z�b�g
			m_ePosX[5][0] = Game::kScreenWidth - 20;
			m_ePosY[5][0] = Game::kScreenHeight - 20;
			moveFlag[0] = true;
			deadFlag[5][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 6) //����
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
			//�ʒu�����Z�b�g
			m_ePosX[6][0] = 520.0f;
			m_ePosY[6][0] = Game::kScreenHeight - 20;
			moveFlag[0] = true;
			deadFlag[6][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 7) //����
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
			//�ʒu�����Z�b�g
			m_ePosX[7][0] = 520.0f;
			m_ePosY[7][0] = 20;
			moveFlag[0] = true;
			deadFlag[7][0] = false;
			deadCount++;
		}
	}

	//�v���C���[�ƃG�l�~�[�̓����蔻��

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
}

void enemy::update4(player& Player)
{
	if (moveFlag[0] == true)
	{
		eDirection[0] = GetRand(8 - 1);
		enemyKinds[0] = GetRand(2 - 1);
	}

	m_ePosX[eDirection[0]];
	m_ePosY[eDirection[0]];

	if (eDirection[0] == 0) //��
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
			//�ʒu�����Z�b�g
			m_ePosY[0][0] = 20;
			moveFlag[0] = true;
			deadFlag[0][0] = false;
			deadCount++;
		}
	}

	else if (eDirection[0] == 1) //��
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
			//�ʒu�����Z�b�g
			m_ePosY[1][0] = Game::kScreenHeight - 20;

			moveFlag[0] = true;
			deadFlag[1][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 2) //��
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
			//�ʒu�����Z�b�g
			m_ePosX[2][0] = 520.0f;
			moveFlag[0] = true;
			deadFlag[2][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 3) //�E
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
			//�ʒu�����Z�b�g
			m_ePosX[3][0] = Game::kScreenWidth - 20;
			moveFlag[0] = true;
			deadFlag[3][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 4) //�E��
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
			//�ʒu�����Z�b�g
			m_ePosX[4][0] = Game::kScreenWidth - 20;
			m_ePosY[4][0] = 20;
			moveFlag[0] = true;
			deadFlag[4][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 5) //�E��
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
			//�ʒu�����Z�b�g
			m_ePosX[5][0] = Game::kScreenWidth - 20;
			m_ePosY[5][0] = Game::kScreenHeight - 20;
			moveFlag[0] = true;
			deadFlag[5][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 6) //����
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
			//�ʒu�����Z�b�g
			m_ePosX[6][0] = 520.0f;
			m_ePosY[6][0] = Game::kScreenHeight - 20;
			moveFlag[0] = true;
			deadFlag[6][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 7) //����
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
			//�ʒu�����Z�b�g
			m_ePosX[7][0] = 520.0f;
			m_ePosY[7][0] = 20;
			moveFlag[0] = true;
			deadFlag[7][0] = false;
			deadCount++;
		}
	}

	//�v���C���[�ƃG�l�~�[�̓����蔻��

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
}

void enemy::update5(player& Player)
{
	if (moveFlag[0] == true)
	{
		eDirection[0] = GetRand(8 - 1);
		enemyKinds[0] = GetRand(2 - 1);
	}

	m_ePosX[eDirection[0]][0];
	m_ePosY[eDirection[0]][0];

	if (eDirection[0] == 0) //��
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
			//�ʒu�����Z�b�g
			m_ePosY[0][0] = 20;
			moveFlag[0] = true;
			deadFlag[0][0] = false;
			deadCount++;
		}
	}

	else if (eDirection[0] == 1) //��
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
			//�ʒu�����Z�b�g
			m_ePosY[1][0] = Game::kScreenHeight - 20;

			moveFlag[0] = true;
			deadFlag[1][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 2) //��
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
			//�ʒu�����Z�b�g
			m_ePosX[2][0] = 520.0f;
			moveFlag[0] = true;
			deadFlag[2][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 3) //�E
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
			//�ʒu�����Z�b�g
			m_ePosX[3][0] = Game::kScreenWidth - 20;
			moveFlag[0] = true;
			deadFlag[3][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 4) //�E��
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
			//�ʒu�����Z�b�g
			m_ePosX[4][0] = Game::kScreenWidth - 20;
			m_ePosY[4][0] = 20;
			moveFlag[0] = true;
			deadFlag[4][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 5) //�E��
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
			//�ʒu�����Z�b�g
			m_ePosX[5][0] = Game::kScreenWidth - 20;
			m_ePosY[5][0] = Game::kScreenHeight - 20;
			moveFlag[0] = true;
			deadFlag[5][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 6) //����
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
			//�ʒu�����Z�b�g
			m_ePosX[6][0] = 520.0f;
			m_ePosY[6][0] = Game::kScreenHeight - 20;
			moveFlag[0] = true;
			deadFlag[6][0] = false;
			deadCount++;
		}
	}
	else if (eDirection[0] == 7) //����
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
			//�ʒu�����Z�b�g
			m_ePosX[7][0] = 520.0f;
			m_ePosY[7][0] = 20;
			moveFlag[0] = true;
			deadFlag[7][0] = false;
			deadCount++;
		}
	}

	//�v���C���[�ƃG�l�~�[�̓����蔻��
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

	//////////////////�G2//////////////////

	if (moveFlag[1] == true)
	{
		eDirection[1] = GetRand(8 - 1);
		enemyKinds[1] = GetRand(2 - 1);
	}

	m_ePosX[eDirection[1]][1];
	m_ePosY[eDirection[1]][1];

	if (eDirection[1] == 0) //��
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
			//�ʒu�����Z�b�g
			m_ePosY[0][1] = 20;
			moveFlag[1] = true;
			deadFlag[0][1] = false;
			deadCount++;
		}
	}

	else if (eDirection[1] == 1) //��
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
			//�ʒu�����Z�b�g
			m_ePosY[1][1] = Game::kScreenHeight - 20;

			moveFlag[1] = true;
			deadFlag[1][1] = false;
			deadCount++;
		}
	}
	else if (eDirection[1] == 2) //��
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
			//�ʒu�����Z�b�g
			m_ePosX[2][1] = 520.0f;
			moveFlag[1] = true;
			deadFlag[2][1] = false;
			deadCount++;
		}
	}
	else if (eDirection[1] == 3) //�E
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
			//�ʒu�����Z�b�g
			m_ePosX[3][1] = Game::kScreenWidth - 20;
			moveFlag[1] = true;
			deadFlag[3][1] = false;
			deadCount++;
		}
	}
	else if (eDirection[1] == 4) //�E��
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
			//�ʒu�����Z�b�g
			m_ePosX[4][1] = Game::kScreenWidth - 20;
			m_ePosY[4][1] = 20;
			moveFlag[1] = true;
			deadFlag[4][1] = false;
			deadCount++;
		}
	}
	else if (eDirection[1] == 5) //�E��
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
			//�ʒu�����Z�b�g
			m_ePosX[5][1] = Game::kScreenWidth - 20;
			m_ePosY[5][1] = Game::kScreenHeight - 20;
			moveFlag[1] = true;
			deadFlag[5][1] = false;
			deadCount++;
		}
	}
	else if (eDirection[1] == 6) //����
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
			//�ʒu�����Z�b�g
			m_ePosX[6][1] = 520.0f;
			m_ePosY[6][1] = Game::kScreenHeight - 20;
			moveFlag[1] = true;
			deadFlag[6][1] = false;
			deadCount++;
		}
	}
	else if (eDirection[1] == 7) //����
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
			//�ʒu�����Z�b�g
			m_ePosX[7][1] = 520.0f;
			m_ePosY[7][1] = 20;
			moveFlag[1] = true;
			deadFlag[7][1] = false;
			deadCount++;
		}
	}

	//�v���C���[�ƃG�l�~�[�̓����蔻��

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

void enemy::update6(player& Player)
{

}

void enemy::updateBoss(player& Player)
{
	///////////////BOSS////////////////

	m_ePosX[2][3];
	m_ePosY[2][3];
	
	if (zako == true)
	{
		m_ePosX[2][3] += 1;

		if (deadFlag[2][3] == true)
		{
			zakoHP -= 1;
			deadFlag[2][3] = false;


			if (zakoHP <= 0)
			{
				//���S���o
				zako = false;
			}
		}
	}
	else
	{
		if (flag == true)
		{
			if (moveFlag[3] == true)
			{
				eDirection[3] = GetRand(8 - 1);
			}

			m_ePosX[eDirection[3]][3];
			m_ePosY[eDirection[3]][3];

			if (eDirection[3] == 0)//��
			{
				moveFlag[3] = false;

				m_ePosY[0][3] += 3;

				if (deadFlag[0][3] == true)
				{
					bossHP -= 1;

					moveFlag[3] = true;
					deadFlag[0][3] = false;

					if (bossHP <= 0)
					{
						//���S���o
					}
				}
			}
			else if (eDirection[3] == 1)//��
			{
				moveFlag[3] = false;

				m_ePosY[1][3] -= 3;

				if (deadFlag[1][3] == true)
				{
					bossHP -= 1;

					moveFlag[3] = true;
					deadFlag[3][3] = false;

					if (bossHP <= 0)
					{
						//���S���o
					}
				}
			}
			else if (eDirection[3] == 2)//��
			{
				moveFlag[3] = false;

				m_ePosX[2][3] += 3;

				if (deadFlag[2][3] == true)
				{
					bossHP -= 1;

					moveFlag[3] = true;
					deadFlag[2][3] = false;

					if (bossHP <= 0)
					{
						//���S���o
					}
				}
			}
			else if (eDirection[3] == 3)//�E
			{
				moveFlag[3] = false;

				m_ePosX[3][3] -= 3;

				if (deadFlag[3][3] == true)
				{
					bossHP -= 1;

					moveFlag[3] = true;
					deadFlag[3][3] = false;

					if (bossHP <= 0)
					{
						//���S���o
					}
				}
			}
			else if (eDirection[3] == 4)//�E��
			{
				moveFlag[3] = false;

				m_ePosX[4][3] -= 3;
				m_ePosY[4][3] += 2.455;

				if (deadFlag[4][3] == true)
				{
					bossHP -= 1;

					moveFlag[3] = true;
					deadFlag[4][3] = false;

					if (bossHP <= 0)
					{
						//���S���o
					}
				}
			}
			else if (eDirection[3] == 5)//�E��
			{
				moveFlag[3] = false;

				m_ePosX[5][3] -= 3;
				m_ePosY[5][3] -= 2.455;

				if (deadFlag[5][3] == true)
				{
					bossHP -= 1;

					moveFlag[3] = true;
					deadFlag[5][3] = false;

					if (bossHP <= 0)
					{
						//���S���o
					}
				}
			}
			else if (eDirection[3] == 6)//����
			{
				moveFlag[3] = false;

				m_ePosX[6][3] += 3;
				m_ePosY[6][3] -= 2.455;

				if (deadFlag[6][3] == true)
				{
					bossHP -= 1;

					moveFlag[3] = true;
					deadFlag[6][3] = false;

					if (bossHP <= 0)
					{
						//���S���o
					}
				}
			}
			else if (eDirection[3] == 7)//����
			{
				moveFlag[3] = false;

				m_ePosX[7][3] += 3;
				m_ePosY[7][3] += 2.455;

				if (deadFlag[7][3] == true)
				{
					bossHP -= 1;
				
					moveFlag[3] = true;
					deadFlag[7][3] = false;

					if (bossHP <= 0)
					{
						//���S���o
					}
				}
			}
		}
		else
		{
			m_ePosX[2][3] += 3;

			count++;

			if (count % 300 == 0)
			{
				flag = true;
				moveFlag[3] = true;
			}
		}
	}
	
}

void enemy::draw()
{
	Bat++;
	if (Bat % 5 == 0)
	{
		batAnimation++;
		if (batAnimation == 8)
		{
			batAnimation = 0;
		}
		Bat = 0;
	}
	
	Eye++;
	if (Eye % 3 == 0)
	{
		eyeAnimation++;
		if (eyeAnimation == 8)
		{
			eyeAnimation = 0;
		}
		Eye = 0;
	}

	Skeleton++;
	if (Skeleton % 10 == 0)
	{
		skeletonAnimation++;
		if (skeletonAnimation == 4)
		{
			skeletonAnimation = 0;
		}
		Skeleton = 0;
	}

	Mush++;
	if (Mush % 5 == 0)
	{
		mushAnimation++;
		if (mushAnimation == 8)
		{
			mushAnimation = 0;
		}
		Mush = 0;
	}

	for (int i = 0; i < DIR; i++)
	{
		if (enemyKinds[0] == 0)
		{
			if (i == 1 || i == 3)
			{
				DrawRotaGraph(m_ePosX[i][0], m_ePosY[i][0], 1.5, 0, m_skeletonHandle[skeletonAnimation], true, true);
				DrawCircle(m_ePosX[i][0], m_ePosY[i][0], m_ePosR, GetColor(255, 0, 0), false);
				
				if (dFlag[i][0] == true)
				{
					Death++;
					
					DrawRotaGraph(deathPosX[i][0], deathPosY[i][0], 1.5, 0, m_skeletonDeathHandle[deathAnimation], true, true);
					
					if (Death % 5 == 0)
					{
						deathAnimation++;

						if (deathAnimation == 4)
						{
							deathAnimation = 0;
							dFlag[i][0] = false;
						}
						Death = 0;
					}
				}
			}
			if (i == 0 || i == 2)
			{
				DrawRotaGraph(m_ePosX[i][0], m_ePosY[i][0], 1.5, 0, m_skeletonHandle[skeletonAnimation], true, false);
				DrawCircle(m_ePosX[i][0], m_ePosY[i][0], m_ePosR, GetColor(255, 0, 0), false);

				if (dFlag[i][0] == true)
				{
					Death++;
					DrawRotaGraph(deathPosX[i][0], deathPosY[i][0], 1.5, 0, m_skeletonDeathHandle[deathAnimation], true, false);
					
					if (Death % 5 == 0)
					{
						deathAnimation++;

						if (deathAnimation == 4)
						{
							deathAnimation = 0;
							dFlag[i][0] = false;
						}
						Death = 0;
					}
				}
			}

			if (i == 4 || i == 5)
			{
				DrawRotaGraph(m_ePosX[i][0], m_ePosY[i][0], 0.3, 0, m_batHandle[batAnimation], true, true);
				DrawCircle(m_ePosX[i][0], m_ePosY[i][0], m_ePosR, GetColor(255, 0, 0), false);
				if (dFlag[i][0] == true)
				{
					dFlag[i][0] = false;
				}
			}
			if (i == 7 || i == 6)
			{
				DrawRotaGraph(m_ePosX[i][0], m_ePosY[i][0], 0.3, 0, m_batHandle[batAnimation], true, false);
				DrawCircle(m_ePosX[i][0], m_ePosY[i][0], m_ePosR, GetColor(255, 0, 0), false);
				if (dFlag[i][0] == true)
				{
					dFlag[i][0] = false;
				}
			}

			
		}
		else if (enemyKinds[0] == 1)
		{
			if (i == 1 || i == 3)
			{
				DrawRotaGraph(m_ePosX[i][0], m_ePosY[i][0], 1.5, 0, m_mushHandle[mushAnimation], true, true);
				DrawCircle(m_ePosX[i][0], m_ePosY[i][0], m_ePosR, GetColor(255, 0, 0), false);

				if (dFlag[i][0] == true)
				{
					Death++;
					DrawRotaGraph(deathPosX[i][0], deathPosY[i][0], 1.5, 0, m_mushDeathHandle[deathAnimation], true, true);

					if (Death % 5 == 0)
					{
						deathAnimation++;

						if (deathAnimation == 4)
						{
							deathAnimation = 0;
							dFlag[i][0] = false;
						}
						Death = 0;
					}
				}
			}
			if (i == 0 || i == 2)
			{
				DrawRotaGraph(m_ePosX[i][0], m_ePosY[i][0], 1.5, 0, m_mushHandle[mushAnimation], true, false);
				DrawCircle(m_ePosX[i][0], m_ePosY[i][0], m_ePosR, GetColor(255, 0, 0), false);

				if (dFlag[i][0] == true)
				{
					Death++;
					DrawRotaGraph(deathPosX[i][0], deathPosY[i][0], 1.5, 0, m_mushDeathHandle[deathAnimation], true, false);

					if (Death % 5 == 0)
					{
						deathAnimation++;

						if (deathAnimation == 4)
						{
							deathAnimation = 0;
							dFlag[i][0] = false;
						}
						Death = 0;
					}
				}
			}

			if (i == 4 || i == 5)
			{
				DrawRotaGraph(m_ePosX[i][0], m_ePosY[i][0], 2.0, 0, m_eyeHandle[eyeAnimation], true, true);
				DrawCircle(m_ePosX[i][0], m_ePosY[i][0], m_ePosR, GetColor(255, 0, 0), false);

				if (dFlag[i][0] == true)
				{
					Death++;
					DrawRotaGraph(deathPosX[i][0], deathPosY[i][0], 1.5, 0, m_eyeDeathHandle[deathAnimation], true, true);

					if (Death % 5 == 0)
					{
						deathAnimation++;

						if (deathAnimation == 4)
						{
							deathAnimation = 0;
							dFlag[i][0] = false;
						}
						Death = 0;
					}
				}
			}
			if (i == 7 || i == 6)
			{
				DrawRotaGraph(m_ePosX[i][0], m_ePosY[i][0], 2.0, 0, m_eyeHandle[eyeAnimation], true, false);
				DrawCircle(m_ePosX[i][0], m_ePosY[i][0], m_ePosR, GetColor(255, 0, 0), false);
				
				if (dFlag[i][0] == true)
				{
					Death++;
					DrawRotaGraph(deathPosX[i][0], deathPosY[i][0], 1.5, 0, m_eyeDeathHandle[deathAnimation], true, false);

					if (Death % 5 == 0)
					{
						deathAnimation++;

						if (deathAnimation == 4)
						{
							deathAnimation = 0;
							dFlag[i][0] = false;
						}
						Death = 0;
					}
				}
			}
		}

		if (enemyKinds[1] == 0)
		{
			if (i == 1 || i == 3)
			{
				DrawRotaGraph(m_ePosX[i][1], m_ePosY[i][1], 1.5, 0, m_skeletonHandle[skeletonAnimation], true, true);
				DrawCircle(m_ePosX[i][1], m_ePosY[i][1], m_ePosR, GetColor(255, 0, 0), false);
				
				if (dFlag[i][1] == true)
				{
					Death++;

					DrawRotaGraph(deathPosX[i][1], deathPosY[i][1], 1.5, 0, m_skeletonDeathHandle[deathAnimation], true, true);

					if (Death % 5 == 0)
					{
						deathAnimation++;

						if (deathAnimation == 4)
						{
							deathAnimation = 0;
							dFlag[i][0] = false;
						}
						Death = 0;
					}
				}
			}
			if (i == 0 || i == 2)
			{
				DrawRotaGraph(m_ePosX[i][1], m_ePosY[i][1], 1.5, 0, m_skeletonHandle[skeletonAnimation], true, false);
				DrawCircle(m_ePosX[i][1], m_ePosY[i][1], m_ePosR, GetColor(255, 0, 0), false);
				
				if (dFlag[i][1] == true)
				{
					Death++;

					DrawRotaGraph(deathPosX[i][1], deathPosY[i][1], 1.5, 0, m_skeletonDeathHandle[deathAnimation], true, false);

					if (Death % 5 == 0)
					{
						deathAnimation++;

						if (deathAnimation == 4)
						{
							deathAnimation = 0;
							dFlag[i][0] = false;
						}
						Death = 0;
					}
				}
			}

			if (i == 4 || i == 5)
			{
				DrawRotaGraph(m_ePosX[i][1], m_ePosY[i][1], 0.3, 0, m_batHandle[batAnimation], true, true);
				DrawCircle(m_ePosX[i][1], m_ePosY[i][1], m_ePosR, GetColor(255, 0, 0), false);

				if (dFlag[i][1] == true)
				{
					dFlag[i][1] = false;
				}
			}
			if (i == 7 || i == 6)
			{
				DrawRotaGraph(m_ePosX[i][1], m_ePosY[i][1], 0.3, 0, m_batHandle[batAnimation], true, false);
				DrawCircle(m_ePosX[i][1], m_ePosY[i][1], m_ePosR, GetColor(255, 0, 0), false); 

				if (dFlag[i][1] == true)
				{
					dFlag[i][1] = false;
				}
			}
		}
		else if (enemyKinds[1] == 1)
		{
			if (i == 1 || i == 3)
			{
				DrawRotaGraph(m_ePosX[i][1], m_ePosY[i][1], 1.5, 0, m_mushHandle[mushAnimation], true, true);
				DrawCircle(m_ePosX[i][1], m_ePosY[i][1], m_ePosR, GetColor(255, 0, 0), false);
				
				if (dFlag[i][1] == true)
				{
					Death++;

					DrawRotaGraph(deathPosX[i][1], deathPosY[i][1], 1.5, 0, m_mushDeathHandle[deathAnimation], true, true);

					if (Death % 5 == 0)
					{
						deathAnimation++;

						if (deathAnimation == 4)
						{
							deathAnimation = 0;
							dFlag[i][1] = false;
						}
						Death = 0;
					}
				}
			}
			if (i == 0 || i == 2)
			{
				DrawRotaGraph(m_ePosX[i][1], m_ePosY[i][1], 1.5, 0, m_mushHandle[mushAnimation], true, false);
				DrawCircle(m_ePosX[i][1], m_ePosY[i][1], m_ePosR, GetColor(255, 0, 0), false);

				if (dFlag[i][1] == true)
				{
					Death++;

					DrawRotaGraph(deathPosX[i][1], deathPosY[i][1], 1.5, 0, m_skeletonDeathHandle[deathAnimation], true, false);

					if (Death % 5 == 0)
					{
						deathAnimation++;

						if (deathAnimation == 4)
						{
							deathAnimation = 0;
							dFlag[i][1] = false;
						}
						Death = 0;
					}
				}
			}

			if (i == 4 || i == 5)
			{
				DrawRotaGraph(m_ePosX[i][1], m_ePosY[i][1], 2.0, 0, m_eyeHandle[eyeAnimation], true, true);
				DrawCircle(m_ePosX[i][1], m_ePosY[i][1], m_ePosR, GetColor(255, 0, 0), false);

				if (dFlag[i][1] == true)
				{
					Death++;

					DrawRotaGraph(deathPosX[i][1], deathPosY[i][1], 1.5, 0, m_eyeDeathHandle[deathAnimation], true, true);

					if (Death % 5 == 0)
					{
						deathAnimation++;

						if (deathAnimation == 4)
						{
							deathAnimation = 0;
							dFlag[i][1] = false;
						}
						Death = 0;
					}
				}
			}
			if (i == 7 || i == 6)
			{
				DrawRotaGraph(m_ePosX[i][1], m_ePosY[i][1], 2.0, 0, m_eyeHandle[eyeAnimation], true, false);
				DrawCircle(m_ePosX[i][1], m_ePosY[i][1], m_ePosR, GetColor(255, 0, 0), false);

				if (dFlag[i][1] == true)
				{
					Death++;

					DrawRotaGraph(deathPosX[i][1], deathPosY[i][1], 1.5, 0, m_eyeDeathHandle[deathAnimation], true, false);

					if (Death % 5 == 0)
					{
						deathAnimation++;

						if (deathAnimation == 4)
						{
							deathAnimation = 0;
							dFlag[i][1] = false;
						}
						Death = 0;
					}
				}
			}
		}

		
	}

#if false
	for (int i = 0; i < DIR; i++)
	{
		if (enemyKinds[0] == 0)
		{
			DrawCircle(m_ePosX[i][0], m_ePosY[i][0], m_ePosR, GetColor(255, 255, 255), true);
		}
		else if (enemyKinds[0] == 1)
		{
			DrawCircle(m_ePosX[i][0], m_ePosY[i][0], m_ePosR, GetColor(255, 0, 0), true);
		}

		if (enemyKinds[1] == 0)
		{
			DrawCircle(m_ePosX[i][1], m_ePosY[i][1], m_ePosR, GetColor(255, 255, 255), true);
		}
		else if (enemyKinds[1] == 1)
		{
			DrawCircle(m_ePosX[i][1], m_ePosY[i][1], m_ePosR, GetColor(255, 0, 0), true);
		}
	}

#endif
}
