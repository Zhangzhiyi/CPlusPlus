#ifndef __CDERIVED_H__
#define __CDERIVED_H__

#include "CBase.h"
class CDerived :public CBase
{
public:
	CDerived(void);
	~CDerived(void);
	virtual void Test() override; //C++11 重写父类虚方法加上override
	virtual void show() override;
	//派生类独有的方法
	void range();
	
	void name();
	int m_num;
};

#endif