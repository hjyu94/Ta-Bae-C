#include <iostream>

using namespace std;

class Base
{
public:
	int i_value;

	Base(const int& i_in)
	{
		i_value = i_in;
	}
};

class Derived : public Base
{
public:
	double d_value;

	Derived(const double& d_in)
	{
		d_value = d_in;
	}

	// �������� ����?
	// ��ӹ޴� ��� Derived �������� 
	// "�̴ϼȶ���������Ʈ"�� "�θ��� �⺻ ������"�� �����Ǿ� �ִ�.

	/*
		Derived(const double& d_in)
			: Base() -> ����ڷ�!
		{
			d_value = d_in;
		}
	*/

	// ���� �θ��� Base Ŭ������ �⺻ �����ڰ� �����Ƿ� ����
};

/********************************************************/
// �ذ�å1) Base�� �⺻ ������ ������ֱ�
// �ذ�å2) �̴ϼȶ���������Ʈ�� ���� ���� Base�� ������ ȣ��

class Base
{
public:
	int i_value;

	Base(const int& i_in /*= 0*/) 
		// = 0 �� �ٿ��ָ� �⺻ �����ڵ� ���� ����� ȿ��! 
		// (���ڰ� ���� �� ����Ʈ �� 0 �� �־��ֱ� ������)
		// ���� Derived �� �⺻�����ڰ� ��������� ������ ������ �ʴ´�.
	{
		i_value = i_in;
	}
};

class Derived : public Base
{
public:
	int d_value;

	Derived(const double& d_in)
	{
		d_value = d_in;
	}
};