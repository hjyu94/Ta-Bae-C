#include "13.2 MyArray.h"


void main()
{
	// MyArray my_array(10); // X
	// error C2955 : 'MyArray' : Ŭ���� ���ø���(��) ����Ϸ��� ���ø� �μ� ����� �ʿ��մϴ�.
	MyArray<int> my_array(10); // O

	for (int i = 0; i < my_array.getLength(); ++i)
	{
		my_array[i] = i * 10;
	}

	my_array.print();
}