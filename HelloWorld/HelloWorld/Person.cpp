#include "StdAfx.h"
#include "Person.h"


Person::Person(void)
{
	age = 10;
}


Person::~Person(void)
{
}
void Person::showAge()
{
	printf("age:%d\n", age);
}
void Person::show1()
{
	show2();
	show3();
}
void Person::show2()
{
	printf("Person::show2()\n");
}
void Person::show3()
{
	printf("Person::show3()\n");
}
void Person::hide()
{
	printf("Person::hide()\n");
}

Children::Children(void)
{
}


Children::~Children(void)
{
}
void Children::show2()
{
	printf("Children::show2()\n");
}
void Children::show3()
{
	printf("Children::show3()\n");
}
void Children::show4()
{
	printf("Children::show4()\n");
}
void Children::hide(int i)
{
	printf("Children::hide()\n");
}