//
// Created by Wayen on 2024/12/17.
//

#ifndef HELLOWORLD_CBASE_H
#define HELLOWORLD_CBASE_H


class CBase {
public:
    CBase(void);
    //要定义虚析构函数，否则下面情况不会调用派生类的析构函数
    // Base* basePtr = new Derived();
    // delete basePtr;  // 只会调用 Base 的析构函数, 引起内存泄露。如果基类的析构函数是虚析构，
    //	那么在delete基类指针时，继承树上的析构函数会被自低向上依次调用，即最底层派生类的析构函数会被首先调用
    virtual ~CBase(void);
    virtual void Test();
    virtual void show();

    void name(); //CBase和CDerived都有的方法，但不是虚方法
    void hide();

    int m_first = 1;
};


#endif //HELLOWORLD_CBASE_H
