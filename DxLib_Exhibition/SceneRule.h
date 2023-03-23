#pragma once
#include "SceneBase.h"
#include "game.h"

class SceneRule : public SceneBase
{
public:
	SceneRule();
	virtual ~SceneRule();

	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;

	virtual bool isEnd() { return m_isEnd; }
private:

	bool m_isEnd;

	int rgb;

	int num;

	LPCSTR font_path;

	int buttonHandle[12];
	int stickHandle[28];

	int Font1;
	int Font2;

	int Button;
	int aButtonAnimation;
	int bButtonAnimation;
	
	int Stick;
	int stickAnimation;

	int backGround[4];

	int bPosX1[4];
	int bPosX2[4];

	bool brightFlag;
	int selectSound;
};