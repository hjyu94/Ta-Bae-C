#include <iostream>
#include <array>
using namespace std;

template<typename T>
class A
{
public:
	A(const T& input) {}

	void doSomething() 
	{
		cout << typeid(T).name() << endl;
	}

	void test() {}
};

template<>
class A<char>
{
public:
	A(const char& input) {}
	
	void doSomething()
	{
		cout << "Char type specialization" << endl;
	}

	// void test() {} // ����!
};

int main()
{
	A<int>		a_int(1);
	A<double>	a_double(3.14);
	A<char>		a_char('a'); 

	a_int.doSomething();
	a_double.doSomething();
	a_char.doSomething();

	a_int.test();
	a_double.test();
	a_char.test(); // X

	// �׳� �ٸ� Ŭ������ �����ϴ� �Ͱ� ������(A<char>�� ��ü���� test �Լ� ����)
	// ���ø��� �ν��Ͻÿ��̼��ΰ�ó�� ����� �� �ִ�.
}