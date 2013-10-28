#include <algorithm>
#include <list>
#include <stdlib.h>
#include <utility>
#include "ComputerPlayer.h"
#include "Board.h"

using namespace std;


ComputerPlayer::ComputerPlayer(char symbol) :
	IPlayer(symbol)
{
}


ComputerPlayer::~ComputerPlayer(void)
{
}

ComputerPlayer::Outcome ComputerPlayer::fork(Board& board, int square, IPlayer* player)
{
	// Make move
	Board copy = Board(board);
	copy.SetSquarePlayer(square, player);

	// Check for end conditions
	if (copy.GetWinner() == this) // Player win
		return Outcome(square, 1);
	if (copy.GetWinner() == this->opponent) // Player lose
		return Outcome(square, -1);
	if (copy.IsFull()) // Tie
		return Outcome(square, 0);

	// Predict opponent's responses and resulting effects
	list<Outcome> outcomes;
	for (int i = 0; i < 9; i++)
	{
		if (copy.SquareIsEmpty(i))
		{
			outcomes.push_back(this->fork(copy, i, (player == this ? this->opponent : this)));

			// Optimization: short-circuit if extreme value already reached
			// See logic below
			if (player == this)
			{
				if (outcomes.back().score == -1)
					return Outcome(square, -1);
			}
			else
			{
				if (outcomes.back().score == 1)
					return Outcome(square, 1);
			}
		}
	}

	// Evaluate options to make choice
	Outcome choice = outcomes.front();
	for (list<Outcome>::iterator it = outcomes.begin(); it != outcomes.end(); it++)
	{
		if (player == this) // Assume opponent chooses my worst possible outcome
		{
			if (it->score < choice.score)
				choice = *it;
		}
		else // Assume AI chooses its own best possible outcome
		{
			if (it->score > choice.score)
				choice = *it;
		}
	}
	return Outcome(square, choice.score);
}

int ComputerPlayer::chooseSquare(Board& board)
{
	Board copy = Board(board);

	// Replace real opponent squares with fake opponent
	if (this->opponent == nullptr)
		this->opponent = new ComputerPlayer(this->Symbol == 'X' ? 'O' : 'X');
	for (int i = 0; i < 9; i++)
	{
		if (!copy.SquareIsEmpty(i) && copy.GetSquarePlayer(i) != this)
			copy.SetSquarePlayer(i, this->opponent);
	}

	// Evaluate all possible moves
	list<Outcome> outcomes;
	for (int i = 0; i < 9; i++)
	{
		if (copy.SquareIsEmpty(i))
			outcomes.push_back(this->fork(copy, i, this));
	}

	// Maximize my minimum outcome
	Outcome move = outcomes.front();
	for (list<Outcome>::iterator it = outcomes.begin(); it != outcomes.end(); it++)
	{
		if (it->score > move.score)
			move = *it;
	}
	return move.square;
}

void ComputerPlayer::TakeTurn(Board& board)
{
	board.SetSquarePlayer(this->chooseSquare(board), this);
}