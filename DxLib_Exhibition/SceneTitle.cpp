#include "game.h"
#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneRule.h"

SceneTitle::SceneTitle() :
	brightFlag(false),
	brightFlag2(false),
	rgb(0),
	select(0),
	textPosX(0),
	textPosX2(0),
	circlePosY(0),
	prev(0),
	Font1(0),
	Font2(0),
	backGround(),
	bPosX1(),
	bPosX2(),
	num(0),
	volume(0),
	cursorSound(),
	selectSound()
{
	m_isEnd = false;

	//リソース読み込み
	font_path = "Data/KH-Dot-Hibiya-24.ttf";
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
	}
	else {
		// フォント読込エラー処理
		MessageBox(NULL, "フォント読込失敗", "", MB_OK);
	}
}

SceneTitle::~SceneTitle()
{
	DeleteFontToHandle(Font1);
	DeleteFontToHandle(Font2);

	if (RemoveFontResourceEx(font_path, FR_PRIVATE, NULL)) {
	}
	else {
		MessageBox(NULL, "remove failure", "", MB_OK);
	}

	for (int i = 0; i < 4; i++)
	{
		DeleteGraph(backGround[i]);
	}
}

void SceneTitle::init()
{
	rgb = 0;

	textPosX = 250;
	textPosX2 = 200;
	
	circlePosY = 350;

	Font1 = CreateFontToHandle("KHドット日比谷24", 32, -1, -1);
	Font2 = CreateFontToHandle("KHドット日比谷24", 80, -1, -1);

	backGround[0] = LoadGraph("Data/background1.png");
	backGround[1] = LoadGraph("Data/background2.png");
	backGround[2] = LoadGraph("Data/background3.png");
	backGround[3] = LoadGraph("Data/background4a.png");

	selectSound = LoadSoundMem("Data/Sound/select.mp3");
	cursorSound = LoadSoundMem("Data/Sound/cursor.mp3");
	
	for (int i = 0; i < 4; i++)
	{
		bPosX1[i] = 0;
		bPosX2[i] = 1800;
	}
	
	PlayMusic("Data/Sound/titleBGM.mp3", DX_PLAYTYPE_LOOP);

}

SceneBase* SceneTitle::update()
{
	SetVolumeMusic(volume);
	
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	static int push = 0;

	switch (num)
	{
	case 0:
		rgb += 5;
		volume += 4;
		if (rgb == 255 && volume >= 200)
		{
			num = 1;
		}
		break;
	case 1:	
		prev = select;
		if (prev == 0)
		{
			textPosX = 250;
			textPosX2 = 200;

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
				StopMusic();
				return(new SceneMain);
			}
			volume -= 5;
			rgb -= 5;
		}

		if (brightFlag2 == true)
		{
			if (rgb == 0)
			{
				brightFlag2 = false;
				StopMusic();
				return(new SceneRule);
			}
			volume -= 5;
			rgb -= 5;
		}
	default:
		break;
	}

	return this;
}

void SceneTitle::draw()
{
	SetDrawBright(rgb, rgb, rgb);

	bPosX1[0] -= 4;
	bPosX1[1] -= 3;
	bPosX1[2] -= 2;
	bPosX1[3] -= 1;

	for (int i = 0; i < 4; i++)
	{
		if (bPosX1[i] == -1800)
		{
			bPosX1[i] = 1800;
		}
	}

	bPosX2[0] -= 4;
	bPosX2[1] -= 3;
	bPosX2[2] -= 2;
	bPosX2[3] -= 1;

	for (int i = 0; i < 4; i++)
	{
		if (bPosX2[i] == -1800)
		{
			bPosX2[i] = 1800;
		}
	}

	DrawGraph(bPosX1[0], 0, backGround[0], true);
	DrawTurnGraph(bPosX2[0], 0, backGround[0], true);
	DrawGraph(bPosX1[1], 0, backGround[1], true);
	DrawTurnGraph(bPosX2[1], 0, backGround[1], true);
	DrawGraph(bPosX1[2], 0, backGround[2], true);
	DrawTurnGraph(bPosX2[2], 0, backGround[2], true);
	DrawGraph(bPosX1[3], 0, backGround[3], true);
	DrawTurnGraph(bPosX2[3], 0, backGround[3], true);

	DrawStringToHandle(200, 150, "Cave Survivor", GetColor(255, 0, 0), Font2);

	DrawCircle(200, circlePosY + 16, 16, GetColor(255, 0, 0), true);
	DrawStringToHandle(textPosX, 350, "START", GetColor(255, 255, 255), Font1);
	DrawStringToHandle(textPosX2, 400, "RULE", GetColor(255, 255, 255), Font1);

#ifdef _DEBUG
	DrawFormatString(200, 500, GetColor(255, 255, 255), "現在 %d", select);
#endif
}