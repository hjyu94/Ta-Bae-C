#include <iostream>
using namespace std;

/*************************************************************/

// [1. �Ϲ� �Լ��� �̿��� �����ε�]
// �Լ� �� �ڸ��� operator + �� ���ش�.
// return-type operator + ( parameter ... )

class Cents
{
private:
	int m_cents;

public:
	Cents() {}
	Cents(int cents) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }
};

Cents operator + (const Cents& c1, const Cents& c2)
{
	return Cents(c1.getCents + c2.getCents());
}

/*************************************************************/

// [2. friend �Լ��� �̿��� �����ε�]
// private ��� ������ �ٷ� ����� �� �־�����.

class Cents1
{
private:
	int m_cents;

public:
	Cents1() {}
	Cents1(int Cents1) { m_cents = Cents1; }
	int getCents1() const { return m_cents; }
	int& getCents1() { return m_cents; }

	friend Cents1 operator + (const Cents1& c1, const Cents1& c2);
};

Cents1 operator + (const Cents1& c1, const Cents1& c2)
{
	return Cents1(c1.m_cents + c2.m_cents);
}

/*************************************************************/

// [3. ��� �Լ��� ������ �����ε�]
// ��� �Լ��� ��������� friend Ű���� ���̵� private ��� ���� �����Ӱ� ��� ����
// ��� �Լ��� �Ǹ� ù��° �Ķ���ͷ� this�� �ڵ����� ���� ������
// �Ķ���͸� �ϳ� ������� �Ѵ�.

// ����θ� �ؾ��ϴ� �����ε� �ؾ��ϴ� ������
// =, [], (), -> 

class Cents2
{
private:
	int m_cents;

public:
	Cents2() {}
	Cents2(int Cents2) { m_cents = Cents2; }
	int getCents2() const { return m_cents; }
	int& getCents2() { return m_cents; }

	Cents2 operator + (const Cents2& c1)
	{
		return Cents2(this->m_cents + c1.m_cents);
	}

};

/*************************************************************/

void main()
{
	Cents cents1(8);
	Cents cents2(6);

	cout << (cents1 + cents2).getCents << endl;
}