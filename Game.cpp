#include <iostream>
#include "Board.h"
#include "Game.h"
#include "IPlayer.h"

using namespace std;


Game::Game(IPlayer* crosses, IPlayer* noughts) :
	crossesPlayer(crosses),
	noughtsPlayer(noughts),
	board(new Board())
{
}

Game::~Game(void)
{
	delete this->crossesPlayer;
	delete this->noughtsPlayer;
	delete this->board;
}

void Game::Run(void)
{
	IPlayer* winner = nullptr;
	IPlayer* players[2];
	players[0] = this->crossesPlayer;
	players[1] = this->noughtsPlayer;
	int turn = 0;

	while ((winner = this->board->GetWinner()) == nullptr && !this->board->IsFull())
	{
		players[turn++ % 2]->TakeTurn(*this->board);
	}

	this->board->Draw();

	if (winner == nullptr)
		cout << "Tie game." << endl;
	else
		cout << "Congrats to " << this->board->GetWinner()->Symbol << "s!" << endl;
}