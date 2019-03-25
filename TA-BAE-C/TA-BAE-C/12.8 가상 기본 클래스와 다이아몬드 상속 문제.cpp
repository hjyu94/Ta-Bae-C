// ���� �⺻ Ŭ����

/*
		A			A	A
	  /   \			|	|
	B		C		B	C
	  \   /			 \ /
		D			  D

	���̾Ƹ�� ����� ����: 
		���ʰ� ���� ��ӹ޾Ҵٰ� �����ߴµ�
		A�� ��� ���� �ּҸ� ���� �ٸ��� ����. 
		�����ʰ� ���� ��ӱ����� ������ �� ��
*/

#include <iostream>
using namespace std;

class PoweredDevice
{
public:
	int m_i;

	PoweredDevice(int power)
	{
		cout << "PoweredDevice: " << power << endl;
	}
};

class Scanner : public PoweredDevice
{
public:
	Scanner(int scanner, int power)
		: PoweredDevice(power)
	{
		cout << "Scanner: " << scanner << endl;
	}
};

class Printer : public PoweredDevice
{
public:
	Printer(int printer, int power)
		: PoweredDevice(power)
	{
		cout << "Printer: " << printer << endl;
	}
};


class Copier : public Scanner, public Printer
{
public:
	Copier(int scanner, int printer, int power)
		: Scanner(scanner, power), Printer(printer, power)
	{
	}
};


int main()
{
	Copier cop(1, 2, 3);
	/*
		PoweredDevice: 3
		Scanner: 1

		PoweredDevice: 3
		Printer: 2

		�����ڰ� �ι� ȣ���
	*/

	//cout << cop.m_i << endl; // X // ambiguous

	cout << &cop.Scanner::PoweredDevice::m_i << endl;
	cout << &cop.Printer::PoweredDevice::m_i << endl;
	// �ּҰ� �ٸ��� ��µ�
}