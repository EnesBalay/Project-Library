#include "Book.h"
using namespace std;

int main()
{
	int x;
	//int bPY = 0;
	string bN/*, bW, bP, Y*/;
	Book book1(bN/*, bW, bP, bPY*/); a:
	cout << "*********Hello Your Book Library*********" << endl;
	cout << "1.Add Book Records         2.Show Book Records\n";
	cout << "3.Check Availability       4.Modify Book Records\n";
	cout << "5.Delete Book Records      6.Exit\n";
	cout << "Please select the action you want to do \n"; cin >> x; cout << endl;
	switch (x)
	{
	case 1:
		cout << "You are adding book records in your library\n";
		book1.addBook();
		cout << endl;
		goto a;
	case 2:
		book1.counterCheck();
		cout << "You are showing book records in your library.\n";
		book1.showBook();
		goto a;
	case 3:
		cout << "You are checking availability book in your library.\n";
		book1.checkBook();
		cout << endl;
		goto a;
	case 4:
		cout << "You are modifying book Records in your library.\n";
		book1.modifyBook();
		cout << endl;
		goto a;
	case 5:
		cout << "Please select how you want to remove the book(s).\n";
		book1.deleteBook();
		cout << endl;
		goto a;
	case 6:
		cout << "You left the library.\n";
		remove("count.txt");
		break;
	default:
		goto a;
	}
}