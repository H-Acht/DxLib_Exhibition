#include "game.h"
#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneRule.h"

SceneRule::SceneRule()
{
}

SceneRule::~SceneRule()
{
}

void SceneRule::init()
{
}

SceneBase* SceneRule::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (padState & PAD_INPUT_3)
	{
		return(new SceneTitle);
	}
	
	return this;
}

void SceneRule::draw()
{
	DrawString(100, 100, "������@�A���[��(��)", GetColor(255, 255, 255));
	DrawString(100, 240, "�X�e�B�b�N: �v���C���[�̌���(������)", GetColor(255, 255, 255));
	DrawString(100, 280, "A�{�^��(Z�L�[): �V���b�g(�ꔭ����)", GetColor(255, 255, 255));
	DrawString(100, 320, "B�{�^��(X�L�[): �{��(�S���ʂɊђʒe�𔭎�)", GetColor(255, 255, 255));
	DrawString(100, 400, "���j��230�ŃN���A", GetColor(255, 255, 255));
	DrawString(100, 440, "HP��0�A���͂ɂ���l�{�̏��������ׂď�������Q�[���I�[�o�[", GetColor(255, 255, 255));


	DrawString(100, 500, "�^�C�g���ɖ߂� �� X�{�^��", GetColor(255, 255, 255));
}

