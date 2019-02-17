// ���� constructor

#include <iostream>

using namespace std;

class Something
{
public:
	int i_m;

	Something()
	{
		cout << "Constructor ~" << endl;
	}

	void setValue(int x)
	{
		i_m = x;
	}

	int getValue() const
	{
		return i_m;
	}
};

void print(Something st);

void main()
{
	Something something;
	cout << "In main: " << &something << endl;

	print(something);
}
// [���]
// main �� print ���� ȣ��Ǵ� �ּҰ��� �ٸ���
// Constructor�� main������ ȣ��ȴ�.

void print(Something st)
{
	cout << "In ftn: " << &st << endl;
	cout << st.i_m << endl;
}
// call by value ���� @ ���� @ �ؼ� �����
// Something Ŭ������ ������Ʈ�� st�� ���� �����
// �����ڰ� ����Ǽ� st�� �����°� �´µ�
// �� Constructor�� �ѹ��� ȣ��ɱ�?
// ---> �Ű����� st�� �����Ҷ��� ���� Constructor�� ȣ��Ǳ� ������!

/***********************************************************/

class Something
{
public:
	int i_m;

	// �⺻ ������
	Something()
	{
		cout << "Constructor ~" << endl;
	}

	// �����ڰ� �ƴ϶� �⺻ ���� ������!
	// ��������� �ʾƵ� �⺻���� ����. ������ ���� ��.
	Something(const Something& st_in)
	{
		cout << "Copy Constructor !" << endl;
		i_m = st_in.i_m;
	}

	void setValue(int x)
	{
		i_m = x;
	}

	int getValue() const
	{
		return i_m;
	}
};

void print(Something st)
{
	cout << "In ftn: " << &st << endl;
	cout << st.i_m << endl;
}
// void print(Something& st)
// ���� ���� ������ �Ѱ��ָ� ���縦 ���ִ°� �ƴϱ� ������
// ���� �����ڰ� ȣ����� �ʰ� main�� something�� ���� �ּҰ� ��µȴ�.

void main()
{
	Something something;
	cout << "In main: " << &something << endl;

	print(something);
}
