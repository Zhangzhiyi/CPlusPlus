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
	//��������еķ���
	void range();
	
	void name();
	int m_num;
};

#endif