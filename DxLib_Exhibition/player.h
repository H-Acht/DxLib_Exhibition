#pragma once
#include "Game.h"

class enemy;
class torch;


class player
{
public:
	player();
	virtual ~player();

	void init();
	void update();
	void shot(enemy& Enemy);
	void draw(torch& Torch);


	//プレイヤー位置
	int m_posX;
	int m_posY;
	int m_posR;

	//デバッグ用
	int m_drawPosX;
	int m_drawPosY;

	bool damageFlag;

	int pHP;
	int prev;

	int weapon;

private:
	//プレイヤーの向いている方向
	int m_dir;

	//pad入力
	int m_inputX;
	int m_inputY;

	//shot
	float m_sPosX;
	float m_sPosY;
	int m_sPosR;

	bool shotFlag;

	bool moveFlag;

	int m_shotHandle[21];
	
	int m_hitHandle[8];

	int Shot;
	int shotAnimation;

	int Hit;
	int hitAnimation;

	float PI;

	int push;

	bool hitFlag;

	float hitPosX;
	float hitPosY;
};