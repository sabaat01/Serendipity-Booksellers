#define _CRT_SECURE_NO_WARNINGS
#ifndef CASHIERMODULE_H
#define CASHIERMODULE_H
#include "InventoryModule.h" //this is relational of GETTING INVENTORY FUNCTIONS AND THE BOOK ARRAY INTO CASHIER!!!
#include "Module.h"
#include <iostream>
#include <string>

using namespace std;
class CashierModule:public Module
{
private:
protected:
	InventoryModule *inventory;
public:
	CashierModule(InventoryModule *inv) : Module()
	{
		inventory = inv;
	}
	void driver();
	bool displayBookPricing(int index)
	{
		return true;
	}//<- FORMATTING
	void transaction()
	{}
	void updateInventory()
	{}
};
void CashierModule::driver()
{
	char choice;
	do
	{
		string entry;
		int index;
		bool compltransact;
		cout << "Enter the title of the book you wish to purchase: ";
		getline(cin, entry);
		index = (inventory->searchByTitle(entry));//(in database)
		compltransact = displayBookPricing(index); //use everywhere! <- complete transaction is used to cout total pricing and give back change.
		if (compltransact){
			transaction();
			updateInventory();
		}
		cout << "\n\nDo you wish to checkout another book? y/n: ";
		cin >> choice;
	} while (choice == 'y');
}

/*

find book:  check if book is available-this is a sorting function - not necessarily have to be a friend function b/c it is NOT editing
display book: cout formatting + pricing OR cout "not available"
transaction: how many books? total pricing: Has the transaction completed? y -> update inventory function
update inventory: IT MUST EDIT QUANTITY! Use inventory's own edit functions?

*/

#endif
