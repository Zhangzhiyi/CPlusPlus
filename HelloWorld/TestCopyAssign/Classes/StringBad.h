#ifndef __STRINGBAD_H__
#define __STRINGBAD_H__

#include <iostream>

using namespace std;

/**
	StringBad是没有开发好的示例，故意留下漏洞来测试
**/
class StringBad
{
public:
		StringBad(const char* s);
		StringBad();
		~StringBad();
		friend ostream & operator<<(ostream & os, const StringBad & st);
private:
		char* str;
		int len;
		static int num_strings;
};
#endif