// TestConst.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "Person.h"
//1�����ڲ��������͵Ĳ������ԣ���void Func(A a) ���������ĺ���ע��Ч�ʱȽϵס���Ϊ�������ڽ�����A ���͵���ʱ�������ڸ��Ʋ���a��
//����ʱ����Ĺ��졢���ơ��������̶�������ʱ�䣬Ӧ�ý���ֵ���ݡ��ķ�ʽ��Ϊ��const ���ô��ݡ���Ŀ�������Ч�ʡ�
//���罫void Func(A a) ��Ϊvoid Func(const A &a)��

//2�������ڲ��������͵������������Ҫ����ֵ���ݡ��ķ�ʽ��Ϊ��const ���ô��ݡ���
//���ں������Զ�������ʱ�������ڸ��Ƹò����������ڲ��������͵Ĳ��������ڹ��졢�����Ĺ��̣�������Ҳ�ǳ��죬
//��ֵ���ݡ��͡����ô��ݡ���Ч�ʼ����൱��������������������豣�������Բ�Ҫ��const ���Ρ�
//����ȴﲻ�����Ч�ʵ�Ŀ�ģ��ֽ����˺����Ŀ�����ԡ�����void Func(int x) ��Ӧ�ø�Ϊvoid Func(const int &x)��

void setAge(int age);//�ڲ�����ֵ����
void showPerson(Person person);//���ֻ������ʱ����
void showPerson(Person& person);//���ô���.��������ʱ������Ч�ʿ�

//constȫ�ֱ�����������Ϊ�ڲ�����C++������ȫ��const�����൱��ʹ����static˵����һ��
const int fingers = 5; //same as static const int fingers = 5
int _tmain(int argc, _TCHAR* argv[])
{

	int m = 100;
	const int * num = &m; //ָ�볣��
	//*num = *num + 1;	//ָ��ָ��Ķ����ܸı�


	Person person;
	person.modifyAge();
	person.showAge();

	const Person &reference = person;
	//reference.modifyAge();//�������,��ͼ�޸ĳ�Ա����
	//reference.showAge();//�������,��ͼ���÷�const����

	const Person* pPerson = &person;
	//pPerson->modifyAge();//�������,��ͼ�޸ĳ�Ա����
	//pPerson->showAge();//�������,��ͼ���÷�const����

	/*const ��Ա�����������������ֵֹģ�const �ؼ���ֻ�ܷ��ں���������β�����������Ϊ�����ط����Ѿ���ռ���ˡ�
	����Const�����ļ������

	a. const����ֻ�ܷ���const��Ա����,����const������Է�������ĳ�Ա����,����const��Ա����.
	b. const����ĳ�Ա�ǲ����޸ĵ�,Ȼ��const����ͨ��ָ��ά���Ķ���ȴ�ǿ����޸ĵ�.
	c. const��Ա�����������޸Ķ��������,���ܶ����Ƿ����const����.���ڱ���ʱ,���Ƿ��޸ĳ�Ա����Ϊ����,���м��.
	e. Ȼ������mutable���η������ݳ�Ա,�����κ������ͨ���κ��ֶζ����޸�,��Ȼ��ʱ��const��Ա�����ǿ����޸�����*/
	system("Pause");
	return 0;
}

