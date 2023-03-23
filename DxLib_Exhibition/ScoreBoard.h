#pragma once
#include "game.h"

class player;
class enemy;
class torch;
class money;

class ScoreBoard
{
public:
	ScoreBoard();
	virtual ~ScoreBoard();
	
	void init();
	void update();
	void draw(player& Player, enemy& Enemy, torch &Torch);

	int Level;

private:
	int boardPosX;
	int boardPosY;

	int stickHandle[28];
	int buttonHandle[12];
	int shotHandle[21];
	int bombHandle[45];
	int numHandle[10];

	int Button;
	int aButtonAnimation;
	int bButtonAnimation;

	int Stick;
	int stickAnimation;

	int Shot;
	int shotAnimation;

	int Bomb;
	int bombAnimation;

	LPCSTR font_path;

	int Font1;
	int Font2;
	int Font3;

	int HPHandle;
	int emptyHPHandle;

	double extend;
	int HP;
	int hpAnimation;

	int a[3];

	bool bombFlag;
	double m_bPosX[8];
	double m_bPosY[8];
	double bPI[8];
};