#include <iostream>

using namespace std;

class B; // ���� ����

class A
{
private:
	int m_value = 1;

	// friend class B1;
	// B�� �� ģ���� private ������ �Ѱ��־ �����ٴ� ǥ��
	// ���� ��� private�� �� �����ֱ�� �������ٸ�

	// B::doSomething ���Ը� ������ ���� �ִ�.
	friend void B::doSomething(A& a);
	// ���⼭ ���� ����!
	// class B�� �ִٴ� �� �˰ڴµ�
	// B�� doSomething�� �ִٴ� �� �� ���� ����
};

class B
{
	void doSomething(A& a)
	{
		cout << a.m_value << endl; // X
	}
};

/************************************************************/
// �׷��� class A, B ������ �ٲ㺽

class A1; // ���� ����

class B1
{
	void doSomething(A1& a)
	{
		cout << a.m_value << endl;
		// �̷��� �� �ٸ� ���� �߻�
		// Ŭ���� A �ȿ� m_value�� �ִٴ� �� �𸣴� ��Ȳ
	}
};

class A1
{
private:
	int m_value = 1;

	friend void B1::doSomething(A1& a);
};

/************************************************************/
// [�ذ�å]
// ������ �ش� �Լ��� ����� ���Ǹ� �и��Ѵ�

class A2; // ���� ����

class B2
{
	void doSomething(A2& a);
	//{
	//	cout << a.m_value << endl;
	//}
	// ����� ���� �и��ϱ�
};

class A2
{
private:
	int m_value = 1;

	friend void B2::doSomething(A2& a);
};

// A2 Ŭ���� ���ο� m_value�� �ִٴ°� �˰� �Ǹ�
// �׶� doSomething �Լ��� ���Ǹ� ���ش�.

void B2::doSomething(A2& a)
{
	cout << a.m_value << endl;
}

/************************************************************/

void main()
{ 

}