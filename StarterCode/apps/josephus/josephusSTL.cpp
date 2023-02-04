#include<queue>
#include<iostream>
#include<string>
#include<stack>

using std::cin;
using std::cout;

std::queue<std::string> setUpGame(int& elim, int& players);
void playRound(std::queue<std::string> &game, int elim, int& players);

int main()
{
	int elim = -1, players = 0;
	do
	{
		std::queue<std::string> game = setUpGame(elim, players);
		while (game.size() > 1)
		{
			playRound(game, elim, players);
		}
		if (game.size() == 1)
		{
			cout << std::endl << game.front() << " is the winner.\nPlay again?\n0 for no, any other value for yes: ";
			cin >> players;
		}
	} while (players != 0);
	cout << std::endl;
	return 0;
}

std::queue<std::string> setUpGame(int& elim, int& players)
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
	
	std::queue<std::string> game;

	for (int x=0; x < players; x++)
	{
		game.push("Player " + std::to_string(x+1));
	}

	return game;
}

void playRound(std::queue<std::string> &game, int elim, int& players)
{
	std::stack<std::string>gameReturn;
	for (int x = 0; x <= elim%players; x++)		//elim%players ensures we elim the right player
	{											//if m > n as written in instructions, m(MOD)n positions will be moved through
		if (x != elim % players)
			gameReturn.push(game.front());		//save to stack to replace
		else
			cout << game.front() << " was eliminated.\n";
		game.pop();								//remove to get to elimination
	}
	while(!gameReturn.empty())
	{
		game.push(gameReturn.top());			//move to end of queue to properly count for elimination next round if relevant
		gameReturn.pop();						//remove from stack
	}
	players--;
}