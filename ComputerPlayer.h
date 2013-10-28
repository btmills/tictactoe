#pragma once

#include <utility>
#include "IPlayer.h"


class ComputerPlayer :
	public IPlayer
{
private:
	struct Outcome
	{
		int square;
		int score;

		Outcome(int square, int score) :
			square(square),
			score(score)
		{}
	};

	IPlayer* opponent;
	
	// Helpers
	int chooseSquare(Board&);
	Outcome fork(Board&, int, IPlayer*);

public:
	// Constructor
	ComputerPlayer(char);
	~ComputerPlayer(void);

	// Methods
	void TakeTurn(Board&);
};

