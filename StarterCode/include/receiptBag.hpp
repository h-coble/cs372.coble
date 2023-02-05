#pragma once
#include<iostream>
#include "list.hpp"

template <typename Thing>
class ReceiptBag 
{
private:
	struct reciptBagItem
	{
		Thing itemData;
		int itemReceipt
	};
	//Vector<Thing> itemVec;
	//Vector<int> receiptVec;
	List<receiptBagItem> bagList;
	int bagSize = 0;
public:
	ReceiptBag()
	{
		bagSize = 0;
	}
	void insert(Thing item)
	{
		receiptBagItem temp;
		temp.itemData = item;
		temp.itemReceipt = bagSize;
		std::cout << "Receipt for " << item << " is " << bagSize <<std::endl;
		bagList.push_back(temp);
		bagSize++;
	}
	Thing pop()
	{
		Thing item;
		if (bagList.getSize() > 0)
		{
			item = bagList.back();
			return item;
			//item = last item in container
		}
		else
			std::cerr << "Bag is empty and cannot pop an item" << std::endl;
		return bagSize;
	}
	void remove(int receipt)
	{
		int indexFound = -1;
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

			for (int i = indexFound; i < bagSize - 1; i++)
			{
				receiptVec.put(receiptVec.at(i + 1), i);
				itemVec.put(itemVec.at(i + 1), i);
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