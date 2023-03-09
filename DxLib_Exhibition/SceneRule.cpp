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
	DrawString(100, 100, "操作方法、ルール(仮)", GetColor(255, 255, 255));
	DrawString(100, 240, "スティック: プレイヤーの向き(八方向)", GetColor(255, 255, 255));
	DrawString(100, 280, "Aボタン(Zキー): ショット(一発ずつ)", GetColor(255, 255, 255));
	DrawString(100, 320, "Bボタン(Xキー): ボム(全方位に貫通弾を発射)", GetColor(255, 255, 255));
	DrawString(100, 400, "撃破数230でクリア", GetColor(255, 255, 255));
	DrawString(100, 440, "HPが0、周囲にある四本の松明がすべて消えたらゲームオーバー", GetColor(255, 255, 255));


	DrawString(100, 500, "タイトルに戻る → Xボタン", GetColor(255, 255, 255));
}

