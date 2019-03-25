#include <iostream>
using namespace std;

class Resource
{
public:
	int* m_data;
	int m_length;

	Resource(int _length = 0)
	{
		cout << "Resource ������" << endl;
		m_data = new int[_length];
		m_length = _length;
	}

	~Resource() 
	{
		cout << "Resource �Ҹ���" << endl;
		if(m_data) delete m_data; 
	}
	
	Resource(Resource& res)
	{
		cout << "Resource ���� ������" << endl;
		Resource(res.m_length);
		for (unsigned i = 0; i < m_length; ++i)
			m_data[i] = res.m_data[i];
	}

	Resource& operator = (Resource& _copy)
	{
		cout << "Resource ���� ���� ������" << endl;
		if (this == &_copy) return *this;
		if (m_data) delete m_data;
		m_length = _copy.m_length;
		m_data = new int[m_length];
		for (int i = 0; i < m_length; ++i)
			m_data[i] = _copy.m_data[i];
		return *this;
	}
};

template <typename T>
class AutoPtr
{
public:
	T* m_data = nullptr;

	AutoPtr(T* _data = nullptr)
	{
		cout << "AutoPtr ������" << endl;
		m_data = _data;
	}

	~AutoPtr()
	{
		cout << "AutoPtr �Ҹ���" << endl;
		if (m_data) delete m_data;
	}

	/*****************************************/
	AutoPtr(AutoPtr& _copy)
	{
		cout << "AutoPtr ���� ������" << endl;
		if (m_data) delete m_data;
		m_data = new T;
		*m_data = *_copy.m_data;
	}

	AutoPtr& operator = (AutoPtr& _copy)
	{
		cout << "AutoPtr ���� ���� ������" << endl;
		if (this == &_copy) return *this;
		if (m_data) delete m_data;
		m_data = new T;
		*m_data = *_copy.m_data;
		return *this;
	}
	/*****************************************/

	AutoPtr(AutoPtr&& _r_copy)
	{
		cout << "AutoPtr ���� ������" << endl;
		m_data = _r_copy.m_data;
	}

	/*****************************************/
	T& operator* () { return *m_data; }
	T* operator-> () { return m_data; }
};


AutoPtr<Resource> generateResource()
{
	AutoPtr<Resource> res(new Resource(10));
	return res;
}

void main()
{
	{
		AutoPtr<Resource> res1(new Resource(10));
		AutoPtr<Resource> res2 = res1;
	}
	cout << endl;
	{
		AutoPtr<Resource> main_res;
		main_res = generateResource();
		cout << main_res->m_data[2] << endl;
	}
}