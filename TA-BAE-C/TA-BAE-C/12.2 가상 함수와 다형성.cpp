// ������ virtual�� ����� �� �ؿ� �ִ� �Լ��� ��� virtual �� �ڵ�����ȴ�.
// �����ص� �׸������� �ҽ��� �д� ������� ���ؼ� virtual�� ������ָ� ����.

// �������̵� �� �� ���� Ÿ���� �ٸ��� ��� �Ǵ°�
// D::print�� �Լ���
// int print() { cout << "D" << endl; } �� ����
// ����Ÿ���� �ٲٸ� C�� �ƴ϶� A���� �ö󰡼� ��¼�ϴٰ� ���� ǥ������
// D Ŭ������ C�� ���������� ��ӹ޾����� �޿� Ÿ�� �ö󰡼� �ֻ���� �θ���� �����Ϸ��� �������ִ� ��

#include <iostream>
using namespace std;

class A
{
public:
	void print() { cout << "A" << endl; }
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
	A a; B b; C c; D d;
	A& ref = a;
	ref.print(); // A
	ref = b;
	ref.print(); // A
	ref = c;
	ref.print(); // A
	ref = d;
	ref.print(); // A
	cout << endl;

	// B& ref1 = a; // X
	// ref1.print(); // X
	B& ref1 = b;
	ref1.print(); // B
	ref1 = c;
	ref1.print(); // B
	ref1 = d;
	ref1.print(); // B
}