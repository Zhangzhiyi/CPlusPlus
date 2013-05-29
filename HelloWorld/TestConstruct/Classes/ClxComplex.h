#ifndef __CLXCOMPLEX_H__
#define __CLXCOMPLEX_H__
#include <iostream>
using namespace std;
class ClxComplex
{
public:
	//ClxComplex(void);
	~ClxComplex(void);

	ClxComplex(double dReal = 0.0, double dImage = 0.0) { m_dReal = dReal; m_dImage = dImage; }

	double GetReal() const { return m_dReal; }
	double GetImage() const { return m_dImage; }
	  
	void show(){cout << "m_dReal=" << GetReal() << " | " <<"m_dImage="<< GetImage() << endl;}
private:
	double m_dReal;
	double m_dImage;
};
#endif
