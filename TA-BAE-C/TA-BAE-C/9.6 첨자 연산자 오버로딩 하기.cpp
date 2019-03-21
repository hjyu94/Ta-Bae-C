#include <iostream>
using namespace std;

class IntList
{
private:
	int m_list[10];

public:
	void setItem(int index, int value)
	{
		m_list[index] = value;
	}

	int getItem(int index)
	{
		return m_list[index];
	}

	int* getList()
	{
		return m_list;
	}
};

void main_1()
{
	IntList my_list;
	my_list.setItem(3, 1);
	cout << my_list.getItem(3) << endl;
	
	my_list.getList()[3] = 10;
	cout << my_list.getList()[3] << endl;
}

/************************************************/
// ÷�� �����ڸ� �̿��ؼ� �����ϰ� �ذ�!

#include <cassert>

class MyList
{
private:
	int m_list[10] = { 0,1,2,3,4,5,6,7,8,9 };

public:
	// ���۷��� Ÿ������ ��ȯ�ؾ� l-value�ν� ������ �� �� �ִ�
	// �޸𸮸� ������ �ֱ� ������ list[3] = 10; �� ����������.
	int& operator [] (int index)
	{
		assert(index >= 0);
		assert(index < 10);
		return m_list[index];
	}

	const int& operator [] (int index) const
	{
		assert(index >= 0);
		assert(index < 10);
		return m_list[index];
	}
};

void main()
{
	// ������Ʈ(��ü)�� const�� ���?
	//	: const�� ������ ��� �Լ��� ȣ���� �� �ִ�.

	const MyList cnst_list;
	MyList my_list;

	cnst_list[3] = 10;
	my_list[3] = 10;

	cout << cnst_list[3] << endl;
	cout << my_list[3] << endl;

	/******************************************/

	MyList* ptr_list = new MyList;

	ptr_list[3] = 10; // Not OK
	(*ptr_list)[3] = 10; // OK
}