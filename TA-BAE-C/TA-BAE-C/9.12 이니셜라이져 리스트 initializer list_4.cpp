#include <iostream>
#include <cassert>
#include <initializer_list>

using namespace std;

class IntArray
{
private:
public:
	unsigned m_length = 0;
	int* m_data;

public:
	IntArray(int length = 0)
		: m_length(length)
	{
		cout << "�⺻ ������" << endl;
		m_data = new int[length];
	}

	IntArray(const std::initializer_list<int>& list)
		: IntArray(list.size())
	{
		cout << "������ ȣ��" << endl;
		int count = 0;
		for (auto& e : list)
			m_data[count++] = e;
	}

	IntArray(IntArray& _arr)
	{
		cout << "���� ������ ȣ��" << endl;
	}

	~IntArray()
	{
		cout << "�Ҹ���ȣ��" << endl;
		delete[] this->m_data;
	}

	friend ostream& operator << (ostream& out, IntArray& arr)
	{
		for (unsigned i = 0; i < arr.m_length; ++i)
			out << arr.m_data[i] << ' ';
		out << endl;
		return out;
	}
	/*
	IntArray& operator = (IntArray& _arr)
	{
		cout << "���� ���� ������" << endl;
		return *this;
	}

	IntArray& operator = (const std::initializer_list<int>& _arr)
	{
		cout << "���� ���� ������" << endl;
		return *this;
	}*/
};

int main()
{
	IntArray int_array{ 1,2,3,4,5 }; // ������ ȣ��
	cout << int_array << endl;

	IntArray int_array2; // �⺻ ������
	int_array2 = { 1, 2, 3, 4, 5 }; // ���� ���� ������
	cout << int_array2.m_length << endl; // 0 ��µ�

	cout << int_array2 << endl;

	return 0;
}