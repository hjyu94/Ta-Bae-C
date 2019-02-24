// [early vinding, static binding]
// ��� identifier(�������̳� �Լ���)�� ����ϰ�
// ���� Ÿ�ӿ� �����Ǿ� ���� �� 

// [late binding, dynamic binding]
// func_ptr : ������Ÿ�ӿ� � �Լ��� ������ �������� ����
// func_ptr�� � �Լ��� �ּҰ� ���� ��Ÿ�ӿ� ������ �ȴ�.
// ���� ���س� ���� func_ptr�� ���� �������� �Ҵ��� �� �Լ��� �����͸�
// ã�ư��� �� �ּҸ� ã�ư��� �� �ּҿ� �ִ� �ش� �Լ��� 
// ȣ����Ѵ޶�� �ϴ� �������� ����� ����Ѵ�.

// �ӵ�?
// static binding�� �� ������
// �ּҸ� Ÿ�� �ѹ� �� �� �ʿ䰡 ���

// ������?
// dynamic binding�� �� �����ϴ�

#include <iostream>
using namespace std;

int add(int x, int y);
int subtract(int x, int y);

void main()
{
	int x, int y;
	cin >> x >> y;

	int op;
	cout << "0: add, 1:subtract" << endl;
	cin >> op;

	// static binding, early binding
	int result;
	switch (op)
	{
	case 0: result = add(x, y); break;
	case 1: result = subtract(x, y); break;
	}
	cout << result << endl;

	// dynamic binding, late binding
	int(*func_ptr)(int, int) = nullptr;
	switch (op)
	{
	case 0: func_ptr = add; break;
	case 1: func_ptr = subtract; break;
	}
	cout << func_ptr(x, y) << endl;
}

int add(int x, int y)
{
	return x + y;
}
int subtract(int x, int y)
{
	return x - y;
}