#pragma once
#include "Game.h"

class enemy;

class player
{
public:
	player();
	~player();

	void init();
	void update(enemy &Enemy);
	void draw();

	//プレイヤー位置
	int m_posX;
	int m_posY;
	int m_posR;

	//デバッグ用
	int m_drawPosX;
	int m_drawPosY;

	
private:
	//プレイヤーの向いている方向
	int m_dir;
	//方向を保存
	int prev;

	//pad入力
	int m_inputX;
	int m_inputY;

	//shot
	int m_sPosX;
	int m_sPosY;
	int m_sPosR;

	bool shotFlag;

	bool moveFlag;

};