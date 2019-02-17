
// �Լ��� �������̴�. �ּҸ� ���� �ִ�.
// �Լ��� �޸𸮿� ���´�.

// �Լ��� ȣ���ϸ�, 
// �ش� �Լ��� ��� �޸𸮿� �ִ��� �˾Ƴ���
// �� �޸𸮿� �ִ� ���α׷��� ȣ���Ѵ�.

#include <iostream>

using namespace std;

int func(int x) { return 5; }
int goo() { return 10; }

void main1()
{
	cout << func << endl;

	/*
		(�Լ� ���� Ÿ��) (* (���� �̸�)) (�Լ� �Ķ���� Ÿ��); // ����
		(�Լ� ���� Ÿ��) (* (���� �̸�)) (�Լ� �Ķ���� Ÿ��) = (�Լ���) // �ʱ�ȭ����
	*/

	int (* fcnptr) (int) = func;

	cout << fcnptr(5) << endl;

	// int(*ptr_ftn) () = goo;

	// fcnptr = goo; // x
	// �ٸ� �Լ��� ����Ű�� �� �� �ִ�.
	// �� �Ű��������� �¾� �������� �Ѵ�.

	// cout << fcnptr() << endl; // x
}

/*************************************************************************/
#include <array>

void printNumbers(const array<int, 10>& arr, bool print_even)
{
	for (auto element : arr)
	{
		if (print_even && element % 2 == 0) cout << element;
		if (!print_even && element & 2 == 1) cout << element;
	}
	cout << endl;
}

void main2()
{
	std::array<int, 10> my_array{ 0,1,2,3,4,5,6,7,8,9 };

	printNumbers(my_array, true); // ¦���� ���
	printNumbers(my_array, false); // Ȧ���� ���
}

/*************************************************************************/

#include <array>

bool isEven(const int& number)
{
	if (number % 2 == 0) return true;
	else return false;
}

bool isOdd(const int& number)
{
	if (number % 2 == 1) return true;
	else return false;
}

void printNumbers(
	array<int, 10>& my_arr
	, bool(*check_ftn)(const int&) = isEven // �Ķ���� �⺻��
)
{
	for (auto element : my_arr)
	{
		if (check_ftn(element)) cout << element << ",";
	}
	cout << endl;
}

void main3()
{
	array<int, 10> my_arr = { 0,1,2,3,4,5,6,7,8,9 };
	printNumbers(my_arr, isEven);
	printNumbers(my_arr, isOdd);
}

/*************************************************************************/
#include <array>

typedef bool(*check_fcn_t)(const int&);
using check_fcn_t = bool(*)(const int&);

bool isEven(const int& number)
{
	if (number % 2 == 0) return true;
	else return false;
}

bool isOdd(const int& number)
{
	if (number % 2 == 1) return true;
	else return false;
}

void printNumbers(array<int, 10>& my_arr, check_fcn_t check_fcn)
{
	for (auto element : my_arr)
	{
		if (check_fcn(element)) cout << element << ",";
	}
	cout << endl;
}

void main4()
{
	array<int, 10> my_arr = { 0,1,2,3,4,5,6,7,8,9 };
	
	printNumbers(my_arr, isEven);
	printNumbers(my_arr, isOdd);
}

/*************************************************************************/

#include <array>
#include <functional>

bool isEven(const int& number)
{
	if (number % 2 == 0) return true;
	else return false;
}

bool isOdd(const int& number)
{
	if (number % 2 == 1) return true;
	else return false;
}

void printArr(
	array<int, 10> my_arr
	, function<bool(const int&)> check_fcn
)
{
	for (auto element : my_arr)
		if (check_fcn(element)) cout << element << ",";
	cout << endl;
}

void main5()
{
	array<int, 10> my_arr{ 0,1,2,3,4,5,6,7,8,9 };
	
	std::function<bool(const int&)> fcnptr = isEven;
	printArr(my_arr, fcnptr);
	
	fcnptr = isOdd;
	printArr(my_arr, fcnptr);
}

/*************************************************************************/
array<int, 10> my_arr{ 0,1,2,3,4,5,6,7,8,9 };

// �Լ� ������ ����, �ʱ�ȭ
int func(double x, int y);
int(*ptr_fcn)(double, int) = func;

// �Ķ���ͷ� �Լ� �����Ͱ� ���� ���
void printNumbers(array<int, 10>& arr, bool(*check_ftn)(const int&))
{
	for (auto element : arr)
		if (check_ftn(element));
}

// �ʹ� ����!
typedef bool(*check_fcn_t)(const int&);
using check_fcn_t = bool(*)(const int&);

void printNumbers(array<int, 10>& arr, check_fcn_t check_fcn)
{
	for (auto element : arr)
		(check_fcn(element));
}

// #include <functional>
void printNumbers(
	array<int, 10>& arr
	, function<bool(const int&)> check_fcn
)
{
	for (auto element : arr)
		(check_fcn(element));
}

std::function<bool(const int&)> check_fcn_ptr = isEven;
printNumbers(my_arr, check_fcn_ptr)
