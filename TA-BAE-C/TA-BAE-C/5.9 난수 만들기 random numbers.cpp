#include <iostream>
// #include <cstdlib> // std::rand(), std::srand()
#include <ctime> // std::time()
using namespace std;

int main()
{
	srand(5323); // ������ ���尪�� ���. ����ø��� ���� ������ ��� ������ ��
	srand(static_cast<unsigned int>(time(0)));
	// ���� cpu clock�� ����� ����ϹǷ� ������ ������ �ٸ� ������ ����

	// �� ����� ���� ������ ���尪�� ����ϴ� ���� ������ ���ĳ��� ���ϴ�.

	for (int count = 1; count <= 100; ++count)
	{
		cout << rand() << "\t";

		if (count % 5 == 0) cout << endl;
	}
}