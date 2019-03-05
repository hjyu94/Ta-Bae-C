#include <iostream>
using namespace std;

// ���ø� �Ķ���Ͱ� �������� �� 
// �Ϻ� �Ķ���Ϳ� ���ؼ��� Ư��ȭ�� �ϴ� ���

template<typename T, unsigned int size>
class StaticArray
{
private:
	T* m_array;

public:
	StaticArray()
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
};

template <typename T, int size>
void print(StaticArray<T, size>& arr)
{
	for (int i = 0; i < size; ++i)
		cout << arr[i] << ' ';
	cout << endl;
}

// size�� int�� �ΰ� T�� char Ÿ���϶� Ư��ȭ�ϱ�
template</*typename T,*/ int size>
void print(StaticArray<char, size>& arr)
{
	for (int i = 0; i < size; ++i)
		cout << arr[i];
	cout << endl;
}

void main()
{
	StaticArray<int, 4> int4;
	int4[0] = 1;
	int4[1] = 2;
	int4[2] = 3;
	int4[3] = 4;
	print(int4);

	StaticArray<char, 14> char14;
	char14[0] = 'H';
	// ...
	strcpy_s(char14.getArray(), 14, "Hello, World");
	print(char14);
}