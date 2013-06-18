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
StringGood("DerivedStringGood") //调用基类的构造方法，不写就调用基类默认构造方法
{
	int len = strlen(name);
	m_name = new char[len + 1];
	strcpy(m_name, name);
}
DerivedStringGood::DerivedStringGood(const DerivedStringGood& dsg):
StringGood(dsg) //调用基类的复制构造函数
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
	StringGood::operator=(dsg); //调用基类的赋值操作函数
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