#include <iostream>

using namespace std;

int min(int x, int y)
{
	return x > y ? y : x;
}

int main()
{
	cout << min(5, 6) << endl;
	cout << min(3, 2) << endl;
}

/*************************************/

inline int min(int x, int y)
{
	return x > y ? y : x;
}

int main()
{
	cout << min(5, 6) << endl;
	cout << min(3, 2) << endl;

	// inline �Լ��� �����Ϸ���
	// ���� �������ִ� ������ ��ġ�� �ʰ�
	// ���� ����� �Ʒ��� �Ȱ��� �ؼ��Ѵ�.

	// ��� �Լ��� inline�� ���δٰ� ��� inline���� �ٲ����� �ʰ�
	// �����Ϸ��� ������ �� �� ������ inline �Լ� ������ ���ش�.
	// �������ִ� ������ �ʿ���� ������ ���� ��������� �� �� ������
	// inline ��Ŀ� �����ؼ� ����ȭ�ϸ� �ȵ�.
	// ���򿡴� �������� ������ ���� �̹���. ���� ���� ����.

	cout << (5 > 6 ? 6 : 5) << endl;
	cout << (3 > 2 ? 2 : 3) << endl;


}