#pragma once

class player;
class enemy;
class torch;
class money;

class ScoreBoard
{
public:
	ScoreBoard();
	~ScoreBoard();
	
	void init();
	void update();
	void draw(player& Player, enemy& Enemy, torch &Torch);

private:
	int boardPosX;
	int boardPosY;
};

