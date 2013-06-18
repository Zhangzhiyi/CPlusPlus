#ifndef _DERIVED_STRINGGOOD_H__
#define _DERIVED_STRINGGOOD_H__

#include "StringGood.h"

using namespace std;
class DerivedStringGood : public StringGood
{
public:
	DerivedStringGood();
	DerivedStringGood(char* name);
	~DerivedStringGood();

	DerivedStringGood(const DerivedStringGood& dsg); //如果不重写，默认的复制构造函数也是会调用StringGood重写的函数
	DerivedStringGood & operator = (const DerivedStringGood& dsg);

private:
	char* m_name; //派生类新增成员指针变量，需要为派生类重新编写复制构造函数和赋值操作函数，否则会出现不安全操作
};
#endif