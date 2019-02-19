#include <iostream>

using namespace std;

class A
{
public:
	A() { cout << "Constructor" << endl; }
	~A() { cout << "Destructor" << endl; }

	void print() { cout << "Hello" << endl; }
};

void main()
{
	A a;
	a.print();
	cout << endl;

	A().print(); // �͸�ü ���
	// 1) A()�� r-value ó�� �۵��Ѵ�
	// 2) ������ �Ұ����ϴ�. (print�� ������ �θ� �� ����)
	// 3) ��� �� �ٷ� �Ҹ��ڰ� ȣ��ȴ�.
	cout << endl;

	A().print();
	cout << endl;

}