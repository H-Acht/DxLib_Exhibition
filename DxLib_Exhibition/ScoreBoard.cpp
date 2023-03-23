#include "ScoreBoard.h"
#include "game.h"

#include "player.h"
#include "enemy.h"
#include "torch.h"

ScoreBoard::ScoreBoard() :
	boardPosX(),
	boardPosY(),
	stickHandle(),
	buttonHandle(),
	shotHandle(),
	bombHandle(),
	Button(0),
	aButtonAnimation(0),
	bButtonAnimation(0),
	Stick(0),
	stickAnimation(0),
	Shot(0),
	shotAnimation(0),
	Bomb(0),
	bombAnimation(0),
	Font1(0),
	Font2(0),
	Font3(0),
	HPHandle(0),
	emptyHPHandle(0),
	extend(0),
	HP(0),
	hpAnimation(0),
	Level(0),
	a(),
	m_bPosX(),
	m_bPosY(),
	bPI(),
	bombFlag(false),
	numHandle()
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

ScoreBoard::~ScoreBoard()
{
	for (int i = 0; i < 21; i++)
	{
		DeleteGraph(shotHandle[i]);
	}
	for (int i = 0; i < 45; i++)
	{
		DeleteGraph(bombHandle[i]);
	}
	for (int i = 0; i < 12; i++)
	{
		DeleteGraph(buttonHandle[i]);
	}
	for (int i = 0; i < 28; i++)
	{
		DeleteGraph(stickHandle[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		DeleteGraph(numHandle[i]);
	}

	DeleteGraph(HPHandle);
	DeleteGraph(emptyHPHandle);

	DeleteFontToHandle(Font1);
	DeleteFontToHandle(Font2);

	if (RemoveFontResourceEx(font_path, FR_PRIVATE, NULL)) {
	}
	else {
		MessageBox(NULL, "remove failure", "", MB_OK);
	}

}

void ScoreBoard::init()
{
	boardPosX = 500;
	boardPosY = 900;

	extend = 1.0;

	for (int i = 0; i < 8; i++)
	{
		m_bPosX[i] = 400;
		m_bPosY[i] = 450;
	}

	LoadDivGraph("Data/Button.png", 12, 3, 4, 16, 16, buttonHandle);
	LoadDivGraph("Data/Stick.png", 28, 3, 10, 16, 16, stickHandle);

	LoadDivGraph("Data/ShotEffect.png", 21, 21, 1, 100, 100, shotHandle);
	LoadDivGraph("Data/BombEffect.png", 45, 45, 1, 64, 64, bombHandle);

	LoadDivGraph("Data/numFont.png", 10, 10, 1, 16, 16, numHandle);

	HPHandle = LoadGraph("Data/HP.png");
	emptyHPHandle = LoadGraph("Data/emptyHP.png");

	Font1 = CreateFontToHandle("KHドット日比谷24", 32, -1, -1);
	Font2 = CreateFontToHandle("KHドット日比谷24", 48, -1, -1);
	Font3 = CreateFontToHandle("KHドット日比谷24", 64, -1, -1);

}

void ScoreBoard::update()
{
	if (bombFlag == false)
	{
		bombFlag = true;
	}
	else if (bombFlag == true)
	{
		m_bPosY[0] -= 1;
		bPI[0] = 4.7;

		m_bPosY[1] += 1;
		bPI[1] = 1.5;

		m_bPosX[2] -= 1;
		bPI[2] = 3.14;

		m_bPosX[3] += 1;
		bPI[3] = 0;

		m_bPosX[4] += 1;
		m_bPosY[4] -= 0.818;
		bPI[4] = 5.3;

		m_bPosX[5] += 1;
		m_bPosY[5] += 0.818;
		bPI[5] = 0.7;

		m_bPosX[6] -= 1;
		m_bPosY[6] += 0.818;
		bPI[6] = 2.3;

		m_bPosX[7] -= 1;
		m_bPosY[7] -= 0.818;
		bPI[7] = 3.7;
	}
	for (int b = 0; b < 8; b++)
	{
		if (m_bPosY[b] > 500 || m_bPosY[b] < 400  ||
			m_bPosX[b] > 450 || m_bPosX[b] < 350)
		{
			m_bPosX[b] = 400;
			m_bPosY[b] = 450;
		
			bombFlag = false;
		}
	}
}

void ScoreBoard::draw(player& Player, enemy& Enemy, torch& Torch)
{
	DrawBox(0, 0, boardPosX, boardPosY, GetColor(100, 100, 100), true);

#ifdef _DEBUG

	DrawFormatString(20, 20, GetColor(255, 255, 255), "direction = %d", Player.prev);

	if (Player.prev == 0)
	{
		DrawString(20, 40, "上", GetColor(255, 255, 255), true);
	}
	else if (Player.prev == 1)
	{
		DrawString(20, 40, "下", GetColor(255, 255, 255), true);
	}
	else if (Player.prev == 2)
	{
		DrawString(20, 40, "左", GetColor(255, 255, 255), true);
	}
	else if (Player.prev == 3)
	{
		DrawString(20, 40, "右", GetColor(255, 255, 255), true);
	}
	else if (Player.prev == 4)
	{
		DrawString(20, 40, "右上", GetColor(255, 255, 255), true);
	}
	else if (Player.prev == 5)
	{
		DrawString(20, 40, "右下", GetColor(255, 255, 255), true);
	}
	else if (Player.prev == 6)
	{
		DrawString(20, 40, "左下", GetColor(255, 255, 255), true);
	}
	else if (Player.prev == 7)
	{
		DrawString(20, 40, "左上", GetColor(255, 255, 255), true);
	}

	DrawFormatString(20, 60, GetColor(255, 255, 255), "HP = %d", Player.pHP);

	DrawFormatString(20, 80, GetColor(255, 255, 255), "eDirection[0] = %d", Enemy.eDirection[0]);

	DrawFormatString(20, 100, GetColor(255, 255, 255), "eDirection[1] = %d", Enemy.eDirection[1]);

	DrawFormatString(20, 120, GetColor(255, 255, 255), "撃破数 = %d", Enemy.deadCount);

	DrawFormatString(20, 140, GetColor(255, 255, 255), "松明 = %d", Torch.torchCount);

	DrawFormatString(20, 160, GetColor(255, 255, 255), "ボム = %d", Player.remainingBomb);

	DrawFormatString(20, 180, GetColor(255, 255, 255), "RGB = %d, %d, %d", Torch.R, Torch.G, Torch.B);

	DrawFormatStringToHandle(200, 800, GetColor(255, 0, 0), Font1, "HP -> %d", Player.pHP);

#endif

	Stick++;
	if (Stick % 5 == 0)
	{
		Stick = 0;
		stickAnimation++;
		if (stickAnimation == 27)
		{
			stickAnimation = 12;
		}
	}

	Shot++;
	if (Shot % 2 == 0)
	{
		shotAnimation++;
		if (shotAnimation == 21)
		{
			shotAnimation = 0;
		}
		Shot = 0;
	}

	Bomb++;
	if (Bomb % 2 == 0)
	{
		bombAnimation++;
		if (bombAnimation == 45)
		{
			bombAnimation = 0;
		}
		Bomb = 0;
	}
	
	HP++;
	if (HP % 2 == 0)
	{
		hpAnimation++;
		extend = 1.0;
		if (hpAnimation == 10)
		{
			extend = 1.2;
		}
		else if (hpAnimation == 13)
		{
			extend = 0.7;
		}
		else if (hpAnimation == 15)
		{
			extend = 1.0;
			hpAnimation = 0;
		}
		HP = 0;
	}

	a[0] = (Enemy.deadCount % 10); 
	a[1] = ((Enemy.deadCount / 10) % 10);
	a[2] = ((Enemy.deadCount / 100) % 10);

	DrawStringToHandle(150, 100, "撃破数", GetColor(0, 0, 0), Font3);
	DrawRotaGraph(180, 200, 4.0, 0, numHandle[a[2]], true, false);
	DrawRotaGraph(240, 200, 4.0, 0, numHandle[a[1]], true, false);
	DrawRotaGraph(300, 200, 4.0, 0, numHandle[a[0]], true, false);

	DrawStringToHandle(120, 300, "目標 150体", GetColor(0, 0, 0), Font2);

	DrawFormatStringToHandle(170, 360, GetColor(0, 0, 0), Font1, "レベル%d", Level);

	//DrawBox(20, 450, 180, 600, GetColor(255, 0, 0), true);
	DrawRotaGraph(100, 490, 1.0, 0, shotHandle[shotAnimation], true, false); //ショットアニメーション
	DrawRotaGraph(100, 550, 3.0, 0, buttonHandle[0], true, false);	//Aボタン

	if (bombFlag = true)
	{
		for (int i = 0; i < 8; i++)
		{
			DrawRotaGraph(m_bPosX[i], m_bPosY[i], 0.3, bPI[i], bombHandle[bombAnimation], true, false); //ボムアニメーション
		}
	}

	DrawRotaGraph(400, 550, 3.0, 0, buttonHandle[3], true, false);	//Bボタン
	DrawRotaGraph(395, 620, 4.0, 0, numHandle[Player.remainingBomb], true, false); //ボム数
	
	if (Player.pHP == 3)
	{
		DrawRotaGraph(150 - 48, 800, extend, 0, HPHandle, true, false);
		DrawRotaGraph(300 - 48, 800, extend, 0, HPHandle, true, false);
		DrawRotaGraph(450 - 48, 800, extend, 0, HPHandle, true, false);
	}
	else if (Player.pHP == 2)
	{
		DrawRotaGraph(150 - 48, 800, extend, 0, HPHandle, true, false);
		DrawRotaGraph(300 - 48, 800, extend, 0, HPHandle, true, false);
		DrawRotaGraph(450 - 48, 800, 1.0, 0, emptyHPHandle, true, false);
	}
	else if (Player.pHP == 1)
	{
		DrawRotaGraph(150 - 48, 800, extend, 0, HPHandle, true, false);
		DrawRotaGraph(300 - 48, 800, 1.0, 0, emptyHPHandle, true, false);
		DrawRotaGraph(450 - 48, 800, 1.0, 0, emptyHPHandle, true, false);
	}
}
