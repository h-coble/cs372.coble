#include<list>
#include<iostream>
template<typename T>
void partitionList(T split,std::list<T>&listParted, std::list<T>* lessPtr, std::list<T>* greaterPtr)
{
	
	for (auto itr = listParted.begin(); itr != listParted.end(); ++itr)
	{
		if (*itr < split)
		{
			lessPtr->push_back(*itr);
		}
		else if(*itr > split)
		{
			greaterPtr->push_back(*itr);
		}
	}

}

template<typename T>
std::list<T>* quicksort(std::list<T>& inputList) {
    //if impossible to be out of order, return a ptr to this list
	if (inputList.size() <= 1) {
        return new std::list<T>(inputList);
    }

    T split = inputList.front();
    std::list<T> lessList, greaterList;
	std::list<T>* lessPtr = &lessList;
	std::list<T>* greaterPtr = &greaterList;
    partitionList(split, inputList, lessPtr, greaterPtr);

    std::list<T>* sortedLess = quicksort(lessList);
    std::list<T>* sortedGreater = quicksort(greaterList);

    sortedLess->push_back(split);
    sortedLess->splice(sortedLess->end(), *sortedGreater);
    delete sortedGreater;
	
    return sortedLess;
}


int main()
{
	std::list<int> test = { 1,0,5,2,3,6,9,8,7,4 };
	std::list<int>* sorted = quicksort(test);
	for (int val : *sorted) 
	{
		std::cout << val << " ";
	}
	return 0;
}