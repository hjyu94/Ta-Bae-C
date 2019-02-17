#include <iostream>

using namespace std;

int main()
{
	int i_v1 = 1, i_v2 = 2, i_v3 = 3;

	{
		// [0. ���� ������ const�� ���]
		int i_Val = 10;
		const int& i_Ref = i_Val;
		i_Val = 888;
		i_Ref = 999; // X
	}

	{
		// [1. const int�� �����ϴ� ����]
		// ���� ������ const���� �Ѵ�.
		const int i_Val = 4;
		const int& i_Ref = i_Val; // O
		i_Ref = i_v1;

		int& i_Ref = i_Val; // X
	}

	{
		// [2. const�� ���� ������ r-value�� �ʱ�ȭ ����]
		const int& const_ref = 5; // O
	}

}

/*****************************************************************/

void Something(int x)
{
	x++;
}

void Something_ref(int& x)
{
	x++;
}

void Something_const_ref(const int& x)
{
	x++; // �Ű������� const �̹Ƿ� �� ���� �Ұ���
	cout << x << endl;
}

void main2()
{
	int i_Val = 10;
	Something(i_Val);			// O
	Something_ref(i_Val);		// O
	Something_const_ref(i_Val);	// O

	Something(10);				// O
	Something_ref(10);			// X
	Something_const_ref(10);	// O
}