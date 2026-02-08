//
// Created by Wayen on 2024/12/20.
//

#include <iostream>
#include "include/CBase.h"
#include "include/CDerived.h"

using namespace std;

void Test1(CBase test)//这样传递非内部数据方式是值传递，即函数会产生临时变量复制数据副本，在函数体内修改不会影响原来的数据。而且这种方式会发生“切割”
{
    cout << "before call Test1()" << endl;
    test.Test(); //函数结束test会给释放内存，运行析构函数
}

void Test2(CBase &test)//引用传递，会修改原来的值，不会重新创建CBase副本，能提高效率，临时变量构造、复制、析构过程都将消耗时间。
{
    cout << "before call Test2()" << endl;
    test.Test();
}
void Test3(CBase* test)//指针传递,会修改原来的值，函数会临时分配一个指针
{
    cout << "before call Test3()" << endl;
    cout << "打印指针自身内存地址:" << &test << endl;
    cout << "打印指针指向内存地址:" << (int *)test << endl;
    test->Test();
    //delete test; //释放指针指向的内存
    test = NULL;
}

int main() {
    std::cout << "Test Virtual!!!" << std::endl;
    //知识点：注意区分指针类型(编译时确定)和对象类型(运行时确定). 总之，非虚方法是根据指针类型来调用，虚方法是根据对象类型来调用
    //指针类型(CBase)    对象类型(CDerived())
    //CBase *pBase = new CDerived();
    CBase base;
    cout << "sizeof(base):" << sizeof(base) << endl; // 16
    cout << sizeof(long long) << endl; // 8字节 64位
    //base.Test();

    CDerived derived;
    cout << "sizeof(derived):" << sizeof(derived) << endl;
    derived.name();
    derived.derived_print();
    CBase* p = &derived; //隐式向上强制转换
    //当一个derived class object被交出去当作一个base class object时，
    //它原本所以“成为一个derived class object”的所有特征，都会被切除（slicing）掉，只留下内部一个base class object。
    //以by reference的方式传递参数，有另一个优点：可避免所谓的“切割（slicing）问题”。引用是除指针外另一个可以产生多态效果的手段。

    Test1(derived);//Output from CBase! 出现切割
    Test2(derived);//Output from CDerived!
    Test3(p);      //Output from CDerived!
    cout << "打印指针自身内存地址:" << &p << endl;
    cout << "打印指针指向内存地址:" << (int *)p << endl;
    p->show();
//    p->range();//编译错误.“range”: 不是“CBase”的成员
    CDerived* derived2 = (CDerived *)&base; //显式向下强制转换
    derived2->range();//调用派生类独有的方法，不安全操作（如果方法内有访问CDerived独有的成员变量，用到this指针就会出问题）

    CDerived* derived3 = dynamic_cast<CDerived*>(&base);//用dynamic_cast来转换类型可以检查转换是否安全成功，失败返回空指针
    if (derived3){
        cout<< "derived3 dynamic_cast successful !!" <<endl;
        derived3->range();
    } else {
        cout<< "derived3 dynamic_cast failed !!" <<endl;
    }

    CDerived* derived4 = dynamic_cast<CDerived*>(p);
    if (derived4){
        cout<< "derived4 dynamic_cast successful !!" <<endl;
        derived4->range();
    } else {
        cout<< "derived4 dynamic_cast failed !!" <<endl;
    }
    derived2->Test();//Output from CBase （根据对象类型来判断）

    //derived.hide(); CBase的hide()方法不可见，无法调用
    derived.hide(1);

    return 0;
}