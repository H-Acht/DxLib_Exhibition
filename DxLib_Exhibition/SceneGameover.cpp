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
	brightFlag2(false),
	rgb(0),
	Font1(0),
	Font2(0),
	in(true),
	corpseHandle(0),
	GreenHandle(0),
	cursorSound(),
	selectSound(),
	lightHandle()
{
	//リソース読み込み
	font_path = "Data/KH-Dot-Hibiya-24.ttf";
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
	}
	else {
		// フォント読込エラー処理
		MessageBox(NULL, "フォント読込失敗", "", MB_OK);
	}
}

SceneGameover::~SceneGameover()
{
	DeleteFontToHandle(Font1);
	DeleteFontToHandle(Font2);

	if (RemoveFontResourceEx(font_path, FR_PRIVATE, NULL)) {
	}
	else {
		MessageBox(NULL, "remove failure", "", MB_OK);
	}

	DeleteGraph(corpseHandle);
	DeleteGraph(lightHandle);
	DeleteGraph(GreenHandle);

	DeleteSoundMem(selectSound);
	DeleteSoundMem(cursorSound);
}

void SceneGameover::init()
{
	textPosX = 200;
	textPosX2 = 200;
	textPosX3 = 200;

	circlePosY = 350;

	Font1 = CreateFontToHandle("KHドット日比谷24", 32, -1, -1);
	Font2 = CreateFontToHandle("KHドット日比谷24", 64, -1, -1);

	corpseHandle = LoadGraph("Data/GameOverCorpse.png");
	lightHandle = LoadGraph("Data/Light.png");
	GreenHandle = LoadGraph("Data/Green.png");

	selectSound = LoadSoundMem("Data/Sound/select.mp3");
	cursorSound = LoadSoundMem("Data/Sound/cursor.mp3");
}

SceneBase* SceneGameover::update()
{
	if (in == true)
	{
		if (rgb <= 255)
		{
			rgb += 5;
		}
		else if (rgb >= 255)
		{
			in = false;
		}
	}

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	static int push = 0;

	prev = select;

	if (prev == 0)
	{
		textPosX = 250;
		textPosX2 = 200;
		textPosX3 = 200;

		circlePosY = 350;

		if (padState & PAD_INPUT_DOWN || padState & PAD_INPUT_UP)
		{
			if (push == 0)
			{
				PlaySoundMem(cursorSound, DX_PLAYTYPE_BACK, true);
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
			PlaySoundMem(selectSound, DX_PLAYTYPE_BACK, false);
			brightFlag = true;
		}
	}
	if (prev == 1)
	{
		textPosX = 200;
		textPosX2 = 250;
		textPosX3 = 200;

		circlePosY = 400;

		if (padState & PAD_INPUT_UP || padState & PAD_INPUT_DOWN)
		{
			if (push == 0)
			{
				PlaySoundMem(cursorSound, DX_PLAYTYPE_BACK, true);
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
			PlaySoundMem(selectSound, DX_PLAYTYPE_BACK, false);
			brightFlag2 = true;
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

	if (brightFlag2 == true)
	{
		if (rgb == 0)
		{
			brightFlag2 = false;
			return(new SceneTitle);
		}
		rgb -= 5;
	}

	return this;
}

void SceneGameover::draw()
{
	SetDrawBright(rgb, rgb, rgb);

	DrawRotaGraph(800, 900, 17.0, 0, GreenHandle, true, false);
	DrawRotaGraph(800, 580, 10.0, 0, corpseHandle, true, false);
	DrawRotaGraph(800, 900, 2.2, 0, lightHandle, true, false);

	DrawStringToHandle(200, 150, "ゲームオーバー...", GetColor(255, 255, 255), Font2);

	DrawCircle(200, circlePosY + 16, 16, GetColor(255, 0, 0), true);
	DrawStringToHandle(textPosX, 350, "もう一度プレイする", GetColor(255, 255, 255), Font1);
	DrawStringToHandle(textPosX2, 400, "タイトルに戻る", GetColor(255, 255, 255), Font1);


#ifdef _DEBUG

	DrawFormatString(200, 500, GetColor(255, 255, 255), "現在 %d", select);

#endif
}
