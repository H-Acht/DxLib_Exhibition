#pragma once
#include "SceneBase.h"
#include "player.h"
#include "enemy.h"
#include "torch.h"

class SceneMain2 : public SceneBase
{
public:
	SceneMain2()
	{
		m_isEnd = false;
	}
	virtual ~SceneMain2() {}

	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;

	virtual bool isEnd() { return m_isEnd; }

private:

	player m_player;
	enemy m_enemy;
	torch m_torch;

	bool m_isEnd;


};