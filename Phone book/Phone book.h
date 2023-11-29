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
	Abonent()
		: fullname{nullptr},
		mobilePhone{"-"},
		workPhone{"-"},
		homePhone{"-"},
		information{"-"} {}
	Abonent(const char* name,const char* mobile,const  char* work,const char* home,const  char* info)
		: fullname{ new char[strlen(name) + 1] }
	{
		strcpy_s(fullname, strlen(name) + 1, name);
		strcpy_s(mobilePhone, 20, mobile);
		strcpy_s(workPhone, 20, work);
		strcpy_s(homePhone, 20, home);
		strcpy_s(information, 50, info);
	}
	void show() {
		cout << "" << fullname << endl;
		cout << "mobile: " << mobilePhone << endl;
		cout << "work: " << workPhone << endl;
		cout << "home: " << homePhone << endl;
		cout << "additional info: " << information << endl;
	}
};