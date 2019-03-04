#include <iostream>
#include <string>
#include <exception>
using namespace std;

class CustomException : public std::exception
{
public:

};

void main()
{

	try
	{
		string s;
		s.resize(-1); // ���������� Exception�� throw��

		throw runtime_error("Bad thing happend");
		throw CustomException();
	}
	catch (std::length_error& exception)
	{
		cout <	< "length_error" << endl;
		cerr << exception.what() << endl;
	}
	catch (std::exception& exception)
	{
		cout << typeid(exception).name() << endl;
		cerr << exception.what() << endl;
	}
}