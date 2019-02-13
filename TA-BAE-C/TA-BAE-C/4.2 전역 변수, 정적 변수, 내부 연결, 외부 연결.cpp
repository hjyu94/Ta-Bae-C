// �ش� ������ �ش� cpp ���� �������� �ƹ������� ��� ����: ���� ����
// �ٸ� cpp ���Ͽ����� ��� ����: �ܺ� ����

/********************************************************/

#include <iostream>

using namespace std;

int value = 124;

int main()
{
	cout << value << ::value << endl;

	int value = 1; // main ���� ������ �̸��� ����
	// ���� ���̵� ���� ����� ����

	cout << value << ::value << endl;
}

// ��������:
// - ������ �������� ��� ����. 
// - ���� ������ ��� ���� �޸𸮰� os�� �ݳ��ǰ� 
// - ���̻� ����ϰų� ������ �� ����. 
// - ������, �෹�̼� ��� ���� ���� ������ ���ѵȴ�.

/********************************************************/

#include <iostream>

void doSomething()
{
	int a = 1;
	// �Ź� ���ο� �޸𸮰� a�� �Ҵ�ȴ�
	++a;
	cout << a << endl;
}

int main()
{
	doSomething(); // 2
	doSomething(); // 2
}

/********************************************************/

#include <iostream>

void doSomething()
{
	static int a = 1;
	// �޸𸮰� os�κ��� ���� �޸𸮰� static�̶�� ��
	// �޸𸮰� �������� ����ȴ�.
	// ���� �޸𸮸� ���� �ʱ�ȭ�� �� �ѹ��� �Ѵ�.	
	// ���ο� a�� ��Ҹ� ã�� �ʴ´�
	
	// static ������ ����� ���ÿ� �ʱ�ȭ�Ǿ�� �Ѵ�.
	// static int a; a = 1; // X

	++a;
	
	cout << a << endl;
}

int main()
{
	doSomething(); // 2
	doSomething(); // 3
	doSomething(); // 4
}

/********************************************************/

#include <iostream>

int a = 1;

void doSomething()
{
	++a;
	cout << a << endl;
}

int main()
{
	doSomething(); // 2
	doSomething(); // 3
	doSomething(); // 4
}

/********************************************************/

// static vs global
// static: �ٸ� cpp ���Ͽ��� ������ �� ����(scope)

// local var.�� ��Ű���� ����.
// ��ϸ� �Ѿ�� ��¥�� ����� ����
// ������� �ʴ´�

// ���� cpp �ȿ����� �������� �۵��ϴ� ��������: ���� ����

/********************************************************/

#include <iostream>

static int g_a = 1; // �ٸ� cpp ���Ͽ��� ���� �Ұ���
// �������� �տ� static�� ���̸� 
// �ش� ���������� �ٸ� cpp���Ͽ��� ���Ǵ� ���� ���´�

int main()
{
	int a = 10;

	return 0;
}

/********************************************************/

// [�ܺο���]
// test.cpp �� doSomething()�� ����ϰ� ���� ���
// 1) cpp ���� ���� ��Ŭ���(������ ��� X)
// 2) ���漱��

#include <iostream>
// #include "4.2 �ܺο��� test.cpp"
#include "4.2 My Constants.h"

// forward declaration
/* extern (�����Ǿ� ����) */ void doSomething();
// ��� doSomething()�� ���ǰ� �����ϴϱ�
// ��ŷ�Ҷ� ���� ���̼���
// ���� �ÿ��� ��ŷ�Ҷ� ���� ����� �����ϼ���

extern int a;
// ���� ���⼭ extern int a = 567; ��� �ϸ�
// �ʱ�ȭ�� ������ ���༭ ����
// (test.cpp���� �̹� �ʱ�ȭ����)

int main()
{
	cout << "In main.cpp: " << Constants::pi << ", �ּ�: " << &Constants::pi << endl;
	// (4.2 MyCosntants.cpp�� ������) 
	// test.cpp �� �ٸ� ������ �޸� ������ ����ϰ� �ȴ�.
	// ����� 1�ﰳ ����� �� ���� cpp ���Ͽ��� ��� ������׸� ��Ŭ��� �ϸ�
	// ���� �������� �ٸ� �޸𸮸� ����ϴ� ����� 1�ﰳ�� ���� -> �޸� ����

	doSomething(); // extern���� ǥ���ؼ� �ٸ� ���Ͽ� �ִٰ� �˷�����

	cout << a << endl; // 123
	// test.cpp ���Ͽ��� extern int a = 123; ����
}

/********************************************************/

int g_x; // external linkage
static int g_x; // �ٸ� ������ ��� �Ұ� internal linkage
const int g_x; // const�� ���� ���Ŀ� �� �ٲٰڴٴ� ���ε� �̷��� �ȵ�

extern int g_z;
extern const int g_z; // �ٸ� �� ��𼱰� �� ������� �ʱ�ȭ �������� ��

int g_y(1);
static int g_y(1); // �ٸ� ������ ��� �Ұ� internal linkage
const int g_y(1);
extern int g_y(1); // �ʱ�ȭ ���������Ƿ� �ٸ� �������� �ʱ�ȭ�ϸ� �ȵ�

extern const int g_w(1); // �ٸ� cpp ���Ͽ����� ��� ����