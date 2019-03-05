#include <iostream>
#include <string>
#include <exception>
using namespace std;

class CustomException : public std::exception
{
public:
	// noexcept: not throw any exception
	// �ش� �Լ� �ȿ����� ���ܸ� ������ �ʰڴ�.
	const char* what() const noexcept override
	{
		return "Custom exception";
	}
};

void main()
{

	try
	{
		std::string s; // std library�� std::Exception���� ����� �� ����
		s.resize(-1); 
		// ������ resize �� �� ����
		// ���������� Exception�� throw��

	}
	// exception: �θ� Ŭ����
	// length_error: �ڽ� Ŭ����
	catch (std::length_error& exception)
	{
		cout << "length_error" << endl;
		cerr << exception.what() << endl;
	}
	catch (std::exception& exception)
	{
		cout << typeid(exception).name() << endl;
		// class std::length_error
		cerr << exception.what() << endl;
		// string too long
	}
	
	/********************************************/

	try
	{
		throw runtime_error("Bad thing happend");
	}
	catch (std::exception& exception)
	{
		cout << typeid(exception).name() << endl;
		// class std::runtime_error
		cerr << exception.what() << endl;
		// Bad thing happened
	}

	/********************************************/
	
	try
	{
		throw CustomException();
	}
	catch (std::exception& exception)
	{
		cout << typeid(exception).name() << endl;
		// class CustomException
		cerr << exception.what() << endl;
		// Custom exception
	}

}