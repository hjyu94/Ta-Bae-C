// ���� �Ҵ� �迭�� �迭�� ����� ������ Ÿ�ӿ� �����Ǿ� �־�߸� ��� ����

#include <iostream>

using namespace std;

int main()
{
	int length;
	cin >> length;
	// int array[length]; // X

	int *array = new int[length] {1, 2, 3};
	// ���� 3���� ���� ���� �Է¹ް� �Ǹ� ��Ÿ�� ���� �߻�
	// os���� �޸𸮸� ����� ���� ���ߴµ� �޸𸮸� �� ������ �ϴϱ� ����!

	for (int i = 0; i < length; ++i) cout << array[i] << endl;

	delete[] array; // �迭�� �Ҵ��� ��~ �޸𸮸� �ݳ��ϴ� ���

	/*
		- �迭�� �ƴ� ������ �ݳ��� ��

		int* iValue = new int{1};
		delete iValue;
	*/

	/*************************************************************/

	int fixedArray[] = { 1,2,3,4,5 }; // O // ������ Ÿ�ӿ� 5����� ������
	int *array1 = new int[]{ 1,2,3,4,5 }; // X
	int *array2 = new int[3]{ 1,2,3,4,5 }; // X // 4, 5 �� ���� �ڸ��� ����
	int *array3 = new int[8]{ 1,2,3,4,5 }; // O
}