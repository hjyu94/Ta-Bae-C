// �θ� Ŭ������ �������ε� �ڽ�Ŭ������ �Լ��� ã�ư��� �� �������ش�.
// �̷��� ������ �������̶�� �θ���.

#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
	string m_name;

public:
	Animal(string name)
		: m_name(name)
	{}
	void speak() const { cout << m_name << " ???" << endl; }
};

/************************************************************************/

class Dog : public Animal
{
public:
	Dog(string name)
		: Animal(name)
	{}
	void speak() const { cout << m_name << " Woof" << endl; }
};


class Cat : public Animal
{
public:
	Cat(string name)
		: Animal(name)
	{}
	void speak() const { cout << m_name << " Meow" << endl; }
};

/************************************************************************/

void main()
{
	Animal animal("my animal");
	Cat cat("my cat");
	Dog dog("my dog");

	animal.speak();
	cat.speak(); // my cat Meow
	dog.speak(); // my dog Woof

	// �ڽ� Ŭ������ ��ü�� �θ� Ŭ������ �����͸� ����Ѵٸ�?
	Animal* ptr_animal1 = &cat;
	Animal* ptr_animal2 = &dog;

	ptr_animal1->speak(); // my cat ???
	ptr_animal2->speak(); // my dog ???

	// for ���� ����ϱ�
	Cat cats[] = { Cat("cat1"), Cat("cat2"), Cat("cat3"), Cat("cat4") };
	Dog dogs[] = { Dog("Dog1"), Dog("Dog2"), Dog("Dog3"), Dog("Dog4"), Dog("Dog5") };

	for (int i = 0; i < 4; ++i)
		cats[i].speak();

	for (int i = 0; i < 5; ++i)
		dogs[i].speak();

	// �׷��� �̶�, ����� �� ���� ��� ���� �� ��� ������ ��û���� ���ٸ�
	// �� Ŭ���� ���� for ���� ������ �ϳ�?

	// �θ��� Ŭ������ ������� �� �ִµ� �̶� ������, Meow�� Woof�� �ƴ϶� ???�� ��µȴ�
	// ��ġ �θ� Ŭ������ �� ó�� �۵��Ѵ�.

	// �̷� ��� Animal Ŭ������ speak �Լ��� virtual�� �ٿ��� �ذ��Ѵ�! [������]
	Animal* my_animals[] =
	{
		&cats[0],&cats[1],&cats[2],&cats[3],
		&dogs[0],&dogs[1],&dogs[2],&dogs[3],&dogs[4],
		// ...
	};

	for (auto element : my_animals)
		element->speak();
} 
