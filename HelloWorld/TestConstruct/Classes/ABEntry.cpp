#include "StdAfx.h"
#include "ABEntry.h"

ABEntry::ABEntry()
{
	//默认的构造函数会为类的成员变量设置初始值(可以调试一下验证)，内部类型除外。因为内部类型没有初始构造方法，
	//所以内部类型变量一定要显式初始化，否则就开启了“不明行为”的潘多拉盒子了
	numTimesConsulted = 0;
}
/**
C++规定，对象的成员变量初始化动作发生在进入构造函数本体之前，在ABEntry构造函数内，
theName，theAddress，thePhones都不是初始化，是赋值。初始化发生的时间更早。
下面两个构造函数，第一个版本的构造函数效率更高。第二个基于赋值构造函数版本首先调用默认构造函数为
theName，theAddress，thePhones初始化设置初值了，然后立刻再对他们赋予新值。默认构造函数的一切作为因此浪费了。
成员列表初值构造函数版本避免了这一问题。
**/
ABEntry::ABEntry(const string& name, const string& address, list<PhoneNumber>& phones):
theName(name),    //成员列表初始化
theAddress(address),
thePhones(phones),
numTimesConsulted(0)
{
	//现在，构造函数不必有任何动作
}
ABEntry::ABEntry(const string& name, const string& address, list<PhoneNumber>& phones, int num)
{
	//进入此构造函数体之前theName，theAddress，thePhones已经分别调用它们各自的默认构造函数初始化了
	//所以以下这些都是赋值，不是初始化。 即是 
	theName = name;		
	theAddress = address;
	thePhones = phones;
	numTimesConsulted = num;
}




ABEntry::~ABEntry(void)
{
}
