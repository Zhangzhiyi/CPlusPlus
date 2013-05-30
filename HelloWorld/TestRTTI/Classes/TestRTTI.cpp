// TestRTTI.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
class Grand
{
private:
	int hold;
public:
	Grand(int h = 0):hold(h){}
	virtual ~Grand(){};
	virtual void Speak() const {cout << "I am a Grand class\n";}
	virtual int Value() const {return hold;}
};
class Superb : public Grand
{
public:
	Superb(int h = 0):Grand(h){}
	virtual ~Superb(){};
	virtual void Speak() const {cout << "I am a Superb class\n";};
	virtual void Say() const {cout << "I hold the superb value of " << Value() << "!\n";}
};
class Magnificent : public Superb
{
private:
	char ch;
public:
	Magnificent(int h = 0, char c = 'A'):Superb(h),ch(c){}
	virtual void Speak() const {cout << "I am a Magnificent class\n";};
	virtual void Say() const {cout << "I hold the character " << ch << " and the integer "<< Value() << "!\n";}
};

/**不包含虚函数**/
class Base 
{

};
class Derived: public Base {};


Grand * getOne(void)
{
	Grand* p;
	int index = rand()%3;
	switch(index)
	{
		case 0:
			p = new Grand(rand() %100);
			break;
		case 1:
			p = new Superb(rand() % 100);
			break;
		case 2:
			p = new Magnificent(rand() % 100, 'A' + rand() % 26);
			break;
	}
	return p;
}
int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(0));
	Grand * pg;
	Superb * ps;
	for (int i = 0; i <5; i++)
	{
		pg = getOne();
		cout << "Now Processing type " << typeid(*pg).name() <<".!\n";
		pg->Speak();
		if (ps = dynamic_cast<Superb*>(pg))
		{
			ps->Say();
		}
		/**typeid运算符使得能够确定两个对象是否为同种类型。typeid运算符返回一个对type_info对象的引用**/
		if (typeid(Magnificent) == typeid(*pg))
		{
			cout << "Yes, You ' re really magnificent.\n";
		}
	}
	/*如果表达式的类型是类类型且至少包含有一个虚函数，则typeid操作符返回表达式的动态类型，
	需要在运行时计算；否则，typeid操作符返回表达式的静态类型，在编译时就可以计算
	
	因为包含虚函数的类编译器会适用动态联编，否则将使用静态联编。
	
	*/

	//当typeid操作符的操作数是不带有虚函数的类类型时，typeid操作符会指出指针的类型，而不是底层对象的类型。
	Base* pbase = new Derived();
	cout << typeid(*pbase).name() << endl; // class Base
	//注意：dynamic_cast运算符只能适用于包含虚函数的类。
	//Derived* pderived = dynamic_cast<Derived*>(pbase);//编译错误 “dynamic_cast”:“Base”不是多态类型
	Derived* pderived = static_cast<Derived*>(pbase);
	cout << typeid(*pderived).name() << endl;

	Magnificent m;
	Magnificent & rm = m;
	cout << typeid(m).name() << endl;
	cout << typeid(rm).name() << endl;
	Magnificent* pm = new Magnificent();
	cout << typeid(pm).name() << endl;
	cout << typeid(*pm).name() << endl;
	system("Pause");
	return 0;
}

