//
// Created by Wayen on 2024/12/21.
//

#ifndef HELLOWORLD_CDERIVED_H
#define HELLOWORLD_CDERIVED_H

#include "CBase.h"
class CDerived : public CBase {
public:
    CDerived(void);
    ~CDerived(void);
    /** override关键字
     1. 只能用于虚函数：override关键字只能用于那些确实覆盖了基类中虚函数的方法。
     2. 提高代码可读性：使用override可以清晰地表明该函数是用来覆盖父类的方法的，从而增加代码的可读性和维护性。
     3. 防止意外行为：如果没有正确覆盖基类的虚函数（例如，因为名字拼写错误），而你认为已经覆盖了，则可能会导致程序逻辑错误。override关键字帮助避免这种问题。
     4. 与final结合使用：你还可以将override与final一起使用，以表示该函数不仅覆盖了基类中的虚函数，而且也不允许其进一步被子类覆盖。
     * **/
    virtual void Test() override; //C++11 重写父类虚方法加上override
    //show()为CBase的虚拟函数 无论加不加virtual都可以实现多态，virtual修饰符会被隐形继承
    virtual void show() final override; // 加上final 不允许其进一步被子类覆盖
    //派生类独有的方法
    virtual void derived_print();
    void range();

    //name()并没有隐藏父类的name()方法
    void name();
    //CBase的hide()函数给隐藏了,CDerived的对象不能调用CDerived的hide()方法了
    //隐藏规则：派生类重载(同名参数不同)基类方法，基类方法会被隐藏,而且无论基类方法是否是虚方法
    void hide(int i);
    int m_num = 0;
};

#endif //HELLOWORLD_CDERIVED_H
