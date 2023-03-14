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
    List<int> aListOfIntegers;

    if (aListOfIntegers.empty()) {
        std::cout << "Yep, the new list is empty." << std::endl;
    }
    for (int i = 3; i >= 0; i--)
    {
        aListOfIntegers.push_front(i);
    }
    aListOfIntegers.traverse(printItem);
    std::cout << std::endl;

    aListOfIntegers.pop_front();
    aListOfIntegers.traverse(printItem);
    std::cout << std::endl;
    
    aListOfIntegers.displayNodeStats();
    std::cout << std::endl;

    aListOfIntegers.freeLazy();

    aListOfIntegers.displayNodeStats();
    std::cout << std::endl;

    return 0;
}
