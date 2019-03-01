#include <iostream>

using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base()" << endl;
	}
	
	/* 1 */
	// virtual ~Base() 
	// �� ��� �ڽ� Ŭ������ �Ҹ��ڸ� override ��� ������ �� �ִ�.
	/* 2 */
	~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base
{
private:
	int* m_array;

public:
	Derived(int length)
	{
		cout << "Derived()" << endl;
		m_array = new int[length];
	}
	
	/* 1 */
	// virtual ~Derived () override
	/* 2 */
	~Derived ()
	{
		cout << "~Derived()" << endl;
		delete[] m_array;
		m_array = nullptr;
	}
};

void main()
{
	{
		// Derived derived(5);

		// Base()		// �θ� Ŭ���� ������
		// Derived()	// �ڽ� Ŭ���� ������
		// ~Derived()	// �ڽ� Ŭ���� �Ҹ���
		// ~Base()		// �θ� Ŭ���� �Ҹ���
	}

	{
		Derived* derived = new Derived(5);
		// Base()
		// Derived()

		Base* base = derived;
		
		delete base;
		// ~Base()
		// ~Derived() �� ȣ����� �ʴ´ٴ� ���� !!

		// �ڽ� Ŭ������ ���� ��������� �𸣴� ��찡 ����
		// �� ����� �� �䳢 �ٶ��� ��ġ...
		// �̷� ��� �������� �̿��ؼ� �θ� Ŭ������ �����ͷ�
		// ��ü�� ����Ű�� ��찡 ����.
		// �׷��� �̷� ��� �ڽ� Ŭ������ �Ҹ��ڰ� ȣ����� �ʴµ� ...

		// �� ��� �Ҹ��ڸ� virtual�� ������ָ� �ȴ�.
		// virtual ~Base(){ ... } �� ���
		// ~Derived()
		// ~Base()
		// ������ ȣ��ȴ�.
	}
}