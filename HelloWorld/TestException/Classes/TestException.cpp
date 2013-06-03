// TestException.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include "exc_mean.h"
using namespace std;

class demo
{
private:
	string word;
public:
	demo(const string & str){ word = str; cout << "demo " << word.c_str() << " created\n";};
	~demo(){cout << "demo " << word.c_str() << " destroyed\n";};
	void show(){cout << "demo " << word.c_str() << " lives!\n";};
};

double hmean(double a, double b);
double gmean(double a, double b);
double means(double a, double b);
int _tmain(int argc, _TCHAR* argv[])
{
	double x, y, z;
	cout << "Enter two numbers: ";
	while (cin>> x >> y)
	{
		try
		{
			z = means(x, y);
			cout << "The mean mean of " << x << " and " << y << " is " << z << endl;
			cout << "Enter next pair: ";
		}
		catch(bad_hmean & bh)
		{
			bh.mesg();
			cout << "Try again.\n";
			continue;
		}
		catch(bad_gmean & bg)
		{
			cout << bg.mesg();
			cout << "Values used: " << bg.v1 << ", " << bg.v2 << endl;
			cout << "Sorry, you don't get to play any more.\n";
			break;
		}
	}
	
	system("Pause");
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean(a, b);
	return 2.0 * a * b /(a + b);
}
double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a, b);
	return sqrt(a * b);
}
double means(double a, double b)
{
	double am, hm, gm;
	demo d2("found in means()");
	am = (a + b)/2.0;
	try
	{
		hm = hmean(a, b);
		gm = gmean(a, b);
	}
	catch (bad_hmean & bg)
	{
		bg.mesg();
		cout << "Caught in means()\n";
		/*���������쳣���⽫���ϰ��쳣���͸�main()������һ����ԣ����������쳣������һ�����������쳣��try-catch����Ͻ��д���
		���û���ҵ������Ĵ������Ĭ������³����쳣��ֹ*/
		throw;   //����main()������catch(bad_hmean & bh)����
	}
	d2.show();
	return (am + hm + gm)/3.0;

}