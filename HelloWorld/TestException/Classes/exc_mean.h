#ifndef __EXC_MEAN_H__
#define __EXC_MEAN_H__

#include <iostream>

using namespace std;
class bad_hmean
{
private:
		double v1;
		double v2;
public:
		bad_hmean(double a = 0, double b = 0):v1(a), v2(b){};
		inline void mesg(){cout << "hmean(" << v1 << ", " << v2 << "): " << "invalid arguments: a = -b\n";};
};

class bad_gmean
{
public:
	double v1;
	double v2;
	bad_gmean(double a = 0, double b = 0):v1(a), v2(b){};
	const char* mesg(){ return "gmaean() arguments should be >=0 \n";}
};
#endif