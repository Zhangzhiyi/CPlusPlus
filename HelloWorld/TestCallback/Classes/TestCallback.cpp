// TestCallback.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Person.h"

//定义函数指针，不是成员函数指针
//获取函数指针很简单：只要使用函数名(后面不跟参数)即可。也就是说，如果print(int)是一个函数，则print就是该函数的地址
typedef void (*FUNC_PRINTF)(int);
void print(int x);
void print(char *str);
void estimate(void (*pc)(char*));
int _tmain(int argc, _TCHAR* argv[])
{
	Student *a = new Student("Join",20);  
	a->say();

	//函数指针
	FUNC_PRINTF pFunc = print;
	//下面两种函数指针调用函数作用是一样
	pFunc(1000);  
	(*pFunc)(10000);

	void (*ps)(int);
	ps = print;
	ps(111);
	(*ps)(222);

	void (*pc)(char *);
	pc = print; //会自动找到合适参数的函数
	pc("method point");

	estimate(pc);
	system("Pause");
	return 0;
}

void print(int x)
{
	cout << "x = "<< x << endl;
}
void print(char *str)
{
	cout << "str = "<< str << endl;
}
void estimate(void (*pc)(char*))
{
	pc("estimate");

}