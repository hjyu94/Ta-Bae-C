#include <iostream>

using namespace std;

// �迭�� �μ��� �����ϱ�
//void printElement(int(&arr)[4])
//{
//
//}

void printElement(int(&arr)[99])
{

}
// �ݵ�� �迭�� ũ�⵵ ���ڿ� �����ϰ� �����ؾ� �Ѵ�.

int main()
{
	int arr[]{ 1,2,3,4 };

	printElement(arr);

}

//////////////////////////////////////////////////////

#include <vector>

void printElement(
	/* const:���������� ������ָ� ���� */ 
	vector<int>& arr)
{

}

int main()
{
	vector<int> arr{ 1,2,3,4 };
	printElement(arr);
}