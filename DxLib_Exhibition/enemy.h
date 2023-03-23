#pragma once
#include "game.h"

class player;

class enemy
{
public:
	enemy();
	virtual ~enemy();

	void init(player &Player);
	void update1(player &Player);
	void update2(player &Player);
	void update3(player& Player);
	void update4(player& Player);
	void update5(player& Player);
	void update6(player& Player);

	void draw();

	float m_ePosX[DIR][ENEMY]; //[ï˚å¸][î‘çÜ]
	float m_ePosY[DIR][ENEMY];
	int m_ePosR;
	
	bool deadFlag[DIR][ENEMY];

	int deadCount;

	int eDirection[ENEMY];
	int enemyKinds[ENEMY];

	float deathPosX[DIR][ENEMY];
	float deathPosY[DIR][ENEMY];
	bool dFlag[DIR][ENEMY];
	bool kindFlag[ENEMY];
	
private:

	bool moveFlag[ENEMY];

	int m_batHandle[4];
	int m_eyeHandle[8];
	int m_skeletonHandle[4];
	int m_mushHandle[8];

	int m_batDeathHandle[5];
	int m_eyeDeathHandle[4];
	int m_skeletonDeathHandle[4];
	int m_mushDeathHandle[4];

	int batAnimation;
	int Bat;

	int eyeAnimation;
	int Eye;

	int skeletonAnimation;
	int Skeleton;

	int mushAnimation;
	int Mush;

	int deathAnimation;
	int Death;

	int bDeathAnimation;

	int bDeath;

	int damageSound;

	int portal1[15];
	int portal2[15];

	int Portal;
	int portalAnimation;

};
