#include <iostream>
using namespace std;

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div2(int a, int b);

/*
	[�Լ� ������ �迭]
	��ȯ���ڷ��� (*�Լ��������̸�[ũ��])(�Ű������ڷ���1, �Ű������ڷ���2);
*/

void main()
{
	int fcnNumber;
	int num1=100, num2=5;
	int(*fp[4])(int, int) = { add, sub, mul, div2 };

	while (true)
	{
		cout << "1.���ϱ� 2.���� 3.���ϱ� 4.������" << endl;
		cin >> fcnNumber;
		cout << fp[--fcnNumber](num1, num2) << endl;
	}
}

int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mul(int a, int b)
{
	return a * b;
}
int div2(int a, int b)
{
	return a / b;
}