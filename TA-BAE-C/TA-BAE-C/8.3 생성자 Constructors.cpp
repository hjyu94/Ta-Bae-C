#include <iostream>

using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;
	// �ʱ�ȭ������ ������ ������ ���� ����ִ�.

public:
	void print()
	{
		cout << m_numerator << " / " << m_denominator << endl;
	}
};

int main()
{
	Fraction frac; // �⺻�����ڸ� ������ �̷������� ��ü ���� ����
	Fraction frac(); // OK

	frac.m_numerator = 0;
	frac.m_denominator = 1;
	// Fraction frac{ 0,1 }; �� ����
	
	// �� �� ��� ������ public�̾�� �ʱ�ȭ ����
}

/*************************************************************/

class Fraction1
{
	int m_numerator; /* = 0;*/
	int m_denominator; /*= 1;*/
	// �⺻���� ������ ���� �ִ�.
};

/*************************************************************/

class Fraction2
{
private:
	int m_numerator;
	int m_denominator;
	// �ʱ�ȭ������ ������ ������ ���� ����ִ�.

public:
	Fraction2(int x) // �⺻ �����ڴ� ������� ��
	// �����ڸ� ��������� �������� �⺻ �����ڰ� �����Ǿ� ������
	// �����ڸ� ���Ƿ� ������ָ� �⺻ �����ڴ� ��������.
	{
		m_numerator = 0;
		m_denominator = 1;
	}

	void print()
	{
		cout << m_numerator << " / " << m_denominator << endl;
	}
};

void main2()
{
	Fraction2 frac; // Fraction2�� �⺻�����ڸ��� ���� �������� ����
	Fraction2 frac(1);
}