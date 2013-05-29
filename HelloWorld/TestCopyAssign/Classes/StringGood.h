#ifndef __STRINGGOOD_H__
#define __STRINGGOOD_H__
#include <iostream>
using namespace std;
class StringGood
{
public:
	
	StringGood();
	~StringGood();
	StringGood(const char* s);
	StringGood(const StringGood& st);  //复制构造函数
	StringGood & operator = (const StringGood& st);//赋值运算符
	StringGood & operator = (const char* s);//赋值运算符


	friend ostream & operator<<(ostream & os, const StringGood & st);
private:
	char* str;	// 像这种指针成员变量记得写自己的复制构造函数和赋值操作符函数
	int len;
	static int num_strings;
};
#endif