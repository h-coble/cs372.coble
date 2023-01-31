//
// File:   listtest.cpp
// Author: Your Glorious Instructor <adam.lewis@athens.edu>
// Purpose:
// Demonstrate the use of our List class.
//
#include <iostream>
#include "List.hpp"

void printItem(int &item) {
  std::cout << item << " ";
}

int main() {
  List<int> aListOfIntegers;
  List<int> anotherListOfIntegers;
  

  if (aListOfIntegers.empty()) {
    std::cout << "Yep, the new list is empty. " << std::endl;
  }
  for (int i = 3; i >= 0; i--) 
  {
    aListOfIntegers.push_front(i);
  }
  aListOfIntegers.traverse(printItem);

  std::cout << std::endl;

  std::cout << "Test iterators: Mutable -> ";
  for (auto iter = aListOfIntegers.begin();
            iter != aListOfIntegers.end();
            ++iter) {
              std::cout << *iter << " ";
            }
  std::cout << "\nTest iterators: Mutable r -> ";
  for (auto iter = aListOfIntegers.rbegin();
      iter != aListOfIntegers.rend();
      --iter) {
      std::cout << *iter << " ";
  }

  std::cout << "\n\nTest iterators: const -> ";
  for (auto iter = aListOfIntegers.cbegin();
      iter != aListOfIntegers.cend();
      ++iter) {
      std::cout << *iter << " ";
  }
   std::cout << "\nTest iterators: const r -> ";
  for (auto iter = aListOfIntegers.crbegin();
            iter != aListOfIntegers.crend();
            --iter) {
              std::cout << *iter << " ";
            }
  
  std::cout << std::endl;
  for (int i = 0; i < 3; i++) {
    int datum = aListOfIntegers.back();
    std::cout << datum << " ";
    aListOfIntegers.pop_back();
  }
  std::cout << std::endl;
  if (!aListOfIntegers.empty()) {
    aListOfIntegers.traverse(printItem);
    std::cout << std::endl;
  }
  aListOfIntegers.push_back(42);
  aListOfIntegers.traverse(printItem);
  std::cout << std::endl;

  
  for (int i = 3; i > 0; i--)
  {
      anotherListOfIntegers.push_front(i);
  }
  anotherListOfIntegers.traverse(printItem);
  std::cout << std::endl << "insert pos 2: ";

  
  auto iterTest = anotherListOfIntegers.begin();
  ++iterTest;
  anotherListOfIntegers.insert(iterTest, 9);
  anotherListOfIntegers.traverse(printItem);
  std::cout << "\nerase pos 3: ";
  anotherListOfIntegers.erase(iterTest);
  anotherListOfIntegers.traverse(printItem);
  std::cout << std::endl<< "insert two 9s: ";



  iterTest = anotherListOfIntegers.begin();
  ++iterTest;
  anotherListOfIntegers.insert(iterTest, 9);
  --iterTest;
  anotherListOfIntegers.insert(iterTest, 9);



  anotherListOfIntegers.traverse(printItem);
  std::cout << std::endl << "erase pos 2 - 4: ";
  iterTest = anotherListOfIntegers.begin();
  ++iterTest;

  auto iterEnd = anotherListOfIntegers.rbegin();
  anotherListOfIntegers.erase(iterTest, iterEnd);
  anotherListOfIntegers.traverse(printItem);
  return 0;
}
