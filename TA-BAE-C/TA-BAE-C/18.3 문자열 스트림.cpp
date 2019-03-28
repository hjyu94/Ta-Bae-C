#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	{
		stringstream os;

		// string stream�� ���ڿ� �ֱ�
		os << "Hello, World!"; // <<: insertion operator // extraction operator
		os.str("Hello, World!"); // ���� ���ۿ� �ִ� ���� �ٲ�

		string str;

		//// ' ' ������ �����ڷ� �����
		//os >> str;
		//cout << str << endl; // Hello,

		str = os.str(); // ���ۿ� �ִ� �� ��� ��������
		cout << str << endl; // Hello, World!

		os << "Hello, World!";
		os << "Hello, World!";
		str = os.str();
		cout << str << endl; // Hello, World!Hello, World!

		os << "Hello, World!";
		os << "Hello, World!";
		os.str("Hello, World!\n"); // ���� ���۸� ���� �ִ´�. ���൵ �д´�.
		str = os.str();
		cout << str << endl;

		os << "Hello, World!" << endl; // string stream�� endl�� ����.
		str = os.str();
		cout << str << endl;

		os.str("12345 67.89");
		string str1;
		string str2;
		os >> str1 >> str2;
		cout << str1 << "|" << str2 << endl;

		os.str("1234567.89");
		os >> str1 >> str2;
		cout << str1 << "|" << str2 << endl;
	}
	{
		stringstream os;

		int i = 12345;
		double d = 67.89;

		string str1, str2;

		os << i << d;
		os >> str1 >> str2;
		cout << str1 << "|" << str2 << endl; // 1234567.89|
	}
	{
		stringstream os;

		int i = 12345;
		double d = 67.89;

		string str1, str2;

		os << i << " " << d;
		os >> str1 >> str2;
		cout << str1 << "|" << str2 << endl; // 12345|67.89
	}
	{
		stringstream os;

		int i = 12345;
		double d = 67.89;

		//os << i << " " << d;
		os << "12345 67.89";

		int i2;
		double d2;

		os >> i2 >> d2;

		cout << i2 << "|" << d2 << endl;
	}
	{
		stringstream os;

		int i = 12345;
		double d = 67.89;

		os << "12345 67.89";
		
		// os.str(""); // �Ķ���Ͱ� ������ ���۸� ������
		// == os.str(string());
		
		os.clear(); // state���� �ʱ�ȭ
		
		os << "Hello";
		cout << os.str() << endl; // �Ķ���Ͱ� ������ ������ �Ѵ�.
		// 12345 67.89Hello
	}
	return 0;
}