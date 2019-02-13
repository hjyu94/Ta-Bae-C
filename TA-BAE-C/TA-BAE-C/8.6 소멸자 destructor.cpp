#include <iostream>

using namespace std;

class Simple
{
public:
	int m_id;

	Simple(int x)
	{
		m_id = x;
		cout << "Constructor " << m_id << endl;
	}

	~Simple()
	{
		cout << "Destructor " << m_id << endl;
	}
};

void main1()
{
	Simple s1(0);
	Simple s2(1);

	// 0 ����
	// 1 ����
	// 1 �Ҹ�
	// 0 �Ҹ�
}
// �ڱ� ������ ��� �� �Ҹ�ȴ�. 

/***************************************************/

void main2()
{
	Simple* s1 = new Simple(0); // �޸� �����Ҵ�
	Simple s2(1);

	delete s1;

	// 0 ����
	// 1 ����
	// 0 �Ҹ�
	// 1 �Ҹ�
}

/***************************************************/

// �Ҹ��ڸ� ���� ������?

class IntArray
{
private:
	int* m_arr = nullptr;
	int m_length = 0;

public:
	IntArray(const int length_in) // #1
	{
		m_length = length_in;
		m_arr = new int[m_length];
	}

	// �޸� ���� �߻��� ����ؼ� �Ҹ��ڿ� ��� ����
	~IntArray()
	{
		if (m_arr != nullptr) delete[] m_arr;
	}

	int getLength() const { return m_length; } // #2
};

void main()
{
	while (true)
	{
		IntArray my_int_arr(10000); // �޸� ���� �߻�
									// delete[] my_int_arr.m_arr; // private�̶� �׼��� �Ұ�
									// --> �̷� ��츦 ����ؼ� Ŭ������ �Ҹ��ڿ� ��� ����
	}
}

/***************************************************/

/*
#1 �Ű������� const�� ���
: �ش� �Լ� ������ ���� �ٲ��� �ʴ� ���

#2 Ŭ������ ��� �Լ��� const�� ���
: �ش� �Լ��� ���� ��ü�� ����� �������� �ʴ� ���

*/