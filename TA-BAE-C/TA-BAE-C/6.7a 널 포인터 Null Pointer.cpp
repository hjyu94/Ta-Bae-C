#include <iostream>
#include <cstddef> // std::nullptr_t
using namespace std;

void doSomething(double* ptr)
{
	if (ptr != nullptr)
	{
		// do something useful
	}
	else
	{
		// do nothing with ptr
	}
}

int main()
{
	// double *ptr = 0; // c-style
	// double *ptr = NULL; 
	double *ptr = nullptr; // modern c++

	std::nullptr_t nptr; // nullptr�� ���� �� �ִ� ������ Ÿ��

}