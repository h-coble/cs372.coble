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
}