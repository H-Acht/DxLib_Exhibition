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
	void bomb(enemy& Enemy);
	void draw(torch& Torch);

	//プレイヤー位置
	int m_posX;
	int m_posY;
	int m_posR;

	int m_drawPosX;
	int m_drawPosY;

	bool m_damageFlag;

	//体力
	int m_pHP;
	
	int prev;

	//ボムの残弾数
	int remainingBomb;

private:
	//プレイヤーの向いている方向
	int m_dir;

	//padアナログスティック入力
	int m_inputX;
	int m_inputY;

	//ショット関連
	float m_sPosX;
	float m_sPosY;
	int m_sPosR;
	bool shotFlag;
	bool moveFlag;

	//ボム関連
	float m_bPosX[8];
	float m_bPosY[8];
	bool bombFlag;
	int m_num;
	
	//グラフィックハンドル関連
	int m_playerHandle[24];
	int m_shotHandle[21];
	int m_hitHandle[8];
	int m_bombHandle[45];
	int CrosshairHandle;

	//アニメーション関連
	int Shot;
	int shotAnimation;

	int Bomb;
	int bombAnimation;

	int Hit;
	int hitAnimation;

	//ショット、ボムの表示角度
	float shotGraphDir;
	float bombGraphDir[8];

	int push;

	//ヒット時関連
	bool hitFlag;
	float hitPosX;
	float hitPosY;

	bool damageEffect;

	//サウンド関連
	int shotSound;
	int enemyDamageSound;
	int bombSound;

	//アナログパッドの数値
	int InputX;
	int InputY;

	//クロスヘア
	int CrosshairX;
	int CrosshairY;
	
};