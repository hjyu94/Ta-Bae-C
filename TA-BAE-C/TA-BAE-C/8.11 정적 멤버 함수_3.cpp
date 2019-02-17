#include <iostream>

using namespace std;

class Something
{
private:
	static int s_value;

public:	
	Something()
		//: s_value(1024)
	{}
};

int Something::s_value = 1;
// static ��� ������ �����ڿ��� �ʱ�ȭ �� �� ����.

// static ��� ������ ����ϴ� �Լ��� static ��� �Լ����� �Ѵ�.
// �����ڰ� static�̾�� static ��� ������ ���� �־��� �� �ִµ�
// �����ڴ� static���� ���� �� ����.

/**************************************************************/

class Another
{
public:
	class _init
	{
	public:
		_init() { s_value = 999; }
	};

private:
	static int s_value;
	static _init s_initializer;

public:
	/*Another()
		: s_value(1024) // X
	{}*/
};
int Another::s_value = 1;
Another::_init Another::s_initializer;

// �갡 ��������鼭 inner Ŭ������ �����ڰ� �ʱ�ȭ�ǰ�
// inner Ŭ������ �����ڿ��� s_value �� �ʱ�ȭ �ȴ�.

// inner class���� ���������� ���

void main()
{

}