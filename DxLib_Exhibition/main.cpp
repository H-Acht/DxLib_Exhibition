#include "game.h"
#include "player.h"
#include "enemy.h"
#include "torch.h"

//プログラムはWin Mainから始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//windowモード設定
	ChangeWindowMode(Game::kWindowMode);
	//ウィンドウ名設定
	SetMainWindowText(Game::kTitleText);
	//画面サイズの設定
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorDepth);

	if (DxLib_Init() == -1)        // ＤＸライブラリ初期化処理
	{
		return -1;        // エラーが起きたら直ちに終了
	}

	//ダブルバッファモード
	SetDrawScreen(DX_SCREEN_BACK);

	player Player;
	enemy Enemy;
	torch Torch;

	Player.init();
	Enemy.init();
	Torch.init();

	while (ProcessMessage() == 0)
	{
		LONGLONG time = GetNowHiPerformanceCount();

		//画面のクリア
		ClearDrawScreen();

		Player.update(Enemy);
		Enemy.update();
		Torch.update();

		Player.draw();
		Enemy.draw();
		Torch.draw();

		//裏画面と表画面を切り替える
		ScreenFlip();

		//escキーで終了
		if (CheckHitKey(KEY_INPUT_ESCAPE))   break;

		//fpsを60に固定
		while (GetNowHiPerformanceCount() - time < 16667)
		{
		}
	}

	DxLib_End();            // ＤＸライブラリ使用の終了処理

	return 0;            // ソフトの終了
}