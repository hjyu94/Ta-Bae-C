// �θ� Ŭ�������� ������ ����� ���� �ϰ�
// ���ٿ��� ������ �� �����ϴ� �Լ��� ����� ������
// �Լ� ���� �Ȱ��� ���� ���� �� --> �������̵�

#include <iostream>
using namespace std;

class Base
{
private:
	int m_i;

public:
	Base(const int& value = 0)
		: m_i(value)
	{}

	void print()
	{
		cout << "I'm base" << endl;
	}

	// ����� ������ �����ε�
	friend ostream& operator << (ostream& out, Base base)
	{
		out << base.m_i; // friend �Լ��� private ����� ���� ����
		return out;
	}
};

class Derived : public Base
{
private:
	double m_d;

public:
	Derived(const double& value)
		: m_d(value)
	{}

	void print()
	{
		// print(); // �ڿ������� �θ� Ŭ������ �Լ��� ȣ�������� ������? // ���� ���ѷ��� ����
		Base::print(); // �θ� Ŭ������ �Լ� ȣ���ϴ� ���
		cout << "I'm derived" << endl;
	}

	// ����� ������ �����ε�
	friend ostream& operator << (ostream& out, Derived derived)
	{
		// Base:: ??? --> static cast! �� ĳ���� ���༭ �������
		out << static_cast<Base>(derived) << endl;
		out << derived.m_d;
		return out;
	}
};


void main()
{
	Base base(5);
	Derived derived(3.14);
	
	base.print();
	cout << endl;

	derived.print();
	cout << endl;

	cout << base << endl;
	cout << derived << endl;
}