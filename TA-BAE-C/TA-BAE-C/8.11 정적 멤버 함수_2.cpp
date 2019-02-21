#include <iostream>

using namespace std;

class Something
{
private:
	static int s_value;
	int m_value;

public:
	static int static_fcn()
	{
		cout << m_value << endl;	// X
		return this->s_value;		// X
	}
	// # static ��� �Լ������� this �����͸� ����� �� ����. #
	// this�� �̿��ؼ� ���;� �ϴ� ��� ������ ����� �� ����.

	int non_static_fcn()
	{
		cout << m_value << endl;	// O // ���� ������ �� �������
		return this->s_value;		// O
	}
};

/*����:static*/ int Something::s_value = 1;

void main()
{
	Something sth;

	int(Something::*non_static_fptr)()	= &Something::non_static_fcn; // O
	int(*static_fptr)()					= &Something::static_fcn; // O

	/*******************************************************************/

	// [�����ϱ�]
	int(Something::*non_static_fptr)() = sth.non_static_fcn; // X
	// error C3867 : 'Something::non_static_fcn' 
	// : non - standard syntax; use '&' to create a pointer to member

	int(Something::*non_static_fptr)() = &(sth.non_static_fcn); // X
	// Something�� ��� �Լ� �����͸� �����ϰڴ�.
	// error C2276 : '&' 
	// : illegal operation on bound member function expression

	int(Something::*non_static_fptr)() = &Something::non_static_fcn; // O
	// �� �ν��Ͻ����� temp�� ������ �ּҿ� ���� �ִ°� �ƴ�
	// �Ű������� �ν��Ͻ��� �ּҸ� �Ѱ��ִ� ����� �����.
	// temp�� sth�� �ƴ϶� Something�� �����ִ� �Լ����� ��� �ǹ̸� ��� ��.
	
	// [ȣ���ϱ�]
	cout << (sth.*non_static_fptr)() << endl << endl;
	// sth�� ������ ������ �۵����� �ʴ´�.
	// non static ��� �Լ��� this �����Ϳ� ���ӵ� ���·� �۵��ϱ� ������
	// this �����͸� �˷��ֱ� ���� sth. �� �տ� �ٿ���� �Ѵ�.

	// non static ��� �Լ��� ���ο� this pointer�� �����Ǿ� ���Ǵ� ��

	/*******************************************************************/

	// int(Something::*static_fptr)() = &Something::static_fcn; // X
	// error C2440 : 'initializing' 
	// : cannot convert from 'int (__cdecl *)(void)' to 'int (__cdecl Something::* )(void)'

	int(*static_fptr)() = &Something::static_fcn; // O
	cout << static_fptr() << endl; // O
	// static ��� �Լ��� Ư�� �ν��Ͻ��� ��� ���� �����ų �� �ִ� ������ ���·� ���´�

}
