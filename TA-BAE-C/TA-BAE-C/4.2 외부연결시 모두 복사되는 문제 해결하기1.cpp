#include <iostream>
#include "4.2 �ܺο���� ��� ����Ǵ� ���� �ذ��ϱ�.h"

void doSomething();

using namespace std;

int main()
{
	cout << "In main.cpp: " << Constants::pi << ", �ּ�: " << &Constants::pi << endl;

	doSomething();
}
