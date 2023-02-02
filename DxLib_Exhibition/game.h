#pragma once
#include "DxLib.h"
#define ENEMY 8
#define TORCH 4

namespace Game
{
    //ウィンドウモード設定
    constexpr bool kWindowMode = true;
    //ウィンドウ名設定
    const char* const kTitleText = "ゲーム名";
    //ウィンドウサイズ
    constexpr int kScreenWidth = 800;
    constexpr int kScreenHeight = 800;
    //カラーモード
    constexpr int kColorDepth = 32;     //32 or 16
};
