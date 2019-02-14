#include <iostream>

using namespace std;

//#### �Ű������� �������� ����
int foo(int x, int y); // prototype
// x, y�� foo��� �Լ��� parameter, �Ű�����

int foo(int x, int y)
{
	return x + y;
} // x and y are destroyed here


//#### ���� ���� ����
void doSomething(int x)
{
	cout << "In func " << x << ", " << &x << endl;
} 
// ���Ӱ� ������ ����� �������� ���� �Ű����� x�� ����ȴ�.


//#### ������ ���� ����
void doSomething2(int &x)
{
	cout << x << ", " << &x << endl;
	x = x + 1;
}
// ���۷��� ������ �̿��ϱ� ������ �ּҵ� �Ȱ��� ���絵 �̷����� �ʴ´�.


// degree: ���� ���� ����, ���� �ٲ� �Լ��� ������ �����. �Է����� ���� ��
// sin_out, cos_out: ������ ���� ����, ���� �ٲ��. ��������� ����
// ���۷����� �Լ��� �̿��ؼ� �������� ���� �������ִ� �÷� ����� ��

// const double degree: �Ű������� const�� ���?
//	: �Լ� ������ �ش� ������ ���� �ٲ��� �ʰڴ�.
// cf) �Լ��� const�� ���?
//	: Ŭ�������� ��� �Լ��� const�� ���� �� �ִµ�
//	: �ش� Ŭ������ ��� ���� ���� �ٲ��� �ʰڴٴ� ǥ���̴�.
void getSinCos(const double degree, double &sin_out, double &cos_out)
{
	static const double pi = 3.141592;
	// static: �ѹ� ���ǵǸ� ���߿� �� ���ǵɶ��� ������ ���� ����. ����ȴ�.
	// �Լ� �ۿ����� pi ���� ��� �Ұ� (4.2 ����)

	double radians = degree * pi / 180.0;

	sin_out = std::sin(radians);
	cos_out = std::cos(radians);
}

//#### �����Ϳ� ���� ����
void doSomething3(int *&ptr) /* ((int*) &ptr) */
{
	cout << ptr << ", " << &ptr << endl;
}
// �� ��� ������ ������ ���۷��� ������ �ޱ� ������
// �Լ� ������ ����� ������ ������ �ּҵ� �����ϰ� ��µȴ�.

int main()
{
	foo(6, 7); 
	// �̶� 6�� 7�� arguments, actual parameter ��� �Ѵ�
	// foo �Լ��� �Ű����� x, y�� 6, 7�� ����ȴ�. 

	cout << "���� ���� ����" << endl;
	int x = 6;
	cout << "In main " << x << ", " << &x << endl;
	doSomething(x);
	cout << endl;
	
	cout << "������ ���� �μ� ����" << endl;
	int y = 10;
	cout << y << ", " << &y << endl;
	doSomething2(y);
	cout << y << ", " << &y << endl;

	double sin(0.0);
	double cos(0.0);
	getSinCos(30.0, sin, cos);
	cout << sin << ", " << cos << endl;
	cout << endl;

	// ������ ���� �μ� ������ ����
	doSomething2(5);
	// ��ó�� ���������� ���� �� �ڸ��� ���ͷ� ������� ������ �ȴٸ�
	// void doSomething2(int &x)��
	// void doSomething2(const int &x)��
	// void doSomething2(int x)�� �ٲٸ� �ȴ�

	// �̷� ��츦 ����ؼ� �Ű��������� �����ϴٸ�
	// ������ ������ const�� �������ָ� ����.

	cout << "�����͸� �μ��� ����" << endl;
	int z = 5;
	int *ptr = &z;
	doSomething3(ptr);
	// void doSomething3(int *&ptr);

}