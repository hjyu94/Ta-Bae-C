// https://dojang.io/mod/page/view.php?id=591

#include <iostream>
using namespace std;

// [�Լ� ������ �����]
// ��ȯ���ڷ��� (* �Լ��������̸� ) (�Ű�����1, ...) ;

/***********************************************************/

void hello()
{
	cout << "Hello!" << endl;
}

void bonjour()
{
	cout << "Bonjour le monde!" << endl;
}

void main1()
{
	cout << hello << endl; // �ּҰ� ��µ�
	
	void(*fp)() = hello;
	fp();

	fp = bonjour;
	fp();

}

/***********************************************************/

int add(int a, int b)
{
	return a + b;
}

void main()
{
	int(*fp_2)(int, int);
	fp_2 = add;
	cout << fp_2(10, 20) << endl;
}