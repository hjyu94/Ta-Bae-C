#pragma once
#include <iostream>

template<typename T>
class Storage
{
public:
	T m_data;

	Storage(T value)
	{
		m_data = value;
	}

	~Storage()
	{}

	// double type�� ���ؼ� instantiation �� ����
	// �ٸ� ����� ���������� ���ڴٰ� �ϸ�?
	void print()
	{
		using namespace std;
		cout << m_data << endl;
	}
};

//template<>
//void Storage<double>::print()
//{
//	using namespace std;
//	cout << "Double Type" << endl;
//	cout << m_data << endl;
//	cout << std::scientific << m_data << endl; // scientific notation
//}
// ������ϰ� cpp ������ �и��ؼ� ���� ������..?
// �ƹ� ǥ�� ���� cpp ���Ͽ� ���� ���ø� Ư��ȭ�� �ߴٴ� �� �����Ϸ��� ��

// �ذ���? 
// ������Ͽ� ���� ���� �и����� ���� �� �����ֱ� (����¸�)
// main.cpp ���� #include "Storage.cpp" �����ֱ