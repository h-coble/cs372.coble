#include<iostream>
#include<vector>
#include<iomanip>
#include "AdjListGraph.hpp"

int main()
{
	AdjListGraph<std::vector<int>> graphA;
	std::vector<int> vectorA = { 0,1,2,3,4 };
	std::vector<int> vectorB = { 5,6,7,8,9 };
	std::vector<int> vectorC = { 10 };
	std::vector<int> vectorD = { 20 };
	graphA.addNode(vectorA);
	graphA.addNode(vectorB);
	graphA.addEdge(vectorA, vectorB);
	graphA.addNode(vectorC);
	graphA.addEdge(vectorB, vectorC);
	graphA.addNode(vectorD);
	graphA.addEdge(vectorC, vectorD);

	AdjListGraph<std::vector<int>> graphB = AdjListGraph<std::vector<int>>(graphA); 
	graphA.deleteNode(vectorB);
	graphA.deleteEdge(vectorC, vectorD);
	AdjListGraph<std::vector<int>> graphC;
	graphC = graphA;
	return 0;
}