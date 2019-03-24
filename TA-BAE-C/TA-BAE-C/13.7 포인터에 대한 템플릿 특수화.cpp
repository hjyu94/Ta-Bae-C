#include <iostream>
using namespace std;

template<class T>
class A
{
private:
	T m_value;

public:
	A(const T& input)
		: m_value(input)
	{}

	void print()
	{
		cout << m_value << endl;
	}
};

// �������� ��쿡�� Ư���ϰ� �۵������� ���� ��
template<class T>
class A<T*>
{
private:
	T* m_value;

public:
	A(/*const */T* input)
		: m_value(input)
	{}

	void print()
	{
		cout << *m_value << endl;
	}
};

void main()
{
	A<int> a_int(123);
	a_int.print(); // 123


	// �����Ϳ� ���� ���ø� Ư��ȭ�� ������ ������
	// �ּҰ��� ��� ������
	//
	// Ư��ȭ�� �������ְ� ����
	// �ּҰ��� �����ؼ� ���� ������� �� �ִ�.

	int temp = 456;
	A<int*> a_int_ptr(&temp);
	a_int_ptr.print(); 

	double temp_d = 3.14;
	A<double*> a_double_ptr(&temp_d);
	a_double_ptr.print();
}

