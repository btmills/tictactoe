#pragma once

class Board;
class IPlayer;

class Triple
{
private:
	int squares[3];
public:
	enum Orientation
	{
		Column,
		Northeast,
		Row,
		Southeast
	};

	Triple(int, int, int);
	~Triple(void);

	bool IsWin(const Board*) const;
	IPlayer* GetWinner(const Board*) const;

	static Triple* Create(int, Orientation);
};
