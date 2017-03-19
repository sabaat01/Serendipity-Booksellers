#include <iostream>
#include <iomanip>
using namespace std;

int main()

{
	double tax = 1.0875;
	//find book
	char bookPurchase[100];
	double bookPurchaseNum;
		cout << "Enter name of book customer wants to purchase: " << endl;
	cin >> bookPurchase;
	//search array for book
	do
	{
		cout << "book is not found, please enter a valid book name " << endl;
	} while (bookPurchase = bookname);		//book is found in book array list
		//display book information

		cout << "How many copies would you like to purchase?" << endl;
	cin >> bookPurchaseNum;

	cout << "Subtotal: " << "/t" << bookPRICE*bookPurchaseNum << endl;
	cout << setprecision (2) << fixed << "Total: " << "/t" << bookPRICE*bookPurchaseNum*tax << endl;
	cout << "Press Y to continue transaction, press any other key to cancel." << endl;

	//update array list with books that were bought if transaction is completed
	cout << "do you want to checkout another book? y / n";

	return 0;
}
