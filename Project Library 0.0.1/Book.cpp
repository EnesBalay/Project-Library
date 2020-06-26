#include "Book.h"
using namespace std;
Book::Book(string bN/*, string bW, string bP, int bPY*/) {
	bN = bookName; /*bW = bookWriter; bP = bookPublisher; bPY = bookPublishYear;*/
	ifstream count("count.txt", ios::in);
	count >> counter;
}
string Book::getBookName() { return bookName; }
//string Book::getBookWriter() { return bookWriter; }
//string Book::getBookPublisher() { return bookPublisher; }
//int Book::getBookNo() { return bookNo; }
//int Book::getBookPublishYear() { return bookPublishYear; }
//int Book::getCounter() { return counter; }
void Book::counterCheck() {
	ifstream readFromFile("Library.txt", ios::in);
	counterReset();
	while (readFromFile >> bookName) {
		counterUp();
	}
}
void Book::counterUp() {
	ifstream count("count.txt", ios::in);
	counter++;
	count.close();
	remove("count.txt");
	ofstream counterUp("count.txt", ios::app);
	counterUp << counter;
	count.close();
}
void Book::counterDown() {
	ifstream count("count.txt", ios::in);
	counter--;
	count.close();
	remove("count.txt");
	ofstream counterUp("count.txt", ios::app);
	counterUp << counter;
	count.close();
}
void Book::counterReset() {
	ifstream count("count.txt", ios::in);
	counter = 0;
	count.close();
	remove("count.txt");
	ofstream counterUp("count.txt", ios::app);
	counterUp << counter;
	count.close();
}
void Book::addBook() {
	cin.ignore();
	while (bookName != "q")
	{
		cout << "If you don't want to add book, you enter 'q'. \n";

		cout << "Book Name: "; getline(cin, bookName);
		/*cout << "Book Writer: "; getline(cin, bookWriter);
		cout << "Book Publisher: "; getline(cin, bookPublisher);
		cout << "Book Publisher Year: "; cin >> bookPublishYear;*/
		if (bookName != "q")
		{
			ofstream saveToFile("Library.txt", ios::app);
			saveToFile << bookName << " " << endl;
			cout << bookName << " has been added to your library.\n\n";
		}
	}
}
void Book::showBook() {
	ifstream readFromFile;
	readFromFile.open("Library.txt");
	cout << "---------------------------------------------\n";
	for (int i = 0; i < counter; i++)
	{
		if (readFromFile.is_open()) {
			string temp;
			char text[50];
			getline(readFromFile, temp);
			strcpy_s(text, temp.c_str());

			cout << text << endl;

		}

	}
	if (counter == 0)
	{
		cout << "We have no books in this library.\n\n";
	}
	else
	{
		cout << "---------------------------------------------\n";
		cout << "We have " << counter << " book(s).\n\n";
	}
}
void Book::checkBook() {
	string tempBook;
	cin.ignore();
	while (tempBook != "q")
	{
		cout << "If you don't want to check book, you enter 'q'.\n";
		cout << "Please enter book name that you want:";  getline(cin, tempBook);
		ifstream check;
		check.open("Library.txt");
		while (check >> bookName)
		{
			if (bookName == tempBook)
			{
				cout << "We have this book:" << tempBook << endl << endl;
				break;
			}
		}
		if (bookName != tempBook & tempBook != "q")
		{
			cout << "Sorry!, we haven't this book:" << tempBook << endl << endl;
		}
	}
}
void Book::modifyBook() {
	string mBookName;
	string tempBook = "a";
	string bN = "b";
	showBook();
	cout << "Please enter book name that will modify.\n"; cin >> mBookName;
	ifstream readFromFile("Library.txt", ios::in);

	while (readFromFile >> bookName)
	{
		if (mBookName == bookName)
		{
			bN = bookName;
			ofstream writeToFile("Library1.txt", ios::app);
			cout << "Please enter new book name:"; cin >> bookName;
			tempBook = mBookName;
			mBookName = bookName;
			writeToFile << mBookName << endl;
			readFromFile.close();
			writeToFile.close();
			rename("Library.txt", "tempLibrary.txt");
			rename("Library1.txt", "Library.txt");
			ifstream readTemp("tempLibrary.txt", ios::in);
			ofstream writeToFile1("Library.txt", ios::app);
			while (readTemp >> bookName)
			{
				if (tempBook != bookName) {
					writeToFile1 << bookName << endl;
				}
			}
			readTemp.close();
			remove("tempLibrary.txt");
			cout << tempBook << " modified to " << mBookName << endl;
		}
	}
	if (bN != tempBook) {
		cout << mBookName << " not found.\n";
	}

}
void Book::deleteBook() {
	string dBookName;
	ifstream readFromFile("Library.txt", ios::in);
	int x;
	cout << "1.Remove a book		2.Remove all books.\n"; cin >> x;
	if (x == 1)
	{
		ofstream writeToFile("Library1.txt", ios::app);
		showBook();
		cout << "Please enter book name that will delete.\n"; cin >> dBookName;
		while (readFromFile >> bookName)
		{
			if (dBookName != bookName) {
				writeToFile << bookName << endl;
			}
		}
		readFromFile.close();
		writeToFile.close();
		remove("Library.txt");
		rename("Library1.txt", "Library.txt");
		cout << dBookName << " has been removed.\n";
	}
	if (x == 2)
	{
		readFromFile.close();
		remove("Library.txt");
		remove("count.txt");
		cout << "All books have been removed.\n";
	}

}
