#include <iostream>

using namespace std;

class Second
{
public:
	Second()
	{
		cout << "class Second constructor()" << endl;
	}
};

class First
{
public:
	Second sec;

	First()
	{
		cout << "class First constructor()" << endl;
	}
};

int main()
{
	// ��� ������ �����ڰ� ���� ȣ��ȴ�.

	First fir;
	// Second ������ ȣ��
	// First ������ ȣ��
}