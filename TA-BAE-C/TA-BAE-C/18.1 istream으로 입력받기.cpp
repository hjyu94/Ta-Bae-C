#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void main()
{
	cout << "Enter a number" << endl;
	
	int i;
	cin >> i;
	cout << i << endl;

	/**********************************/

	char buf[5];

	cin >> buf;
	// [�Է�] abcde // ����
	// [�Է�] abcd  // OK

	cout << buf << endl;

	/**********************************/

	// �׷� �׻� �����ؼ� �Է��ؾ� �ϴ���?
	// #include <iomanip>
	char buf2[5];

	cin >> setw(5) >> buf2;
	cout << buf2 << endl;
	// setw(5): 
	// ���ۿ� ������ ���� �� �߿��� 5���� ������ ��
	// ������ ���� �ڸ����� �� �����Ͱ� ��
	// 
	// ���� ���ڸ� �Է��ϸ� 5���ڸ� �������� �� �޾Ƶ���
	// ������ ���ڴ� ���ۿ� �״�� �����ִ�.	

	cin >> setw(5) >> buf2;
	cout << buf2 << endl;

	cin >> setw(5) >> buf2;
	cout << buf2 << endl;

	/**********************************/

	// �ѱ��ھ� ��� �޾ƺ���
	char ch;

	while (cin >> ch)
		cout << ch;
	// [�Է�] Hello World
	// [���] HelloWorld
	
	/**********************************/
	
	int i;
	float f;
	cin >> i >> f;
	cout << i << " " << f << endl;
	// [�Է�] 1024 3.14
	// [���] 1024 3.14
	//
	// ��ĭ���� ������ �Ǿ�����.

	/**********************************/

	// ��ĭ���� �ް� ���� ���
	while (cin.get(ch))
		cout << ch;
	// [�Է�] Hello. World
	// [���] Hello. World
	// 
	// ��ĭ�� �� �о�´�.

	/**********************************/
	
	char buf3[5];
	cin.get(buf3, 5);
	cout << buf3 << endl;
	// [�Է�] Hello. World
	// [���] Hell

	/**********************************/

	char buf4[5];
	cin.get(buf4, 5);
	cout << cin.gcount() << buf4 << endl;
	cin.get(buf4, 5);
	cout << cin.gcount() << buf4 << endl;
	
	// [�Է�] Hello. World!!
	// [���] 4 Hell
	//		  4 o. W
	//
	// cin.gcount(): �� ���� �о�鿴���� ���� �Լ�

	/**********************************/

	char buf5[5];
	cin.getline(buf5, 5); // ��·�� ���� �ѹ��� �� �о��
	cout << cin.gcount() << buf5 << endl; // 4 Hell
	cin.getline(buf5, 5); // ù��° getline�� ������ �� �о������ ���̻� ������ X
	cout << cin.gcount() << buf5 << endl;

	/**********************************/

	char buf6[100];
	cin.getline(buf6, 100);
	cout << cin.gcount() << " " << buf6 << endl;
	// [�Է�] Hello
	// [���] 6 Hello
	//
	// �ٹٲ� ���ڱ��� ���� �д´�

	/**********************************/

	char buf7[100];
	cin.get(buf7, 100);
	cout << cin.gcount() << " " << buf7 << endl;
	
	// [�Է�] Hello
	// [���] 5 Hello
	//		  1
	
	/**********************************/

	string str_buf;
	getline(cin, str_buf);
	cout << cin.gcount() << " " << str_buf << endl;
	// [�Է�] Hello. World
	// [���] 0 Hello. World
	//
	// ���� ����� ���� ��� ���� �ʰ� �о��

	/**********************************/

	char buf8[1024];

	cin.ignore();
	cin >> buf8;
	cout << buf8 << endl;
	// [�Է�] Hello
	// [���] ello
	//
	// cin.ignore() �Է¹��� ���ڸ� (���ڰ�)�� ��ŭ ������

	cin.ignore(2);
	cin >> buf8;
	cout << buf8 << endl;
	// [�Է�] Hello
	// [���] llo

	/**********************************/

	char buf9[1024];
	cout << (char)cin.peek() << endl;
	cin >> buf9;
	cout << buf9 << endl;
	// [�Է�] Hello
	// [���] H
	//		 Hello
	//
	// ���� �Ѱ� �о�鿩�� ���ۿ��� �ϳ� ������ ������
	// ���������� ello �� ��µǴ°� �Ϲ����ε�
	// peek�� �鿩�� ���⸸ �ϰ� �������� �ʴ� ��
	// ���� ���� �о�� ���ڰ� ���� ��¦ �鿩�� ���� �� ��
	// ���ۿ��� ������ �ʾƼ� ������ ����Ҷ� ���� ��ġ�� X

	/**********************************/

	char buf10[1024];

	cin >> buf10;
	cout << buf10 << endl;
	
	cin.unget();
	
	cin >> buf10;
	cout << buf10 << endl;

	// [�Է�] Hello
	// [���] Hello
	//		 o
	//
	// peek()�� �ݴ� ����. 
	// �������� ���� ���ڸ� ���� ���ۿ� �ִ´�.

	/**********************************/

	char buf11[1024];

	cin >> buf11;
	cout << buf11 << endl;

	cin.putback('A');

	cin >> buf10;
	cout << buf10 << endl;
	
	// [�Է�] Hello
	// [���] Hello
	// 		  A
	//
	// putback() ���ϴ� ���ڸ� �ٽ� ���ۿ� ���� �ִ´�.
}