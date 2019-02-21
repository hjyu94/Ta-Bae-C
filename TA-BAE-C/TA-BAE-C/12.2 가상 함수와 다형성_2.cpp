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
	int print() { cout << "D" << endl; }
};

void main()
{
	cout << "2 version" << endl;
	A a; B b; C c; D d;

	A& ref1_1 = a;
	ref1_1.print(); // A

	A& ref1_2 = b;
	ref1_2.print(); // B

	A& ref1_3 = c;
	ref1_3.print(); // C

	A& ref1_4 = d;
	ref1_4.print(); // D

	cout << endl;


	// B& ref1 = a; // X
	// ref1.print(); // X

	B& ref2_1 = b;
	ref2_1.print(); // B

	B& ref2_2 = c;
	ref2_2.print(); // C
	
	B& ref2_3 = d;
	ref2_3.print(); // D

	cout << endl;

}