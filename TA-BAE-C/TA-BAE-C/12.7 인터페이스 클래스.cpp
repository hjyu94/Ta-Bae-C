// �������̽� Ŭ����: ���� �����Լ��θ� �̷���� Ŭ����
// ��� ~~�� �ؾ� �Ѵ�. 
// �ܺο��� ����� �� �� �̷��̷��� ����� ���� �Ŷ�� �����ϴ� �߰� ����.

#include <iostream>
#include <string>
using namespace std;

class IErrorLog // I+ErrorLog: I�� �������̽� �ǹ�
{
public:
	/* �����Լ� */ virtual bool reportError(const char* errorMessage) = 0;
	/* �����Լ� */ virtual ~IErrorLog() {}
	// �Ҹ��ڴ� �����Լ������� �ڽ� Ŭ�������� ���� ���������� �ʾƵ� ����
	// �⺻ �Ҹ��ڰ� �������.
};

class FileErrorLog : public IErrorLog
{
public:
	bool reportError(const char* errorMessage)
	{
		cout << "Writing error to a file" << endl;
		return true;
	}
};

class ConsoleErrorLog : public IErrorLog
{
public:
	bool reportError(const char* errorMessage)
	{
		cout << "Printing error to a console" << endl;
		return true;
	}
};

void doSomething(IErrorLog& log) // �Ķ���ͷ� �������̽��� ������Ʈ�� ���
{
	log.reportError("Runtime error!!");
}

int main()
{
	FileErrorLog file_log;
	ConsoleErrorLog console_log;

	doSomething(file_log);
	doSomething(console_log);

	return 0;
}