#include <iostream>

using namespace std;

void doSomething(const int& x);
void doOther(int& x);

int main()
{
	{
		// #1 ���۷��� ������ const�� ���
		// �ٸ� ���� ����ų �� ����
		int			x = 5, y = 1;
		const int&	ref_x = x;
		x = y;		// O
		ref_x = y;	// X
	}

	{
		// #2 ���� ������ const�� ���
		// const�� �ƴ� ���۷��� ������ ����ų �� ����.
		const int x = 5; // O
		int& ref_x = x;  // X
	}

	{
		// �Ʒ� ���� ��������?
		// �Լ��� �Ű������� ���� �� ���������� ���簡 �� �ʿ䰡 ����.
		const int  ref_x = 3 + 4;
		const int& ref_x = 3 + 4;

		// ���۷����� �޸� �ּҰ� �־�߸� �Ҵ� �����ϴ�.
		// �׷��� ���۷��� ������ const�̸� ���ͷ� ����� ���� �����ϴ�.
		int&		ref_x = 3;		// X
		const int&	ref_x = 3 + 4;	// O

		cout << ref_x << ", " << &ref_x << endl;
	}

	/********************************************************/

	int a = 1;
	doSomething(a);
	doSomething(1);
	doSomething(a+1);
	
	doOther(a); 
	doOther(1); // X // lvalue�� ���ڷ� ��� ����
	doOther(a+1); // X
}


void doSomething(const int& x)
{
	cout << x << endl;
}

void doOther(int& x)
{
	cout << x << endl;
}
