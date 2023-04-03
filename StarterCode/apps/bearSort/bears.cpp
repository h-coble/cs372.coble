#include<iostream>

bool bears(int initial, int inc, int n, int goal)
{
	//std::cout << "Values for this step: initial, inc, n, goal" << std::endl
	//	<< initial << " " << inc << " " << n << " " << goal << std::endl;
	//
	// Commented out; was used in debugging to check the values on each iteration.
	//Included in submission in case seeing "yes/no" was not sufficient.

	if (n >= 0 && initial == goal)
	{ 
		std::cout << "It is possible to reach " << goal << " in this number of steps.\n\n";
		return true;
	}
	else if (n > 0)
	{
		if (initial % 2 == 0)
		{
			initial /= 2;
			n--;
			return bears(initial, inc, n, goal);
		}
		else
		{
			initial += inc;
			n--;
			return bears(initial, inc, n, goal);
		}
	}
	else
	{
		std::cout << "It is not possible to reach " << goal << " in this number of steps.\n\n";
		return false;
	}
}


int main()
{
	std::cout << "initial = 19\n"
		<< "increment = 3\n"
		<< "n = 15\n"
		<< "goal = 14\n";
	bool won = bears(19, 3, 15, 14);

	std::cout << "initial = 1\n"
		<< "increment = 21\n"
		<< "n = 15\n"
		<< "goal = 43\n";

	won = bears(1, 21, 15, 43);
}