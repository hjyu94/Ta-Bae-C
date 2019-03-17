// move semantics�� �׻� ����� ���� ����
// move semantics�� ������� ����, Ȥ�� ����� �� ������, ����ϸ� �ȵ�����
// ������ �� ������ ���� �˾ƺ���.
#include <iostream>
using namespace std;

int getResult()
{
	return 0;
}

// move semantics�� ��� �Ұ���
// �Ķ���ͷ� �Ѱܺ��� ������ �� �Լ� ȣ�� �� ����Ϸ���
// �������� ������ ���¶� ������ �߻��Ѵ�.
void doSomething(int& lref)
{
	cout << "L-value ref" << endl;
}

// ��¥�� �ٸ����� ����� ���� ���� ������
// �� �����ٰ� �ᵵ �ȴ�.
// move semantics�� ��� ����
void doSomething(int&& ref)
{
	cout << "R-value ref" << endl;
}

int main()
{
	int x = 5;
	// r-value�� �� �����
	// l-value�� r-value�� �־ ��� ����ϰڴٴ� �ǹ�
	int y = getResult();
	// �Լ��� ���ϰ��� r-value�� ����ϰ� �ִ�.
	const int cx = 6;
	// const: ���߿� ���� �ٲ� �� ����.

	// [L-value references]
	int& lr1 = x;	// Modifiable l-values
	int& lr2 = cx;	// Non-modifiable l-values
	int& lr3 = 5;	// R-values
	// ���������� �ڱⰡ �����ϴ� ������ �޸𸮸� ���� �־�� �Ѵ�
	// ���� �޸𸮰� ���� ���� ���� �� ����

	const int& lr4 = x;	// Modifiable l-values
	const int& lr5 = cx; // Non-modifiable l-values
	const int& lr6 = 5; // R-values

	// [R-value references]
	// &&: R-value�� ���� �� �ִ�.
	int&& rr1 = x;	// Modifiable l-values
	int&& rr2 = cx;	// Non-modifiable l-values
	int&& rr3 = 5;	// R-values
	int&& rr3_2 = getResult();
	// 5, getResult()�� �ڵ� ���� ���Ŀ� ����� ���. 
	// �ӽ÷θ� �����ϴ� �긦 �����ϰ� ���شٴ� �ǹ�

	const int&& rr4 = x;	// Modifiable l-values
	const int&& rr5 = cx;	// Non-modifiable l-values
	const int&& rr6 = 5;	// R-values

	// r-ref�� �� ����� ��鸸 ���� �� �ִ� ��. r-value�� move�� �ٸ����� �Űܹ����� �ƹ��� ã�� �ʴ´ٴ� �ǹ�
	// �׿� ���� l-ref�� x�� ����ִ� ���빰�� �ٸ����� �Űܹ����� x�� ���� �ٽ� �� ���빰�� ������ �� ��� �浹�� �����.

	// [L/R-value reference parameters]
	doSomething(x); // L-value ref (�޸𸮸� ���� ��)
	doSomething(cx); // void doSomething(const int& ref)�� ���Ǹ� �ٲٸ� �굵 ����.
	doSomething(5); // R-value ref (�޸𸮸� ���� ���ϴ� ��)
	doSomething(getResult()); // R-value ref

}