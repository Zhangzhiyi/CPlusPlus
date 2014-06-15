#include "StdAfx.h"
#include "Person.h"

void Person::callBack(string str)
{
	cout << "My name is "<< str << endl;
}
Student::Student(string name, int age)
{
	m_name = name;
	m_age = age;
}
Student::~Student()
{

}
void Student::registerCallback(Person *pSelectorTarget, SEL_CallFun selector)
{	
	mpfnSelector = selector;
	// 回调函数指针赋值。需要强转成 SEL_CallFun
	//mpfnSelector = (SEL_CallFun)(&Person::callBack);
	//mpfnSelector = callFunc_selector(Person::callBack);
	m_pListen = pSelectorTarget;
}
void Student::say()
{
	cout << "hi, this is a Student" << endl;
	// 调用回调，参数是个string  
	(m_pListen->*mpfnSelector)(m_name);
}