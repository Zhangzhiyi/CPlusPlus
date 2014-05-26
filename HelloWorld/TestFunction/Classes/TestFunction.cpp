// TestFunction.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <functional>
using namespace std;

void printA(int a)
{
	cout << a << endl;
}
int _tmain(int argc, _TCHAR* argv[])
{
	function<void(int a)> func1 = printA;
	func1(1);

	int a = 10;
	int b = 20;
	function<int(int a, int b)> func2 = [](int a, int b){ cout << "a = " << a << endl; cout << "b = " << b << endl; return a + b; };
	int result = func2(a, b);

	function<void()> func3 = [=](){ cout << "a = " << a << endl; cout << "b = " << b << endl; };
	func3();

	function<void()> func4 = [&](){};
	system("Pause");
	return 0;
}

