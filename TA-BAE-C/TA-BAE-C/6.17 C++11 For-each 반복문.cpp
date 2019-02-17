#include <iostream>

using namespace std;

void main1()
{
	int fibonacci[] = { 0,1,1,2,3,5,8,13,21,34,55 };

	// [change array values 1]
	for (int number : fibonacci)
	 	number = 10;
	// �� �ٲ��� �ʴ´�.
	// number�� ���ο� �޸𸮸� �����ϰ� fibonacci�� ���Ҹ� �����ؿ��� ����

	// [change array values 2]
	for (int& number : fibonacci)
		number = 10;
	// �� �ٲ��.
	// fibonacci ���Ҹ� �����ؿ��� ������ �ƴϱ� ����

	// [change array values 3]
	for (int* number : fibonacci) // X
		*number = 10;

	// output
	for (int number : fibonacci)
		cout << number << ' ';
	cout << endl;
}

int main()
{
	int fibonacci[] = { 0,1,1,2,3,5,8,13,21,34,55 };

	for (auto& number : fibonacci)
		number = 10;
	
	for (const auto number : fibonacci)
		cout << number << ' ';
	cout << endl;
}

