#include<fstream>
#include"stack.hpp"
#include<iostream>
#include<string>


using std::cout;
using std::endl;

int main()
{
	Stack<int>strSizes;			//Stores the length of each line; used to accurately place a new line
	Stack<char> sentences;		//Stores the characters of each line/entire file
	std::ifstream inFile;		
	std::ofstream outFile;
	std::string str;			//temporary string used to get each line from a file and store the characters in a stack

	inFile.open("char.txt");
	if (!inFile.is_open())
	{
		cout << "File not found\n";
		return 1;
	}
	else
	{
		while (!inFile.eof())
		{
			getline(inFile, str);
			strSizes.push(str.size());

			for (int y = 0; y < strSizes.top(); y++)
				sentences.push(str[y]);
		}
		inFile.close();
	}
	outFile.open("txt.rahc");
	int y = 0;
	while(!strSizes.empty())		
	{
		y = strSizes.top();
		for (y; y > 0; y--)
		{
			outFile << sentences.top();
			cout << sentences.top();
			sentences.pop();
		}
		cout << endl;
		outFile << endl;
		strSizes.pop();
	}

	return 0;
}