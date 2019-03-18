// �ǹ����� ���� ������Ʈ�� �����ϴ� ����
// ��� �̰� ������ ���� ®�µ�? ��� ������ �ϰ� �� ��

// ǥ�� ���ø� ���̺귯��(Standard Template Libraries)��
// �����̳ʿ� ���ؼ� �������

#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>

using namespace std;

void sequence_containers()
{
	// vector
	{
		vector<int> vec; // #include <vector>
		for (int i = 0; i < 10; ++i)
			vec.push_back(i); // �ڿ� �߰���

		for (auto& e : vec)
			cout << e << " ";
		cout << endl;
	}

	// deque
	{
		deque<int> deq; // #include <deque>
		for (int i = 0; i < 10; ++i)
		{
			deq.push_back(i);
			deq.push_front(i); // vector���� ������. �����ε� �߰� ����
		}

		for (auto& e : deq)
			cout << e << " ";
		cout << endl;
	}
}

void associative_containers()
{
	// set
	{
		set<string> str_set; // ���Ұ� �ߺ����� �ʴ´�.

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");

		cout << str_set.size() << endl; // 2

		for (auto& e : str_set)
			cout << e << " ";
		cout << endl;
	}

	// multiset: duplication is allowed
	{
		set<string> str_set;

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");

		cout << str_set.size() << endl; // 3

		for (auto& e : str_set)
			cout << e << " ";
		// Hello World Hello ������ �־��
		// ����� �Ʒ��� ����
		//
		// Hello Hello World
		cout << endl;
	}

	// map: key/value
	{
		map<char, int> map;
		map['a'] = 10;
		map['b'] = 20;
		map['c'] = 50;

		cout << map['a'] << endl; // 10

		map['a'] = 100;
		cout << map['a'] << endl; // 100

		for (auto& e : map)
			cout << e.first << " " << e.second << endl;
		// [e.first] key / [e.second] value
		// a 100 b 20 c 50
		cout << endl;
	}

	// multimap: duplicated keys
	{
		std::multimap<char, int> map;
		map.insert(pair<char, int>('a', 10));
		map.insert(pair<char, int>('b', 10));
		map.insert(pair<char, int>('c', 100));
		map.insert(pair<char, int>('a', 100));

		cout << map.count('a') << endl; // 2

		for (auto& e : map)
			cout << e.first << " " << e.second << endl;
		// a 10 a 100 b 10 c 100
		// sorted list�� ��µ�
		cout << endl;
	}
}

void container_adapters()
{
	// stack
	{
		cout << "Stack" << endl;
		stack<int> stack;
		stack.push(1);		// push adds a copy
		stack.emplace(2);	// emplace constructs a new obj
		stack.emplace(3);
		cout << stack.top() << endl; // 3
		stack.pop();
		cout << stack.top() << endl; // 2
	}

	// queue
	{
		cout << "Queue" << endl;
		queue<int> queue;
		queue.push(1);
		queue.push(2);
		queue.push(3);
		cout << queue.front() << " " << queue.back() << endl; // 1 3
		queue.pop(); // 1�� ��������
		cout << queue.front() << " " << queue.back() << endl; // 2 3
	}

	// primary queue
	{
		cout << "Priority queue" << endl;
		priority_queue<int> queue;
		// int�� �ƴ϶� ����� ���� �ڷ��� Ŭ������ ���
		// ũ�⸦ ���ϴ� �����ڸ� �����ε����־�� �Ѵ�.

		for (const int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
			queue.push(n);

		for (int i = 0; i < 10; ++i)
		{
			cout << queue.top() << " ";
			queue.pop();
		}
		// 9 8 7 6 5 4 3 2 1 0
	}
}

void main()
{
	/* 1 */ sequence_containers();
	/* 2 */ associative_containers();
	/* 3 */ container_adapters();
}