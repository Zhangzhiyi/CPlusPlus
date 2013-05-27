#include "StdAfx.h"
#include "CDerived.h"
#include <iostream>
using namespace std;

CDerived::CDerived(void)
{
	m_num = 1000;
	cout << "CDerived Contruct!" << endl; 
}


CDerived::~CDerived(void)
{
	cout << "delete from CDerived" << endl;
}

void CDerived::Test()
{
	cout << "Output from CDerived!" << endl; 
}
void CDerived::show()
{
	CBase::show(); //调用父类的虚拟方法
	cout << "I am CDerived!" << endl;
}
void CDerived::range()
{
	//m_num = 10000;
	cout << "CDerived::range():" << m_num << endl;
}
void CDerived::name()
{
	CBase::name(); //name()不是虚函数也可以用::来调用基类方法，但是不建议这样做. 忠告：绝对不要重新定义继承而来的非虚拟函数
	cout << "I ' m CDerived!" << endl;
}