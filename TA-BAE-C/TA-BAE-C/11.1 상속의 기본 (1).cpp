/*
	�����ε�, �������̵�
	https://memoryfilm.tistory.com/16
*/

#include <iostream>

using namespace std;

class Mother
{
private:
	int m_i;

public:
	void setValue(const int& i_in)
	{
		m_i = i_in;
	}

	int getValue() const
	{
		return m_i;
	}
};

class Daughter /* ���! */: public Mother 
{
private:
	double m_d;

public:
	void setValue(const double& d_in) // �������̵�
	{
		m_d = d_in;
	}

	int getValue() const // �������̵�
	{
		return m_d;
	}
};

int main()
{
	Mother mom; // �⺻ �����ڸ� ���� �� �̷������� ���� ����
	// �ٸ� ����� mom(����1, ����2, ...) ó�� ��ȣ�� �ʿ��ϴ�
	mom.setValue(10); // ���⼭�� m_i�� �� �Ҵ�

	Daughter me;
	me.setValue(10); // ���⼭�� m_i��? m_d��? ��� �Ҵ��ұ� // m_d�� �Ҵ���
					 // Daughter�� setValue�� ȣ���
	
	// ���� Daughter���� �������̵� �� �Լ��� �ƴ϶�
	// �θ��� �Լ��� ȣ���ϰ� ������?
	me.Mother::getValue();
	me.Mother::setValue(10);
}

/************************************************************/
// �ٸ� ����� ������

class Mother
{
private:
	int m_i;

public:
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
	void setValue(const int& i_in, const double& d_in)
		: m_i(i_in), m_d(d_in) // X 
							   // �̴ϼȶ����� ��� �Ұ���, Mother ��� ������ public���� �ص� �Ұ���
	{
		// �Ʒ��� m_i�� private�̶� �Ұ���
		m_i = i_in;
		m_d = d_in;

		//### �ذ��!
		Mother::setValue(i_in);
		m_d = d_in;
	}

	void setValue(const double& d_in)
	{
		m_d = d_in;
	}

	int getValue() const
	{
		return m_d;
	}
};

int main()
{
	Daughter me;
	me.setValue(13.4);
	me.setValue(10, 13.4);
	me.Mother::setValue(10);
}

/********************************************************/

// ������: �޸𸮸� �Ҵ� �� �� ���� �־��ش�
// �޸𸮸� �Ҵ� �س��� ���߿� ���� �������ִ� ������ �ƴ�

/********************************************************/

// const double degree: �Ű������� const�� ���?
//	: �Լ� ������ �ش� ������ ���� �ٲ��� �ʰڴ�.

// cf) �Լ��� const�� ���?
//	: Ŭ�������� ��� �Լ��� const�� ���� �� �ִµ�
//	: �ش� Ŭ������ ��� ���� ���� �ٲ��� �ʰڴٴ� ǥ���̴�.
