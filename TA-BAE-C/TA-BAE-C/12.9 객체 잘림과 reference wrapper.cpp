// �θ𺸴� �ڽ� Ŭ������ �� ���� ������ ������ �Ǵ� ��찡 ��ټ�.

// �ڽ� Ŭ������ �� �� ��ü���� Ŭ������
// �θ� Ŭ�������� �� ���� ������ �Լ��� ������ ���� �� �ִ�.
// �Լ� �����ε��� �Ǿ� ���� �� �ִ�.

// ���� ���� �θ��� ��ü�� ���� ū �ڽ� Ŭ������ ��ü�� ������ �����ϴ� ���?
// �ڽ� Ŭ�������� ���� ������ ��� ������� �Ǵµ�
// �̷��� �͵��� ��ü �߸��̶�� �Ѵ�.
// ���� �׸��� ū ��ü�� �������� �ϴٺ��� ����� ����!

#include <iostream>
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

class Derived : public Base
{
public:
	int m_j = 1;

	virtual void print() override
	{
		cout << "I'm derived" << endl;
	}
};

void doSomething(Base& b)
{
	b.print();
}

int main()
{
	Derived d;
	Base& b = d; 
	// Base �� ���۷����� Derived ��ü�� �־���
	// �������� �����ȴ�.

	b.print();
	// Base�� ���������� ����Ǿ�����
	// Derived Ŭ������ print �Լ��� ȣ��ȴ�.

	Base b2 = d; 
	// b2�� d�� �����ؼ� �ְ� �ִ�.
	// Derived���� �־��� ����(m_j)�� ��� �ɱ�?

	b2.print();
	// �ڽ� Ŭ������ �Լ����� ������ �� 
	// �ʿ��� �߰����� �����鵵 �� �߷� ������
	// Base Ŭ�������� �ִ� �����鸸 ȣ��ȴ�.
	// �ᱹ �������� �������.

	doSomething(d);
	// �������� �����Ǿ� I'm derived�� ȣ��ȴ�.

	// ���� 
	// void doSomething(Base& b) �� �ƴ϶�
	// void doSomething(Base& b) ���ٸ�
	// �������� ������� I'm based�� ȣ��ȴ�.
	
	return 0;
}