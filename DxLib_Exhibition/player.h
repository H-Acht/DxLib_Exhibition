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
	int m_direction;
	//������ۑ�
	int prev;

	//pad����
	int m_inputX;
	int m_inputY;

	//���C���[(shot)
	int m_shotX;
	int m_shotY;
	int m_DshotFlag;
	bool m_shotFlag;
};
