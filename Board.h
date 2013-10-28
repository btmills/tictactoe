#pragma once

class IPlayer;
class Square;

class Board
{
private:
	int lastSquare;
	Square* squares[9];
public:
	Board(void);
	Board(const Board&);
	~Board(void);
	void Draw(void) const;
	bool IsFull(void) const;
	bool SquareIsEmpty(int) const;
	IPlayer* GetSquarePlayer(int) const;
	void SetSquarePlayer(int, IPlayer*);
	IPlayer* GetWinner(void) const;
};