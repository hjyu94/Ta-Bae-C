#include <iostream>
using namespace std;

class A
{
public:
	virtual void print(int x) const { cout << "A" << endl; }
};

class B : public A
{
public:
	// ���� ���� �Ϸ��� �� �������̵��ε�
	// �Ķ������ ������ Ÿ���� �޶����� �����Ϸ��� �����ε� �ߴٰ� ������

	void print(short x) { cout << "B" << endl; }
	/*
		A& ref = b;
		ref.print(1);
	*/
	// �� �Լ��� ����ϸ� B�� �ƴ϶� A�� ��µ�

	// �Լ��� �Ķ���Ͱ� �ٸ��� �������̵��� �� �� ����.
	// �Լ� ���忡���� �������̵��� �ƴ϶� �����ε� �߳� ���� ����
	
	virtual void print(short x) const override { cout << "B" << endl; }
	// ������ġ ���? -> override Ű����!
	// �������̵��̶�� ��������� �� �Լ��� ������ �������̵� �� �Լ�!
	// Ȥ�� �� ������ ������ ã���ش�
	// �Ǽ��� int�� short��� ���� �Ŷ�� �����ؼ� �����ٷ� ������ ǥ������
};

class C : public B
{
public:
	virtual void print() final { cout << "C" << endl; }
	// �ش� �Լ��� �������̵� �� �� ���ٰ� ���� ���� ���
};

class D : public C
{
public:
	virtual void print() { cout << "D" << endl; }
	// �θ� Ŭ������ C���� �ش� �Լ��� final�� �����־
	// �ڽ� Ŭ������ D���� �������̵� �� �� ����.
};

void main()
{
	B b;
	A& ref = b;
	ref.print(1);
}