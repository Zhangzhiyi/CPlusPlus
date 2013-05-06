// TestString.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	string str = "12345";
	cout << str.size() << endl;

	int value[100];// value[i]的值不确定，没有初始化
	value[0] = 1;//value[0]为1，其他不确定

	int value2[100] = {1, 2};// value[0]和value[1]的值分别为1和2，而没有定义的初始化为0
	int *pia = new int[10]; // 每个元素都没有初始化
	int *pia2 = new int[10] ();  // 每个元素初始化为0

	char pc[10]; //没有初始化，值不确定
	memset(pc, '1', 10); //都初始化为'1'
	pc[9] = '\0'; //记得补0或者NULL
	cout << pc << endl;

	char a[] = "abc"; //记得后面还有0哦
	unsigned int length = strlen(a) + 1; //4  记得后面还有0哦，所以要 + 1
	char *b = new char[length];//没有初始化，值不确定
	strcpy(b, a);    
	cout << b << endl;
	char c[5];//char c[length]这样写会编译错误
	strcpy(c, a); //c变成了['a', 'b', 'c', 0, '?']  可见自动补0了
	cout << c << endl;
	//注意：使用strcpy复制字符串目标长一定要大于源长，否则会出现意想不到的错误

	char a2[] = "123";
	unsigned int size = strlen(a2) + 1; //4
	char *b2 = new char[size];
	strncpy(b2, a2, size);
	cout << b2 << endl;
	char c2[4];
	strncpy(c2, a2, size);
	cout << c2 << endl;
	char c3[4];
	strncpy(c3, a2, size - 1); //当复制的长度小于源长的时候，一定要手动补0，否则输出不是期望的结果
	c3[size - 1] = 0;//手动补0
	cout << c3 << endl;
	//注意：1、使用strncpy目标长的长度一定要大于或等于指定长度参数，否则运行会出错
	//		2、当指定长度参数的长度大于等于源长的时候，会自动补0
	//		3、当指定长度参数的长度小于源长的时候，一定要手动补0，否则输出不是期望的结果

	int arr[5] = {1,2,3,4,5};
	// 20(5个4字节int,20字节) | 4(arr[2]表示访问第2个下表的int，一个int占4个字节)
	cout << sizeof(arr) << " | " << sizeof(arr[2]) << endl;
	char *ps = "12345"; 
	cout << "打印指针自身内存地址:" << &ps << endl;
	cout << "打印指针指向内存地址:" << (int *)ps << endl;
	char p1 = *(ps + 4);  // 5
	char p2 = *(ps + strlen(ps));  // 0 证明字符指针后面也要有'\0'指示结束
	//4(指针永远都是占4个字节) |  1(char占一个字节)  |  5(字符个数)
	cout << sizeof(ps) << " |  "<< sizeof(*ps)<< " | "<< strlen(ps) <<endl;
	char parry[] = "12345";
	//6(5后面有'\0',sizeof方法算'\0') | 1 (parry[2]表示访问下标为2的char)   |  5(strlen方法不算'\0')
	cout << sizeof(parry) << " | "<< sizeof(parry[2]) << " |  " << strlen(parry) << endl; 
	/*结论：  sizeof(指针) 永远占4位，因为制作地址是用int表示     
			  sizeof(*指针) 指针类型占的位数
			  sizeof(指针数组) 指针数组大小 * 数组类型占的位数，注意字符串数组后面有'\0'
			  
			  strlen(字符指针) 或者 strlen(字符指针数组) 计算的字符个数都是不算最后的'\0'*/
	system("Pause");
	return 0;
}

