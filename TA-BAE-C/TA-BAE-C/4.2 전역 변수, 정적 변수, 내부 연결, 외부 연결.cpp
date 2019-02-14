/* 
	https://www.letmecompile.com/c-auto-static-extern-%ED%82%A4%EC%9B%8C%EB%93%9C-%EC%9D%98%EB%AF%B8/ 
	
	https://dojang.io/mod/page/view.php?id=683
	https://dojang.io/mod/page/view.php?id=684
	https://dojang.io/mod/page/view.php?id=802

*/

// �ش� ������ �ش� cpp ���� �������� �ƹ������� ��� ����: ���� ����
// �ٸ� cpp ���Ͽ����� ��� ����: �ܺ� ����

/********************************************************/

#include <iostream>

using namespace std;

int value = 124;

int main()
{
	cout << value << ::value << endl; // 124 124

	int value = 1; // main ���� ������ �̸��� ����
	// ���� ���̵� ���� ����� ����

	cout << value << ::value << endl; // 1 124
}

// ��������:
// - ������ ���� ���ĺ��� ��� ����. 
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
	// �ٽ� doSomething() �� ȣ��ɶ��� �ش� �ڵ� �������� ����
	// ���ο� a�� ��Ҹ� ã�� �ʴ´�
	
	// static ������ ����� ���ÿ� �ʱ�ȭ�Ǿ�� �Ѵ�.
	// static int a; a = 1; // X
	// �ʱ�ȭ�� �����ϸ� 0���� �ڵ� �ʱ�ȭ

	/*
		- static�� ���Ǵ� ��ġ�� ���� �ǹ̰� �޶����� �����ؼ� ����Ұ�.
		- ������������ : 
			- �Լ� ������ ������ static�� ���Ȱ��, �ش� ������ �Լ� ���ο����� ����� ����.
			- ������, ���α׷��� ����Ǵ� ���� ��� ���� ������
		- �ܺ��������� : 
			- �Լ� �ܺ��� ���������� ������ static�� ���Ȱ��, 
			- �ش� ���� ���ο����� ��������ó�� ��������, �ƴ� �ٸ� �ҽ����Ͽ����� ������ �� ����
			(�� : ���� �ϳ��� example.c ���� ���ο����� ����ϱ����� ���������� ����.
			�ٸ� ������ example.h�� include�ϴ��� �ش� static���� ����� ���������� ������ �ʾ� ���� �Ұ�)
	*/

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
// �ش� ��ϸ� ����� ��¥�� ����� ����
// �ٸ� cpp ���Ͽ� ������� �ʴ´�

// ���� cpp �ȿ����� �������� �۵��ϴ� �������� -> (���� ����)

/********************************************************/

#include <iostream>

static int g_a = 1; 
// �ٸ� cpp ���Ͽ��� ���� �Ұ���

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
	
	doSomething(); 
	// extern���� ǥ���ؼ� �ٸ� ���Ͽ� �ִٰ� �˷�����
	// Constants::pi �� ���� �ּҸ� ����ϴ� �Լ�

	// (4.2 MyCosntants.cpp�� ���� 4.2 MyConstants.h�� �ִ� ��쿡) 
	// test.cpp �� �ٸ� ������ �޸� ������ ����ϰ� �ȴ�.
	// ����� 1�ﰳ ����� �� ���� cpp ���Ͽ��� ��� ��������� ��Ŭ��� �ϸ�
	// ���� �������� �ٸ� �޸𸮸� ����ϴ� ����� 1�ﰳ�� ���� -> �޸� ���� �����ؾ� ��
	// 4.2 MyConstants.cpp �� ������༭ �̸� �ذ���.

	cout << a << endl; // 123
	// test.cpp ���Ͽ��� extern int a = 123; ����
}

/********************************************************/

int g_x; // external linkage
static int g_x; // �ٸ� ������ ��� �Ұ� internal linkage. ����� ���ÿ� �ʱ�ȭ ���Ѿ� ��
const int g_x; // const�� ���� ���Ŀ� �� �ٲٰڴٴ� ���ε� ����� ���ÿ� �ʱ�ȭ ���Ѿ� ��

extern int g_z;
extern const int g_z; // �ٸ� �� ��򰡿��� �� ������� �ʱ�ȭ �������� ��, �ٸ� cpp ���Ͽ����� ��� ����

int g_y(1);
static int g_y(1); // �ٸ� .cpp ���� ��� �Ұ� internal linkage
const int g_y(1);
extern int g_y(1); // �ʱ�ȭ ���������Ƿ� �ٸ� �������� �ʱ�ȭ�ϸ� �ȵ�
