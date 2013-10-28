#pragma once

class IPlayer;

class Square
{
public:
	IPlayer* Player;
	Square(void);
	~Square(void);
	bool IsEmpty(void) const;
	char GetSymbol(void) const;
};