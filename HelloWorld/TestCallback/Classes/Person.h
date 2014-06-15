#ifndef _PERSON_H_
#define _PERSON_H_

#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	//�ص�����
	void callBack(string str);
};

//������ĳ�Ա����ָ��, ע���ǳ�Ա����ָ�룬����Ҫ��ʵ��������ܵ��ó�Ա����
typedef void (Person::*SEL_CallFun)(string);
#define callFunc_selector(_SELECTOR) (SEL_CallFun)(&_SELECTOR) 
class Student
{
	private:
		string m_name;
		int m_age;
	public:
		Student(string name, int age);
		~Student();
		//say������Ҫ���õĻص������ĺ���
		void say();
		void registerCallback(Person *pSelectorTarget, SEL_CallFun selector);
	protected:
		//�ص���ִ����
		Person *m_pListen;
		//�ص�����ָ��
		SEL_CallFun mpfnSelector;
};
#endif


