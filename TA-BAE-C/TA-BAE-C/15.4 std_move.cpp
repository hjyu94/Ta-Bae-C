// move semantics�� ��� �ۿ��ϴ��� � ������ �ִ���
// �ֱ������� move semantics�� ����ϴ� ����
// �����Ϸ��� ������ �ƴ϶� ���α׷��� ������ move semantics�� ������� ����
// �����ϰ� ���� ���� �ִµ� �̷� �� ��밡�q�� std::move�� �˾ƺ���.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Resource
{
private:
	int* m_data = nullptr;
	unsigned m_length = 0;

public:
	Resource(const int _iLength = 0)
	{
		cout << "Resource length constuctor" << endl;
		m_data = new int[_iLength];
		m_length = _iLength;
	}

	void print()
	{
		for (unsigned i = 0; i < m_length; ++i)
			cout << m_data[i] << ' ';
		cout << endl;
	}

	void setAll(const int& v)
	{
		for (unsigned i = 0; i < m_length; ++i)
			m_data[i] = v;
	}
};

template<typename T>
class AutoPtr
{
public:
	T* m_ptr;

public:
	AutoPtr(T* _pInput = nullptr)
		: m_ptr (_pInput)
	{
		cout << "AutoPtr �⺻ ������" << endl;
	}

	~AutoPtr()
	{
		cout << "AutoPtr �Ҹ���" << endl;
		if (m_ptr != nullptr) delete m_ptr;
	}

	AutoPtr(const AutoPtr& a)
	{
		cout << "AutoPtr ���� ������" << endl;

		// deep copy
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}

	AutoPtr& operator= (const AutoPtr& a)
	{
		cout << "AutoPtr ���� ���� ������" << endl;
		if (&a == this) return *this;
		if (m_ptr != nullptr) delete m_ptr;
		
		// deep copy
		m_ptr = new T;
		*m_ptr = *a.m_ptr;

		return *this;
	}

	// ���� �����ڳ� ���� ���� �����ڸ�
	// ������ ������� �ʰԲ� �ϰ� ���� ��
	// AutoPtr(const AutoPtr& a) = delete;
	// AutoPtr& operator= (const AutoPtr& a) = delete;

	AutoPtr(AutoPtr&& a)
		: m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr;
		cout << "AutoPtr �̵� ������" << endl;
	}

	AutoPtr& operator= (AutoPtr&& a)
	{
		cout << "AutoPtr �̵� ���� ������" << endl;
		if (&a == this) return *this;
		if (!m_ptr) delete m_ptr;

		// shallow copy
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
};

template<typename T>
void MySwap(T& a, T& b)
{
	//1) ���簡 ���� �Ͼ.
	T temp = a;	// ���� ������
	a = b;		// ���� ���� ������
	b = temp;	// ���� ���� ������

	/*
		Resource res = res_a;	// ���� ������
		res_a = res_b;			// ���� ���� ������
		res_b = res;			// ���� ���� ������
	*/

	////2) std::move �� �̿��غ��� -> r-value�� �ν�
	//T tmp(std::move(a));
	//a = std::move(b);
	//b = std::move(tmp);
}

int main()
{
	{
		AutoPtr<Resource> res1(new Resource(10));
		cout << res1.m_ptr << endl;

		AutoPtr<Resource> res2(res1); // ���� ������
		// AutoPtr<Resource> res2;
		// res2 = res1; �̰Ŵ� ���� ���� ������ 

		cout << res1.m_ptr << endl; // �ּҰ� 1
		cout << res2.m_ptr << endl; // �ּҰ� 2 
		// (���������� ���Ӱ� �����Ҵ� �� ��, �ű⿡ �����ϱ�)
		// copy semantics, value semantics
	}

	cout << endl;
	
	{
		AutoPtr<Resource> res1(new Resource(10));
		cout << res1.m_ptr << endl; // �ּҰ� 1

		AutoPtr<Resource> res2(std::move(res1)); // �̵� ������
		// std::move�� r-value�� ������
		// �����ڰ� res1�� �ν��Ҷ� l-value�� �ƴ϶� r-value�� �ν����ִ� ��
		
		// (���Ӱ� �����Ҵ��ؼ� ���°Ŷ�� ������ ���� ������)
		// res1�� ���� �� �̻� ������� ���� ���̶��
		// ���α׷��Ӱ� �Ǵ����� �� r-valueó�� �Ѱ��� ���� �� �ִ�.

		cout << res1.m_ptr << endl; // �ּҰ� 1
		cout << res2.m_ptr << endl; // �ּҰ� 2 
		// move semantics
		// �ּҸ� ���ѱ�� nullptr�� �Ǹ�
		// ������ ��� ���� ���� �ּҰ��� ���� �ȴ�.
	}

	cout << endl;

	{
		AutoPtr<Resource> res1(new Resource(3));
		res1->setAll(3);

		AutoPtr<Resource> res2(new Resource(5));
		res2->setAll(5);

		res1->print();
		res2->print();

		MySwap(res1, res2);

		res1->print();
		res2->print();
		// Resource �� ���ؼ� �̵� ������, �̵� ���� ������ ����
		// �츮�� ���� ������ ���ұ� ������ ������ ���̴�.
	}
	cout << endl;
	{
		vector<string> v;
		string str = "Hello";
		
		v.push_back(str); 
		// push_back ���� ���콺�� �÷�������.
		// l-value�� �޾Ƶ��δ�. copy-semantics ����Ѵ�.
		
		cout << str << endl;	// Hello
		cout << v[0] << endl;	// Hello

		v.push_back(std::move(str));
		// push_back ���� ���콺�� �÷�������.
		// r-value�� �޾Ƶ��δ�. move-semantics
		
		cout << str << endl; // �ƹ��͵� ��� �ȵ�, move-semantics�� ���ѱ� ��
		cout << v[0] << " " << v[1] << endl; // Hello Hello

		// std::vector�� ������ �������
		// r-value�� ���ؼ� �̵� ������, �̵� ���� ������ ����
		// �̸� �����س��ұ� ������ std::move�� ��� ���� �Ѱ�.
	}
	cout << endl;
	{
		string x("abc");
		string y("de");

		cout << "x: " << x << endl;
		cout << "y: " << y << endl;

		MySwap(x, y);

		cout << "x: " << x << endl;
		cout << "y: " << y << endl;
	}
}