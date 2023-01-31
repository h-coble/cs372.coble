#include "vector.hpp"

#include<iostream>
#include<iomanip>
using std::cout;

using std::setw;
int main()
{
	Vector<int> vectorA;
	

	Vector<int> C;

	cout << vectorA.size() << setw(5) << vectorA.capacity() << std::endl;
	vectorA.push_back(1);
	cout << vectorA.size() << setw(5) << vectorA.capacity() << std::endl;

	vectorA.traverse();
	vectorA.put(2, 0);
	cout << "Entry at 0: " << vectorA.at(0)<<std::endl;
	
	Vector<int> vectorB = vectorA;
	vectorB.traverse();
	
	C = vectorB;

	cout << "Traversal\n\n";
	vectorA.traverse();

	vectorB.traverse();

	C.traverse();

	C.push_back(4);
	vectorA = C;

	vectorA.traverse();

	vectorB.traverse();

	C.traverse();

	for (auto iter = C.begin(); iter != C.end(); ++iter)
	{
		std::cout<<C.at(iter) << " ";
	}
	std::cout << std::endl;
	for (auto iter = C.rbegin(); iter != C.rend(); --iter)
	{
		std::cout << C.at(iter) << " ";
	}
	std::cout << std::endl;
	for (auto iter = C.cbegin(); iter != C.cend(); ++iter)
	{
		std::cout << C.at(iter) << " ";
	}
	std::cout << std::endl;
	for (auto iter = C.crbegin(); iter != C.crend(); --iter)
	{
		std::cout << C.at(iter) << " ";
	}

	C.push_back(3);
	C.push_back(7);
	std::cout << std::endl;
	C.traverse();
	auto iter = C.begin();
	++iter;
	
	C.insert(iter, 5);
	std::cout << std::endl;

	//iterator return doesn't work properly, must reset iterator if used again
	iter = C.begin();
	++iter;

	C.traverse();
	C.insert(iter, 6);
	std::cout << std::endl;
	C.traverse();



}