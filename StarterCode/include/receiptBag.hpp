#pragma once
#include<iostream>
#include "vector.hpp"

template <typename Thing>
class ReceiptBag 
{
private:
	Vector<Thing> itemVec;
	Vector<int> receiptVec;
	int bagSize = 0;
public:
	ReceiptBag()
	{
		bagSize = 0;
	}
	void insert(Thing item)
	{
		itemVec.push_back(item);
		receiptVec.push_back(bagSize);
		std::cout << "Receipt for " << item << " is " << bagSize <<std::endl;
		bagSize++;
	}
	Thing pop()
	{
		Thing item;
		if (itemVec.size() > 0)
		{
			item = itemVec.at(bagSize - 1);
			return item;
			//item = last item in vector
		}
		else
			std::cerr << "Bag is empty and cannot pop an item" << std::endl;
		return bagSize;
	}
	void remove(int receipt)
	{
		int indexFound= -1;
		for (int i = 0; i < bagSize; i++)
		{
			if (receiptVec.at(i) == receipt)
			{
				indexFound = i;
				break;
			}
		}
		if (indexFound >= 0)
		{
			
			for (int i = indexFound; i < bagSize-1; i++)
			{
				receiptVec.put(receiptVec.at(i + 1),i);
				itemVec.put(itemVec.at(i + 1),i);
			}
			receiptVec.shrink();
			itemVec.shrink();
			bagSize -= 1;

		}
		else
		{
			std::cout << "Receipt was not found.\n";
		}
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
			if (itemVec.at(i) == item)
				itemCount++;
		}
		return itemCount;
	}
	void print()
	{
		std::cout"\nBag Contents\n\n";
			std::cout << "Items: ";
			itemVec.traverse();
			std::cout << "Receipts: ";
			receiptVec.traverse();
			std::cout << std::endl;
	}
};