#include <iostream>

namespace work1
{
	int a = 1;
	void doSomething()
	{
		a += 3;
	}
}

namespace work2
{
	int a = 1;
	void doSomething()
	{
		a += 5;
	}
}

int main()
{
	using namespace std;

	// apple = 999; // X
	int apple = 5;
	apple = 1;
	
	cout << apple << endl; // 1

	// int apple = 888; // X // ������ �Ұ���
	{
		cout << apple << endl; // 1
		int apple = 888; // ������ ����, ��� ������ �Ѿ�� �������
		cout << apple << endl; // 888
	}
	
	cout << apple << endl; // 1

}

// apple = 999; // X