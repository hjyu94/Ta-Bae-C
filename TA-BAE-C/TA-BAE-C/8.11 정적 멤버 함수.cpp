#include <iostream>
using namespace std;

class Something
{
private:
	static int s_private;
	// Ŭ���� �ٱ����� ���� �־���� �Ѵ�.

public:
	static int s_public;

	int get_public() { return s_public; }
	int get_private1() { return s_private; }
	static int get_private2() { return s_private; }
	void print_public() { s_public = 3; cout << ++s_public << endl; }
	void print_private() { s_private = 3; cout << ++s_private << endl; }
};

/*static:�������*/ int Something::s_private = 1;
/*static:�������*/ int Something::s_public = 10;

void main()
{
	Something s1;

	s1.s_public;
	s1.s_private;
	s1.get_public();
	s1.get_private1();
	s1.get_private2();
	s1.print_public();
	s1.print_private();

	// Ŭ�������� �̿��ϴ� ��쿡��
	// Ư�� �ν��Ͻ��� ���ӵ��� �ʴ� 
	// static ��� �Լ��� ȣ���� �� �ִ�.

	Something::s_public;
	Something::s_private;
	Something::get_public();
	Something::get_private1();
	Something::get_private2();
	Something::print_public();
	Something::print_private();
}