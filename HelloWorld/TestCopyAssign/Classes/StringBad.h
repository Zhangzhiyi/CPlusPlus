#ifndef __STRINGBAD_H__
#define __STRINGBAD_H__

#include <iostream>

using namespace std;

/**
	StringBad��û�п����õ�ʾ������������©��������
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