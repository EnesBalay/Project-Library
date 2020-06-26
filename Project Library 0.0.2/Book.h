#ifndef BOOK
#define	BOOK
#include<iostream>
#include<string>
#include<fstream>

using namespace std;
class Book {
private:
	string bookName, bookWriter, bookPublisher;
	int bookNo, bookPublishYear, counter;
public:
	Book(string/*, string, string, int*/);
	string getBookName();
	/*string getBookWriter();
	string getBookPublisher();
	int getBookNo();
	int getBookPublishYear();
	int getCounter();*/
	void counterCheck();
	void counterUp();
	void counterDown();
	void counterReset();
	void addBook();
	void showBook();
	void checkBook();
	void modifyBook();
	void deleteBook();
};
#endif // !BOOK
