// ������ ���� �Ʒ��ʿ��� ���ܸ� ������ �Ǹ�
// ������ �ǰ��� ���鼭 ���ܸ� ó���ϰ� �ȴ�.

#include <iostream>
using namespace std;

// void last throw(int): exception specifier
// void last throw(...): exception specifier

// void last throw(): exception specifier
// --> ��� �ϳ��� �� ���� ���̴�!! ��� �� ������� ��
// --> �̷��� ������� ���ܸ� �� ������ ���� �߻�

// throw(int): int�� ������ ���� �ִ�.
void last() throw(int)
{
	cout << "last" << endl;
	cout << "Throws exception" << endl;
	throw - 1;

	cout << "End last" << endl; // ��� X
}

void third()
{
	cout << "third" << endl;
	last();
	// ���� ����
	cout << "End third" << endl; // ��� X
}

void second()
{
	cout << "second" << endl;
	try { third(); }
	//catch (int) { cerr << "second caught int exception" << endl; }
	catch (double) { cerr << "second caught double exception" << endl; }
	cout << "End second" << endl;
	// ������ End second���� �� ��µ�
}

void first()
{
	cout << "first" << endl;
	try { second(); }
	catch (int) { cerr << "first caught int exception" << endl; }
	cout << "End first" << endl;
}

void main()
{
	cout << "Start" << endl;
	try { first(); }
	catch (int) { cerr << "main caught int exception" << endl; }

	catch (...) // catch-all handlers
	{
		cerr << "man caught ellipses exception" << endl;
	}
	// � Ÿ���̴��� �� �����.

	cout << "End main" << endl;
}