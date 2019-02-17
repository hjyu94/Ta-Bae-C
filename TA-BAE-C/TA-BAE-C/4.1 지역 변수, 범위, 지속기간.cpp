// [���� �����̽�]
// http://soen.kr/lecture/ccpp/cpp3/34-1-2.htm

#include <iostream>

// ���� �����̽��� �ݵ�� ���� ������ �����ؾ� �Ѵ�
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
	cout << endl;

	cout << work1::a << endl; // 1
	work1::doSomething();
	cout << work1::a << endl; // 4


}

// apple = 999; // X


// ����:

namespace {
	int internal; 
} // C++ style
static int internal1; // C stype

// �ܺη� �˷����� �ʴ´�.
// �ٸ� cpp ���Ͽ��� �ش� �������� ����� �� ����.