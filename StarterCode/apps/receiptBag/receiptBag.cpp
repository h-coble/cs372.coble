#include "receiptBag.hpp"

int main()
{
	ReceiptBag<int>	bag;
	int insertion;
	char choice;

	std::cout << "Enter an integer into the bag: ";
	std::cin >> insertion;
	do
	{
		bag.insert(insertion);
		std::cout << "Insert another integer, or enter -43110 to stop filling the bag: ";
		std::cin >> insertion;	
	} while (insertion != -43110);
	bag.print();
	do
	{
		std::cout << "\nEnter the receipt # to remove the corresponding item: ";
		std::cin >> insertion;

		bag.remove(insertion);
		bag.print();
		std::cout << "Remove another item? n for no, any other character for yes: ";
		std::cin >> choice;
	} while (choice != 'n');

	bag.print();
}