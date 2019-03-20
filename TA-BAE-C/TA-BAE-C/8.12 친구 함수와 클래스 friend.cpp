#include <iostream>

using namespace std;

class A
{
private:
	int m_value = 1;
};

class B
{
private:
	int m_value = 2;
};

void doSomething(A& a, B& b)
{
	cout << a.m_value << ", " << b.m_value << endl;
}
// private ������ ����ؾ� �ϴ� �Լ��� ���� ��?
// ---> friend Ű���带 �̿��ؼ� �ذ�

/************************************************************/

// [�ذ�å]
// private ������ �ִ� Ŭ���� ������ 
// doSomething �Լ��� friend��� �����ָ�
// �ش� Ŭ������ private ������ ��� �����ϴ�.

// [���漱��]
// �ؿ� ��� B�� ���ǰ� ������
// B�� ���� �𸣴� ������ ������ �� �ؿ��� �о��
class B2;

class A2
{
private:
	int m_value = 1;

	friend void doSomething(A2& a, B2& b); 
	// ���漱���� ������ ���⼭ B2�� ���� ��
};

class B2
{
private:
	int m_value = 2;

	friend void doSomething(A2& a, B2& b);
};

void doSomething(A2& a, B2& b)
{
	cout << a.m_value << ", " << b.m_value << endl;
}

void main()
{

}