// TestCopyAssign.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "StringBad.h"

using namespace std;

void callme1(StringBad & rsb);
void callme2(StringBad sb);
int _tmain(int argc, _TCHAR* argv[])
{
	{
		StringBad headline1("Celery Stalks at Midnight");
		StringBad headline2("Lettuce Prey");
		StringBad sports("Spinash Leaves Bowl for Dollars");
		cout << "headline1: " << headline1 << endl;
		cout << "headline2: " << headline2 << endl;
		cout << "sports: " << sports << endl;
		callme1(headline1);
		cout << "headline1: " << headline1 << endl;
		callme2(headline2);
		cout << "headline2: " << headline2 << endl;

		cout << "Initialize one object to another:\n";
		StringBad sailor = sports;
		cout << "sailor: " << sailor << endl;

		cout << "Assign one object to another:\n";
		StringBad knot;
		knot = headline1;
		cout << "knot: " << knot << endl;
	}
	
	system("Pause");
	return 0;
}

void callme1(StringBad & rsb)
{
	cout << "String passed by reference:\n";
	cout <<"    \"" << rsb << "\"\n";
}
void callme2(StringBad sb)
{
	cout << "String passed by value:\n";
	cout <<"    \"" << sb << "\"\n";
}
