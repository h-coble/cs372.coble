//
// File:   listtest.cpp
// Author: Your Glorious Instructor <adam.lewis@athens.edu>
// Purpose:
// Demonstrate the use of our List class.
//
#include <iostream>
#include "List.hpp"

void printItem(int& item) {
    std::cout << item << " ";
}

int main() {
    SelfAdjustingList<int> aListOfIntegers;

    if (aListOfIntegers.empty()) {
        std::cout << "Yep, the new list is empty." << std::endl;
    }
    for (int i = 3; i >= 0; i--)
    {
        aListOfIntegers.push_front(i);
    }
    aListOfIntegers.traverse(printItem);
    std::cout << std::endl;
    aListOfIntegers.find(2);
    aListOfIntegers.traverse(printItem);
    std::cout << std::endl;
    aListOfIntegers.find(3);
    aListOfIntegers.traverse(printItem);
    std::cout << std::endl;
    aListOfIntegers.find(4);
    aListOfIntegers.traverse(printItem);
    std::cout << std::endl;
    int* findPtr = aListOfIntegers.find(3);
    int findVal = *findPtr;
    std::cout << "De-ref ptr: " << findVal << " = .front() " << aListOfIntegers.front() << std::endl;
    


    return 0;
}
