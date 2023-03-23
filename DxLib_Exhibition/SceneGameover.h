#pragma once
#include "SceneBase.h"
#include "game.h"

class SceneGameover : public SceneBase
{
public:
	SceneGameover();
	virtual ~SceneGameover();

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

	bool brightFlag;
	bool brightFlag2;

	int rgb;

	LPCSTR font_path;

	int Font1;
	int Font2;

	int corpseHandle;

	bool in;

	int lightHandle;
	int GreenHandle;

	int selectSound;
	int cursorSound;
};