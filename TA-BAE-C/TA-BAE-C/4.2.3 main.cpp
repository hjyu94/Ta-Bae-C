#include <iostream>
#include "4.2.3 Header.h"

using namespace std;

extern int a; // �ٸ� �ҽ� ����(�ܺ�)�� �ִ� ���� ���� num1�� ���
/* extern */ void doSomething(); // �ٸ� �ҽ� ����(�ܺ�)�� �ִ� �Լ� doSomething�� ���

void main()
{
	cout << a << endl;
	doSomething();
	cout << "Main.cpp: " << pi << ", " << &pi << endl;
}
