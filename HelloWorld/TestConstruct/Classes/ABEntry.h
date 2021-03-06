#ifndef __ABENTRY_H__
#define __ABENTRY_H__

#include <iostream>
#include <string>
#include <list>
using namespace std;

class PhoneNumber;
class ABEntry
{
public:
	/*
		当且仅当没有定义任何构造函数时，编译器才会提供默认构造函数。当程序员为类定义了构造函数后，编译器就不再为类提供默认的构造函数
		程序员就必须为它提供默认构造函数。否则这样的声明将出错： ABEntry entry; 而且默认的构造函数只能有一个.
		例如：
				Klunk() {klunk_ct = 0;}	//constructor #1
				Klunk(int n = 0){klunk_ct = n;}	// ambiguous constructor #2

				Klunk kar(10)	//clearly matches Klunt(int n)
				Klunk bus;			//could match either constructor
	*/
	ABEntry();
	ABEntry(const string& name, const string& address, list<PhoneNumber>& phones);
	ABEntry(const string& name, const string& address, list<PhoneNumber>& phones, int num);
	~ABEntry(void);

private:
		string theName;
		string theAddress;
		list<PhoneNumber> thePhones;
		int numTimesConsulted;
};

class PhoneNumber {};

#endif
