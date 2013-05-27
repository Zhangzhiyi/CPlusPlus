// TestThisPoint.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "CNullPointCall.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	//浅析C++中的this指针 http://blog.csdn.net/starlee/article/details/2062586

	/*你肯定会很奇怪我为什么这么问。一个值为NULL的指针怎么可以用来调用类的成员函数呢？！可是实事却很让人吃惊：除了call 4那行代码以外，其余3个类成员函数的调用都是成功的，都能正确的输出结果，而且包含这3行代码的程序能非常好的运行。
	经过细心的比较就可以发现，call 4那行代码跟其他3行代码的本质区别：类CNullPointCall的成员函数中用到了this指针。
	对于类成员函数而言，并不是一个对象对应一个单独的成员函数体，而是此类的所有对象共用这个成员函数体。 当程序被编译之后，此成员函数地址即已确定。而成员函数之所以能把属于此类的各个对象的数据区别开, 就是靠这个this指针。函数体内所有对类数据成员的访问， 都会被转化为this->数据成员的方式。
	而一个对象的this指针并不是对象本身的一部分，不会影响sizeof（“对象”）的结果。this作用域是在类内部，当在类的非静态成员函数中访问类的非静态成员的时候，编译器会自动将对象本身的地址作为一个隐含参数传递给函数。也就是说，即使你没有写上this指针，编译器在编译的时候也是加上this的，它作为非静态成员函数的隐含形参，对各成员的访问均通过this进行。
	对于上面的例子来说，this的值也就是pNull的值。也就是说this的值为NULL。而Test1()是静态函数，编译器不会给它传递this指针，所以call 1那行代码可以正确调用（这里相当于CNullPointCall::Test1()）；对于Test2()和Test3()两个成员函数，虽然编译器会给这两个函数传递this指针，但是它们并没有通过this指针来访问类的成员变量，因此call 2和call 3两行代码可以正确调用；而对于成员函数Test4()要访问类的成员变量，因此要使用this指针，这个时候发现this指针的值为NULL，就会造成程序的崩溃。 */   

	CNullPointCall *pNull = NULL; // 没错，就是给指针赋值为空
	pNull->Test1(); // call 1
	pNull->Test2(); // call 2
	pNull->Test3(13); // call 3
	pNull->Test4(); // call 4  这里调用会出错，因为调用到类的成员变量，要用到this指针
	system("Pause");
	return 0;
}

