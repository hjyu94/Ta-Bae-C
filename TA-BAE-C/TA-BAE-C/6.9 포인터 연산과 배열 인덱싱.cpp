#include <iostream>

using namespace std;

void main1()
{
	int iValue = 7;
	int *ptr_i = &iValue;

	double dValue = 7.0;
	double *ptr_d = &dValue;

	for (int i = 0; i < 3; ++i)
		cout << uintptr_t(ptr_i + i) << endl; // 4�� ������
	cout << endl;
	
	for (int i = 0; i < 3; ++i)
		cout << uintptr_t(ptr_d + i) << endl; // 8�� ������
	cout << endl;

	// ������ ������ �� ������ Ÿ���� �����ִ� ����
	// 1) �� ���۷��� �� �� ��ȯ�Ǵ� ������ Ÿ���� �˱� ���ؼ�
	// 2) ���� ����, ������ ����� �� �� ����Ǵ��� �˱� ���ؼ�
}

void main()
{
	int array[]{1, 2, 3, 4, 5};

	// cf) 
	// int* arr = new int[]{ 1,2,3,4,5 }; // X
	// ����: new �Ŀ����� �迭 ũ�⸦ �����ؾ� �մϴ�.
	// ���� �Ҵ� �ÿ� �ʱ�ȭ�� ���ָ� �迭 ũ�⸦ ������� �Ѵ�.

	int *ptr = array;

	for (int i = 0; i < 5; ++i) 
		cout << *(ptr+i) << " " << (uintptr_t)(ptr+i) << endl;
}
// array[i] = *(array+i)