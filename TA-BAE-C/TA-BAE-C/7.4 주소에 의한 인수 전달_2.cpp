#include <iostream>

using namespace std;

void getSinCos(const double degree, double *sin_out, double *cos_out)
{
	static const double pi = 3.141592;
	// static: �ѹ� ���ǵǸ� ���߿� �� ���ǵɶ��� ������ ���� ����. ����ȴ�.

	double radians = degree * pi / 180.0;

	/* de-referencing */       *sin_out = std::sin(radians);
	/* �����Ͱ� ����Ű�� ���� ��*/ *cos_out = std::cos(radians);
}

int main()
{
	double degree = 30;
	double sin, cos;

	getSinCos(degree, &sin, &cos);

	cout << sin << ", " << cos << endl;
}