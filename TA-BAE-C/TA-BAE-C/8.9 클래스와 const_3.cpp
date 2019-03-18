// [C++] Ŭ���������� ��� ����, ��� �Լ��� ���ȭ (const�� ����)
// https://pacs.tistory.com/entry/C-%ED%81%B4%EB%9E%98%EC%8A%A4%EC%97%90%EC%84%9C%EC%9D%98-%EB%A9%A4%EB%B2%84-%EB%B3%80%EC%88%98-%EB%A9%A4%EB%B2%84-%ED%95%A8%EC%88%98%EC%9D%98-%EC%83%81%EC%88%98%ED%99%94-const%EC%9D%98-%EC%82%AC%EC%9A%A9%EB%B2%95

// ���۷��� ������ const �κ� �ٽ� ����!

#include <iostream>

using namespace std;

class Something
{
public:
	string m_value = "default";

	/*string getValue() const
	{
		return m_value;
	}*/
	// ��� ����

	// ���۷����� �����ϴµ� �Լ��� const�� ���!
	/*const*/ string& getValue() const
		// ���� const �ּ� ó���ϸ� ����
	{
		cout << "const version" << endl;
		return m_value;
	}
	
	// string str = getValue();
	// str = "another";
	// �̷� ���� �߻��� �� �ִ�.

	// getValue()�� const �Լ��̹Ƿ� ��� ���� ���� �ٲ㼭�� �ȵǹǷ�
	// �̷� ���� ����� ���� �����ϰ� ������
	// ��ȯ ������ string&�� �ƴ϶� const string&�� ����ؾ� �Ѵ�.
	
	// const string m_value = "default"; �� ��,
	// string& str_Ref = m_value;		// X
	// const string& str_Ref = m_value;	// O

	string& getValue()
	{
		cout << "non-const version" << endl;
		return m_value;
	}
};

void main()
{
	const Something const_sth;
	const_sth.getValue()=10;

	Something sth;
	sth.getValue()=10;
}

/*
�����ε��� Ư¡ :
1. �޼ҵ� �̸��� ���ƾ� �Ѵ�.
2. �������� ���Ƶ� �ǰ� �޶� �ȴ�.
3. �Ķ���� ������ �޶���Ѵ�.
4. �Ķ���� ������ ���� ���, �ڷ����� �޶�� �Ѵ�.
(����Ÿ���� ������ �Ķ���ʹ� �޶�� �Ѵ�)

��ó : https ://memoryfilm.tistory.com/16 [������ Memory Film]
*/

// �Ķ���Ͱ� �������� ���� �����ε� �ȵ����� const�� ���ηδ� �����ε��� �����ϴ�.