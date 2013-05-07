// TestVirtual.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "CBase.h"
#include "CDerived.h"
#include "Person.h"

using namespace std;
void Test1(CBase test)//�������ݷ��ڲ����ݷ�ʽ��ֵ���ݣ��������������ʱ�����������ݸ������ں��������޸Ĳ���Ӱ��ԭ�������ݡ��������ַ�ʽ�ᷢ�����и
{
	test.Test(); //��������test����ͷ��ڴ棬������������
}

void Test2(CBase &test)//���ô��ݣ����޸�ԭ����ֵ���������´���CBase�����������Ч�ʣ���ʱ�������졢���ơ��������̶�������ʱ�䡣
{
	test.Test();
}
void Test3(CBase* test)//ָ�봫��,���޸�ԭ����ֵ����������ʱ����һ��ָ��
{
	cout << "��ӡָ�������ڴ��ַ:" << &test << endl; 
	cout << "��ӡָ��ָ���ڴ��ַ:" << (int *)test << endl;
	test->Test();
	//delete test; //�ͷ�ָ��ָ����ڴ�
	test = NULL;
}
int _tmain(int argc, _TCHAR* argv[])
{
	//֪ʶ�㣺ע������ָ������(����ʱȷ��)�Ͷ�������(����ʱȷ��). ��֮�����鷽���Ǹ���ָ�����������ã��鷽���Ǹ��ݶ�������������
	//ָ������(CBase)    ��������(CDerived()
	//CBase *pBase = new CDerived();
	CBase base;
	//base.Test();

	CDerived derived;
	CBase* p = &derived; //��ʽ����ǿ��ת��
	//��һ��derived class object������ȥ����һ��base class objectʱ��
	//��ԭ�����ԡ���Ϊһ��derived class object�����������������ᱻ�г���slicing������ֻ�����ڲ�һ��base class object��
	//��by reference�ķ�ʽ���ݲ���������һ���ŵ㣺�ɱ�����ν�ġ��иslicing�����⡱��
	Test1(derived);//Output from CBase! �����и�
	Test2(derived);//Output from CDerived!
	Test3(p);      //Output from CDerived!
	cout << "��ӡָ�������ڴ��ַ:" << &p << endl; 
	cout << "��ӡָ��ָ���ڴ��ַ:" << (int *)p << endl;
	p->show();
	//p->range();//�������.��range��: ���ǡ�CBase���ĳ�Ա

	CDerived* derived2 = (CDerived *)&base; //��ʽ����ǿ��ת��
	derived2->range();//������������еķ���������ȫ����������������з���CDerived���еĳ�Ա�������õ�thisָ��ͻ�����⣩
	CDerived* derived3 = dynamic_cast<CDerived*>(&base);//��dynamic_cast��ת�����Ϳ��Լ��ת���Ƿ�ȫ�ɹ���ʧ�ܷ��ؿ�ָ��
	if (derived3)
	{
		derived3->range();
	}
	CDerived* derived4 = dynamic_cast<CDerived*>(p);
	if (derived4)
	{
		derived4->range();
	}
	derived2->Test();//Output from CBase �����ݶ����������жϣ�
	
	CBase *pBase = new CDerived();
	/*��������
	���һ�����������࣬����ͨ����Ҫvirtual��������������������������Ҫ��
	������������������������������������delete���ͷŻ���ָ��(����ʵָ�����������Ķ���ʵ��)ռ�õ��ڴ��ʱ��
	ֻ�л�����������������ã���������������������ᱻ���ã���Ϳ��������ڴ�й¶����������������������������
	��ô��delete����ָ��ʱ���̳����ϵ����������ᱻ�Ե��������ε��ã�����ײ�����������������ᱻ���ȵ��ã�
	Ȼ��һ��һ������ֱ����ָ�����������͡�*/
	delete pBase;

	Person *person = new Person();
	person->showAge();
	person->show1();
	printf("%d\n", Person::date);
	Children *children = new Children();
	printf("%d\n", Children::date);
	children->show1();
	Person *person1 = children;
	//show2()û��ʹ��virtual�ؼ��֣����򽫸������û���ָ������ѡ�񷽷����Ҹ棺���Բ�Ҫ���¶���̳ж����ķ����⺯��
	person1->show2(); //Person::show2()
	Children* children2 = (Children*)person;//��ʽ����ǿ��ת��
	children2->show2(); //Children::show2()  ����ת��֮���ǿ��Ե���Children�ĺ����ģ���Ϊ�����ʱ�����ڴ��ַ�Ѿ�ȷ�����������������Ҫ�õ�thisָ����õ���Ա�����Ͳ���ȫ
	Person *person2 = new Children();
	//person2->show4(); person2�����ܵ���show4()��ֻ�ܵ���Person�෽��;
	person2->hide();
	//children->hide(); //Person��hide()������������,���ܵ���
	children->hide(1);
	//���Ը���
	person1->testOverride(10);
	person2->testOverride(10);
	children->testOverride(10);
	system("Pause");
	return 0;
}

