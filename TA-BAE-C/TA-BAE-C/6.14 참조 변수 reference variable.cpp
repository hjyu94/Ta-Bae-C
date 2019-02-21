#include <iostream>

using namespace std;

int main1()
{
	int value = 5;
	int& ref = value;

	cout << value << ", " << &value << ", " 
		<< ref << ", " << &ref << endl;
	
	ref = 10;

	cout << value << ", " << &value << ", "
		<< ref << ", " << &ref << endl;

	// 자기 자신이 별도의 주소를 갖지 않는다는 점에서 포인터와 다르다
	// 포인터는 별도의 자신만의 주소를 갖는다

	/*************************************************************/

	int& r_val; // X
	// 레퍼런스 변수는 일종의 별명이다.
	// 별명은 원래 이름이 있어야 별명을 지을 수 있다.
	// 따라서 원래 이름을 갖도록 선언과 동시에 초기화가 반드시 필요하다
	
	int& r_val = 10; // X 
	// 상수 리터럴은 별도의 메모리를 가지지 않기 때문에
	// (해당 코드 라인을 넘어가면 날아간다)
	// 레퍼런스 변수는 원래 변수의 메모리를 가지고 오는 별명이다.

	/*************************************************************/

	int x = 5;
	int& ref = x;

	const int y = 8;
	int& ref = y; // X

	const int& ref = y; // O
	// ref를 이용해서 값을 바꾸면 const인 y값도 바뀔 수 있으므로
}

/******************************************************************/

struct Something
{
	int v1;
};

struct Other
{
	Something st;
};

void main()
{
	Other ot;

	ot.st.v1 = 10;
	// ...

	// ot.st.v1을 가지고 많이 작업할 경우 타이핑이 매우 귀찮아진다.
	// 이럴때 레퍼런스 변수를 이용하면 편해진다.
	// 또한 복사하는 과정이 없기 때문에 성능에도 저하가 오지 않는다.

	int& v1 = ot.st.v1;
	v1 = 10;
	// ...
}

