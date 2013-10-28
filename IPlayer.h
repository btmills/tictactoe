#pragma once

class Board;

class IPlayer
{
public:
	const char Symbol;
	IPlayer(char);
	virtual ~IPlayer(void);
	virtual void TakeTurn(Board&) = 0;
};