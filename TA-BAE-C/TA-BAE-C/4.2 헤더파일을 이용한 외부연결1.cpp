#include <iostream>
#include "4.2 ��������� �̿��� �ܺο���3.h"

void doSomething();

using namespace std;

int main()
{
	cout << "In main.cpp: " << Constants::pi << ", �ּ�: " << &Constants::pi << endl;

	doSomething();
}

// (4.2 MyCosntants.cpp�� ���� 4.2 MyConstants.h�� �ִ� ��쿡) 
// test.cpp �� �ٸ� ������ �޸� ������ ����ϰ� �ȴ�.
// ����� 1�ﰳ ����� �� ���� cpp ���Ͽ��� ��� ��������� ��Ŭ��� �ϸ�
// ���� �������� �ٸ� �޸𸮸� ����ϴ� ����� 1�ﰳ�� ���� -> �޸� ���� �����ؾ� ��
// 4.2 MyConstants.cpp �� ������༭ �̸� �ذ���.
