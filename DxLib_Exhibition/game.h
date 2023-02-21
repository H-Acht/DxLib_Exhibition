#pragma once
#include "DxLib.h"
#define DIR 8
#define ENEMY 3
#define TORCH 4

namespace Game
{
#ifdef _DEBUG //デバッグ
    //ウィンドウモード設定
    constexpr bool kWindowMode = true;
#else
    //ウィンドウモード設定
    constexpr bool kWindowMode = false;
#endif
    //ウィンドウ名設定
    const char* const kTitleText = "ゲーム名";
    //ウィンドウサイズ
    constexpr int kScreenWidth = 1600;
    constexpr int kScreenHeight = 900;
    //カラーモード
    constexpr int kColorDepth = 32;     //32 or 16
};
