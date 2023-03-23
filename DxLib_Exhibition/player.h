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


	//�v���C���[�ʒu
	int m_posX;
	int m_posY;
	int m_posR;

	//�f�o�b�O�p
	int m_drawPosX;
	int m_drawPosY;

	bool damageFlag;

	int pHP;
	int prev;

	int remainingBomb;


private:
	//�v���C���[�̌����Ă������
	int m_dir;

	//pad����
	int m_inputX;
	int m_inputY;

	//shot
	float m_sPosX;
	float m_sPosY;

	int m_sPosR;

	bool shotFlag;

	bool moveFlag;

	bool bombFlag;
	float m_bPosX[8];
	float m_bPosY[8];

	int playerHandle[24];

	int m_shotHandle[21];
	
	int m_hitHandle[8];

	int m_bombHandle[45];

	int Shot;
	int shotAnimation;

	int Bomb;
	int bombAnimation;

	int Hit;
	int hitAnimation;

	float PI;
	float bPI[8];

	int push;

	bool hitFlag;

	float hitPosX;
	float hitPosY;

	int num;

	bool damageEffect;

	int shotSound;
	int enemyDamageSound;
	int bombSound;
};