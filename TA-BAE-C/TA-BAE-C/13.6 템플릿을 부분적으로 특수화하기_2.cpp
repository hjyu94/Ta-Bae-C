// �Ķ���� �� �Ϻθ� Ư��ȭ �ϴ� �Լ���
// Ŭ������ ��� �Լ��� ����ϰ� �Ǹ� Ư��ȭ�� ����� �� ��
// ����� �̿��ؾ� �Ѵ�!

#include <iostream>

using namespace std;

template <typename T, int size>
class StaticArray_Base
{
private:
	T* m_array;

public:
	StaticArray_Base()
	{
		m_array = new T[size];
	}

	T& operator [] (const int index)
	{
		return m_array[index];
	}

	T* getArray()
	{
		return m_array;
	}

	void print()
	{
		for (int i = 0; i < size; ++i)
			cout << (*this)[i] << ' ';
		cout << endl;
	}
};

// ������ �̷��� ����ϴµ�
template <typename T, int size>
class StaticArray : public StaticArray_Base<T, size>
{};

// ��ӹ��� �� T�� char�϶� Ư��ȭ�ϱ�
template </*typename T,*/ int size>
class StaticArray<char, size> : public StaticArray_Base<char, size>
{
public:
	void print()
	{
		for (int i = 0; i < size; ++i)
			cout << (*this)[i];
		cout << endl;
	}
};


void main()
{
	StaticArray<int, 4> int4;
	int4[0] = 1;
	int4[1] = 2;
	int4[2] = 3;
	int4[3] = 4;
	int4.print();

	StaticArray<char, 14> char14;
	char14[0] = 'H';
	// ...
	strcpy_s(char14.getArray(), 14, "Hello, World");
	char14.print();
}