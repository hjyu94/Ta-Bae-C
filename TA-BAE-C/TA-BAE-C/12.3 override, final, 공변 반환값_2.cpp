#include <iostream>

using namespace std;

class A
{
public:
	void print() { cout << "A" << endl; }
	virtual A* getThis()
	{
		cout << "A::getThis()" << endl;
		return this;
	}
};

class B : public A
{
public:
	void print() { cout << "B" << endl; }
	virtual B* getThis() 
	{
		cout << "B::getThis()" << endl;
		return this; 
	}
	// ��ȯ�ϴ� ������ Ÿ���� �ٸ��� �������̵��� �� �Ǵµ�
	// A�� B�� �ڽ� �θ� ����� �������̵��̶�� �����Ѵ�.
};

void main()
{
	A a; B b;
	A& ref = b;

	b.getThis()->print();	
	// B::getThis()
	// B

	ref.getThis()->print(); 
	// B::getThis()
	// A
	// ���������� A ���� �ѹ� �� ���ļ� �����

	cout << typeid(b.getThis()).name() << endl;
	// class B * __ptr64
	cout << typeid(ref.getThis()).name() << endl;
	// class A * __ptr64
}