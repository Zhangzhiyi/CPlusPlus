#include "StdAfx.h"
#include "DerivedStringGood.h"
#include <iostream>

DerivedStringGood::DerivedStringGood()
{
	char s[] = "DerivedStringGood";
	int len = strlen(s);
	m_name = new char[len + 1];
	strcpy(m_name, s);
}
DerivedStringGood::DerivedStringGood(char* name):
StringGood("DerivedStringGood") //���û���Ĺ��췽������д�͵��û���Ĭ�Ϲ��췽��
{
	int len = strlen(name);
	m_name = new char[len + 1];
	strcpy(m_name, name);
}
DerivedStringGood::DerivedStringGood(const DerivedStringGood& dsg):
StringGood(dsg) //���û���ĸ��ƹ��캯��
{
	int len = strlen(dsg.m_name);
	m_name = new char[len + 1];
	strcpy(m_name, dsg.m_name);
}
DerivedStringGood & DerivedStringGood::operator= (const DerivedStringGood& dsg)
{
	if (this == &dsg)
	{
		return *this;
	}
	StringGood::operator=(dsg); //���û���ĸ�ֵ��������
	delete [] m_name;
	int len = strlen(dsg.m_name);
	m_name = new char[len + 1];
	strcpy(m_name, dsg.m_name);
	return *this;
}
DerivedStringGood::~DerivedStringGood()
{
	if (m_name)
	{
		delete [] m_name;
		m_name = NULL;
	}
}