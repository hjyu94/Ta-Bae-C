
// �Լ��� �������̴�. �ּҸ� ���� �ִ�.
// �Լ��� �޸𸮿� ���´�.

// �Լ��� ȣ���ϸ�, 
// �ش� �Լ��� ��� �޸𸮿� �ִ��� �˾Ƴ���
// �� �޸𸮿� �ִ� ���α׷��� ȣ���Ѵ�.

#include <iostream>

using namespace std;

int func1() { return 5; }
int goo() { return 10; }

void main1()
{
	cout << func1 << endl;

	// ��ȯ���ڷ��� (* �Լ��������̸� ) (�Ű�����1, ...) ;

	int (* fcnptr) () = func1;

	cout << fcnptr << endl;

	fcnptr = goo;

	// �ٸ� �Լ��� ����Ű�� �� �� �ִ�.
	// �� �Ű��������� �¾� �������� �Ѵ�.
}

/*************************************************************************/
#include <array>

void printNumbers2(const array<int, 10>& arr, bool print_even)
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

	printNumbers2(my_array, true); // ¦���� ���
	printNumbers2(my_array, false); // Ȧ���� ���
}

/*************************************************************************/

#include <array>

bool isEven3(const int& number)
{
	if (number % 2 == 0) return true;
	else return false;
}

bool isOdd3(const int& number)
{
	if (number % 2 == 1) return true;
	else return false;
}

void printNumbers3(
	array<int, 10>& my_arr
	, bool(*check_ftn)(const int&) = isEven3 // �Ķ���� �⺻��
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
	printNumbers3(my_arr, isEven3);
	printNumbers3(my_arr, isOdd3);
}

/*************************************************************************/
#include <array>

typedef bool(*check_fcn_t)(const int&);
using check_fcn_t = bool(*)(const int&);

bool isEven4(const int& number)
{
	if (number % 2 == 0) return true;
	else return false;
}

bool isOdd4(const int& number)
{
	if (number % 2 == 1) return true;
	else return false;
}

void printNumbers4(array<int, 10>& my_arr, check_fcn_t check_fcn)
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
	
	printNumbers4(my_arr, isEven4);
	printNumbers4(my_arr, isOdd4);
}

/*************************************************************************/

#include <array>
#include <functional>

bool isEven5(const int& number)
{
	if (number % 2 == 0) return true;
	else return false;
}

bool isOdd5(const int& number)
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
	
	std::function<bool(const int&)> fcnptr = isEven5;
	printArr(my_arr, fcnptr);
	
	fcnptr = isOdd5;
	printArr(my_arr, fcnptr);
}

/*************************************************************************/
array<int, 10> my_arr{ 0,1,2,3,4,5,6,7,8,9 };

// �Լ� ������ ����, �ʱ�ȭ
int func(double x, int y);

int(*ptr_fcn)(double, int) = func;

// �Ķ���ͷ� �Լ� �����Ͱ� ���� ���
void printNumbers_1(array<int, 10>& arr, bool(*check_ftn)(const int&))
{
	for (auto element : arr)
		if (check_ftn(element));
}

// �ʹ� ����!
typedef bool(*check_fcn_t)(const int&);
using check_fcn_t = bool(*)(const int&);

void printNumbers_2(array<int, 10>& arr, check_fcn_t check_fcn)
{
	for (auto element : arr)
		(check_fcn(element));
}

// #include <functional>
void printNumbers_3(
	array<int, 10>& arr
	, function<bool(const int&)> check_fcn
)
{
	for (auto element : arr)
		(check_fcn(element));
}

std::function<bool(const int&)> check_fcn_ptr = isEven;
printNumbers(my_arr, check_fcn_ptr)
