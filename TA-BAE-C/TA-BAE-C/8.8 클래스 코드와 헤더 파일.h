#pragma once

#include <iostream>

using namespace std; 
// include�ϴ� ���ϵ鿡 ���� ������ ���Ĺ����� ���⿡ �� ���°� ����

class Calc
{
	//  using namespace std; // X

private:
	//	using namespace std; // X
	int m_value;

public:
	//	using namespace std; // X
	Calc(int init_value)
		: m_value(init_value)
	{}

	Calc& add(int value) 
	{
		m_value += value; 
		return *this; 
	}
	
	Calc& add1(int value) 
	{ 
		m_value += value; 
		return *this; 
	}
	
	Calc& add2(int value) 
	{ 
		m_value += value; 
		return *this; 
	}

	Calc& add3(int value) 
	{ 
		m_value += value; 
		return *this; 
	}

	void print()
	{
		using namespace std;
		cout << m_value << endl;
	}
};

/***********************************************/

// ��������� �ʹ� ��� �б� ������
// ������Ͽ� ���� ���ܵΰ�
// ���Ǵ� ���� ���δ°� ����.

#pragma once

#include <iostream>

class Calc
{

private:
	int m_value;

public:
	Calc(int init_value)
		: m_value(init_value)
	{}

	// �Լ��� ������ ��Ŭ�� - ���� �۾� �� �����͸� - ���� ��ġ �̵� - Ctrl + S (����)
	Calc& add(int value);
	Calc& add1(int value);
	Calc& add2(int value);
	Calc& add3(int value)
	{
		m_value += value;
		return *this;
	}

	void print()
	{
		using namespace std;
		cout << m_value << endl;
	}
};
