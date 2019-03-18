// string <-> �⺻ ������ ����ȯ

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T>
string ToString(T x);

template <typename T>
bool FromString(string& str, T& x);

void main()
{
	std::string my_string("my string");

	// ������ �����ε�
	cout << string(my_string, 3) << endl; // my 'string'
	cout << string(my_string, 3, 5) << endl; // my 'strin'g
	cout << string(my_string, 3, 2) << endl; // my 'st'ring
	
	cout << endl;

	const char* my_string2 = "my string";
	cout << string(my_string2, 3) << endl; // 'my 'string
	cout << string(my_string2, 3, 5) << endl; // my 'strin'g
	cout << string(my_string2, 3, 2) << endl; // my 'st'ring

	cout << endl;

	cout << string(10, 'A') << endl; // AAAAAAAAAA

	vector<char> vec;
	for (auto e : "Today is a good day.")
		vec.push_back(e);
	cout << string(vec.begin(), vec.end()) << endl; // Today is a good day.

	// find(): algor4ithm
	cout << string(vec.begin(), std::find(vec.begin(), vec.end(), 'g')) << endl; // 'Today is a 'good day.
	cout << string(vec.begin(), std::find(vec.begin(), vec.end(), 'y')) << endl; // 'Toda'y is a good day.

	/****************************************************************************************/

	string my_str(to_string(1004));
	my_str += std::to_string(128);
	cout << my_str << endl; // 1004128
	
	int i = std::stoi(my_str);
	cout << i << endl;

	float f = stof(my_str);
	cout << f << endl;

	cout << endl;

	/****************************************************************************************/

	cout << ToString(3.14f) << endl; // 3.14
	
	/****************************************************************************************/

	double d;
	
	my_str = string("3.14"); // double�� ��ȯ ����
	if (FromString(my_str, d))
		cout << d << endl;
	else
		cout << "Cannot convert string to double" << endl;

	my_str = string("Hello"); // double�� ��ȯ �Ұ���
	if (FromString(my_str, d))
		cout << d << endl;
	else
		cout << "Cannot convert string to double" << endl;

}

#include <sstream> // stream of stream
template<typename T>
string ToString(T x)
{
	std::ostringstream osstream;
	osstream << x; // osstream���� �޿� ��� �� ��
	return osstream.str(); // ���� ���µ� string���� �ٲ��ش�.
}

template <typename T>
bool FromString(string& str, T& x)
{
	istringstream isstream(str);
	// input stream �� �ʱ�ȭ �Ҷ� str�� �־ �ʱ�ȭ�Ѵ�

	return(isstream >> x) ? true : false;
	// stream�� ���������
}