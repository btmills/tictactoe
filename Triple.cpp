#include "Triple.h"
#include "Board.h"
#include "IPlayer.h"


Triple::Triple(int first, int second, int third)
{
	squares[0] = first;
	squares[1] = second;
	squares[2] = third;
}

Triple::~Triple(void)
{
}

bool Triple::IsWin(const Board* board) const
{
	IPlayer* player = nullptr;
	for (int i = 0; i < 3; i++)
	{
		if (board->SquareIsEmpty(this->squares[i]))
			return false;
		if (player == nullptr)
		{
			player = board->GetSquarePlayer(this->squares[i]);
		}
		else if(player != board->GetSquarePlayer(this->squares[i]))
		{
			return false;
		}
	}
	return true;
}

IPlayer* Triple::GetWinner(const Board* board) const
{
	if (this->IsWin(board))
		return board->GetSquarePlayer(this->squares[0]);
	return nullptr;
}

Triple* Triple::Create(int start, Orientation orientation)
{
	int first, second, third;

	if (start < 0 || 9 <= start)
		return nullptr;

	if (orientation == Column)
	{
		first = start % 3;
		second = first + 3;
		third = first + 6;
	}
	else if (orientation == Northeast)
	{
		if (start != 2 && start != 4 && start != 6)
			return nullptr;

		first = 2;
		second = 4;
		third = 6;
	}
	else if (orientation == Row)
	{
		first = start - (start % 3);
		second = first + 1;
		third = first + 2;
	}
	else if (orientation == Southeast)
	{
		if (start != 0 && start != 4 && start != 8)
			return nullptr;

		first = 0;
		second = 4;
		third = 8;
	}
	else
	{
		return nullptr;
	}

	return new Triple(first, second, third);
}