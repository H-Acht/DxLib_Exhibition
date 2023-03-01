#pragma once
#include "SceneBase.h"

class player;
class enemy;
class torch;
class ScoreBoard;

class SceneMain : public SceneBase
{
public:
	SceneMain();
	virtual ~SceneMain();

	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;

	virtual void gameoverUpdate();
	virtual void gameoverDraw();

	virtual void mainUpdate1();
	virtual void mainDraw1();

	virtual void clearUpdate1();
	virtual void clearDraw1();


	virtual bool isEnd() { return m_isEnd; }

private:
	
	player* m_pPlayer;
	enemy* m_pEnemy;
	torch* m_pTorch;
	ScoreBoard* m_pScore;
	
	int num;

	bool m_isEnd;

	int select;
	
	int textPosX;
	int textPosX2;
	int textPosX3;

	int circlePosY;

	int prev;
};