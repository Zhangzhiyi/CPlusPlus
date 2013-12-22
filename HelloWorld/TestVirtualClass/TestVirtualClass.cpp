// TestVirtualClass.cpp : 定义控制台应用程序的入口点。
//测试虚基类

#include "stdafx.h"
#include <iostream>
#include "Base.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	/*由此可知，其公共基类的构造函数只调用了一次，并且优先于非基类的构造函数调用；并且发现，子派生类的对象obj的成员变量的值只有一个，
	所以，当公共基类CBase被声明为虚基类后，虽然它成为CDerive1和CDerive2的公共基类，但子派生类CDerive12中也只有它的一个备份。
	可以仔细比较与例2的运行结果有什么不同。*/
	CDerive12 obj(100, 200, 300);
	//得到从CDerive1继承的值
	cout << " from CDerive1 : a = " << obj.CDerive1::getValue() << endl;
	//得到从CDerive2继承的值
	cout << " from CDerive2 : a = " << obj.CDerive2::getValue() << endl;
	system("Pause");
	return 0;
}

