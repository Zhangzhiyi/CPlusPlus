#include "StdAfx.h"
#include "CDerived.h"
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
	cout << "Output from CDerived!" << endl; 
}
void CDerived::show()
{
	CBase::show(); //���ø�������ⷽ��
	cout << "I am CDerived!" << endl;
}
void CDerived::range()
{
	//m_num = 10000;
	cout << "CDerived::range():" << m_num << endl;
}
void CDerived::name()
{
	CBase::name(); //name()�����麯��Ҳ������::�����û��෽�������ǲ�����������. �Ҹ棺���Բ�Ҫ���¶���̳ж����ķ����⺯��
	cout << "I ' m CDerived!" << endl;
}