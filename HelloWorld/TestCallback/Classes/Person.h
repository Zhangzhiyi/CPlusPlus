#ifndef _PERSON_H_
#define _PERSON_H_

#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	//回调函数
	void callBack(string str);
};

//定义类的成员函数指针, 注意是成员函数指针，所以要有实例对象才能调用成员函数
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
		//say方法，要调用的回调函数的函数
		void say();
		void registerCallback(Person *pSelectorTarget, SEL_CallFun selector);
	protected:
		//回调的执行者
		Person *m_pListen;
		//回调函数指针
		SEL_CallFun mpfnSelector;
};
#endif


