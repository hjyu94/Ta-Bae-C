#include "8.8 Ŭ���� �ڵ�� ��� ����.h"
using namespace std;

int main()
{
	Calc cal(10);
	cal.add(1).add(2).add(3).print(); // chaining member 

	Calc(10).add(1).add(2).add(3).print(); // chaining member 
}
