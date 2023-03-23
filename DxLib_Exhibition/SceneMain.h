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

	virtual bool isEnd() { return m_isEnd; }

private:
	
	player* m_pPlayer;
	enemy* m_pEnemy;
	torch* m_pTorch;
	ScoreBoard* m_pScore;
	
	bool m_isEnd;

	int rgb;

	bool brightFlag;
	
	int num;

	bool gameoverEffect;

	int backGround[4];
	int volume;
};