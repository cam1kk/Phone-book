#pragma once
#include <iostream>
using namespace std;


class Abonent {
private:
	char* fullname;
	char mobilePhone[20];
	char workPhone[20];
	char homePhone[20];
	char information[50];
public:

	Abonent();
	Abonent(const char*, const char*, const char*, const char*, const char*);

	void show(int);

	void setFullName(const char*);
	void setMobilePhone(const char*);
	void setWorkPhone(const char*);
	void setHomePhone(const char*);
	void setInformation(const char*);

	char* getFullName();
};

class Book {
private:
	Abonent* abonents;
	int size;
	int capacity;

public:
	Book(int);
	~Book();

	void addAbonent(const Abonent&);
	void removeAbonent(int);
	void findAbonent(char*);

	void showAll();
};