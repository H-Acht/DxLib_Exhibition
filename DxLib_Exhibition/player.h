#pragma once
#include "Game.h"

class enemy;
class torch;


class player
{
public:
	player();
	~player();

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

private:
	//プレイヤーの向いている方向
	int m_dir;
	//方向を保存

	//pad入力
	int m_inputX;
	int m_inputY;

	//shot
	float m_sPosX;
	float m_sPosY;
	int m_sPosR;

	bool shotFlag;

	bool moveFlag;

	int m_pHandle[9];

};