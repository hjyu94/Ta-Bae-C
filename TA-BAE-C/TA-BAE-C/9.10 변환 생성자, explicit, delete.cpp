// ���α׷����� ���Ǹ� ���� ���� �����ڸ� ��ȯ�� �����ִ� converting constructor
// ��ȯ�����ڸ� ������� ���ϰ� ���ƹ����� explicit Ű����
// Ư���� �����ڸ� ������� ���ϰ� ���������� delete Ű����

// �����Ҵ翡���� delete�ʹ� �ٸ� �ǹ��Դϴ�!

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
	Fraction(char) = delete;

	explicit Fraction(int num = 0, int den = 1)
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

void doSomething(Fraction frac)
{
	cout << frac << endl;
}

void main()
{
	Fraction frac(7);

	doSomething(frac);
	doSomething(Fraction(7));
	doSomething(7); 
	// �Ķ���Ͱ� ��ü �ϳ����̶�� ������ó�� �ڵ����� �ٲ��ش�.
	// converting constructor
	// �̶� �����ڿ� explicit Ű���带 ����ϸ� 
	// �����ڸ� converting constructor�� ��� �Ұ���.

	Fraction('a'); 
	// �ڵ� conversion �ǰų� casting �Ǵ� 
	// �����Ǵ� ��찡 �־� ������ ���ƹ�����.
}