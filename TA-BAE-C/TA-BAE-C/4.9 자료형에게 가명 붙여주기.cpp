#include <iostream>
#include <vector>

using namespace std;

void main1()
{
	typedef float distance_t;

	double		my_distance;
	distance_t	home2work;
	distance_t	home2school;

	// �̶� 
	// typedef float distance_t; ��
	// typedef double distance_t; �� �ٲ��ָ�
	// ���İ��� ��� distance_t�� double�� �ǹǷ�
	// �ڵ��� ���������� ����������.
}

int main()
{
	vector<pair<string, int>> pairlist1;
	// Ÿ���� ������ ���⵵ ������
	// ������ �ٲٸ� �� ������

	// �� �� ����
	typedef vector<pair<string, int>> pairlist_t;
	using pairlist_t = vector<pair<string, int>>;
	// assignment�� �ϴ� �� ���� ��������
	// �������� ���� assignment�� �޸𸮸� ����������
	// ���� �޸𸮸� �������� �ʰ� �����Ϸ����� pairlist_t�� � Ÿ������ �˷��� ��

	pairlist_t pairlist_1;
	pairlist_t pairlist_2;
}