#include"vectorRace.hpp"
#include<iostream>

int main()
{
	vecRace race;
	int count = 0;
	char choice = 'a';
	do
	{
		for (int i = 0; i < 100000; i++)
		{
			double time1 = race.timeSTL();
			double time2 = race.timeMine();
			std::cout << "\nTime for STL push_back #" << ++count << " in seconds: " << time1 << std::endl;
			std::cout << "Time for my vector push_back #" << count << " in seconds: " << time2 << std::endl;
			if (time1 < time2)
				system("pause");
		}
		std::cout << "Enter N to exit or any other character to push 50x again: ";
		std::cin >> choice;
	} while (choice != 'N');
	race.printLast();
	return 7;
}