#include "SceneClear.h"
#include "SceneMain.h"
#include"game.h"

void SceneClear::init()
{
}

SceneBase* SceneClear::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (padState & PAD_INPUT_2)
	{
		return (new SceneMain);
	}
	return this;
}

void SceneClear::draw()
{
	DrawString(200, 200, "ステージクリア", GetColor(255, 255, 255));
	DrawString(200, 250, "next stage(未実装) -> ボタン2", GetColor(255, 255, 255));
}
