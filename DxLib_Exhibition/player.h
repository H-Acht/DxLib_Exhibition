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

	int m_drawPosX;
	int m_drawPosY;

	bool m_damageFlag;

	//�̗�
	int m_pHP;
	
	int prev;

	//�{���̎c�e��
	int remainingBomb;

private:
	//�v���C���[�̌����Ă������
	int m_dir;

	//pad�A�i���O�X�e�B�b�N����
	int m_inputX;
	int m_inputY;

	//�V���b�g�֘A
	float m_sPosX;
	float m_sPosY;
	int m_sPosR;
	bool shotFlag;
	bool moveFlag;

	//�{���֘A
	float m_bPosX[8];
	float m_bPosY[8];
	bool bombFlag;
	int m_num;
	
	//�O���t�B�b�N�n���h���֘A
	int m_playerHandle[24];
	int m_shotHandle[21];
	int m_hitHandle[8];
	int m_bombHandle[45];
	int CrosshairHandle;

	//�A�j���[�V�����֘A
	int Shot;
	int shotAnimation;

	int Bomb;
	int bombAnimation;

	int Hit;
	int hitAnimation;

	//�V���b�g�A�{���̕\���p�x
	float shotGraphDir;
	float bombGraphDir[8];

	int push;

	//�q�b�g���֘A
	bool hitFlag;
	float hitPosX;
	float hitPosY;

	bool damageEffect;

	//�T�E���h�֘A
	int shotSound;
	int enemyDamageSound;
	int bombSound;

	//�A�i���O�p�b�h�̐��l
	int InputX;
	int InputY;

	//�N���X�w�A
	int CrosshairX;
	int CrosshairY;
	
};