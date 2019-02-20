#include <iostream>

using namespace std;

class A_Device
{
private:
	int m_id;

public:
	A_Device(const int& id) { m_id = id; };
	void doA() {};
	int getID() { return m_id; };
};

class B_Device
{
private:
	int m_id;

public:
	B_Device(const int& id) { m_id = id; };
	void doB() {};
	int getID() { return m_id; };
};

// ���� ���
class AB_Device : public A_Device, public B_Device
{
public:
	AB_Device(int a_id, int b_id)
		: A_Device(a_id), B_Device(b_id)
	{}
};

void main()
{
	AB_Device AandB(10, 20);

	// A�� �Լ��� B�� �Լ� ��� ȣ�� ����
	AandB.doA();
	AandB.doB();
	
	// ���� �̸��� �Լ��� �ִ� ���� ��� �ؾ� �ұ�?
	AandB.getID();				// X // ��ȣ��
	AandB.A_Device::getID();	// O
	AandB.B_Device::getID();	// O

}