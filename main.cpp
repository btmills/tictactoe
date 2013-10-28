//#include <conio.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "Game.h"
#include "IPlayer.h"
#include "ComputerPlayer.h"
#include "HumanPlayer.h"
#include "RandomPlayer.h"

using namespace std;


int main(int argc, char* argv[])
{
	char pieces[2] = { 'X', 'O' };

	IPlayer* players[2] = { nullptr, nullptr };

	vector<string> playerTypes;
	playerTypes.push_back("Human");
	playerTypes.push_back("Computer");
	playerTypes.push_back("Random");

	for (int i = 0; i < 2; i++)
	{
		unsigned int input;
		char piece = pieces[i];

		cout << "Choose an " << piece << "s player:" << endl;
		do
		{
			int count;
			vector<string>::iterator it;
			for (count = 0, it = playerTypes.begin(); it != playerTypes.end(); count++, it++)
			{
				cout << count + 1 << ". " << *it << endl;
			}
			cin >> input;
		}
		while (!(1 <= input && input <= playerTypes.size()));

		IPlayer* player;
		string choice = playerTypes.at(input - 1);

		if (choice == "Human")
			player = new HumanPlayer(piece);
		else if (choice == "Computer")
			player = new ComputerPlayer(piece);
		else // Default to "Random" player
			player = new RandomPlayer(piece);

		players[i] = player;
	}

	Game game = Game(players[0], players[1]);
	cout << endl << "Let's play!" << endl;
	game.Run();

	cout << "Press any key to exit." << endl;
	getchar();

	return 0;
}
