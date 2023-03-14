#include<iostream>
#include<vector>
#include<iomanip>
#include "AdjListGraph.hpp"
//#include "AdjMatrixGraph.hpp"
void visit(std::vector<int> aNode)
{
	for (int i = 0; i < aNode.size(); i++)
		std::cout << aNode[i] << "  ";
	std::cout << std::endl;
};
int main()
{
	AdjListGraph<std::vector<int>> graphA;
	std::vector<int> vectorA = { 0,1,2,3,4 };
	std::vector<int> vectorB = { 5,6,7,8,9 };
	std::vector<int> vectorC = { 10 };
	std::vector<int> vectorD = { 20 };

	std::vector<std::vector<int>> neighbors;
	graphA.addNode(vectorA);
	graphA.addNode(vectorB);
	graphA.addEdge(vectorA, vectorB);
	graphA.addNode(vectorC);
	graphA.addEdge(vectorB, vectorC);
	graphA.addNode(vectorD);
	graphA.addEdge(vectorC, vectorD);
	

	graphA.dfs(vectorA, visit);
	std::cout << std::endl << std::endl;
	graphA.bfs(vectorA, visit);
	AdjListGraph<std::vector<int>> graphB = AdjListGraph<std::vector<int>>(graphA); 

	std::cout << "A";
	std::cout << std::endl << graphA.adjacent(vectorA, vectorB) << "\t\t";
	std::cout << graphA.adjacent(vectorA, vectorC) << std::endl;


	neighbors = graphA.neighbors(vectorC);
	std::cout << std::endl;
	for (int x = 0; x < neighbors.size(); x++)
	{
		for (int y = 0; y < neighbors[x].size(); y++)
		{
			std::cout << neighbors[x][y] << "   ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	graphA.deleteNode(vectorB);
	graphA.deleteEdge(vectorC, vectorD);
	AdjListGraph<std::vector<int>> graphC;
	graphC = graphA;



	return 0;
}