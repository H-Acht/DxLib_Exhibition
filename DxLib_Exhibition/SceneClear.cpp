#include "SceneClear.h"
#include "game.h"
#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneRule.h"
#include <Windows.h>

SceneClear::SceneClear() :
	select(0),
	textPosX(0),
	textPosX2(0),
	textPosX3(0),
	circlePosY(0),
	prev(0),
	m_isEnd(false),
	Font1(0),
	Font2(0),
	brightFlag(0),
	brightFlag2(0),
	rgb(0),
	in(true),
	selectSound(0),
	cursorSound(0),
	backGround(),
	bPosX1(),
	bPosX2(),
	CavePosX(),
	Player(0),
	playerAnimation(12),
	fallFlag(false),
	fallPosX(0),
	shakeX(0),
	shakeY(0),
	shakeFlag(false),
	Emotion(0),
	emotionAnimation(0),
	emotionEX(0),
	soundFlag1(false),
	soundFlag2(false),
	Cavehandle(),
	Smoke(0),
	brakeSound(),
	clearBGM(),
	crashSound(),
	emotionFlag(),
	stopFlag(false),
	emotionHandle1(),
	emotionHandle2(),
	emotionSound(),
	fallSound(),
	num(),
	playerHandle(),
	playerPosX(),
	smokeAnimation(0),
	smokeHandle(),
	volume(0)
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

SceneClear::~SceneClear()
{
	for (int i = 0; i < 3; i++)
	{
		DeleteGraph(emotionHandle1[i]);
		DeleteGraph(emotionHandle2[i]);
	}
	for (int i = 0; i < 6; i++)
	{
		DeleteGraph(backGround[i]);
	}
	for (int i = 0; i < 24; i++)
	{
		DeleteGraph(playerHandle[i]);
	}
	for (int i = 0; i < 8; i++)
	{
		DeleteGraph(smokeHandle[i]);
	}

	DeleteSoundMem(selectSound);
	DeleteSoundMem(cursorSound);
	DeleteSoundMem(fallSound);
	DeleteSoundMem(crashSound);
	DeleteSoundMem(emotionSound);
	DeleteSoundMem(brakeSound);

	DeleteFontToHandle(Font1);
	DeleteFontToHandle(Font2);

	if (RemoveFontResourceEx(font_path, FR_PRIVATE, NULL)) {
	}
	else {
		MessageBox(NULL, "remove failure", "", MB_OK);
	}
}

void SceneClear::init()
{
	textPosX = 200;
	textPosX2 = 200;
	textPosX3 = 200;

	circlePosY = 350;

	emotionFlag[0] = false;
	emotionFlag[1] = false;
	
	Font1 = CreateFontToHandle("KHドット日比谷24", 32, -1, -1);
	Font2 = CreateFontToHandle("KHドット日比谷24", 64, -1, -1);

	selectSound = LoadSoundMem("Data/Sound/select.mp3");
	cursorSound = LoadSoundMem("Data/Sound/cursor.mp3");

	backGround[0] = LoadGraph("Data/Hill1.png");
	backGround[1] = LoadGraph("Data/Hill2.png");
	backGround[2] = LoadGraph("Data/Hill3.png");
	backGround[3] = LoadGraph("Data/Hill4.png");
	backGround[4] = LoadGraph("Data/Hill5.png");
	backGround[5] = LoadGraph("Data/Hill6.png");

	Cavehandle = LoadGraph("Data/Cave.png");

	LoadDivGraph("Data/player.png", 24, 6, 4, 20, 28, playerHandle);

	LoadDivGraph("Data/Smoke.png", 8, 8, 1, 54, 32, smokeHandle);

	LoadDivGraph("Data/emotion1.png", 3, 3, 1, 32, 32, emotionHandle1);
	LoadDivGraph("Data/emotion2.png", 3, 3, 1, 32, 32, emotionHandle2);

	fallSound = LoadSoundMem("Data/Sound/fall.mp3");
	crashSound = LoadSoundMem("Data/Sound/crash.mp3");
	emotionSound = LoadSoundMem("Data/Sound/emotion.mp3");
	brakeSound = LoadSoundMem("Data/Sound/brake.mp3");

	for (int i = 0; i < 6; i++)
	{
		bPosX1[i] = 0;
		bPosX2[i] = 1800;
	}
	CavePosX = 500;
	playerPosX = 500;

	fallPosX = 4000;

	PlayMusic("Data/Sound/clearBGM.mp3", DX_PLAYTYPE_LOOP);

	num = 0;
}

