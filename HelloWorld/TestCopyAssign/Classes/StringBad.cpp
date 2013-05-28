#include "StdAfx.h"
#include "StringBad.h"

int StringBad::num_strings = 0;
StringBad::StringBad() //默认构造函数
{
	len = 4;
	str = new char[len];
	strcpy(str, "C++");
	num_strings ++ ;
	cout << num_strings << ":\"" << str << "\" object created\n";
}
StringBad::StringBad(const char* s)
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	num_strings ++ ;
	cout << num_strings << ":\"" << str << "\" object created\n";
}
ostream & operator<<(ostream & os, const StringBad & st)
{
	os << st.str;
	return os;
}
StringBad::~StringBad()
{
	cout <<"\"" << str << "\" objcect deleted, ";
	--num_strings;
	cout <<num_strings << " left\n";
	delete [] str;
	str = NULL;
}