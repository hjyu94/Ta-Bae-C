#include <iostream>

using namespace std;

class Second
{
public:
/*3*/	Second()
	{
/*4*/		cout << "class Second constructor()" << endl;
	}
};

class First
{
public:
	Second sec;

/*1*/	First()
/*2*/ {
/*5*/		cout << "class First constructor()" << endl;
	}
};

int main()
{
	// ��� ������ �����ڰ� ���� ȣ��ȴ�.

/*0*/	First fir;
		// Second ������ ȣ��
		// First ������ ȣ��
}