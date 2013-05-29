#ifndef __PERSON_H__
#define __PERSON_H__

class Person
{
public:
	Person(void);
	~Person(void);
	int age;
	void showAge();
	const static int date = 100;
	void show1();
	void show2();
	virtual void show3();

	void hide();
	void testOverride(int);
};
class Children :public Person
{
public:
	Children(void);
	~Children(void);
	//show2()并没有隐藏父类的show2()方法
	void show2();//
	//show3()为person的虚拟函数 无论加不加virtual都可以实现多态，virtual修饰符会被隐形继承
	virtual void show3();

	void show4();
	//Person的hide()函数给隐藏了,Children的对象不能调用Person的hide()方法了 
	//隐藏规则：派生类重载(同名参数不同)基类方法，基类方法会被隐藏,而且无论基类方法是否是虚方法
	void hide(int i);

	void call();
	void call(int i);

	void testOverride(int);
};

#endif