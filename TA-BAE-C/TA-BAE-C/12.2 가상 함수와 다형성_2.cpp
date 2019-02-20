// ������ virtual�� ����� �� �ؿ� �ִ� �Լ��� ��� virtual �� �ڵ�����ȴ�.
// �����ص� �׸������� �ҽ��� �д� ������� ���ؼ� virtual�� ������ָ� ����.

// �������̵� �� �� ���� Ÿ���� �ٸ��� ��� �Ǵ°�
// D::print�� �Լ��� ����Ÿ���� �ٲٸ� C�� �ƴ϶� A���� �ö󰡼� ��¼�ϴٰ� ���� ǥ������

#include <iostream>
using namespace std;

class A
{
public:
	virtual void print() { cout << "A" << endl; }
};

class B : public A
{
public:
	void print() { cout << "B" << endl; }
};

class C : public B
{
public:
	void print() { cout << "C" << endl; }
};

class D : public C
{
public:
	void print() { cout << "D" << endl; }
};

void main()
{
	cout << "2 version" << endl;
	A a; B b; C c; D d;

	A& ref1_1 = a;
	ref11.print(); // A
	A& ref1_2 = b;
	ref2.print(); // A
	A& ref1_3 = c;
	ref3.print(); // A
	A& ref1_4 = d;
	ref4.print(); // A
	cout << endl;

	// B& ref1 = a; // X
	// ref1.print(); // X
	B& ref2_1 = b;
	ref2_1.print(); // B
	ref1 = c;
	ref1.print(); // B
	ref1 = d;
	ref1.print(); // B
}