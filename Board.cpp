#include <iostream>
#include "Board.h"
#include "Square.h"
#include "IPlayer.h"
#include "Triple.h"

using namespace std;


Board::Board(void) :
	lastSquare(-1)
{
	for (int i = 0; i < 9; i++)
	{
		squares[i] = new Square();
	}
}

Board::Board(const Board& other)
{
	this->lastSquare = other.lastSquare;
	for(int i = 0; i < 9; i++)
	{
		this->squares[i] = new Square(*other.squares[i]);
	}
}

Board::~Board(void)
{
	for (int i = 0; i < 9; i++)
	{
		delete squares[i];
	}
}

bool Board::IsFull(void) const
{
	for (int i = 0; i < 9; i++)
	{
		if (this->squares[i]->IsEmpty())
			return false;
	}
	return true;
}

bool Board::SquareIsEmpty(int square) const
{
	return squares[square]->IsEmpty();
}

IPlayer* Board::GetSquarePlayer(int square) const
{
	return squares[square]->Player;
}

void Board::SetSquarePlayer(int square, IPlayer* player)
{
	this->lastSquare = square;
	this->squares[square]->Player = player;
}

void Board::Draw(void) const
{
	int i = 0;

	while (i < 9)
	{
		cout << squares[i]->GetSymbol();

		i++;

		if (i % 3 == 0)
		{
			if (i < 9)
			{
				cout << endl << "-----" << endl;
			}
		}
		else
		{
			cout << '|';
		}
	}

	cout << endl;
}

IPlayer* Board::GetWinner(void) const
{
	// Check all routes through lastSquare for winner
	Triple* triple = Triple::Create(lastSquare, Triple::Column);
	if (triple != nullptr)
	{
		if (triple->IsWin(this))
			return triple->GetWinner(this);
		delete triple;
	}
	triple = Triple::Create(lastSquare, Triple::Northeast);
	if (triple != nullptr)
	{
		if (triple->IsWin(this))
			return triple->GetWinner(this);
		delete triple;
	}
	triple = Triple::Create(lastSquare, Triple::Row);
	if (triple != nullptr)
	{
		if (triple->IsWin(this))
			return triple->GetWinner(this);
		delete triple;
	}
	triple = Triple::Create(lastSquare, Triple::Southeast);
	if (triple != nullptr)
	{
		if (triple->IsWin(this))
			return triple->GetWinner(this);
		delete triple;
	}

	return nullptr;
}
