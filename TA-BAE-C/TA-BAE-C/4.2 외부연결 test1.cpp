
// [�ܺο���]
// test.cpp �� doSomething()�� ����ϰ� ���� ���
// 1) cpp ���� ���� ��Ŭ���(������ ��� X)
// 2) ���漱��

#include <iostream>

using namespace std;

// [���漱���� �̿��� �ܺο���]

void doSomething();
// extern void doSomething();
// extern ��� ������ �ʾƵ� ��. �����Ǿ� ����.

extern int a;
// extern ��� �� ���ָ� ��������

void main()
{
	doSomething();

	cout << a << endl;
}