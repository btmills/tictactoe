#pragma once

class IPlayer;
class Board;

class Game
{
private:
	Board* board;
	IPlayer* crossesPlayer;
	IPlayer* noughtsPlayer;

public:
	Game(IPlayer*, IPlayer*);
	~Game(void);
	void Run(void);
};