#include "StdAfx.h"
#include "CNullPointCall.h"
#include <iostream>

using namespace std;
int CNullPointCall::m_iStatic = 0;
CNullPointCall::CNullPointCall(void)
{
}


CNullPointCall::~CNullPointCall(void)
{
}

void CNullPointCall::Test1()
{
	cout << m_iStatic << endl;
}

void CNullPointCall::Test2()
{
	cout << "Very Cool!" << endl; 
}

void CNullPointCall::Test3(int iTest)
{
	cout << iTest << endl; 
}

void CNullPointCall::Test4()
{
	cout << m_iTest << endl; 
}