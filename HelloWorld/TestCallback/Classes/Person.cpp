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
	// �ص�����ָ�븳ֵ����Ҫǿת�� SEL_CallFun
	//mpfnSelector = (SEL_CallFun)(&Person::callBack);
	//mpfnSelector = callFunc_selector(Person::callBack);
	m_pListen = pSelectorTarget;
}
void Student::say()
{
	cout << "hi, this is a Student" << endl;
	// ���ûص��������Ǹ�string  
	(m_pListen->*mpfnSelector)(m_name);
}