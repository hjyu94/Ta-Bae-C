#include <iostream>
#include "4.2 �ܺο���� ��� ����Ǵ� ���� �ذ��ϱ�.h"

void doSomething()
{
	using namespace std;

	cout << "In other cpp: " << Constants::pi << ", �ּ�: " << &Constants::pi << endl;
}

// (4.2 MyCosntants.cpp�� ���� 4.2 MyConstants.h�� �ִ� ��쿡) 
// test.cpp �� �ٸ� ������ �޸� ������ ����ϰ� �ȴ�.
// ����� 1�ﰳ ����� �� ���� cpp ���Ͽ��� ��� ��������� ��Ŭ��� �ϸ�
// ���� �������� �ٸ� �޸𸮸� ����ϴ� ����� 1�ﰳ�� ���� -> �޸� ���� �����ؾ� ��
// 4.2 MyConstants.cpp �� ������༭ �̸� �ذ���.
