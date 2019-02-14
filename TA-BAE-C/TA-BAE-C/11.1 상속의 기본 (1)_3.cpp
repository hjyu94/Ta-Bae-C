// �׷��� �� �����ڸ� �Ẹ�� �ʹ�! �� �� �� ���� �� �ִ� ����

#include <iostream>

using namespace std;

class Mother
{
private:
	int m_i;

public:
	// Mother() {} // �⺻ ������

	Mother(const int& i_in)
		: m_i(i_in)
	{
		
	}

	void setValue(const int& i_in)
	{
		m_i = i_in;
	}

	int getValue() const
	{
		return m_i;
	}
};

class Daughter : public Mother
{
private:
	double m_d;

public:
	Daughter(const int& i_in, const double& d_in)
	// Mother Ŭ������ �⺻ �����ڰ� ��� ������ ����
	// Daughter ������ ���������� Mother Ŭ������ �⺻ �����ڸ� ȣ���ϱ� ����

	// �ذ�å1) Mother Ŭ������ �⺻������ ������ֱ�
	// �ذ�å2) Daughter ������ ȣ���� �� Mother�� ������ ȣ�����ֱ�
	{ // X
		Mother::setValue(i_in);
		m_d = d_in;
	}

	void setValue(const int& i_in, const double& d_in)
	{
		Mother::setValue(i_in);
		m_d = d_in;
	}

	int getValue() const
	{
		return m_d;
	}
};

int main()
{
	Mother mom(1024);
	Daughter me(10, 3.14);
}

/***************************************************************/

class Daughter : public Mother
{
private:
	double m_d;

public:
	Daughter(const int& i_in, const double& d_in)
		: Mother(i_in), m_d(d_in)
	// �ذ�å2) Daughter ������ ȣ���� �� Mother�� �⺻ ������ ȣ�����ֱ�
	{}

	void setValue(const int& i_in, const double& d_in)
	{
		Mother::setValue(i_in);
		m_d = d_in;
	}

	int getValue() const
	{
		return m_d;
	}
};