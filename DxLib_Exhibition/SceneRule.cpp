#include "game.h"
#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneRule.h"

SceneRule::SceneRule() :
	buttonHandle(),
	stickHandle(),
	Font1(0),
	Font2(0),
	Button(0),
	aButtonAnimation(0),
	bButtonAnimation(3),
	Stick(0),
	stickAnimation(12),
	rgb(0),
	brightFlag(false),
	backGround(),
	bPosX1(),
	bPosX2(),
	m_isEnd(false)
{
	//���\�[�X�ǂݍ���
	font_path = "Data/KH-Dot-Hibiya-24.ttf";
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
	}
	else {
		// �t�H���g�Ǎ��G���[����
		MessageBox(NULL, "�t�H���g�Ǎ����s", "", MB_OK);
	}
}

SceneRule::~SceneRule()
{
	for (int i = 0; i < 12; i++)
	{
		DeleteGraph(buttonHandle[i]);
	}
	for (int i = 0; i < 28; i++)
	{
		DeleteGraph(stickHandle[i]);
	}

	DeleteFontToHandle(Font1);
	DeleteFontToHandle(Font2);

	if (RemoveFontResourceEx(font_path, FR_PRIVATE, NULL)) {
	}
	else {
		MessageBox(NULL, "remove failure", "", MB_OK);
	}

	for (int i = 0; i < 4; i++)
	{
		DeleteGraph(backGround[i]);
	}

}

void SceneRule::init()
{
	Font1 = CreateFontToHandle("KH�h�b�g����J24", 32, -1, -1);
	Font2 = CreateFontToHandle("KH�h�b�g����J24", 48, -1, -1);

	LoadDivGraph("Data/Button.png", 12, 3, 4, 16, 16, buttonHandle);
	LoadDivGraph("Data/Stick.png", 28, 3, 10, 16, 16, stickHandle);

	backGround[0] = LoadGraph("Data/background1.png");
	backGround[1] = LoadGraph("Data/background2.png");
	backGround[2] = LoadGraph("Data/background3.png");
	backGround[3] = LoadGraph("Data/background4a.png");

	selectSound = LoadSoundMem("Data/Sound/select.mp3");

	for (int i = 0; i < 4; i++)
	{
		bPosX1[i] = 0;
		bPosX2[i] = 1800;
	}
}

SceneBase* SceneRule::update()
{
	if (brightFlag == false)
	{
		if (rgb <= 255)
		{
			rgb += 5;
		}
	}
	else
	{
		rgb -= 5;
		if (rgb <= 0)
		{
			return(new SceneTitle);
		}
	}
	
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_1)
	{
		PlaySoundMem(selectSound, DX_PLAYTYPE_BACK, false);
		brightFlag = true;
	}
	
	return this;
}

void SceneRule::draw()
{
	SetDrawBright(rgb, rgb, rgb);

	Button++;
	if (Button % 10 == 0)
	{
		Button = 0;
		
		aButtonAnimation++;
		if (aButtonAnimation == 2)
		{
			aButtonAnimation = 0;
		}
		
		bButtonAnimation++;
		if (bButtonAnimation == 5)
		{
			bButtonAnimation = 3;
		}
	}

	Stick++;
	if (Stick % 5 == 0)
	{
		Stick = 0;
		stickAnimation++;
		if (stickAnimation == 27)
		{
			stickAnimation = 12;
		}
	}


	bPosX1[0] -= 4;
	bPosX1[1] -= 3;
	bPosX1[2] -= 2;
	bPosX1[3] -= 1;

	for (int i = 0; i < 4; i++)
	{
		if (bPosX1[i] == -1800)
		{
			bPosX1[i] = 1800;
		}
	}

	bPosX2[0] -= 4;
	bPosX2[1] -= 3;
	bPosX2[2] -= 2;
	bPosX2[3] -= 1;

	for (int i = 0; i < 4; i++)
	{
		if (bPosX2[i] == -1800)
		{
			bPosX2[i] = 1800;
		}
	}

	DrawGraph(bPosX1[0], 0, backGround[0], true);
	DrawTurnGraph(bPosX2[0], 0, backGround[0], true);
	DrawGraph(bPosX1[1], 0, backGround[1], true);
	DrawTurnGraph(bPosX2[1], 0, backGround[1], true);
	DrawGraph(bPosX1[2], 0, backGround[2], true);
	DrawTurnGraph(bPosX2[2], 0, backGround[2], true);
	DrawGraph(bPosX1[3], 0, backGround[3], true);
	DrawTurnGraph(bPosX2[3], 0, backGround[3], true);

	DrawStringToHandle(100, 100, "������@", GetColor(255, 255, 255), Font2);
	DrawStringToHandle(130, 200, " : �v���C���[�̌���(������)", GetColor(255, 255, 255), Font1);
	DrawRotaGraph(110, 216, 2.0, 0, stickHandle[stickAnimation], true, false);	//�A�i���O�X�e�B�b�N
	DrawStringToHandle(130, 240, " : �V���b�g(�ꔭ����)", GetColor(255, 255, 255),Font1);
	DrawRotaGraph(110, 256, 2.0, 0, buttonHandle[aButtonAnimation], true, false);	//A�{�^��
	DrawStringToHandle(130, 280, " : �{��(�S���ʂɊђʒe�𔭎�)", GetColor(255, 255, 255), Font1);
	DrawRotaGraph(110, 296, 2.0, 0, buttonHandle[bButtonAnimation], true, false);	//B�{�^��


	DrawStringToHandle(100, 350, "���[��", GetColor(255, 255, 255), Font2);
	DrawStringToHandle(100, 450, "���j��150�̂ŃN���A", GetColor(255, 255, 255), Font1);
	DrawStringToHandle(100, 490, "HP��0�A���͂ɂ���l�{�̏��������ׂď�������Q�[���I�[�o�[", GetColor(255, 255, 255), Font1);
	DrawStringToHandle(100, 530, "�{����3�ێ����Ă��āA30�̓|������������", GetColor(255, 255, 255), Font1);


	DrawStringToHandle(130, 600, " : �^�C�g���ɖ߂�", GetColor(255, 255, 255), Font1);
	DrawRotaGraph(110, 616, 2.0, 0, buttonHandle[aButtonAnimation], true, false);	//B�{�^��

}

