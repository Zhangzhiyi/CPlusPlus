#pragma once
class Person
{
public:
	Person(void);
	~Person(void);
	int getAge() const;
	void modifyAge();
	void showAge();
private:
	int age;
};

