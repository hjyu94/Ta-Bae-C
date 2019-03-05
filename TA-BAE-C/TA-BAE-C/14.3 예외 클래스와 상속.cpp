#include <iostream>
using namespace std;

class Exception
{
public:
	void report()
	{
		cerr << "Exception report"<< endl;
	}
};

class ArrayException : public Exception
{
public:
	void report()
	{
		cerr << "Array Exception" << endl;
	}
};

class MyArray
{
private:
	int m_data[5];

public:
	int& operator [] (const int& index)
	{
		// ����Լ������� throw�� �� �� �ִ�.
		//if (index < 0 || index >= 5) throw - 1;
		//if (index < 0 || index >= 5) throw Exception();
		if (index < 0 || index >= 5) throw ArrayException();

		return m_data[index];
	}
};

void doSomething()
{
	MyArray my_array;
	
	try
	{
		my_array[100];
	}
	catch (const int& x)
	{
		cerr << "Exception " << x << endl;
	}
	catch (Exception& e)
	{
		cout << "doSomething() ";
		e.report();
		// ArrayException�� ��ü�� �޾��ֱ� ������
		// �θ��� report �Լ��� ȣ��ȴ�.

		// re-throw ���� // main������ catch���� �� �޾���
		throw e; // ��ü�߸� // Exception���� �޾���
		throw;   // ArrayException���� �޾��ְ� ��
	}
	catch (ArrayException& e)
	{
		cout << "doSomething() ";
		e.report();
		// ������ ���� catch�Ǿ� ������� ����.
		// ���� ������ �ٲٸ� ArrayException�� report �Լ��� ȣ��ȴ�.
	}
} 

void main()
{
	try
	{
		doSomething();
	}

	catch (Exception& e)
	{
		cout << "main() ";
		e.report();
	}

	catch (ArrayException& e)
	{
		cout << "main() ";
		e.report();
	}
}