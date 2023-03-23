#pragma once
#include "SceneBase.h"
#include "game.h"

class SceneTitle : public SceneBase
{
public:
	SceneTitle();
	
	virtual ~SceneTitle();

	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;

	virtual bool isEnd() { return m_isEnd; }
private:

	bool m_isEnd;

	bool brightFlag;
	bool brightFlag2;

	int rgb;

	int select;

	int textPosX;
	int textPosX2;
	
	int circlePosY;

	int prev;

	LPCSTR font_path;

	int Font1;
	int Font2;

	int backGround[4];

	int bPosX1[4];
	int bPosX2[4];
	int num;

	int selectSound;
	int cursorSound;

	int volume;
};