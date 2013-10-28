#include <iostream>
#include "HumanPlayer.h"
#include "Board.h"

using namespace std;


HumanPlayer::HumanPlayer(char symbol)
	: IPlayer(symbol)
{
}


HumanPlayer::~HumanPlayer(void)
{
}

void HumanPlayer::TakeTurn(Board& board)
{
	int square = -1;

	board.Draw();
	cout << "Go " << this->Symbol << "s. Which square? ";
	cin >> square;
	square--;

	while (square < 0 || 9 <= square || !board.SquareIsEmpty(square))
	{
		board.Draw();
		cout << "Square is occupied." << endl;
		cout << "Go " << this->Symbol << "s. Which square? ";
		cin >> square;
		square--;
	}

	board.SetSquarePlayer(square, this);
}