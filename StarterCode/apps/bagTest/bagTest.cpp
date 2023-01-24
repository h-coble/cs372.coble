#include "bag.hpp"
#include <iostream>;
#include<iomanip>;
int main()
{
	Bag<float> fBag;
	float popItem = fBag.pop();
	std::cout << fBag.size() << std::setw(5) << " " << "Last item inserted into bag : " << popItem << std::endl;

	fBag.insert(3.14);
	popItem = fBag.pop();
	std::cout << fBag.size() << std::setw(5) << " " << "Last item inserted into bag : " << popItem << std::endl;

	fBag.insert(100000.00);
	popItem = fBag.pop();
	std::cout << fBag.size() << std::setw(5) << " " << "Last item inserted into bag : " << popItem << std::endl;

	fBag.insert(3.14);
	popItem = fBag.pop();
	std::cout << fBag.size() << std::setw(5) << " " << "Last item inserted into bag : " << popItem << std::endl;


	std::cout << "Number of entry \"3.14\" : " << fBag.count(3.14) << std::endl;
	std::cout << "Number of entry \"100,000.00\" : " << fBag.count(100000.00) << std::endl;
	std::cout << "Number of entry \"3\" : " << fBag.count(3) << std::endl;
}