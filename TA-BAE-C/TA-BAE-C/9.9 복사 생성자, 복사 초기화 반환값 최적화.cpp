
#include <iostream>
#include <cassert>
using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;
	// �ʱ�ȭ������ �ʰ� ����� �� ��Ÿ�� ���� �߻��Ѵ�.

public:
	Fraction(int num = 0, int den = 1)
		:m_numerator(num), m_denominator(den)
	{
		cout << "constructor called" << endl;
		assert(den != 0);
	}

	void print()
	{
		cout << m_numerator << "/" << m_denominator << endl;
	}

	Fraction(const Fraction& fraction)
		: m_numerator(fraction.m_numerator)
		, m_denominator(fraction.m_denominator)
	{
		cout << "copy constructor called" << endl;
	}

	friend ostream& operator << (ostream& out, const Fraction& f)
	{
		out << f.m_numerator << "/" << f.m_denominator;
		return out;
	}
};

Fraction doSomething()
{
	Fraction temp(1, 2);
	cout << &temp << endl;
	return temp;
}

void main()
{
	Fraction frac(3, 5);

	Fraction fr_copy(frac); // copy constructor ȣ��
	Fraction fr_copy2 = frac; // �̶��� copy constructor ȣ��
	// == Fraction fr_copy2(frac);

	Fraction fr_copy3(Fraction(3, 5)); 
	// ���� ��ü�� ����� �¸� ���ڷ� �־��ָ� ���� �����ڰ� ȣ����� ����
	// Fraction fr_copy(3,5); �� �ڵ����� �����Ϸ��� �ٲ���.
	
	cout << frac << " " << fr_copy << endl;
	cout << endl;

	/******************************************************/

	Fraction result = doSomething();
	cout << &result << endl;

	// [����� ���]
	// constructor called
	// 0x100 - doSomething stack
	// copy constructor called 
	// 0x200 - main stack

	// [������ ���]
	// constructor called
	// 0x100 - main stack
	// 0x100 - main stack

	// return value optimization -> �����Ϸ��� ����ȭ�� �����ִ� ��!
}