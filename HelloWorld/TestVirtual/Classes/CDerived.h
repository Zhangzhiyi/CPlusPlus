#ifndef __CDERIVED_H__
#define __CDERIVED_H__

#include "CBase.h"
class CDerived :public CBase
{
public:
	CDerived(void);
	~CDerived(void);
	virtual void Test();
	virtual void show();
	//派生类独有的方法
	virtual void derived_print();
	void range();
	

	void name();
	int m_num;
};

#endif