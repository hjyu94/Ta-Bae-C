// �θ𺸴� �ڽ� Ŭ������ �� ���� ������ ������ �Ǵ� ��찡 ��ټ�.

// �ڽ� Ŭ������ �� �� ��ü���� Ŭ������
// �θ� Ŭ�������� �� ���� ������ �Լ��� ������ ���� �� �ִ�.
// �Լ� �����ε��� �Ǿ� ���� �� �ִ�.

// ���� ���� �θ��� ��ü�� ���� ū �ڽ� Ŭ������ ��ü�� ������ �����ϴ� ���?
// �ڽ� Ŭ�������� ���� ������ ��� ������� �Ǵµ�
// �̷��� �͵��� ��ü �߸��̶�� �Ѵ�.
// ���� �׸��� ū ��ü�� �������� �ϴٺ��� ����� ����!

#include <iostream>
#include <vector>
#include <functional> // for reference wrapper
using namespace std;

class Base
{
public:
	int m_i = 0;

	virtual void print()
	{
		cout << "I'm Base" << endl;
	}
};

class Derived : public Base
{
public:
	int m_j = 1;

	virtual void print() override
	{
		cout << "I'm derived" << endl;
	}
};

void doSomething(Base& b)
{
	b.print();
}

int main()
{
	Base b;
	Derived d;

	std::vector<Base> my_vec;
	my_vec.push_back(b);
	my_vec.push_back(d);
	// derived�� �־����� push_back �Լ� ������ ��ü �߸��� �߻��ؼ�
	// �������� �������� �ʴ´�.

	for (auto & e : my_vec)
		e.print();
	// I'm Base
	// I'm Base

	/**********************************************************/
	
	// std::vector<Base&> my_vec;
	// �̷��� ����� ��ü�� �߷������� �ʰ�
	// �������� ����� ������
	// ���Ϳ� ���۷������� ��Ƴ��� �� ����.

	/**********************************************************/

	// [������ ���͸� �̿��� �ذ�]
	std::vector<Base*> my_vec2;
	my_vec2.push_back(&b);
	my_vec2.push_back(&d);

	for (auto & e : my_vec2)
		e->print();
	// I'm Base
	// I'm Derived

	/**********************************************************/

	// [reference wrapper�� �̿��� �ذ�]
	std::vector<std::reference_wrapper<Base>> my_vec3;
	// my_vec3�� Base�� ���۷����� �����ϴ� ���Ͱ� �ȴ�.
	
	Base		base;
	Derived		derived;
	
	Base&		b_ref = base;
	Derived&	d_ref = derived;

	my_vec3.push_back(b_ref);
	my_vec3.push_back(d_ref);

	for (auto & e : my_vec3)
		e.get().print();
	// get ���� ���콺�� �÷����� ����
	// ��ȯ ���� Base�� ���� �������� �� �� �ִ�.

	// I'm Base
	// I'm Derived

	return 0;
}