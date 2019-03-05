#include <iostream>
using namespace std;

void doSomething()
//{
try
{
	throw - 1;
}
catch (...)
{
	cout << "Catch in doSomething()" << endl;
}
//}

// �Լ� ��ü�� ���ؼ� try�� �� ���� �ִ�.
// �ε�Ʈ ������ �ϳ� �پ��.

int main1()
{
	try
	{
		doSomething();
	}
	catch (...)
	{
		cout << "Catch in main()" << endl;
	}
	// doSomething() �ȿ��� catch�� �ɷ����Ƿ�
	// main������ ���� ����.
	return 0;
}

// ���
// Catch in doSomething()

/*******************************************************/

class A
{
private:
	int m_x;
public:
	A(int x) : m_x(x)
	{
		if (x <= 0) throw 1;
	}
};

class B : public A
{
public:
	B(int x)
		: A(x)
	{}
};

int main2()
{
	try
	{
		B b(0);
	}
	catch (...)
	{
		cout << "Catch in main()" << endl;
	}

	return 0;
}

// [���] Catch in main()

/*******************************************************/

class A2
{
private:
	int m_x;
public:
	A2(int x) : m_x(x)
	{
		if (x <= 0) throw 1;
	}
};

class B2 : public A2
{
public:
	B2(int x) try /**/ : A2(x) {} /**/
	// �ּ� ���̿� �ִ°� ��� try
	// �̴ϼȶ���������Ʈ, ��ȣ �� �Ѵ�
	catch (...)
	{
		cout << "Catch in B constructor" << endl;
		// ���⿡ throw; �� ������ �ִ� ��ó�� �۵���
	}
};

int main()
{
	try
	{
		B2 b(0);
	}
	catch (...)
	{
		cout << "Catch in main()" << endl;
	}
}
// [���]
// Catch in B constructor
// Catch in main