#include <iostream>

using namespace std;

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

// ��� 1
void add(const Cents& c1, const Cents& c2, Cents& c_out)
{
	c_out.getCents() = c1.getCents() + c2.getCents();
}

// ��� 2
Cents add(const Cents& c1, const Cents& c2)
{
	return Cents(c1.getCents() + c2.getCents());
}

void main()
{
	Cents cents1(8);
	Cents cents2(6);

	// ��� 1
	Cents sum;
	add(cents1, cents2, sum);
	cout << sum.getCents() << endl;

	// ��� 2
	cout << add(cents1, cents2).getCents << endl;
	
	cents1 + cents2; // X // �̷��� ���� �����ٵ� 
	// �̷��� ������ �����ε� ���!
}
