// C, C++
// new, delete�� �̿��ؼ�
// ���� �޸𸮸� ���� �����ؾ� �Ѵٴ� ���� ������
//
// �ֱ��� C������
// ����Ʈ �����͸� �����ؼ�
// ���κ� �����Ͽ���.

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

/*****************************************************************/

// [RAII��?] resource acquisition is initialization
// �����Ҵ� ���� ������ �޸� �ݳ����� å������ ó�����־�� �Ѵ�.
void doSomething()
{
	Resource *res = new Resource;
	// work with res
	delete res;
	return;
}

// [�̶� ���� �� �ִ� ���� 1]
// �߰��� ���ϵǾ� res�� �޸� �ݳ��� ���� �ʴ� ���
void doSomething()
{
	Resource *res = new Resource; // dull pointer(������ �޸𸮸� �ݳ����� �ʴ� ������)
	// work with res

	if (true) return; // early return

	delete res;
	return;
}
/*
	if (true)
	{
		delete res;
		return;
	}

	�̷������� �ٲٸ� �����ϱ� �ϴ�
	�ٵ� �������� ���Ѱ����� �Ǽ��� ���߸����� �ִ�.
*/

// [�̶� ���� �� �ִ� ���� 2]
// �߰��� ����ó�� res�� �޸� �ݳ��� ���� �ʴ� ���
void doSomething()
{
	try
	{
		Resource *res = new Resource; // dull ptr
		// work with res

		if (true) throw - 1;

		delete res;
	}
	catch (...)
	{

	}
}

/*****************************************************************/
// ������ ������ �Ǵ� ������ Ŭ������ ������

// std::auto_ptr<int>; �����غ��� 
// (C++98 �� ������µ�, C++17 ������ �����)

template<class T>
class AutoPtr
{
public:
	T* m_ptr = nullptr;

public:
	// �Ҹ��ڰ� ȣ��ɶ� �ڵ����� �޸𸮸� �ݳ��ϵ��� ���� Ŭ����

	AutoPtr(T* ptr = nullptr)
		: m_ptr(ptr)
	{
	}

	~AutoPtr()
	{
		if (m_ptr != nullptr) delete m_ptr;
	}


	// �������� ������ó�� �� �� �ְԲ� ������ �Լ�
	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
};

/*****************************************************************/

void doSomething()
{
	AutoPtr<Resource> auto_res(new Resource); // smart pointer
	
	if (true) return; // early return
	 
	return;
}

void doSomething()
{
	try
	{
		AutoPtr<Resource> auto_res(new Resource); // smart pointer

		if (true) throw - 1;
	}
	catch (...)
	{

	}
}

/*****************************************************************/

// AutoPtr�� ����
void doSomething()
{
	{
		AutoPtr<Resource> res1(new Resource);
		AutoPtr<Resource> res2;
		// Resource constructor�� �ѹ��� ȣ���
		// ��ġ int i; int* ptr1 = &i; int* ptr2 = nullptr; ��

		cout << res1.m_ptr << endl; // 0x100
		cout << res2.m_ptr << endl; // 0x000

		res2 = res1;
		// ���� �����ڰ� ȣ��ȴ�.
		// ��� �������� ��� ������.
		// ���⼭�� m_ptr ���� �״�� ����

		cout << res1.m_ptr << endl; // 0x100
		cout << res2.m_ptr << endl; // 0x100
	}
	// ���� ��ȣ�� ����� ���� res1, res2�� �Ҹ��ڰ� ȣ��Ǵµ�
	// res1, res2 ��� ���� �޸𸮸� ����Ű�� �־
	// �Ȱ��� ��ġ�� ������� ��.
	// ������ �޸𸮸� �� ������� ��Եȴ�.
	//
	// �������� ���� �������� ����
	// �� ���� �θ��� ������ �ִ� ��
	//
	// �ذ��?
	// res2 = res1; �� ������ �� �������� �Ѱ��ָ� �ȴ�.
}
