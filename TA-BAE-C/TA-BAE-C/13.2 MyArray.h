#pragma once
#include <assert.h> // for assert
#include <iostream>

template<typename T>
// T�� ������ó�� �����ϸ� �ȴ�
// template<class T>
// �ڿ� �����ݷ� ���� ����

class MyArray
{
private:
	int	 m_length;
	T*	 m_data;

public:
	MyArray()
	{
		m_length = 0;
		m_data = new T[m_length];
	}

	MyArray(int length)
	{
		m_length = length;
		m_data = new T[length];
	}

	~MyArray()
	{
		reset();
	}

	void reset()
	{
		delete[] m_data;
		m_data = nullptr;
		m_length = 0;
	}

	T& operator[] (int index)
	{
		assert(index >= 0 && index < m_length);
		//return *(m_data + index);
		return m_data[index];
	}

	int getLength();

	// main.cpp ���� MyArray.h �� ��Ŭ��� �� ����
	// ���Ǵ� ������Ͽ� ���� cpp ���Ͽ� ����
	// main.cpp ���� MyArr<char> my_arr(10);���� �ν��Ͻÿ��̼� �� ��
	// MyArray.cpp ������ ������ �� ���� �� ���� ���?

	// main.cpp ���� #include "13.2 MyArray.cpp" �ϸ� �ذ�Ǳ�� �ϳ�
	// ������Ʈ�� Ŀ���� cpp ������ ��Ŭ����ϸ� ����

	void print();
};




// Ŭ������ ��� �Լ��� ����� ���Ǹ� �и��� �� ���ø��� ����ϸ� �ٸ� ������ ���ȴ�.
template<typename T>
void MyArray<T>::print() // O
// void MyArray::print() // X
{
	using namespace std;
	for (int i = 0; i < m_length; ++i) cout << m_data[i] << ' ';
	cout << endl;
}
