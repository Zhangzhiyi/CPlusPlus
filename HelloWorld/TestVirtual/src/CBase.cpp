//
// Created by Wayen on 2024/12/17.
//

#include "../include/CBase.h"

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
    cout << "CBase::Test()" << endl;
}
void CBase::show()
{
    cout << " CBase::show()" << endl;
}

void CBase::name()
{
    cout <<"CBase::name()" << endl;
}

void CBase::hide() {
    cout << "CBase::hide()" << endl;
}