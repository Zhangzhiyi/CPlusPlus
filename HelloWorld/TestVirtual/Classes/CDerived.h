#pragma once
#include "CBase.h"
class CDerived :public CBase
{
public:
	CDerived(void);
	~CDerived(void);
	virtual void Test();
	virtual void show();
	//派生类独有的方法
	void range();
	
	void name();
	int m_num;
};

