#include "StdAfx.h"
#include "Person.h"


void Person::name(string name)
{
	cout << name << endl;
}

Student::Student(string name, int age)
{
	m_name = name;
	m_age = age;
}
Student::~Student()
{

}
void Student::say()
{
	cout << "hi, this is a Student" << endl;
	// �ص�����ָ�븳ֵ����Ҫǿת�� SEL_CallFun
	//mpfnSelector = (SEL_CallFun)(&Student::callBack);
	mpfnSelector = callFunc_selector(Student::callBack);
	m_pListen = this;

	// ���ûص��������Ǹ�string  
	(m_pListen->*mpfnSelector)(m_name);

}

void Student::callBack(string str)
{
	cout<<"My name is "  
		<< str<<endl  
		<< "age is "  
		<<m_age<<endl;
}