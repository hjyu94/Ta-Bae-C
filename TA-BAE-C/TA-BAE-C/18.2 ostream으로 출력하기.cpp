#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout.setf(std::ios::showpos); // �÷��� ����
	cout << 108 << endl; // +108 // ��ȣ���� ���

	cout.unsetf(std::ios::showpos); // �÷��� ���� ����
	cout << 108 << endl; // +108 // ��ȣ���� ���

	cout.unsetf(std::ios::dec); // 10���� ��带 ����
	cout.setf(std::ios::hex); // 16���� ��带 Ų��
	cout << 108 << endl;
	
	// basefield: ���� �÷��� �� basefield�� �÷��׸� ������ �ְڴٴ� ��
	cout.setf(std::ios::hex, std::ios::basefield);
	cout << 108 << endl;

	cout << std::hex << 108 << endl; // 16������ ���
	cout << std::dec << 110 << endl; // 10������ ���

	cout.setf(std::ios::uppercase);
	cout << std::hex << 108 << endl; // 16������ ���
	cout << std::dec << 110 << endl; // 10������ ���
	cout.unsetf(std::ios::uppercase);
	cout << endl;

	cout << true << ", " << false << endl;
	cout << std::boolalpha << true << ", " << false << endl;
	cout << endl;

	//cout << std::defaultfloat;
	cout << std::setprecision(3) << 123.456 << endl;
	cout << std::setprecision(4) << 123.456 << endl;
	cout << std::setprecision(5) << 123.456 << endl;
	cout << std::setprecision(6) << 123.456 << endl;
	cout << std::setprecision(7) << 123.456 << endl;
	cout << endl;

	cout << std::fixed; // �Ҽ��� �ڿ� �ڸ� ������Ű��
	cout << std::setprecision(3) << 123.456 << endl;
	cout << std::setprecision(4) << 123.456 << endl;
	cout << std::setprecision(5) << 123.456 << endl;
	cout << std::setprecision(6) << 123.456 << endl;
	cout << std::setprecision(7) << 123.456 << endl;
	cout << endl;

	cout << std::scientific;
	cout << std::setprecision(3) << 123.456 << endl;
	cout << std::setprecision(4) << 123.456 << endl;
	cout << std::setprecision(5) << 123.456 << endl;
	cout << std::setprecision(6) << 123.456 << endl;
	cout << std::setprecision(7) << 123.456 << endl;
	cout << endl;

	cout << std::scientific << std::uppercase;
	cout << std::setprecision(3) << 123.456 << endl;
	cout << std::setprecision(4) << 123.456 << endl;
	cout << std::setprecision(5) << 123.456 << endl;
	cout << std::setprecision(6) << 123.456 << endl;
	cout << std::setprecision(7) << 123.456 << endl;
	cout << endl;

	cout << std::showpoint;
	cout << std::setprecision(3) << 123.456 << endl;
	cout << std::setprecision(4) << 123.456 << endl;
	cout << std::setprecision(5) << 123.456 << endl;
	cout << std::setprecision(6) << 123.456 << endl;
	cout << std::setprecision(7) << 123.456 << endl;
	cout << endl;

	cout << -12345 << endl;
	////cout.fill('*'); // ��ĭ�� *�� ä����
	cout << std::setw(10) << -12345 << endl; // 10�ڸ��� ä���� ����϶�
	cout << std::setw(10) << std::left << -12345 << endl; // 10�ڸ��� ä���� ����϶�
	cout << std::setw(10) << std::right << -12345 << endl; // 10�ڸ��� ä���� ����϶� // �������� �ٿ���
	cout << std::setw(10) << std::internal << -12345 << endl; // 10�ڸ��� ä���� ����϶� // ��ȣ�� ���� ���̿� ��ĭ


	// �� �ܿ��� �������� �÷��װ� ����
	// �� ��, �� ��, ã�Ƽ� �������.

	return 0;
}