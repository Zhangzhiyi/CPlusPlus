#include "StdAfx.h"
#include "Person.h"
#include <iostream>

using namespace std;

Person::Person(void):
age(100)
{
}


Person::~Person(void)
{
}

int Person::getAge() const
{
	return age;
}
void Person::modifyAge()
{
	age++ ;
}
void Person::showAge()
{
	cout << "age:" << age << endl;
}