#include <iostream>
using namespace std;

template<typename T>
class Resource
{
public:
	T* m_data = nullptr;
	unsigned m_length = 0;

public:
	Resource()
	{
		cout << "Resource default constructor" << endl;
	}

	Resource(unsigned length)
	{
		m_data = new T[length];
		m_length = length;
	}

	Resource(const Resource& res)
	{
		// deep copy (shallo copy, X)
		cout << "Resource copy constructor" << endl;
		Resource(res.m_length);
		for (unsigned i = 0; i < res.m_data; ++i)
			m_data[i] = res.m_data[i];
	}

	~Resource()
	{
		cout << "Resource dstroyed" << endl;
		if (m_data)
		{
			delete[] m_data;
			m_data = nullptr;
			m_length = 0;
		}
	}

	// copy assignment
	Resource& operator = (Resource& res)
	{
		cout << "Resource copy assignment" << endl;
		
		if (&res == this) return *this;
		if (this->m_data != nullptr) delete[] m_data;

		m_length = res.m_length;
		m_data = new T[m_length];

		for (int i = 0; i < m_length; ++i)
			m_data[i] = res.m_data[i];

		return *this;
	}

	void print()
	{
		for (unsigned i = 0; i < m_length; ++i)
			cout << m_data[i] << " ";
		cout << endl;
	}
};

template<typename T>
class AutoPtr
{
private:
	T* m_ptr;

public:
	AutoPtr(T* ptr = nullptr)
		: m_ptr(ptr)
	{
		cout << "AutoPtr default constructor" << endl;
	}

	~AutoPtr()
	{
		cout << "AutoPtr destructor" << endl;
	}

	////##1. Parameter: L-value reference
	//
	//AutoPtr(const AutoPtr& a)
	//{
	//	cout << "AutoPtr copy constructor" << endl;
	//	
	//	// deep copy 
	//	// -> ���������� �����ϴ� ������ �־ �ӵ��� �� ����
	//	*m_ptr = *a.m_ptr; // deep copy: resource copy assignment
	//	//m_ptr = a.m_ptr; // shallow copy
	//	a.m_ptr = nullptr; 
	//}
	//
	//AutoPtr& operator = (const AutoPtr& a)
	//{
	//	cout << "AutoPtr copy assignment" << endl;
	//	
	//	if (&a == this) return *this;
	//	
	//	m_ptr = new T;
	//	// deep copy
	//	// ��� �����͸� �ϳ��ϳ� �����ؿ��� ������ ��������� �Ѵ�
	//	*m_ptr = *a.m_ptr;
	//	
	//	return *this;
	//}
	
	////##2. Parameter: R-value reference
	AutoPtr(AutoPtr&& a)
		// a�� �޸𸮸� ���� �ְ� �ƴ϶�
		// ��� �ִٰ� ����� ��
		// R value�� �޾Ƽ� shallow copy�� ����
		: m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr; // really necessary?
		// AutoPtr�� �Ҹ��ڰ� Ȥ�ó� �Ҹ�ɱ�� ������ ����

		cout << "AutoPtr move constructor" << endl;
		// ���� �Ѱ��� �� ���踸 �� �ִ� ��.
		// ���� ��°�� �� �ű�� ���� �ʿ� ����.
	}

	AutoPtr& operator = (AutoPtr&& a)
	{
		cout << "AutoPtr move assignment" << endl;
		
		if (&a == this)
			return *this;
		
		if (!m_ptr) delete m_ptr;

		// shallow copy
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr; // really necessary?

		return *this;
	}
};

AutoPtr<Resource<int>> generateResource()
{
	AutoPtr<Resource<int>> res(new Resource<int>(100000));

	return res;
	// �����ϴ� ������ ����ȴ�.
}

void main()
{
	{
		AutoPtr<Resource<int>> main_res;
		main_res = generateResource();
		// return �Ǵ� ���� R-value
	}

}