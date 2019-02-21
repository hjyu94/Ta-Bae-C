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
	
	int get_private_s_Value() { return s_private_value; }		
	static int get_private_s_Value_2() { return s_private_value; }
	
	void print_s_Value() { s_public_value = 3; cout << ++s_public_value << endl; };	// O
	// non static ��� �Լ��ε� static ������ ����� �����ϴ�.

};

/*static:�������*/ int Something::s_public_value = 1;
/*static:�������*/ int Something::s_private_value = 10;

void main()
{
	Something s1;

	s1.s_public_value;
	// s1.s_private_value;		// X // inaccessible

	s1.get_public_s_Value();	// O
	s1.get_private_s_Value();	// O
	s1.get_private_s_Value_2();	// O
	s1.print_s_Value();			// O

	/************************************************************************************/

	// Ŭ���� ���� �̿��ϴ� ����
	// Ư�� �ν��Ͻ��� ���ӵ��� �ʴ� static ��� �Լ��� ȣ���� �� �ִ�.

	// Something::s_private_value;		// X // inaccessible
	Something::s_public_value;

	Something::get_public_s_Value();	// X
	Something::get_private_s_Value();	// X
	Something::get_private_s_Value_2(); // O 
	Something::print_s_Value();			// O
}
