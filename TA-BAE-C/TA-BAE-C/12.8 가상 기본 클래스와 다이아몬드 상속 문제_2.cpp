// ���̾Ƹ�� ����� ������ �ذ��ϴ� ��: ���� �⺻ Ŭ����

#include <iostream>
using namespace std;

class PoweredDevice
{
public:
	int m_i;

	PoweredDevice(int power)
	{
		cout << "PowerDevice: " << power << endl;
	}
};

//class Scanner : public PoweredDevice
class Scanner : virtual public PoweredDevice
{
public:
	Scanner(int scanner, int power)
		: PoweredDevice(power)
	{
		cout << "Scanner: " << scanner << endl;
	}
};

//class Printer : public PoweredDevice
class Printer : virtual public PoweredDevice
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
		// , PoweredDevice(power) // PoweredDevice�� ������ ȣ��
	{
	}
};

int main()
{
	Copier cop(1, 2, 3);
	/*
		PoweredDevice: 3 // �����ڰ� �ѹ��� ȣ��ȴ�
		Scanner: 1
		Printer: 2
	*/

	cout << &cop.Scanner::PoweredDevice::m_i << endl;
	cout << &cop.Printer::PoweredDevice::m_i << endl;
	// �� �ּҰ� �Ȱ��� ��µ�. �����긦 ����Ų�ٴ� ���
}