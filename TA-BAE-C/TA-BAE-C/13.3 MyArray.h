#pragma once
#include <iostream>
#include <array>
#include <assert.h>

template<typename T, unsigned int T_SIZE>
// T_SIZE�� ������Ÿ�ӿ� �������־�� �Ѵ�.
class MyArray
{
private:
	// int m_length;
	T	*m_data;
	// T	m_data[T_SIZE]
	// �ص� ����� ������ stack�� �����Ͱ� ����ȴ�.

public:
	MyArray()
	{
		m_data = new T[T_SIZE];
	}

	T& operator[] (int index)
	{
		assert(index >= 0 && index < T_SIZE);
		return m_data[index];
	}

	int getLength()
	{
		return T_SIZE;
	}

	void print()
	{
		using namespace std;
		for (int i = 0; i < T_SIZE; ++i) cout << m_data[i] << ' ';
		cout << endl;
	}
};

