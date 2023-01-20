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
	int posX;
	int posY;

	//�v���C���[�̌����Ă������
	int direction;
	//���̌����Ă������
	int shield;
	//������ۑ�
	int prev;

	//�e�̍��W
	int sPosX;
	int sPosY;
	//�������A�e�t���O
	bool DshotFlag;
	//������A�e�t���O
	bool UshotFlag;
	//�������A�e�t���O
	bool LshotFlag;
	//�E�����A�e�t���O
	bool RshotFlag;

	//���݂��邩
	bool visibleFlag;

	bool shotFlag;

};

