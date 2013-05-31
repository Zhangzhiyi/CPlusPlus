// TestRTTI.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
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
class Base {};
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
	{
		srand(time(0));
		Grand * pg;
		Superb * ps;
		for (int i = 0; i <5; i++)
		{
			pg = getOne();
			cout << "Now Processing type " << typeid(*pg).name() <<".!\n";
			pg->Speak();
			//dynamic_cast运算符只能用于向上转型，向下转型会返回空指针
			if (ps = dynamic_cast<Superb*>(pg))
			{
				ps->Say();
			}
			else{
				cout << typeid(*pg).name() << " dynamic_cast  Superb failed!!\n";
			}
			/**typeid运算符使得能够确定两个对象是否为同种类型。typeid运算符返回一个对type_info对象的引用**/
			if (typeid(Magnificent) == typeid(*pg))
			{
				cout << "Yes, You ' re really magnificent.\n";
			}
		}
	}
	
	/*如果表达式的类型是类类型且至少包含有一个虚函数，则typeid操作符返回表达式的动态类型，
	需要在运行时计算；否则，typeid操作符返回表达式的静态类型，在编译时就可以计算
	
	因为包含虚函数的类编译器会适用动态联编，否则将使用静态联编。如果表达式的类型是类类型且至少包含有一个虚函数，
	则typeid操作符返回表达式的动态类型，需要在运行时计算；否则，typeid操作符返回表达式的静态类型，在编译时就可以计算。
	
	*/
	//当typeid操作符的操作数是不带有虚函数的类类型时，typeid操作符会指出指针的类型，而不是底层对象的类型。
	Base* pbase = new Derived();
	cout << typeid(*pbase).name() << endl; // class Base
	//注意：dynamic_cast运算符只能适用于包含虚函数的类，否则在编译期间就会出现错误
	//Derived* pderived = dynamic_cast<Derived*>(pbase);//编译错误 “dynamic_cast”:“Base”不是多态类型
	Derived* pderived = static_cast<Derived*>(pbase);
	cout << typeid(*pderived).name() << endl;

	/**
		dynamic_cast也可以用于引用的转换，其用法稍微不同：没有与空指针对应的引用值，因此无法使用特殊的引用值指示失败。当请求不正确时，
		dynamic_cast将引发类型为bad_cast的异常，这种异常时从exception类派生而来的，它是在头文件typeinfo中定义的。
	**/
	cout << "----------测试dynamic_cast用于引用的转换----------\n";
	{
		Magnificent magnificent;
		Grand & rgrand = magnificent;
		cout << typeid(rgrand).name() << endl;
		Magnificent rmagnificent = dynamic_cast<Magnificent&>(rgrand);
		cout << typeid(rmagnificent).name() << endl;

		Grand grand;
		Grand & rg = grand;
		try
		{
			//不可以向下转型，引用转型抛出异常
			Superb & rs = dynamic_cast<Superb &>(rg);
		}
		catch(bad_cast & bc){
			cout << "bad_cast" << endl;
		}
	}
	

	{
		cout << "----------测试static_cast的转换----------\n";
		/*
			static_cast向上转型或者向下转型都是合法的，而转换无关类型编译期就会报错。可以用static_cast将整形转换为枚举，double转换int，
			将float转换为long以及其他各种类型转换
		*/

		Grand grand;
		Superb superb;
		Magnificent magnificent;
		
		//向下转型
		Magnificent * pm = static_cast<Magnificent*>(&grand);
		pm->Speak(); //"I am a Superb class
		//pm->Say();  调用Say方法出错，因为里面有调用到Magnificent的特有的变量，需要this指针
		
		//向上转型
		Superb * ps = static_cast<Superb*>(&magnificent);
		ps->Speak(); //I am a Magnificent class
		ps->Say();  // I hold the character  A and the integer 0 !

		//无关类型不可以转换
		//Base* pb = static_cast<Base*>(&grand); //error C2440: “static_cast”: 无法从“Grand *”转换为“Base *”

		//C++特许指针void指针
		void* vps = ps;
		Superb * ps2 = static_cast<Superb*>(vps);
		ps2->Speak();  //I am a Magnificent class
		ps2->Say(); //// I hold the character  A and the integer 0 !

		void* vc = "void指针转char*";
		char* data = static_cast<char*>(vc);
		cout << data <<endl;
		char* data2 = (char*)vc;
		cout << data2 <<endl;
	}


	cout << "----------测试typeid的输出----------\n";
	Magnificent m;
	Magnificent & rm = m;
	cout << typeid(m).name() << endl;  //class Magnificent
	cout << typeid(rm).name() << endl; //class Magnificent
	Magnificent* pm = new Magnificent();
	cout << typeid(pm).name() << endl; //class Magnificent *
	cout << typeid(*pm).name() << endl; //class Magnificent

	

	
	system("Pause");
	return 0;
}

