#include <iostream>
#include <cassert>
#include <initializer_list>

using namespace std;


class IntArray
{
private:
	unsigned m_length = 0;
	int* m_data;

public:
	IntArray(int length)
		: m_length(length)
	{
		cout << "�⺻ ������" << endl;
		m_data = new int[length];
	}

	~IntArray()
	{
		delete[] this->m_data;
	}

	friend ostream& operator << (ostream& out, IntArray& arr)
	{
		for (unsigned i = 0; i < arr.m_length; ++i)
			out << arr.m_data[i] << ' ';
		out << endl;
		return out;
	}
};

int main()
{
	int my_arr1[5] = { 1,2,3,4,5 };
	int* my_arr2 = new int[5]{ 1,2,3,4,5 };

	auto il = { 10, 20, 30 };
	// auto Ÿ��: (std::initializer_list<int>)
	// �Լ� 3��: begin(), end(), size()

	cout << "begin(): " << *il.begin() << endl;
	cout << "end(): " << il.end() << endl;
	cout << "size(): " << il.size() << endl;
	cout << endl;

	// �̴ϼȶ����� ����Ʈ�� �Ķ���ͷ� ���� �����ڰ� ������ ������ ����.
	IntArray int_array{ 1,2,3,4,5 }; // error
	cout << int_array << endl;
	
	return 0;
}
