#include "StdAfx.h"
#include "StringGood.h"

int StringGood::num_strings = 0;
StringGood::StringGood()
{
	len = 4;
	str = new char[len];
	strcpy(str, "C++");
	num_strings ++ ;
	cout << num_strings << ":\"" << str << "\" object created\n";
}
StringGood::StringGood(const char* s)
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	num_strings ++ ;
	cout << num_strings << ":\"" << str << "\" object created\n";
}
StringGood::StringGood(const StringGood& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	strcpy(str, st.str);
	cout << num_strings << ":\"" << str << "\" object copy created\n";
}
StringGood & StringGood::operator= (const StringGood& st)
{
		if (this == &st)
		{
			return *this;
		}
		delete [] str;
		len = st.len;
		str = new char[len + 1];
		strcpy(str, st.str);
		return *this;
}
StringGood & StringGood::operator= (const char* s)
{
	delete [] str;
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	return *this;
}
ostream & operator<<(ostream & os, const StringGood & st)
{
	os << st.str;
	return os;
}
StringGood::~StringGood()
{
	cout <<"\"" << str << "\" objcect deleted, ";
	--num_strings;
	cout <<num_strings << " left\n";
	delete [] str;
	str = NULL;
}