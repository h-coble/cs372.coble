#include"queue.hpp"
#include<iostream>
#include<string>
#include"stack.hpp"

bool equalParens(std::string entry)
{
	
	Stack<char> syntaxChecker;
	//Pushing and popping only checks for missing parens
	// Because of this, to check for extra, the process is repeated,
	// pushing and popping the opposite of what the first iteration does
	
	//Check for missing ')'
	for (int i = 0; i < entry.length(); i++)
	{
		if (entry[i] == '(')
			syntaxChecker.push(entry[i]);
		else if (entry[i] == ')')
			syntaxChecker.pop();
	}
	if (!syntaxChecker.empty())			//If failed, return false
		return syntaxChecker.empty();
	else
		for (int i = entry.length() - 1; i >= 0; i--)	//Check for extra ')' 
		{
			if (entry[i] == ')')
				syntaxChecker.push(entry[i]);
			else if (entry[i] == '(')
				syntaxChecker.pop();
		}
	return syntaxChecker.empty();		//Return result
}

int main()
{
	std::string entry;

	
	getline(std::cin, entry);

	if (equalParens(entry))
		std::cout << "No extra parenthesis found.\n";
	else
		std::cout << "There is an extra or missing parenthesis.\n";
	return 0;
}

