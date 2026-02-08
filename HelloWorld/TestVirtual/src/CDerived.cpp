//
// Created by Wayen on 2024/12/21.
//

#include "../include/CDerived.h"

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
    cout << "CDerived::Test()" << endl;
}
void CDerived::show()
{
    CBase::show(); //调用父类的虚拟方法
    cout << "CDerived::show()" << endl;
}
void CDerived::range()
{
    m_num = 10000;
    cout << "CDerived::range():" << m_num << endl;
}
void CDerived::derived_print()
{
    cout << "CDerived::derived_print()" << endl;
}
void CDerived::name()
{
    CBase::name(); //name()不是虚函数也可以用::来调用基类方法，但是不建议这样做. 忠告：绝对不要重新定义继承而来的非虚拟函数
    cout << "CDerived::name()" << endl;
}

void CDerived::hide(int i) {
    //CBase::hide(); 这里内部可以调用
    cout << "CDerived::hide(int i)" << endl;
}
