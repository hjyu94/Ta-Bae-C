// ���� Ŭ�������� ��� �����ڸ� �������̵��ؼ� ������?

#include <iostream>
using namespace std;

class Base
{
public:
	Base() {}

	// friend ftn �� ��� �Լ� �ƴ�
	// �ڽ� Ŭ�������� �ָ� ���� �������̵� �� �� ����.

	// �׷��� �Ķ���ͷ� ������Ʈ�� �Ѱ��ְ� ���� �̿��� ��� �Լ� ȣ��
	// �ι�° ���ڷ� Derived ��ü�� ������ �������� �����ȴ�.
	friend std::ostream& operator << (std::ostream &out, const Base &b)
	{
		return b.print(out);
	}

	virtual std::ostream& print(std::ostream& out) const
	{
		out << "Base";
		return out;
	}
};

class Derived : public Base
{
public:
	Derived() {}

	// print �Լ� �������̵�
	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "Derived";
		return out;
	}
};

int main()
{
	Base b;
	cout << b << endl;

	Derived d;
	cout << d << endl;

	Base& b_ref = d;
	cout << b_ref << endl;

	return 0;
}