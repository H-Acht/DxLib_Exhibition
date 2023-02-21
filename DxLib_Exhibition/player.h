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

private:
	//�v���C���[�̌����Ă������
	int m_dir;
	//������ۑ�

	//pad����
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