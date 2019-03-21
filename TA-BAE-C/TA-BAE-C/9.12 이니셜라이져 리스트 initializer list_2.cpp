#include <iostream>
#include <initializer_list> // for std::initializer_list
using namespace std;

class IntArray
{
private:
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

		//for (unsigned count = 0; count < list.size(); ++count)
		//	m_data[count] = list[count]; // error

		//// ���������� iterator�� ����Ѵ�
		//// �̴ϼȶ���������Ʈ�� []�� �������� �ʴ´�.
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

	friend ostream& operator << (ostream& out, IntArray arr)
	{
		for (unsigned i = 0; i < arr.m_length; ++i)
			out << arr.m_data[i] << ' ';
		out << endl;
		return out;
	}
};

int main()
{
	IntArray int_array{ 1,2,3,4,5 };
	cout << int_array << endl;

	// �Ҹ��ڰ� �ι� ȣ��Ǹ鼭 ������ �߻�!! ���ϱ�!! �����!!

	return 0;
}