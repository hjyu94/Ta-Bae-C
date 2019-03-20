#include <iostream>
using namespace std;

class Digit
{
private:
	int m_digit;
public:
	Digit(int digit) : m_digit(digit) {}

	// prefix
	Digit& operator ++ ()
	{
		++m_digit;
		return *this;
	}

	// post: parameter�� dummy�� �ƹ��ų� ���� ��
	Digit operator ++ (int)
	{
		Digit temp(m_digit); // ���簪�� ������ temp ��ü
		++(*this); // using prefix operator �� ���� ���߿� ������ �־����
		return temp;
	}

	friend ostream& operator << (ostream& out, const Digit& digit)
	{
		out << digit.m_digit;
		return out;
	}
};

void main()
{
	// �⺻ �ڷ���
	int a = 10;
	cout << ++a << endl;	// 11
	cout << a << endl;		// 11
	cout << a++ << endl;	// 11
	cout << a << endl;		// 12

	// ����� ���� �ڷ���
	Digit d(5);
	cout << ++d << endl;	// 6
	cout << d << endl;		// 6
	cout << d++ << endl;	// 6
	cout << d << endl;		// 7
}