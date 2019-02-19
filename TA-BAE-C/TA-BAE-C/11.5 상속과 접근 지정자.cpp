// https://thrillfighter.tistory.com/531

#include <iostream>
using namespace std;

// 1�� 2�� �� ���ȿ� ������ ������ ���Ѵ�.

class Base
{
private: /* 1-��� */
	int m_private;
protected:
	int m_protected;
public:
	int m_public;

	// ��� Ŭ���� �������� ��� ���� ����
	void setValue(int a, int b, int c)
	{
		m_public = a;
		m_protected = b;
		m_private = c;
	}
};

class public_Derived : /*2-����*/ public Base
{
public:
	public_Derived(int a=0, int b=0, int c=0)
	{
		Base::m_public = a;
		Base::m_protected = b; // protected: �Ļ�Ŭ������ ���Ǻο����� ������ ����������
		Base::m_private = c;
	}
};

void A1(public_Derived public_derived){
	public_derived.m_public;
	public_derived.m_protected; // �ܺο����� ������ �Ұ����ϴ�. 
								// (���Ŭ������ ��ü��, �Ļ�Ŭ������ ��ü)
	public_derived.m_private;
}

/******************************************************************************************************/

class protected_Derived : protected Base
// protected ��� : 
// ��� Ŭ������ �Ӽ� ���� �������� �ǹ̸� �ּ� protected�� �����.
{
public:
	protected_Derived(int a = 0, int b = 0, int c = 0)
	{
		Base::m_public = a;		// -> protected
		Base::m_protected = b;	// ���� protected
		Base::m_private = c;	// ���� private���� ���� �Ұ�
	}
};

void B1(protected_Derived protected_derived) {
	// protected ����� �޾Ƽ�
	// ��� ������ �ּ� protected�� ����

	protected_derived.m_public;		// protected �̹Ƿ� �ܺο��� ���� �Ұ���
	protected_derived.m_protected;	// protected �̹Ƿ� �ܺο��� ���� �Ұ���
	protected_derived.m_private;	// X
}


class protected_Derived2 : public protected_Derived
{
public:
	protected_Derived2(int a = 0, int b = 0, int c = 0)
	{
		Base::m_public = a;		// protected �̹Ƿ� ���� ����
		Base::m_protected = b;	// protected �̹Ƿ� ���� ����
		Base::m_private = c;	// ���� private���� ���� �Ұ�
	}
};

void B2(protected_Derived2 protected_derived) {
	protected_derived.m_public;		// protected �̹Ƿ� �ܺο��� ���� �Ұ���
	protected_derived.m_protected;	// protected �̹Ƿ� �ܺο��� ���� �Ұ���
	protected_derived.m_private;	// X
}

/******************************************************************************************************/

class private_Derived : private Base
{
public:
	private_Derived(int a = 0, int b = 0, int c = 0)
	{
		Base::m_public = a;		// -> private
		Base::m_protected = b;	// -> private
		Base::m_private = c;	// ���� private���� ���� �Ұ�
	}
};

void C(private_Derived private_derived)
{
	private_derived.m_public;		// private �̹Ƿ� ���� �Ұ���
	private_derived.m_protected;	// private �̹Ƿ� ���� �Ұ���
	private_derived.m_private;		// private �̹Ƿ� ���� �Ұ���
}



class private_Derived2 : public private_Derived
{
public:
	private_Derived2(int a = 0, int b = 0, int c = 0)
	{
		Base::m_public = a;		// private �̹Ƿ� ���� �Ұ���
		Base::m_protected = b;	// private �̹Ƿ� ���� �Ұ���
		Base::m_private = c;	// private �̹Ƿ� ���� �Ұ���
	}
};

void C2(private_Derived2 private_derived)
{
	private_derived.m_public;		// private �̹Ƿ� ���� �Ұ���
	private_derived.m_protected;	// private �̹Ƿ� ���� �Ұ���
	private_derived.m_private;		// private �̹Ƿ� ���� �Ұ���
}