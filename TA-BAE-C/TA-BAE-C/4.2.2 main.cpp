#include <iostream>
#include "4.2.2 Header.h"

using namespace std;

// [�ܺ� ���Ͽ� �ִ� ���� ����ϱ�]
//	: extern Ű���� ���� �Ұ���
//	: ���� ���� ���� ���� extern int a; �� �����ϸ� ������(��ũ) ������ �߻��Ѵ�
//	: ��, extern int a; �� ���� ������ ���� �ܺο� �ִٴ� ���� ǥ�ø� �� �� ���� ���� ��ü�� ���������� �ʽ��ϴ�.

extern int a; // �ٸ� �ҽ� ����(�ܺ�)�� �ִ� ���� ���� a�� ���

// [�ܺ� ���Ͽ� �ִ� �Լ� ����ϱ�]
//	: extern Ű���� ���� ����
/* extern */ void doSomething(); // �ٸ� �ҽ� ����(�ܺ�)�� �ִ� �Լ� doSomething�� ���

void main()
{
	cout << a << endl;
	doSomething();
	cout << "Main.cpp: " << pi << ", " << &pi << endl;
}
