#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
	int m_iBase = 0;

	virtual void print()
	{
		cout << "I'm Base" << endl;
	}
};

class Derived1 : public Base
{
public:
	int m_iDer = 1024;

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
			d1.m_iDer;		// O
			base->m_iDer;	// X
		*/

		// base ������ �ٽ� Derived�� ����Ű���� �� ���� ������?
		// (d1 ���� ���� ���Ϸ� �ٲ�ٰ� ���� �ٲٳİ� ����ٸ�
		// �Ķ���ͷ� Base�� �����Ͱ� �Ѿ�� ����� ����)

		// �ٵ� �ظ��ϸ� ��������ȯ ���ϴ°� ����. �򰥸�
		auto* base_to_d1 = dynamic_cast<Derived1*>(base);
		// base->m_iDer;	 // X
		base_to_d1->m_iDer; // O // �Ұ����߾����� ��������

		d1.m_iDer = 2048;
		cout << d1.m_iDer << endl; // 2048
		base_to_d1->m_iDer = 256;
		cout << d1.m_iDer << endl; // 256

		/**************************************************/

		// [���ǻ���]
		auto* base_to_d2 = dynamic_cast<Derived2*>(base);
		// cout << base_to_d2->m_name << endl;
		// ���... ������ �� �߰� �ƹ��͵� �� ��� ����?
		// (Derived1 -> Base -> Derived2 �� ��� �翬�ϱ� ��)

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
	Derived1 d1;
	Base* base = &d1;

	auto* base_to_d1 = dynamic_cast<Derived1*>(base);
	if (base_to_d1 != nullptr)
	{
		base_to_d1->print();
		cout << base_to_d1->m_iDer << endl;;
	}
	else
		cout << "Failed" << endl;

	auto* base_to_d2 = dynamic_cast<Derived2*>(base);
	if (base_to_d2 != nullptr)
	{
		base_to_d2->print();
		cout << base_to_d2->m_name << endl;
	}
	else
		cout << "Failed" << endl;

	/*
		[���]
		Derived
		1024
		Failed
	*/

	/********************************************************/

	base_to_d1 = static_cast<Derived1*>(base);
	if (base_to_d1 != nullptr)
	{
		base_to_d1->print();
		cout << base_to_d1->m_iDer << endl;;
	}
	else
		cout << "Failed" << endl;

	base_to_d2 = static_cast<Derived2*>(base);
	if (base_to_d2 != nullptr)
	{
		base_to_d2->print();
		cout << base_to_d2->m_name << endl;
	}
	else
		cout << "Failed" << endl;

	/*
		[���]
		Derived
		1024
		Derived
		("Dr. Two" �� �������� �ʴ´�.)
	*/

}