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
	DrawString(100, 100, "ñ¢íË", GetColor(100, 100, 100));
	DrawString(100, 150, "START Å® 2É{É^Éì", GetColor(255, 255, 255));

}