SceneBase* SceneClear::update()
{
	SetVolumeMusic(volume);

	if (in == true)
	{
		if (rgb <= 255 && volume <= 150)
		{
			rgb += 5;
			volume += 3;
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
		volume -= 5;
	}

	if (brightFlag2 == true)
	{
		if (rgb == 0)
		{
			brightFlag2 = false;
			return(new SceneTitle);
		}
		rgb -= 5;
		volume -= 5;
	}

	return this;
}

void SceneClear::draw()
{
	SetDrawBright(rgb, rgb, rgb);
	SetDrawArea(shakeX, shakeY, shakeX + 1800, shakeY + 900);

	if (stopFlag == false)
	{
		Player++;
		if (Player % 3 == 0)
		{
			Player = 0;

			playerAnimation++;
			if (playerAnimation == 14)
			{
				playerAnimation = 12;
			}
		}
	}

	Emotion++;
	if (Emotion % 10 == 0)
	{
		Emotion = 0;

		emotionAnimation++;
		if (emotionAnimation == 3)
		{
			emotionAnimation = 0;
		}
	}

	if (fallFlag == false)
	{
		Smoke++;
		if (Smoke % 5 == 0)
		{
			Smoke = 0;

			smokeAnimation++;
			if (smokeAnimation == 2)
			{
				smokeAnimation = 0;
			}
		}

		bPosX1[0] -= 4;
		bPosX1[1] -= 5;
		bPosX1[2] -= 6;
		bPosX1[3] -= 7;
		bPosX1[4] -= 8;
		bPosX1[5] -= 9;
		CavePosX -= 8;
		fallPosX -= 8;

		for (int i = 0; i < 6; i++)
		{
			if (bPosX1[i] == -1800)
			{
				bPosX1[i] = 1800;
			}
		}

		bPosX2[0] -= 4;
		bPosX2[1] -= 5;
		bPosX2[2] -= 6;
		bPosX2[3] -= 7;
		bPosX2[4] -= 8;
		bPosX2[5] -= 9;

		for (int i = 0; i < 6; i++)
		{
			if (bPosX2[i] == -1800)
			{
				bPosX2[i] = 1800;
			}
		}
	}

	if (fallPosX < 1800)
	{
		emotionFlag[0] = true;
		if (fallPosX < 1000)
		{
			emotionFlag[0] = false;
			stopFlag = true;
			PlaySoundMem(brakeSound, DX_PLAYTYPE_BACK, false);
		}
	}

	if (shakeFlag == true)
	{
		if (soundFlag1 == false)
		{
			PlaySoundMem(fallSound, DX_PLAYTYPE_NORMAL, false);
			soundFlag1 = true;
		}

		shakeX = GetRand(5);
		shakeY = GetRand(5);
		num++;
		if (num >= 10)
		{
			if (soundFlag2 == false)
			{
				PlaySoundMem(crashSound, DX_PLAYTYPE_NORMAL, false);
				StopSound();
				soundFlag2 = true;
			}

			shakeX = 0;
			shakeY = 0;
			shakeFlag = false;
			emotionFlag[1] = true;
		}
	}

	DrawGraph(bPosX1[0] + shakeX, 0 + shakeY, backGround[0], true);
	DrawTurnGraph(bPosX2[0] + shakeX, 0 + shakeY, backGround[0], true);
	DrawGraph(bPosX1[1] + shakeX, 0 + shakeY, backGround[1], true);
	DrawTurnGraph(bPosX2[1] + shakeX, 0 + shakeY, backGround[1], true);
	DrawGraph(bPosX1[2] + shakeX, 0 + shakeY, backGround[2], true);
	DrawTurnGraph(bPosX2[2] + shakeX, 0 + shakeY, backGround[2], true);
	DrawGraph(bPosX1[3] + shakeX, 0 + shakeY, backGround[3], true);
	DrawTurnGraph(bPosX2[3] + shakeX, 0 + shakeY, backGround[3], true);

	DrawBox(CavePosX + 40 + shakeX, 750 + shakeY, CavePosX + 120, 850, GetColor(0, 0, 0), true);
	DrawBox(fallPosX + 40 + shakeX, 750 + shakeY, fallPosX + 120, 850, GetColor(0, 0, 0), true);

	DrawRotaGraph(playerPosX + shakeX, 800 + shakeY, 3.0, 0, playerHandle[playerAnimation], true);	//走るプレイヤー


	if (fallPosX <= 380)
	{
		fallFlag = true;
		shakeFlag = true;
	}

	if (fallPosX >= 1000)
	{
		DrawRotaGraph(playerPosX - 100 + shakeX, 790 + shakeY, 3.0, 0, smokeHandle[smokeAnimation], true, false);	//エフェクト
	}
	if (emotionFlag[0] == true)
	{
		PlaySoundMem(emotionSound, DX_PLAYTYPE_BACK, false);
		DrawRotaGraph(playerPosX, 700, 2.0, 0, emotionHandle1[emotionAnimation], true, false);
	}
	if (emotionFlag[1] == true)
	{
		emotionEX += 0.03;
		if (emotionEX >= 2.0)
		{
			emotionEX = 2.0;
		}
		DrawRotaGraph(playerPosX, 600, emotionEX, 0, emotionHandle2[emotionAnimation], true, false);
	}
	
	DrawGraph(CavePosX - 130 + shakeX, 650 + shakeY, Cavehandle, true);	//出口
	DrawTurnGraph(fallPosX + shakeX, 650 + shakeY, Cavehandle, true); //入口

	DrawGraph(bPosX1[4] + shakeX, 0 + shakeY, backGround[4], true);
	DrawTurnGraph(bPosX2[4] + shakeX, 0 + shakeY, backGround[4], true);
	
	DrawGraph(bPosX1[5] + shakeX, 0 + shakeY, backGround[5], true);
	DrawTurnGraph(bPosX2[5] + shakeX, 0 + shakeY, backGround[5], true);



	DrawStringToHandle(200, 200, "You Are Cave Surviver!!", GetColor(0, 0, 0), Font2);

	DrawCircle(200, circlePosY + 16, 16, GetColor(255, 0, 0), true);
	DrawStringToHandle(textPosX, 350, "もう一度プレイする", GetColor(0, 0, 0), Font1);
	DrawStringToHandle(textPosX2, 400, "タイトルに戻る", GetColor(0, 0, 0), Font1);

	DrawFormatString(200, 500, GetColor(255, 255, 255), "現在 %d", select);

}