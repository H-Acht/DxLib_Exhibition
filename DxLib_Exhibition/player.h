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

	
private:
	//�v���C���[�ʒu
	int m_posX;
	int m_posY;

	//�v���C���[�̌����Ă������
	int m_dir;
	//������ۑ�
	int prev;

	//pad����
	int m_inputX;
	int m_inputY;

	//shot
	int m_sPosX;
	int m_sPosY;
	int m_sPosR;

	bool shotFlag;

	bool moveFlag;
};