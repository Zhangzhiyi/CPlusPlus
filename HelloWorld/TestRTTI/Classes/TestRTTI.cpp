// TestRTTI.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
class Grand
{
private:
	int hold;
public:
	Grand(int h = 0):hold(h){}
	virtual ~Grand(){};
	virtual void Speak() const {cout << "I am a Grand class\n";}
	virtual int Value() const {return hold;}
};
class Superb : public Grand
{
public:
	Superb(int h = 0):Grand(h){}
	virtual ~Superb(){};
	virtual void Speak() const {cout << "I am a Superb class\n";};
	virtual void Say() const {cout << "I hold the superb value of " << Value() << "!\n";}
};
class Magnificent : public Superb
{
private:
	char ch;
public:
	Magnificent(int h = 0, char c = 'A'):Superb(h),ch(c){}
	virtual void Speak() const {cout << "I am a Magnificent class\n";};
	virtual void Say() const {cout << "I hold the character " << ch << " and the integer "<< Value() << "!\n";}
};

/**�������麯��**/
class Base 
{

};
class Derived: public Base {};


Grand * getOne(void)
{
	Grand* p;
	int index = rand()%3;
	switch(index)
	{
		case 0:
			p = new Grand(rand() %100);
			break;
		case 1:
			p = new Superb(rand() % 100);
			break;
		case 2:
			p = new Magnificent(rand() % 100, 'A' + rand() % 26);
			break;
	}
	return p;
}
int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(0));
	Grand * pg;
	Superb * ps;
	for (int i = 0; i <5; i++)
	{
		pg = getOne();
		cout << "Now Processing type " << typeid(*pg).name() <<".!\n";
		pg->Speak();
		if (ps = dynamic_cast<Superb*>(pg))
		{
			ps->Say();
		}
		/**typeid�����ʹ���ܹ�ȷ�����������Ƿ�Ϊͬ�����͡�typeid���������һ����type_info���������**/
		if (typeid(Magnificent) == typeid(*pg))
		{
			cout << "Yes, You ' re really magnificent.\n";
		}
	}
	/*������ʽ�������������������ٰ�����һ���麯������typeid���������ر��ʽ�Ķ�̬���ͣ�
	��Ҫ������ʱ���㣻����typeid���������ر��ʽ�ľ�̬���ͣ��ڱ���ʱ�Ϳ��Լ���
	
	��Ϊ�����麯����������������ö�̬���࣬����ʹ�þ�̬���ࡣ
	
	*/

	//��typeid�������Ĳ������ǲ������麯����������ʱ��typeid��������ָ��ָ������ͣ������ǵײ��������͡�
	Base* pbase = new Derived();
	cout << typeid(*pbase).name() << endl; // class Base
	//ע�⣺dynamic_cast�����ֻ�������ڰ����麯�����ࡣ
	//Derived* pderived = dynamic_cast<Derived*>(pbase);//������� ��dynamic_cast��:��Base�����Ƕ�̬����
	Derived* pderived = static_cast<Derived*>(pbase);
	cout << typeid(*pderived).name() << endl;

	Magnificent m;
	Magnificent & rm = m;
	cout << typeid(m).name() << endl;
	cout << typeid(rm).name() << endl;
	Magnificent* pm = new Magnificent();
	cout << typeid(pm).name() << endl;
	cout << typeid(*pm).name() << endl;
	system("Pause");
	return 0;
}

