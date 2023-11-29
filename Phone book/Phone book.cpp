#include <iostream>
#include "Phone book.h"
using namespace std;

int main() {
	char* name = new char[20] {"\0"};
	char num1[15]{}, num2[15]{}, num3[15]{}, info[50]{};
	Abonent camal{name,num1,num2,num3,info};
	camal.show();
}