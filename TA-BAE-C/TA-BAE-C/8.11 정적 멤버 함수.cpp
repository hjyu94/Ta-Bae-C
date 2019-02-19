#include <iostream>

using namespace std;

class Something
{
private:
	static int s_private_value;

public:

public:
	static int s_public_value; // Ŭ���� �ٱ����� ���� �־���� �Ѵ�.
	
	int get_public_s_Value() { return s_public_value; }
	
	int get_private_s_Value() { return s_private_value; }			// X
	static int get_private_s_Value_2() { return s_private_value; }	// O
	// static ��� ������ �����ϴ� �Լ��� static ��� �Լ����� �Ѵ�.
	
	void print_s_Value() { s_public_value = 3; cout << ++s_public_value << endl; };	// O
	// non static ��� �Լ��ε� static ������ ����� �����ϴ�.

};

/*static:�������*/ int Something::s_public_value = 1;
/*static:�������*/ int Something::s_private_value = 10;

void main()
{
	cout << Something::s_public_value << endl;
	Something s1;
	cout << s1.get_public_s_Value() << endl;
	cout << s1.s_public_value << endl;

	//cout << Something::s_private_value << endl; // X // inaccessible

	cout << Something::get_private_s_Value_2() << endl; // O
	cout << Something::get_private_s_Value() << endl; // X
	// static ��� ������ �����ϴ� �Լ��� static ��� �Լ����� �Ѵ�.

	s1.print_s_Value();
}
