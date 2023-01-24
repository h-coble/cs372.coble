#pragma once
#include<iostream>
#include "vector.hpp"

template <typename Thing>
class Bag 
{
private:
	Vector<Thing> bagVec;
	int bagSize = 0;
public:
	Bag()
	{
		//Vector<Thing> bagVec;
		bagSize = 0;
	}
	void insert(Thing item)
	{
		bagVec.push_back(item);
		bagSize++;		
	}
	Thing pop()
	{
		Thing item;
		if (bagVec.size() > 0)
		{
			item = bagVec.at(bagSize - 1);
			return item;
			//item = last item in vector
		}
		else
			std::cerr << "Bag is empty and cannot pop an item" << std::endl;
		return bagSize;
	}
	int size()
	{
		return bagSize;
	}
	int count(Thing item)
	{
		int itemCount = 0;
		for (int i = 0; i < bagSize; i++)
		{
			if (bagVec.at(i) == item)
				itemCount++;
		}
		return itemCount;
	}
};