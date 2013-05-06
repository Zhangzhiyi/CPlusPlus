#include "StdAfx.h"
#include "CBase.h"
#include <iostream>
using namespace std;

CBase::CBase(void)
{
	cout << "CBase Construct" << endl;
}


CBase::~CBase(void)
{
	cout << "delete from CBase" << endl;
}
void CBase::Test()
{
	cout << "Output from CBase!" << endl;
}
void CBase::show()
{
	cout << "I am CBase!" << endl;
};