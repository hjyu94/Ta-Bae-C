// ���� ������: �����ڰ� �����ڸ� ȣ���ϴ� ��

#include <iostream>

using namespace std;

class Student
{
public:
	int		m_id;
	string	m_name;

	/*
		Student(const string& name_in)
			: Student(0, name_in) // ���� ������
		{}
	*/

	Student(const int& id_in, const string& name_in)
		: m_id{ id_in }, m_name{ name_in }
	{}
};

int main()
{
	Student std1(0, "ABC");
	Student std2("DEF");
}