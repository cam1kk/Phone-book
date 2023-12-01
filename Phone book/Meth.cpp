#include <iostream>
#include "Phone book.h"
using namespace std;


// class Abonent
Abonent::Abonent()
	: fullname{nullptr},
	mobilePhone{ "-" },
	workPhone{"-"},
	homePhone{"-"},
	information{"-"} {}
Abonent::Abonent(const char* name, const char* mobile, const char* work, const char* home, const char* info)
	: fullname{ new char[strlen(name) + 1] } {
	strcpy_s(fullname, strlen(name) + 1, name);
	strcpy_s(mobilePhone, 20, mobile);
	strcpy_s(workPhone, 20, work);
	strcpy_s(homePhone, 20, home);
	strcpy_s(information, 50, info);
}
void Abonent::show(int i) {
	cout << "\n";
	cout << i << endl;
	cout << "" << fullname << endl;
	cout << "mobile: " << mobilePhone << endl;
	cout << "work: " << workPhone << endl;
	cout << "home: " << homePhone << endl;
	cout << "additional info: " << information << endl;
}
void Abonent::setFullName(const char* name) {
	delete[] fullname;
	fullname = new char[strlen(name) + 1];
	strcpy_s(fullname, strlen(name) + 1, name);
}
void Abonent::setMobilePhone(const char* mobile) {
	strcpy_s(mobilePhone, 20, mobile);
}
void Abonent::setWorkPhone(const char* work) {
	strcpy_s(workPhone, 20, work);
}
void Abonent::setHomePhone(const char* home) {
	strcpy_s(homePhone, 20, home);
}
void Abonent::setInformation(const char* info) {
	strcpy_s(information, 50, info);
}
char* Abonent::getFullName() {
	return fullname;
}
// class Abonent



// class Book
Book::Book(int capacity = 10)
	: abonents{ new Abonent[capacity] }, size{ 0 }, capacity{ capacity } 
{}
Book::~Book() {
	delete[] abonents;
}
void Book::addAbonent(const Abonent& abonent) {
	if (size < capacity) {
		abonents[size++] = abonent;
	}
	else {
		int newCapacity = capacity * 2;
		Abonent* newAbonents = new Abonent[newCapacity];
		for (int i = 0; i < size; ++i) {
			newAbonents[i] = abonents[i];
		}
		delete[] abonents;
		abonents = newAbonents;
		capacity = newCapacity;
		abonents[size++] = abonent;
	}
}

void Book::removeAbonent(int index) {
	if (index >= 0 && index < size) {
		Abonent* newAbonents = new Abonent[capacity - 1];
		for (int i = 0; i < index; ++i) {
			newAbonents[i] = abonents[i];
		}
		for (int i = index + 1; i < size; ++i) {
			newAbonents[i - 1] = abonents[i];
		}
		delete[] abonents;
		abonents = newAbonents;
		size--;
		if (size < 0) {
			size = 0;
		}
	}
}


void Book::findAbonent(char* fullname) {
	for (int i = 0; i < size; ++i) {
		if (strcmp(abonents[i].getFullName(), fullname) == 0) {
			abonents[i].show(i);
		}
	}
}

void Book::showAll() {
	for (int i = 0; i < size; ++i) {
		abonents[i].show(i);
		cout << "-------------------------" << endl;
	}
}
// class Book



// func

// func