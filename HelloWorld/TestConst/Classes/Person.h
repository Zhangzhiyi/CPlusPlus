#ifndef __PERSON_H__
#define __PERSON_H__

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

#endif