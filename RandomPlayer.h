#pragma once

#include "IPlayer.h"

class Board;


class RandomPlayer :
	public IPlayer
{
public:
	RandomPlayer(char);
	~RandomPlayer(void);
	virtual void TakeTurn(Board&);
};

