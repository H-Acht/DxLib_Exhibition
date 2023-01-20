#include "game.h"
#include "player.h"

//�v���O������Win Main����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //window���[�h�ݒ�
    ChangeWindowMode(Game::kWindowMode);
    //�E�B���h�E���ݒ�
    SetMainWindowText(Game::kTitleText);
    //��ʃT�C�Y�̐ݒ�
    SetGraphMode(1280, 720, 32);

    if (DxLib_Init() == -1)        // �c�w���C�u��������������
    {
        return -1;        // �G���[���N�����璼���ɏI��
    }

    //�_�u���o�b�t�@���[�h
    SetDrawScreen(DX_SCREEN_BACK);

    player Player;
    Player.init();

    while (ProcessMessage() == 0)
    {
        LONGLONG time = GetNowHiPerformanceCount();

        //��ʂ̃N���A
        ClearDrawScreen();

        Player.update();
        Player.draw();

        //����ʂƕ\��ʂ�؂�ւ���
        ScreenFlip();

        //esc�L�[�ŏI��
        if (CheckHitKey(KEY_INPUT_ESCAPE))   break;

        //fps��60�ɌŒ�
        while (GetNowHiPerformanceCount() - time < 16667)
        {
        }
    }

    DxLib_End();            // �c�w���C�u�����g�p�̏I������

    return 0;            // �\�t�g�̏I��
}