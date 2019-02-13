#include <iostream>
using namespace std;

// �����Ϳ� ���� �� ����
// �ּҸ� �����ؼ� ���ο� ���̿� ���� ��
void foo(int *ptr)
{
	cout << *ptr << "\t" << ptr << "\t" << &ptr << " :In foo() " << endl;
}

int main()
{
	int value = 5;

	cout << value << "\t" << &value << " :In main() " << endl;
	
	foo(&value);
	// foo(5); // ���ͷ��� �ٷ� �� �� ����
	/* 
		void foo(int &ptr){...}
		�� ��쿴�ٸ� void foo(const int &ptr)��
		const�� �߰����ָ� ���ͷ��� �Ѱ��� �� �ִ�.
	*/
	cout << endl;

	int *ptr = &value;
	cout << *ptr << "\t" << ptr << "\t" << &ptr << " :In main() " << endl;
	foo(ptr);

	// ���ο����� &ptr��
	// �Լ��� �Ű������� ���̴� ptr�� &ptr�� �ٸ���
	// ������ ������ �ϳ��� �����ν� �ּ� ���� �������ִ� ����̱� �����̴�.

	return 0;
}