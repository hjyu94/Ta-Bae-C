#include "13.3 MyArray.h"

void main()
{
	// std::vector<double> my_array; my_array.resize(100);
	// MyArray<double> my_array(100);
	// ���� ���� �����Ҵ��. 100�̶�� ���ڰ� ������Ÿ�ӿ� �������� �ʾƵ� ��

	MyArray<double, 100> my_array; // std::array<double, 100>
	// ���� ���� 100�� compile Ÿ�ӿ� ������ �Ǿ�� �Ѵ�.

	// �Ʒ� ���� �� ��. 
	// int i = 100;
	// MyArray<double, i> my_array; // std::array<double, 100>
	// (const int �� ���������� ��)

	for (int i = 0; i < my_array.getLength(); ++i)
		my_array[i] = i + 65;

	my_array.print();
}