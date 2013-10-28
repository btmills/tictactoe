#include <cstdlib>
#include <time.h>
#include "RandomPlayer.h"
#include "Board.h"


RandomPlayer::RandomPlayer(char symbol)
	: IPlayer(symbol)
{
	srand(time(NULL));
}


RandomPlayer::~RandomPlayer(void)
{
}

void RandomPlayer::TakeTurn(Board& board)
{
	int square;
	do
	{
		square = rand() % 9;
	}
	while (!board.SquareIsEmpty(square));
	board.SetSquarePlayer(square, this);
}
