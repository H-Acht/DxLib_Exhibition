#include "SceneGameOver.h"
#include "SceneMain.h"
#include "game.h"

void SceneGameOver::init()
{
}

SceneBase* SceneGameOver::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (padState & PAD_INPUT_2)
	{
		return (new SceneMain);
	}
	return this;

}

void SceneGameOver::draw()
{
	DrawString(200, 200, "ゲームオーバー", GetColor(255, 255, 255));
}
