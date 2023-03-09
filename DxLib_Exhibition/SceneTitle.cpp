#include "game.h"
#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneRule.h"

SceneTitle::SceneTitle() :
	brightFlag(false),
	rgb(0),
	select(0),
	textPosX(0),
	textPosX2(0),
	textPosX3(0),
	circlePosY(0),
	prev(0)
{
	m_isEnd = false;
}

void SceneTitle::init()
{
	rgb = 255;

	textPosX = 200;
	textPosX2 = 200;
	textPosX3 = 200;

	circlePosY = 270;
}

SceneBase* SceneTitle::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	prev = select;

	if (prev == 0)
	{
		textPosX = 250;
		textPosX2 = 200;
		textPosX3 = 200;

		circlePosY = 250;

		static int push = 0;

		if (padState & PAD_INPUT_DOWN || padState & PAD_INPUT_UP)
		{
			if (push == 0)
			{
				select = 1;
			}
			push = 1;
		}
		else
		{
			push = 0;
		}

		if (padState & PAD_INPUT_1)
		{
			brightFlag = true;
		}
	}
	if (prev == 1)
	{
		textPosX = 200;
		textPosX2 = 250;
		textPosX3 = 200;

		circlePosY = 300;

		static int push = 1;

		if (padState & PAD_INPUT_UP || padState & PAD_INPUT_DOWN)
		{
			if (push == 0)
			{
				select = 0;
			}
			push = 1;
		}
		else
		{
			push = 0;
		}

		if (padState & PAD_INPUT_1)
		{
			return (new SceneRule);
		}
	}

	if (brightFlag == true)
	{
		if (rgb == 0)
		{
			brightFlag = false;
			return(new SceneMain);
		}
		rgb -= 5;
	}
	return this;
}

void SceneTitle::draw()
{
	SetDrawBright(rgb, rgb, rgb);

	DrawString(200, 200, "É^ÉCÉgÉãñ¢íË", GetColor(255, 255, 255));

	DrawCircle(200, circlePosY, 10, GetColor(255, 0, 0), true);
	DrawString(textPosX, 250, "START", GetColor(255, 255, 255));
	DrawString(textPosX2, 300, "RULE", GetColor(255, 255, 255));

	DrawFormatString(200, 500, GetColor(255, 255, 255), "åªç› %d", select);
}