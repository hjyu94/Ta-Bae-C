// �޸� ������ �ȵǾ� �޸� ������ �߻��� ���� �ִ�
#include <iostream>
using namespace std;

void doSomething()
{
	try
	{
		int* i = new int[10000];

		// do something with i
		throw "error";

		delete[] i;
	}
	catch (...)
	{
		cout << "Catch" << endl;
	}

	// catch �ȿ��� i �� delete �� �� ���� ���ٴ� ����
	// �ذ��? unique_ptr<int> up_i(i); �� ����Ѵ�.
	// ������ ����� ��(�߰�ȣ ��, ����ó�� �� ��) �޸𸮸� �ڵ����� �����Ѵ�.
}

/****************************************************************/

class A
{
public:
	~A() { throw "error"; }
	// �Ҹ��ڿ����� ���ܸ� ���� �� ����.
};

void doSomething2()
{
	try { A a; }
	catch (...) { cout << "Catch" << endl; }
}

/****************************************************************/

