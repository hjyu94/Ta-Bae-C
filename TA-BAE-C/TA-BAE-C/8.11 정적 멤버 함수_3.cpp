#include <iostream>

using namespace std;

class Something
{
private:
	static int s_value;

public:	
	Something()
		: s_value(1024) // X
	{
		s_value = 1024; // O
	}
};

int Something::s_value = 1;


// static ��� ������ �������� �̴ϼȶ��������� �ʱ�ȭ �� �� ����.
//
//					static����		non-static����	static�Լ�	non-static�Լ�
// non static ftn:		O				O				O			O
// static ftn:			O				X				O			X

/**************************************************************/

class Sth
{
private:
	int m_value;
public:
	void non_print()
	{
		cout << m_value << endl;
	}
	static void print(Sth sth)
	{
		sth.non_print(); // ��� �����ѵ�
		non_print(); // �ִ� �Ұ���
	}
};

Sth::print(); //-> m_value�� ������ �� � ��ü�� ������ �����ؾ� �ϴ°�...
// ���� static �Լ����� non-static������ ������ �� ����.

/**************************************************************/

class Another
{
public:
	class _init
	{
	public:
		_init() { s_value = 999; }
	};

private:
	static int s_value;
	static _init s_initializer;

public:
	/*Another()
		: s_value(1024) // X
	{}*/
};
int Another::s_value = 1;
Another::_init Another::s_initializer; // ??????
// int a; ��?

// �갡 ��������鼭 inner Ŭ������ �����ڰ� �ʱ�ȭ�ǰ�
// inner Ŭ������ �����ڿ��� s_value �� �ʱ�ȭ �ȴ�.

// inner class���� ���������� ���

void main()
{

}