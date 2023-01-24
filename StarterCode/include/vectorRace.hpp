#pragma once
#include <vector>
#include<chrono>
#include "vector.hpp"

class vecRace
{
public:
	vecRace();
	~vecRace();
	double timeSTL()
	{
		auto start = std::chrono::steady_clock::now();
		stlVec.push_back(stlVec.size());
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - start;
		return elapsed_seconds.count();
	}
	double timeMine();
	void printLast()
	{
		std::cout << "STL: " << stlVec.back() << std::endl;
		std::cout << "Mine: " << myVec.at(myVec.size() - 1);
	}
private:
	std::vector<int> stlVec;
	Vector<int> myVec;

	void fillSTL()
	{
		for (int i = 0; i < stlVec.size(); i++)
			stlVec[i] = i;
	}

	void fillMine()
	{
		for (int i = 0; i < myVec.size(); i++)
		{
			myVec.put(i, i);
		}
	}
};

vecRace::vecRace()
{
	this->fillMine();
	this->fillSTL();
}

vecRace::~vecRace()
{
}
double vecRace::timeMine()
{
	auto start = std::chrono::steady_clock::now();
	myVec.push_back(myVec.size());
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	return elapsed_seconds.count();
};