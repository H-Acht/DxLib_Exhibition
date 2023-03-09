#pragma once
#include "SceneBase.h"

class SceneClear : public SceneBase
{
public:
	SceneClear();
	virtual ~SceneClear();

	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;

	virtual bool isEnd() { return m_isEnd; }
private:

	bool m_isEnd;

	int select;

	int textPosX;
	int textPosX2;
	int textPosX3;

	int circlePosY;

	int prev;
};