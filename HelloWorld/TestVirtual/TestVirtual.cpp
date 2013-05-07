// TestVirtual.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "CBase.h"
#include "CDerived.h"
#include "Person.h"

using namespace std;
void Test1(CBase test)//这样传递非内部数据方式是值传递，即函数会产生临时变量复制数据副本，在函数体内修改不会影响原来的数据。而且这种方式会发生“切割”
{
	test.Test(); //函数结束test会给释放内存，运行析构函数
}

void Test2(CBase &test)//引用传递，会修改原来的值，不会重新创建CBase副本，能提高效率，临时变量构造、复制、析构过程都将消耗时间。
{
	test.Test();
}
void Test3(CBase* test)//指针传递,会修改原来的值，函数会临时分配一个指针
{
	cout << "打印指针自身内存地址:" << &test << endl; 
	cout << "打印指针指向内存地址:" << (int *)test << endl;
	test->Test();
	//delete test; //释放指针指向的内存
	test = NULL;
}
int _tmain(int argc, _TCHAR* argv[])
{
	//知识点：注意区分指针类型(编译时确定)和对象类型(运行时确定). 总之，非虚方法是根据指针类型来调用，虚方法是根据对象类型来调用
	//指针类型(CBase)    对象类型(CDerived()
	//CBase *pBase = new CDerived();
	CBase base;
	//base.Test();

	CDerived derived;
	CBase* p = &derived; //隐式向上强制转换
	//当一个derived class object被交出去当作一个base class object时，
	//它原本所以“成为一个derived class object”的所有特征，都会被切除（slicing）掉，只留下内部一个base class object。
	//以by reference的方式传递参数，有另一个优点：可避免所谓的“切割（slicing）问题”。
	Test1(derived);//Output from CBase! 出现切割
	Test2(derived);//Output from CDerived!
	Test3(p);      //Output from CDerived!
	cout << "打印指针自身内存地址:" << &p << endl; 
	cout << "打印指针指向内存地址:" << (int *)p << endl;
	p->show();
	//p->range();//编译错误.“range”: 不是“CBase”的成员

	CDerived* derived2 = (CDerived *)&base; //显式向下强制转换
	derived2->range();//调用派生类独有的方法，不安全操作（如果方法内有访问CDerived独有的成员变量，用到this指针就会出问题）
	CDerived* derived3 = dynamic_cast<CDerived*>(&base);//用dynamic_cast来转换类型可以检查转换是否安全成功，失败返回空指针
	if (derived3)
	{
		derived3->range();
	}
	CDerived* derived4 = dynamic_cast<CDerived*>(p);
	if (derived4)
	{
		derived4->range();
	}
	derived2->Test();//Output from CBase （根据对象类型来判断）
	
	CBase *pBase = new CDerived();
	/*虚析构：
	如果一个类用作基类，我们通常需要virtual来修饰它的析构函数，这点很重要。
	如果基类的析构函数不是虚析构，当我们用delete来释放基类指针(它其实指向的是派生类的对象实例)占用的内存的时候，
	只有基类的析构函数被调用，而派生类的析构函数不会被调用，这就可能引起内存泄露。如果基类的析构函数是虚析构，
	那么在delete基类指针时，继承树上的析构函数会被自低向上依次调用，即最底层派生类的析构函数会被首先调用，
	然后一层一层向上直到该指针声明的类型。*/
	delete pBase;

	Person *person = new Person();
	person->showAge();
	person->show1();
	printf("%d\n", Person::date);
	Children *children = new Children();
	printf("%d\n", Children::date);
	children->show1();
	Person *person1 = children;
	//show2()没有使用virtual关键字，程序将根据引用或者指针类型选择方法。忠告：绝对不要重新定义继承而来的非虚拟函数
	person1->show2(); //Person::show2()
	Children* children2 = (Children*)person;//显式向下强制转换
	children2->show2(); //Children::show2()  发现转型之后还是可以调用Children的函数的，因为编译的时函数内存地址已经确定，如果函数里面需要用到this指针调用到成员变量就不安全
	Person *person2 = new Children();
	//person2->show4(); person2并不能调用show4()，只能调用Person类方法;
	person2->hide();
	//children->hide(); //Person的hide()函数给隐藏了,不能调用
	children->hide(1);
	//测试覆盖
	person1->testOverride(10);
	person2->testOverride(10);
	children->testOverride(10);
	system("Pause");
	return 0;
}

