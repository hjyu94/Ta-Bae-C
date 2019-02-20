#include <iostream>

using namespace std;

class Base
{
protected:
	int m_i;

public:
	Base(const int& value = 0)
		: m_i(value)
	{}

	void print() { cout << "I'm base" << endl; }
};

/**********************************************************************/

class Derived : public Base
{
private:
	double m_d;

public:
	Derived(const double& value)
		: m_d(value)
	{}
};

void main1()
{
	Derived derived(3.14);
	derived.m_i = 10; // protected �� �ܺο��� �׼��� �Ұ���
	derived.print(); // public���� �ܺο��� ��� ����
}

/**********************************************************************/

class Derived2 : public Base
{
private:
	double m_d;

public:
	Derived2(const double& value)
		: m_d(value)
	{}

	using Base::m_i; // Derived2������ m_i�� publicó�� �� �� �־���

private:
	// Base�� print �Լ��� ������� �ʰ� �ϴ� ���
	/* 1 */
	using Base::print/*()*/; 
	// Derived2������ print�� private���� ������
	// ��ȣ�� ����� ��
	
	/* 2 */
	void print() = delete;
};

void main()
{
	Derived2 derived(3.14);
	derived.m_i = 10; // public���� ���ؼ� �ܺο��� �׼��� ����
	derived.print(); // private���� ���ؼ� �ܺο��� �׼��� �Ұ���, delete�ؼ� ��� �Ұ���
}