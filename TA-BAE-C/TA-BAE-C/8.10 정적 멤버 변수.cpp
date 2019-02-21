#include <iostream>

using namespace std;

class Something
{
public:
	/* 1 */
	int m_value = 1;

	/* 2 */
	// static int s_value = 1; // X
	static int s_value;		// O 
	// �ߺ� ���� ����
	// static �������� ������ �����ϸ� ������ ����.
	// Ŭ���� ���ο��� ���� �ʱ�ȭ���� ���ָ�
	// �ν��Ͻ��� ������ ������ �а� �ǹǷ� �ʱ�ȭ�� Ŭ���� �ۿ��� �Ѵ�

	// ���� ������Ϸ� static ������ ���� ����� ��찡 �ִٸ�
	// �׶��� ���������� 
	// ������Ͽ� ���� �ϰ� cpp ���Ͽ��� ���� ���� ���ִ°� ����.
	
	/* 3 */
	static const int s_c_value = 1;
	// �ݴ�� static const ������ Ŭ���� ���ο��� �ʱ�ȭ�� ����� ��
	// const ������ ����� ���ÿ� �ʱ�ȭ�� ���־�� ��.

	/* 4 */
	static constexpr int s_c_expr_value = 1;
	// constexpr�� ��� ������Ÿ�ӿ� ���� Ȯ���� �����Ǿ�� ��
};

/*static:�������*/ int Something::s_value = 1;

// const int Something::s_c_value = 999; // X
// const ������ ����� ���ÿ� �ʱ�ȭ�� ���־�� ��.
// ���� Ŭ���� ���ο��� �����Ҷ� �ʱ�ȭ ����. ���߿� �� �ٲ� �� ����.

void main1()
{
	Something st1, st2;
	st1.m_value = 2;
	cout << &st1.m_value << " " << st1.m_value << endl;
	cout << &st2.m_value << " " << st2.m_value << endl;
	// �ٸ� �ּҰ� ��µȴ�.
}

void main()
{
	cout << &Something::s_value << " " << Something::s_value << endl;
	// ���� ��� ������ �ν��Ͻ��� ���� ���� Ŭ���� ������ �ּҸ� ����� �� �� �ִ�.
	// �� ���� ���� �ʰ�(int Something::s_value = 1;)
	// ����ϸ� ��ŷ ������ �߻��Ѵ�.

	Something st1, st2;
	st1.s_value = 999; // O // static ���� �� ���� ����
	cout << &st1.s_value << " " << st1.s_value << endl;
	cout << &st2.s_value << " " << st2.s_value << endl;
}
