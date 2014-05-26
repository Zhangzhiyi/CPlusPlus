// TestStatic.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "TestSource1.h"
#include "TestSource2.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	/*定义全局变量时使用static，意味着该变量的作用域只限于定义它的源文件中，其它源文件不能访问。
	既然这种定义方式出现在头文件中，那么可以很自然地推测：包含了该头文件的所有源文件中都定义了这些变量，
	即该头文件被包含了多少次，这些变量就定义了多少次。*/

	TestSource1();
	TestSource2();
	/*可以看到，虽然在代码中好像使用了相同的变量，但是实际上使用的是不同的变量，在每个源文件中都有单独的变量。
	所以，在头文件中定义static变量会造成变量多次定义，造成内存空间的浪费，而且也不是真正的全局变量。
	应该避免使用这种定义方式。*/
	system("Pause");
	return 0;
}

