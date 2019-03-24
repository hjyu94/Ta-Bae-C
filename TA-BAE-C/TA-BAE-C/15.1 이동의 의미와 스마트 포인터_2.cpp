#include <iostream>
using namespace std;

class Resource
{
public:
	int m_data[100];

public:
	Resource()
	{
		cout << "Resource constructor" << endl;
	}

	~Resource()
	{
		cout << "Resource destructor" << endl;
	}
};

template<class T>
class AutoPtr
{
public:
	T* m_ptr = nullptr;

public:
	AutoPtr(T* ptr = nullptr)
		: m_ptr(ptr)
	{}

	~AutoPtr()
	{
		if (m_ptr != nullptr) delete m_ptr;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }

	/**********************************************/
	
	// copy constructor
	AutoPtr(AutoPtr& a)
	{
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr; // �������� �Ѱ��ش�!!
	}

	// assignment operator
	AutoPtr& operator = (AutoPtr& a)
	{
		if (&a == this)
			return *this;

		delete m_ptr; // �̹� ���� �����ִٸ� �´� ����������
		m_ptr = a.m_ptr;

		a.m_ptr = nullptr; // �������� �Ѱ��ش�!!
		return *this;
	}
	
};


void another(AutoPtr<Resource> ptr)
{}

void doSomething()
{
	{
		AutoPtr<Resource> res1(new Resource);
		AutoPtr<Resource> res2;

		cout << res1.m_ptr << endl; // 0x100
		cout << res2.m_ptr << endl; // 0x000

		res2 = res1;
		// ���� �����ڰ� ȣ��ȴ�.

		cout << res1.m_ptr << endl; // 0x000
		cout << res2.m_ptr << endl; // 0x100
	}
	
	// Move Semantics

	// Semantics: �������� �Ǵµ� ���������� �� �ǹ̰� ���İ� �߿�.
	// Syntax: ������ �´��� �ƴϳ�. �������� �Ǵ��� �ȵǴ���.

	// [syntax vs. semantics]
	int x = 1, y = 1;
	x + y;

	string str1("Hello"), str2("World");
	str1 + str2; 
	// ��ȣ�� + ��ȣ�� ������ string ������ append�� �ǹ̸� ���´�.
	// �̰� semantics!

	// [Semantics]
	// value semantics (copy semantics)
	// reference semantics (pointer)
	// move semantics (move)

	{
		AutoPtr<Resource> res1(new Resource);
		another(res1);
		// doSometing �Լ� res1�� �����ڷ� ����
		// �Լ��� �����鼭 �޸𸮸� �ݳ��ع����ϱ� �Լ� ȣ�� ���Ŀ� ������ ����⵵ �Ѵ�.
		// �̷� ������ ������ ���� �����ʹ� ����� ������ �Ǿ���
	}
}

