#include <iostream>
#include "4.2 My Constants.h"

extern int a = 123; // �ʱ�ȭ�� ������� �޸𸮰� �Ҵ�ȴ�.

void doSomething()
{
	using namespace std;

	cout << "Hello" << endl;

	cout << "In test.cpp: " << Constants::pi << ", �ּ�: " << &Constants::pi << endl;

}