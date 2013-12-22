#include "stdafx.h"
#include "Base.h"
#include <iostream>
using namespace std;
CBase::CBase(int value)
{
	a = value;
	cout << "CBase constructor!" << endl;
}
CBase::~CBase()
{
	cout << "CBase deconstructor! " << endl;
}

CDerive1::CDerive1(int value) :
CBase(value)
{
	cout << "CDerive1 constructor! " << endl;
}
CDerive1::~CDerive1()
{
	cout << "CDerive1 deconstructor! " << endl;
}
CDerive2::CDerive2(int value) :
CBase(value)
{
	cout << "CDerive2 constructor! " << endl;
}
CDerive2::~CDerive2()
{
	cout << "CDerive2 deconstructor! " << endl;
}

CDerive12::CDerive12(int n1, int n2, int n3) :CDerive1(n1), CDerive2(n2), CBase(n3)
{
	cout << "CDerive12 constructor! " << endl;
}
CDerive12::~CDerive12()
{
	cout << "CDerive12 deconstructor! " << endl;
}