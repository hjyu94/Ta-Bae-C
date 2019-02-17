#include <iostream>

using namespace std;

class Simple
{
private:
	int m_id;

public:
	Simple(int id)
	{
		setID(id);
	}

	void	setID(const int id) { m_id = id; }
	int		getID() const { return m_id; }
};

int main()
{
	Simple s1(1), s2(2);
	s1.setID(2); 
	s2.setID(3);

	// Simple Ŭ������ �������� ��ü s1, s2, s3, ... �� �� �� �ִ�.
	// �ϳ��� Ŭ������ �������� ��ü�� �� �� �ִµ�
	
	// Simple::setID �Լ��� Simple�� ��� ��ü���� �����ؼ� ����Ѵ�.
	// �׷��ٸ� setID(id) �� ������ �� � ��ü�� m_id�� ���� �־�����
	// ��� ã�Ƴ��°�?

	// ��, �� �Լ��� �� ��ü���� �ٸ� �޸𸮿� �����ϰ� ������?
	// s1, s2 ���� ���� �ڽŸ��� ������ �� �� �Լ��� �������� �ʴ´�

	// s1.setID(2); �� ���
	// Simple::setID(&s1, 2) �� ����� �Ѵ� - ���������� �̷��� ���� ���� ��ɻ�!
	// ������ �ʴ� �����Ͱ� ���������� ����ִ� ��

	// �� �ν��Ͻ����� �ڽ��� �����͸� ���� �ְ� �̸� this�� ���� �� �� �ִ�. 
	// this: �ش� ��ü�� �ּҰ�
}

/**************************************************************/

class Simple
{
private:
	int m_id;

public:
	Simple(int id)
	{
		cout << this << " constructor" << endl;

		/*this->*/ setID(id); // ���������δ� �̷��� ����� ��
	}

	void	setID(const int id) { /*this->*/ m_id = id; }
	int		getID() const { return /*this->*/ m_id; }
};

// s1.setID(10);
// Simple::setID(&s1, 10);