#include <iostream>
#include <Windows.h>
#include "Phone book.h"
using namespace std;

int main() {
	Book book(10);
	Abonent ktoto{ "ktoto","123","456","789","ktoto" };
	book.addAbonent(ktoto);
	Abonent camal;
	camal.setFullName("Camal Babayev");
	camal.setMobilePhone("12 312 31 23");
	camal.setWorkPhone("12 312 31 23");
	camal.setHomePhone("12 312 31 23");
	camal.setInformation("Step IT");
	book.addAbonent(camal);
	while (true) {
		int menu = 0;
		cout << "\n\nMenu:\n1 - Pokaz vsex abonentov\n2 - Dobavit Abonenta\n3 - Udalit Abonenta\n4 - Poisk po FIO\n0 - Vixod\n\nVibor: ";
		cin >> menu;
		system("cls");
		if (menu == 1) {
			book.showAll();
		}
		else if (menu == 2) {
			char name[30]{}, numM[20]{}, numW[20]{}, numH[20]{}, info[50]{};
			cout << "Vvedite imya: ";
			cin >> name;
			cout << "Vvedite mobilniy nomer: ";
			cin >> numM;
			cout << "Vvedite rabochiy nomer: ";
			cin >> numW;
			cout << "Vvedite domasniy nomer: ";
			cin >> numH;
			cout << "Vvedite dopolnitelnuyu informaciyu: ";
			cin >> info;
			Abonent newAbonent{ name,numM,numW,numH,info };
			book.addAbonent(newAbonent);
			cout << "Abonent dobavlen" << endl;
			Sleep(500);
			system("cls");
		}
		else if (menu == 3) {
			book.showAll();
			cout << "Viberite nomer abonenta kotorogo xotite udalit: ";
			int number{};
			cin >> number;
			book.removeAbonent(number);
			cout << "Abonent udalen" << endl;
			Sleep(500);
			system("cls");
		}
		else if (menu == 4) {
			char name[30]{};
			cout << "Vvedite imya polzovatelya kotorogo xotite nayti: ";
			cin >> name;
			book.findAbonent(name);
		}
		else if (menu == 0) {
			cout << "Bye!" << endl;
			return 0;
		}
		else {
			cout << "Error" << endl;
			return 0;
		}
	}
}