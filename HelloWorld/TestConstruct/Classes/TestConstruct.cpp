// TestConstruct.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ClxComplex.h"
#include "ClxString.h"
#include <iostream>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	//下面的3行代码是等价的
	/*对于前两行来说，编译器都是把它们转换成第3行的代码来实现的。因为我们写了构造函数，
	编译器就按照我们的构造函数来进行隐式转换，直接把一个double数值隐式转换成了一个ClxComplex的对象。
	可是，有些时候，我们不希望进行隐式转换，或者隐式转换会造成错误*/
	ClxComplex lxTest1 = 2.0;
	lxTest1.show();
	ClxComplex lxTest2 = ClxComplex(2.0);
	lxTest2.show();
	ClxComplex lxTest3 = ClxComplex(2.0, 0.0);
	lxTest3.show();
	
	ClxString lsTest1 = 13;  // 等同于ClxString lsTest1 = ClxString(13);
	ClxString lsTest2 = "ABC";  // 等同于ClxString lsTest2 = ClxString("A");
	ClxString lsTest3 = 'A';	// 等同于ClxString lsTest2 = ClxString(65);这种情况都不是我们希望看到的。在这个时候我们就要用到显式构造函数了,将构造函数声明成explicit就可以防止隐式转换
	cout << lsTest2.getString() << endl;
	system("Pause");
	return 0;
}

