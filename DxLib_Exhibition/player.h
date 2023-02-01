#pragma once
#include "Game.h"

class player
{
public:
	player();
	~player();

	void init();
	void update();
	void draw();

private:
	//プレイヤー位置
	int m_posX;
	int m_posY;

	//プレイヤーの向いている方向
	int m_dir;
	//方向を保存
	int prev;

	//pad入力
	int m_inputX;
	int m_inputY;

	//shot
	int m_shotX;
	int m_shotY;
	bool shotFlag;

};
