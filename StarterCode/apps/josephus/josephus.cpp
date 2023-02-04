#include"queue.hpp"
#include<iostream>
#include<string>
#include"stack.hpp"

using std::cin;
using std::cout;

//queue<std::string> setUpGame(int& elim, int& players);
//void playRound(std::queue<std::string> &game, int elim, int& players);

int main()
{
	Queue<std::string> game;
	Stack<std::string> tempGame;
	int elim = -1, players = 0;
	do
	{
		do
		{
			cout << "Enter the number of players (greater than 0): ";
			cin >> players;
			cout << "Enter a non-negative number of positions to move before elimination: ";
			cin >> elim;
			if (elim < 0 || players <= 0)
			{
				cout << "One or more of your entries are invalid; try again.\n\n";
			}
			else
				break;
		} while (true);

		

		for (int x = 0; x < players; x++)
		{
			game.push("Player " + std::to_string(x + 1));
		}

		while (game.size() > 1)
		{
			for (int x = 0; x <= elim % players; x++)		//elim%players ensures we elim the right player
			{											//if m > n as written in instructions, m(MOD)n positions will be moved through
				if (x != elim % players)
					tempGame.push(game.front());		//save to stack to replace
				else
					cout << game.front() << " was eliminated.\n";
				game.pop();								//remove to get to elimination
			}
			while (!tempGame.empty())
			{
				game.push(tempGame.top());			//move to end of queue to properly count for elimination next round if relevant
				tempGame.pop();						//remove from stack
			}
		}

		if (game.size() == 1)
		{
			cout << std::endl << game.front() << " is the winner.\nPlay again?\n0 for no, any other value for yes: ";
			cin >> players;
		}
		game.pop();
	} while (players != 0);
	cout << std::endl;

	return 0;
}
