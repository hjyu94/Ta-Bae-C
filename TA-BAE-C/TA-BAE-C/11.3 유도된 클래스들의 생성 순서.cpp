#include <iostream>

using namespace std;

class Mother
{
public:
	int m_i;
};

class Child : public Mother
{
public:
	Child()
		: m_i(10) // �̴ϼȶ����������� �ʱ�ȭ �Ұ���
	{
		// ������ ���ο����� �ʱ�ȭ �����ѵ�
		this->m_i = 10;
		this->Mother::m_i = 10;
	}
};

/******************************************************/

class A
{
public:
	int m_i;

	A()
3		: m_i(1) // �ʱ�ȭ ����� �޸𸮰� ����
2	{
4		cout << "Mother construction" << endl;
5	}
};

class B : public A
{
public:
	double m_d;

	B()
6		:m_d(3.14) // , m_i(1) // X
1	{
7		cout << "Child construction" << endl;
8	}
};

void main()
{
	B child;

	// [���]
	// Mother construction
	// Child construction
}

// �θ� �ִ� ��� �� �ʱ�ȭ �� ������
// �ڽ��� �͵��� �ʱ�ȭ �Ѵ�.

// �׷��� �ڽ��� ������ �̴ϼȶ���������Ʈ������
// �θ��� ��������� �ʱ�ȭ �� �� ����.

// �θ� �����ڿ��� ������ �ʱ�ȭ �� �������� �����ϹǷ�
// �̴ϼȶ���������Ʈ�� �ƴ� ������ ��� �ȿ����� �ʱ�ȭ �����ϴ�

/******************************************************/

class A
{
public:
	int m_i;
	
	A(const int& i_in)
4		: m_i(i_in)
3	{
5		cout << "Mother construction" << endl;
6	}
};

class B : public A
{
public:
	double m_d;

	B()
/*2,7*/		: A()/* ��� �갡 �����Ǿ� �ִ� ��*/, m_d(3.14) // , A(1024) 
			// �տ� ������ �ڿ� ������ ��� ����
1	{
8		cout << "Child construction" << endl;
9	}
};

void main2()
{
	B child;
}

/******************************************************/

/*
	�θ��� ��������� ��� �ʱ�ȭ �� �Ŀ�
	�ڽ��� �������� �ʱ�ȭ�Ѵ�.
*/

