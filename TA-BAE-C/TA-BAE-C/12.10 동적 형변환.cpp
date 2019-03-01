#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
	int m_i = 0;

	virtual void print()
	{
		cout << "I'm Base" << endl;
	}
};

class Derived1 : public Base
{
public:
	int m_j = 1024;

	virtual void print() override
	{
		cout << "I'm dervied" << endl;
	}
};

class Derived2 : public Base
{
public:
	string m_name = "Dr. Two";

	virtual void print() override
	{
		cout << "I'm dervied" << endl;
	}
};

void main()
{
	{
		Derived1 d1;
		Base* base = &d1;

		/*
			�θ� Ŭ�������� ���� �ڽ� Ŭ�������� �ִ� �͵��� 
			������ �� ��������.
			d1.m_j;		// O
			base->m_j;	// X
		*/

		// base ������ �ٽ� Derived�� ����Ű���� �� ���� ������?
		// (d1 ���� ���� ���Ϸ� �ٲ�ٰ� ���� �ٲٳİ� ����ٸ�
		// �Ķ���ͷ� Base�� �����Ͱ� �Ѿ�� ����� ����)

		// �ٵ� �ظ��ϸ� ��������ȯ ���ϴ°� ����. �򰥸�
		auto* base_to_d1 = dynamic_cast<Derived1*>(base);
		// base->m_j;	 // X
		base_to_d1->m_j; // O // �Ұ����߾����� ��������

		d1.m_j = 2048;
		cout << d1.m_j << endl; // 2048
		base_to_d1->m_j = 256;
		cout << d1.m_j << endl; // 256

		/**************************************************/

		// [���ǻ���]
		auto* base_to_d2 = dynamic_cast<Derived2*>(base);
		// cout << base_to_d2->m_name << endl;
		// ���... ������ �� �߰� �ƹ��͵� �� ��� ����?

		if (base_to_d2 != nullptr)
			base_to_d2->print();
		else
			cout << "Failed" << endl;
		// ĳ���ÿ� �����ϸ� nullptr�� �ݳ��Ѵ�
	}
	cout << endl << endl;


	/******************************************************************************/
	// dynamic cast�ʹ� �޸�
	// static cast�� �� �� �ִ� �� �ִ�� �Ǵ°ɷ� �о���δ�.
	// � ��쿡�� �ȵž� �� �͵� ��.

	{
		Derived1 d1;
		Base* base = &d1;

		auto* base_to_d1 = dynamic_cast<Derived1*>(base);
		if (base_to_d1 != nullptr)
			base_to_d1->print();
		else
			cout << "Failed" << endl;

		auto* base_to_d2 = dynamic_cast<Derived2*>(base);
		if (base_to_d2 != nullptr)
			base_to_d2->print();
		else
			cout << "Failed" << endl;
	}
	
	cout << endl;

	{
		Derived1 d1;
		Base* base = &d1;
	
		auto* base_to_d1 = static_cast<Derived1*>(base);
		if (base_to_d1 != nullptr)
			base_to_d1->print();
		else
			cout << "Failed" << endl;

		auto* base_to_d2 = static_cast<Derived2*>(base);
		if (base_to_d2 != nullptr)
			base_to_d2->print();
		else
			cout << "Failed" << endl;
	}
}