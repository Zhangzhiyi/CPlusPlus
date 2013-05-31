// TestRTTI.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
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
class Base {};
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
	{
		srand(time(0));
		Grand * pg;
		Superb * ps;
		for (int i = 0; i <5; i++)
		{
			pg = getOne();
			cout << "Now Processing type " << typeid(*pg).name() <<".!\n";
			pg->Speak();
			//dynamic_cast�����ֻ����������ת�ͣ�����ת�ͻ᷵�ؿ�ָ��
			if (ps = dynamic_cast<Superb*>(pg))
			{
				ps->Say();
			}
			else{
				cout << typeid(*pg).name() << " dynamic_cast  Superb failed!!\n";
			}
			/**typeid�����ʹ���ܹ�ȷ�����������Ƿ�Ϊͬ�����͡�typeid���������һ����type_info���������**/
			if (typeid(Magnificent) == typeid(*pg))
			{
				cout << "Yes, You ' re really magnificent.\n";
			}
		}
	}
	
	/*������ʽ�������������������ٰ�����һ���麯������typeid���������ر��ʽ�Ķ�̬���ͣ�
	��Ҫ������ʱ���㣻����typeid���������ر��ʽ�ľ�̬���ͣ��ڱ���ʱ�Ϳ��Լ���
	
	��Ϊ�����麯����������������ö�̬���࣬����ʹ�þ�̬���ࡣ������ʽ�������������������ٰ�����һ���麯����
	��typeid���������ر��ʽ�Ķ�̬���ͣ���Ҫ������ʱ���㣻����typeid���������ر��ʽ�ľ�̬���ͣ��ڱ���ʱ�Ϳ��Լ��㡣
	
	*/
	//��typeid�������Ĳ������ǲ������麯����������ʱ��typeid��������ָ��ָ������ͣ������ǵײ��������͡�
	Base* pbase = new Derived();
	cout << typeid(*pbase).name() << endl; // class Base
	//ע�⣺dynamic_cast�����ֻ�������ڰ����麯�����࣬�����ڱ����ڼ�ͻ���ִ���
	//Derived* pderived = dynamic_cast<Derived*>(pbase);//������� ��dynamic_cast��:��Base�����Ƕ�̬����
	Derived* pderived = static_cast<Derived*>(pbase);
	cout << typeid(*pderived).name() << endl;

	/**
		dynamic_castҲ�����������õ�ת�������÷���΢��ͬ��û�����ָ���Ӧ������ֵ������޷�ʹ�����������ֵָʾʧ�ܡ���������ȷʱ��
		dynamic_cast����������Ϊbad_cast���쳣�������쳣ʱ��exception�����������ģ�������ͷ�ļ�typeinfo�ж���ġ�
	**/
	cout << "----------����dynamic_cast�������õ�ת��----------\n";
	{
		Magnificent magnificent;
		Grand & rgrand = magnificent;
		cout << typeid(rgrand).name() << endl;
		Magnificent rmagnificent = dynamic_cast<Magnificent&>(rgrand);
		cout << typeid(rmagnificent).name() << endl;

		Grand grand;
		Grand & rg = grand;
		try
		{
			//����������ת�ͣ�����ת���׳��쳣
			Superb & rs = dynamic_cast<Superb &>(rg);
		}
		catch(bad_cast & bc){
			cout << "bad_cast" << endl;
		}
	}
	

	{
		cout << "----------����static_cast��ת��----------\n";
		/*
			static_cast����ת�ͻ�������ת�Ͷ��ǺϷ��ģ���ת���޹����ͱ����ھͻᱨ��������static_cast������ת��Ϊö�٣�doubleת��int��
			��floatת��Ϊlong�Լ�������������ת��
		*/

		Grand grand;
		Superb superb;
		Magnificent magnificent;
		
		//����ת��
		Magnificent * pm = static_cast<Magnificent*>(&grand);
		pm->Speak(); //"I am a Superb class
		//pm->Say();  ����Say����������Ϊ�����е��õ�Magnificent�����еı�������Ҫthisָ��
		
		//����ת��
		Superb * ps = static_cast<Superb*>(&magnificent);
		ps->Speak(); //I am a Magnificent class
		ps->Say();  // I hold the character  A and the integer 0 !

		//�޹����Ͳ�����ת��
		//Base* pb = static_cast<Base*>(&grand); //error C2440: ��static_cast��: �޷��ӡ�Grand *��ת��Ϊ��Base *��

		//C++����ָ��voidָ��
		void* vps = ps;
		Superb * ps2 = static_cast<Superb*>(vps);
		ps2->Speak();  //I am a Magnificent class
		ps2->Say(); //// I hold the character  A and the integer 0 !

		void* vc = "voidָ��תchar*";
		char* data = static_cast<char*>(vc);
		cout << data <<endl;
		char* data2 = (char*)vc;
		cout << data2 <<endl;
	}


	cout << "----------����typeid�����----------\n";
	Magnificent m;
	Magnificent & rm = m;
	cout << typeid(m).name() << endl;  //class Magnificent
	cout << typeid(rm).name() << endl; //class Magnificent
	Magnificent* pm = new Magnificent();
	cout << typeid(pm).name() << endl; //class Magnificent *
	cout << typeid(*pm).name() << endl; //class Magnificent

	

	
	system("Pause");
	return 0;
}

