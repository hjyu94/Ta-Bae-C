#include "8.8 Ŭ���� �ڵ�� ��� ����.h"

int main()
{
	using namespace std;
	Calc cal(10);
	cal.add(1).add(2).add(3).print(); // chaining member 

	Calc(10).add(1).add(2).add(3).print(); // chaining member 
}
