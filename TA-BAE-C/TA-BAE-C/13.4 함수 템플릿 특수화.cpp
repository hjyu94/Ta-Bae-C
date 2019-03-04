// �������� ��ɿ� ���ؼ� ���ø� ���α׷����� �ϴ� ����
// Ư�� �ڷῡ ���ؼ��� �ٸ� ����� �����ϰ� ���� ���� �ִ�
// �̷��� ���ø� Ư��ȭ�� ����Ѵ�.

#include <iostream>
#include "13.4 Storage.h"
using namespace std;

template<typename T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}

// char Ÿ�Կ� ���ؼ��� �ٸ� ������� ó���ϰ� ���� ��
template<>
char getMax(char x, char y)
{
	cout << "Warning: comparing chars" << endl;
	return (x > y) ? x : y;
}

int main1()
{
	cout << getMax(1, 2) << endl; // �Ķ���Ͱ� int�� �ڵ������� �ν��Ͻÿ��̼� ��
	cout << getMax<int>(1, 2) << endl;

	cout << getMax<double>(1.0, 2.0) << endl; // double
	cout << getMax<double>(1, 2) << endl; // �굵 double
	
	cout << getMax('a', 'b') << endl;

	return 0;
}

/***********************************************************************/

int main()
{
	Storage<int> nValue(5);
	Storage<double> dValue(6.7);

	nValue.print();
	dValue.print()
}