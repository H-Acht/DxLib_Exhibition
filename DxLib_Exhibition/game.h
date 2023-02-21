#pragma once
#include "DxLib.h"
#define DIR 8
#define ENEMY 3
#define TORCH 4

namespace Game
{
#ifdef _DEBUG //�f�o�b�O
    //�E�B���h�E���[�h�ݒ�
    constexpr bool kWindowMode = true;
#else
    //�E�B���h�E���[�h�ݒ�
    constexpr bool kWindowMode = false;
#endif
    //�E�B���h�E���ݒ�
    const char* const kTitleText = "�Q�[����";
    //�E�B���h�E�T�C�Y
    constexpr int kScreenWidth = 1600;
    constexpr int kScreenHeight = 900;
    //�J���[���[�h
    constexpr int kColorDepth = 32;     //32 or 16
};
