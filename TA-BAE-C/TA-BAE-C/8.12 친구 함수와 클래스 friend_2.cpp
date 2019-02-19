#include <iostream>

using namespace std;

// �ٸ� Ŭ�������� �� Ŭ������ �ִ� private ������ ����ϰ� ���� ���?
class A
{
private:
	int m_value = 1;
};

class B
{
	void doSomething(A& a)
	{
		cout << a.m_value << endl; // X
	}
};

/************************************************************/
// �ذ�å

class B1; // ���� ����

class A1
{
private:
	int m_value = 1;

	friend class B1;
	// B�� �� ģ���� private ������ �Ѱ��־ �����ٴ� ǥ��
};

class B1
{
	void doSomething(A1& a)
	{
		cout << a.m_value << endl; // O
	}
};

/************************************************************/

void main()
{

}