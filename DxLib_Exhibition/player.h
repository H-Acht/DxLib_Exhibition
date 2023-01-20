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
	int posX;
	int posY;

	//プレイヤーの向いている方向
	int direction;
	//盾の向いている方向
	int shield;
	//方向を保存
	int prev;

	//弾の座標
	int sPosX;
	int sPosY;
	//下方向、弾フラグ
	bool DshotFlag;
	//上方向、弾フラグ
	bool UshotFlag;
	//左方向、弾フラグ
	bool LshotFlag;
	//右方向、弾フラグ
	bool RshotFlag;

	//存在するか
	bool visibleFlag;

	bool shotFlag;

};

