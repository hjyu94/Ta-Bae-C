#include <iostream>

using namespace std;

class B
{
public:
	int m_b;

	B(const int& m_b_in)
/*4*/		 : m_b(m_b_in)
		{
/*5*/		cout << "B constructor" << endl;
		}
};

class Something
{
private:
	int	m_i = 999;
	int m_arr[5] = { 999, };
	B	m_b{ 999 };
	// ��װ� ���� �ɷ�. ���ϴ�

public:
	Something()
/*1*/		: m_i{ 1 },
/*2*/		m_arr{ 1,2,3,4,5 }, /* �迭�� �̴ϼȶ����� ����Ʈ ��� ����*/
/*3*/		m_b{ m_i - 1 }
		{
/*6*/		m_i = 2; // �̰� ���� ��
/*7*/		cout << "Something constructor" << endl;
		}
};

int main()
{
	Something sth1;
	// �ʱ�ȭ�� Ŭ���� ������ �⺻���� �־��ټ��� �ְ�
	// �����ڿ��� �̴ϼȶ����� ����Ʈ�� ����Ҽ��� �ִµ�
	// �� �� ���� �Ǹ� �����ڰ� �켱�̴�.

	// �������� {} �ȿ� �־��� ���� �������� �ȴ�.
}

