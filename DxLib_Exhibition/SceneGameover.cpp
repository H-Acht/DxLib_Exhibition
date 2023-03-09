#include "SceneGameover.h"
#include "game.h"
#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneRule.h"

SceneGameover::SceneGameover() :
	select(0),
	textPosX(0),
	textPosX2(0),
	textPosX3(0),
	circlePosY(0),
	prev(0),
	m_isEnd(false),
	brightFlag(false),
	rgb(0)
{
}

SceneGameover::~SceneGameover()
{
}

void SceneGameover::init()
{
	rgb = 255;

	textPosX = 200;
	textPosX2 = 200;
	textPosX3 = 200;

	circlePosY = 270;
}

SceneBase* SceneGameover::update()
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

		if (padState & PAD_INPUT_2)
		{
			return (new SceneMain);
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

		if (padState & PAD_INPUT_2)
		{
			return (new SceneTitle);
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

void SceneGameover::draw()
{
	SetDrawBright(rgb, rgb, rgb);

	DrawString(200, 200, "ゲームオーバー...", GetColor(255, 255, 255));

	DrawCircle(200, circlePosY, 10, GetColor(255, 0, 0), true);
	DrawString(textPosX, 250, "もう一度プレイする", GetColor(255, 255, 255));
	DrawString(textPosX2, 300, "タイトルに戻る", GetColor(255, 255, 255));

	DrawFormatString(200, 500, GetColor(255, 255, 255), "現在 %d", select);
}
