#include <iostream>
#include <string>

using namespace std;

void main()
{
	// try, catch, throw
	double x;
	cin >> x;

	try
	{
		if (x < 0.0) throw string("Negative input"); // O
		// if (x < 0.0) throw "Negative input"; // X
		// �츮 ������ string���� �ٲ� �� �� �� ������
		// ����ó���� ����ȯ�� ������ �����ؼ� �ȵ�.
		// �̷� �����
		// catch(const char* error_message){...} �� �־�� ��

		throw - 1.0; // X
		// double�� �޾��ִ� �갡 ��� ��Ÿ�� ����

		cout << sqrt(x) << endl;
	}

	catch (int x)
	{
		cout << "Catch integer: " << x << endl;
	}

	catch (string error_message)
	{
		cout << error_message << endl;
	}
} 