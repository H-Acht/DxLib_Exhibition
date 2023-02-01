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
	int m_shotX;
	int m_shotY;
	bool shotFlag;

};
