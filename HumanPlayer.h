#pragma once

#include "IPlayer.h"

class HumanPlayer :
	public IPlayer
{
public:
	HumanPlayer(char);
	~HumanPlayer(void);
	void TakeTurn(Board&);
};