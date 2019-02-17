#include <iostream>

using namespace std;

// [1. return by value]
// ���� �����ؼ� ������

int getValue1(int x)
{
	int value = x * 2;
	return value;
}

void main1()
{
	int value = getValue1(5);
}

/************************************************************/

// [2. return by pointer]
int* getValue2(int x)
{
	int value = x * 2;
	return &value;
} 

void main2()
{
	int value = *getValue2(5); // �׳��� ���⼭�� value�� ���� ������ ����
	cout << value << endl; // 10
	cout << value << endl; // 10

	int* value2 = getValue2(5); // �̰� �� ����
	cout << *value2 << endl; // 10
	cout << *value2 << endl; // -858993460 // ������ ��µ�

}
// getValue���� value�� ���������� �Լ��� ����� ����� ����
// ����� ���������� �̿��ؼ� ���� ����ϴ� ����� ������ �� �ִ�.

/************************************************************/

// [3. return by reference]
int& getValue3(int x)
{
	int value = x * 2;
	return value;
} // value�� ���������� ��ȣ ������ �޸𸮸� �ݳ��ع��� �Ŷ� ���� �߻�

void main()
{
	int& value = getValue3(5);
	cout << value << endl; // 10
	cout << value << endl; // -858993460 // ������ ��µ�
}

/************************************************************/
