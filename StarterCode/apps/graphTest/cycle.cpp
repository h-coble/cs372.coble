#include<iostream>
#include<fstream>
#include<sstream>
#include<list>
#include<iomanip>
#include "AdjListGraph.hpp"
//#include "AdjMatrixGraph.hpp"

void visit(int aNode)
{
	std::cout << aNode << " ";
};

bool hasCycle(std::string path, AdjListGraph<int> graph)
{
	std::stringstream pathStream;
	pathStream.str(path);
	int source, dest;
	std::vector<int> visited;

	pathStream >> source >> dest;
	visited.push_back(source);
	visited.push_back(dest);
	
	if (!graph.adjacent(source, dest))
	{
		std::cout << "Invalid path.\n";
		return false;
	}
	else if (source == dest)
	{
		std::cout << "There is a cycle in the path: \"" << path << "\"\n";
		return false;
	}
	else
	{
		source = dest;
		while (pathStream >> dest)
		{	
			if (!graph.adjacent(source, dest))
			{
				std::cout << "Invalid path.\n";
				return false;
			}
			else
			{
				for (int x = 0; x < visited.size(); x++)
				{
					if (visited[x] == dest)
					{
						std::cout << "There is a cycle in the path: \"" << path << "\"\n";
						return true;		//per instructions, this checks for "a cycle" and not all/multiple cycles. If one is found, returns true.
					}
					else
					{
						visited.push_back(dest);
						source = dest;
					}
				}
			}
		}
		std::cout << "There is no cycle in the path: \"" << path << "\"\n";
		return false;
	}

}

int main()
{
	//Open File
	std::ifstream fileIn;
	fileIn.open("directedGraph.txt");		//In my project, this is located at "... / out / build / x64 - Debug
											//Sample data from instructions was used, and a copy is in graphTest

	if (!fileIn.is_open())
		return 1;


	//Variables===========================
	std::string tempString;
	std::stringstream nodeEdgeLine;
	int source, dest;
	
	//Graph=Creation======================
	AdjListGraph<int> txtGraph;

	while (std::getline(fileIn, tempString))
	{
		nodeEdgeLine.str(tempString);
		nodeEdgeLine.clear();
		nodeEdgeLine >> source;
		txtGraph.addNode(source);			//Needed for first iteration, shouldn't create dupes on further iterations

		while (nodeEdgeLine >> dest)
		{
			txtGraph.addEdge(source, dest);		//Creates dest node if it doesn't exist, so only original source must be explicitly created
		}
	}
	fileIn.close();


	//Cycle Checking======================
	std::cout << "Enter a path of integers, each separated by a space: ";
	std::getline(std::cin, tempString);

	hasCycle(tempString, txtGraph);

	return 0;

}