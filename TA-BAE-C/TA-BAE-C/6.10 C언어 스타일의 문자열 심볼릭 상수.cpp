#include <iostream>

using namespace std;

char* getName()
{
	return "Jack Jack";
}

int main()
{
	// char name[] = "Jack Jack";
	char * name = "Jack Jack";
	
	const char * name2 = "Jack Jack";
	name2 = "Another"; // O

	char * const name3 = "Jack Jack";
	name3 = "Another"; // X

	cout << (uintptr_t)name << name << endl;		// 14322480 Jack Jack
	cout << (uintptr_t)name2 << name2 << endl;		// 14322480 Jack Jack
	cout << (uintptr_t)getName() << getName() << endl; // 14322480 Jack Jack
	// ���ڿ��� ������ ���� �ּҰ� ��µ�

	char c = 'Q';
	cout << &c << endl; // Q���������������� // null ���� ���
	cout << *&c << endl; // Q
	
	// cout���� ���ڿ��� �ּҰ� ������ �ּҰ� �ƴ϶� ���ڿ��� ��µȴ�!!
	// cout���� ���� ������ �ּҰ� ���� ���� �ּҰ� �ƴ϶� ���ڿ��� ��µȴ�.
}