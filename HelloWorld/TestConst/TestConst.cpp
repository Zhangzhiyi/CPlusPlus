// TestConst.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Person.h"
//1、非内部数据类型的参数而言，象void Func(A a) 这样声明的函数注定效率比较底。因为函数体内将产生A 类型的临时对象用于复制参数a，
//而临时对象的构造、复制、析构过程都将消耗时间，应该将“值传递”的方式改为“const 引用传递”，目的是提高效率。
//例如将void Func(A a) 改为void Func(const A &a)。

//2、对于内部数据类型的输入参数，不要将“值传递”的方式改为“const 引用传递”，
//由于函数将自动产生临时变量用于复制该参数，而且内部数据类型的参数不存在构造、析构的过程，而复制也非常快，
//“值传递”和“引用传递”的效率几乎相当。该输入参数本来就无需保护，所以不要加const 修饰。
//否则既达不到提高效率的目的，又降低了函数的可理解性。例如void Func(int x) 不应该改为void Func(const int &x)。

void setAge(int age);//内部数据值传递
void showPerson(Person person);//这种会产生临时变量
void showPerson(Person& person);//引用传递.不产生临时变量，效率快

//const全局变量的链接性为内部，在C++看来，全局const定义相当于使用了static说明符一样
const int fingers = 5; //same as static const int fingers = 5
int _tmain(int argc, _TCHAR* argv[])
{

	int m = 100;
	const int * num = &m; //指针常量
	//*num = *num + 1;	//指针指向的对象不能改变


	Person person;
	person.modifyAge();
	person.showAge();

	const Person &reference = person;
	//reference.modifyAge();//编译错误,企图修改成员变量
	//reference.showAge();//编译错误,企图调用非const函数

	const Person* pPerson = &person;
	//pPerson->modifyAge();//编译错误,企图修改成员变量
	//pPerson->showAge();//编译错误,企图调用非const函数

	/*const 成员函数的声明看起来怪怪的：const 关键字只能放在函数声明的尾部，大概是因为其它地方都已经被占用了。
	关于Const函数的几点规则：

	a. const对象只能访问const成员函数,而非const对象可以访问任意的成员函数,包括const成员函数.
	b. const对象的成员是不可修改的,然而const对象通过指针维护的对象却是可以修改的.
	c. const成员函数不可以修改对象的数据,不管对象是否具有const性质.它在编译时,以是否修改成员数据为依据,进行检查.
	e. 然而加上mutable修饰符的数据成员,对于任何情况下通过任何手段都可修改,自然此时的const成员函数是可以修改它的*/
	system("Pause");
	return 0;
}

