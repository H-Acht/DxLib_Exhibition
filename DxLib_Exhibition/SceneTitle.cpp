#include "game.h"
#include "SceneTitle.h"
#include "SceneMain.h"

void SceneTitle::init()
{
}

SceneBase* SceneTitle::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (padState & PAD_INPUT_2)
	{
		return (new SceneMain);
	}
	return this;
}

void SceneTitle::draw()
{
	DrawString(100, 100, "–¢’è", GetColor(100, 100, 100));
}