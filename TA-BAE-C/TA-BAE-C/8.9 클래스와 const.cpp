
// �Ű������� const�� ���?
//	: �Լ� ������ �ش� ������ ���� �ٲ��� �ʰڴ�.

// �Լ��� const�� ���?
//	: Ŭ�������� ��� �Լ��� const�� ���� �� �ִµ�
//	: �ش� Ŭ������ ��� ���� ���� �ٲ��� �ʰڴٴ� ǥ���̴�.

// ������Ʈ(��ü)�� const�� ���?
//	: const�� ������ ��� �Լ��� ȣ���� �� �ִ�.

/********************************************************/

#include <iostream>

using namespace std;

class Something
{
private:
	int i_m;

public:
	void setValue(int x)
	{
		i_m = x;
	}

	int getValue()
	{
		return i_m;
	}
};

void main()
{
	const Something something;
	something.setValue(5);					// X
	cout << something.getValue() << endl;	// X
}

/********************************************************/

class Something1
{
private:
	int i_m;

public:
	void setValue(int x) // const
	// setValue�� const�� �ƴϸ�
	// something.setValue(5); �� �ȵǰ�

	// �׷��ٰ� �ؼ� const�� �����
	// i_m ���� ������ �� ����.
	{
		i_m = x;
	}

	int getValue() const
	{
		return i_m;
	}
};

void main1()
{
	const Something1 something;
	something.setValue(5);
	cout << something.getValue() << endl;
}

