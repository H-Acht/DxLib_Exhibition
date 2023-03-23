#pragma once
#include "SceneBase.h"
#include "game.h"

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

	LPCSTR font_path;

	int Font1;
	int Font2;

	bool brightFlag;
	bool brightFlag2;

	int rgb;

	bool in;
	
	int selectSound;
	int cursorSound;

	int backGround[6];

	int bPosX1[6];
	int bPosX2[6];

	int Cavehandle;

	int CavePosX;

	int playerHandle[24];

	int Player;
	int playerAnimation;

	int playerPosX;

	int smokeHandle[13];
	int Smoke;
	int smokeAnimation;

	bool fallFlag;
	int fallPosX;

	bool shakeFlag;
	int shakeX;
	int shakeY;

	int emotionHandle1[3];
	int emotionHandle2[3];

	int Emotion;
	int emotionAnimation;

	int num;

	bool emotionFlag[2];
	float emotionEX;

	int fallSound;
	int crashSound;
	int emotionSound;
	int brakeSound;

	bool soundFlag1;
	bool soundFlag2;

	int clearBGM;
	int volume;
	
	int stopFlag;
};