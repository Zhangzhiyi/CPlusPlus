#pragma once
class CBase
{
public:
	CBase(void);
	virtual ~CBase(void);
	virtual void Test();
	virtual void show();

	void name(); //CBase和CDerived都有的方法，但不是虚方法
};

