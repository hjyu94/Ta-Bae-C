#include <iostream>

using namespace std;

void main1()
{
	int array[5] = { 1,2,3,4,5 };
	cout << *array << endl; // 1�� ��µ�

	char name[] = "JackJack";
	cout << *name << endl; // JackJack? J? // J !
	cout << name << endl; // JackJack ! // '\0'���� ���

	// cout���� ���ڿ��� �ּҰ� ������ �ּҰ� �ƴ϶� ���ڿ��� ��µȴ�!!
}

/*******************************************************************/

// void printArray(int* array)�� ����
void printArray(int array[]) /* ���������� ������*/
{
	cout << sizeof(array) << endl;		// 8 (x64���� ������ ������ ������ 8byte)
}

int main()
{
	int array[5] = { 1,2,3,4,5 };
	int *ptr = array;

	cout << array << endl;		// �ּҰ� ��µ�
	cout << &array[0] << endl;	// �ּҰ� ��µ� (���� ��)

	cout << sizeof(array) << endl;		// 20 (int 5��) 
	printArray(array);					// 8 (x64���� ������ ������ ������ 8byte)
	cout << sizeof(&array[0]) << endl;	// 8 (x64���� ������ ������ ������ 8byte)
	cout << sizeof(ptr) << endl;		// 8 (x64���� ������ ������ ������ 8byte)
										// �迭 ������ ������ Ÿ���̶� ��� ����
}