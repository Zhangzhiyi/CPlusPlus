#ifndef __CBASE_H__
#define __CBASE_H__
class CBase
{
public:
	CBase(int value);
	virtual ~CBase();
protected:
	int a;
};
class CDerive1 : virtual public CBase
{
public:
	CDerive1(int value);
	~CDerive1();

	int getValue(){ return a; }
};
class CDerive2 : virtual public CBase
{
public:
	CDerive2(int value);
	~CDerive2();

	int getValue(){ return a; }
};
class CDerive12 : public CDerive1, public CDerive2
{
public:
	CDerive12(int n1, int n2, int n3);
	~CDerive12();

};
#endif

