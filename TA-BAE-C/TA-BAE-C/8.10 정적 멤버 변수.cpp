// memory: data / code / heap / stack

// data: ���� ����, static ����
// heap: ���� �Ҵ�� ����
// stack: ���� ����

#include <iostream>

using namespace std;

class Something
{
public:
	int m_value = 1;

	// static int s_value = 1; // X
	static int s_value;		// O 
	// �ߺ� ����(�ʱ�ȭ) ����
	// static ���� �������� ������ �����ϸ� ������ ����.

	// ���� ������Ϸ� ���� ����� ����
	// ������Ͽ� ���� �ϰ� cpp ���Ͽ��� ���� ���� ���ִ°� ����.
	
	static const int s_c_value = 1;
	// �ݴ�� static const ������ Ŭ���� ���ο��� �ʱ�ȭ�� ����� ��
	// const ������ ����� ���ÿ� �ʱ�ȭ�� ���־�� ��.

	static constexpr int s_c_expr_value = 1;
	// constexpr�� ��� ������Ÿ�ӿ� ���� Ȯ���� �����Ǿ�� ��
};

/*static:�������*/ int Something::s_value = 1;

// const int Something::s_c_value = 999; // X
// const ������ ����� ���ÿ� �ʱ�ȭ�� ���־�� ��.
// const ������ ���߿� �� �ٲ� �� ����.

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
	// ���� ��� ������ �ν��Ͻ��� ���� ���� �ּҸ� ����� �� �� �ִ�.
	// �� ���� ���� �ʰ�(int Something::s_value = 1;)
	// ����ϸ� ��ŷ ������ �߻��Ѵ�.

	Something st1, st2;
	st1.s_value = 999; // O // static ���� �� ���� ����
	cout << &st1.s_value << " " << st1.s_value << endl;
	cout << &st2.s_value << " " << st2.s_value << endl;
}
