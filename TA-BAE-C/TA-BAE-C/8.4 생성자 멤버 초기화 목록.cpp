		#include <iostream>

		using namespace std;

		class B
		{
		public:
			int m_b;

			B(const int& m_b_in)
/*7*/			: m_b(m_b_in)
/*6*/		{		
/*8*/			cout << "B constructor" << endl;
/*9*/		}
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
/*3*/			: m_i{ 1 },
/*5*/			m_b{ m_i - 1 },
/*4*/			m_arr{ 1,2,3,4,5 } /* �迭�� �̴ϼȶ����� ����Ʈ ��� ����*/
/*2*/		{
/*10*/			m_i = 2; // �̰� ���� ��
/*11*/			cout << "Something constructor" << endl;
/*12*/		}
		};

		int main()
		{
/*1*/		Something sth1;
			// �ʱ�ȭ�� Ŭ���� ������ �⺻���� �־��ټ��� �ְ�
			// �����ڿ��� �̴ϼȶ����� ����Ʈ�� ����Ҽ��� �ִµ�
			// �� �� ���� �Ǹ� �����ڰ� �켱�̴�.

			// �������� {} �ȿ� �־��� ���� �������� �ȴ�.
		}
