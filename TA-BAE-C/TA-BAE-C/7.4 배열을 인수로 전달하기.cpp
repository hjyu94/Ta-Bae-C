#include <iostream>

using namespace std;

void foo(int *arr, int length)
{
	for (int i = 0; i < length; ++i)
		cout << arr[i] << endl;

	arr[0] = 1.0;
}
// �ּҸ� ã�ư��� �ٲٱ� ������
// ���� �ٲ��
