#ifndef __CBASE_H__
#define __CBASE_H__

class CBase
{
public:
	CBase(void);
	virtual ~CBase(void);
	virtual void Test();
	virtual void show();

	void name(); //CBase��CDerived���еķ������������鷽��

};

#endif