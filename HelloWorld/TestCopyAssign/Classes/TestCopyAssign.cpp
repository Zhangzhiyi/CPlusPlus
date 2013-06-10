// TestCopyAssign.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "StringBad.h"
#include "StringGood.h"
#include "DerivedStringGood.h"
using namespace std;

void callme1(StringBad & rsb);
void callme2(StringBad sb);

void callme1(StringGood & rsb);
void callme2(StringGood sb);
StringGood getStringGood();
int _tmain(int argc, _TCHAR* argv[])
{
	{
		/*StringBad headline1("Celery Stalks at Midnight");
		StringBad headline2("Lettuce Prey");
		StringBad sports("Spinash Leaves Bowl for Dollars");
		cout << "headline1: " << headline1 << endl;
		cout << "headline2: " << headline2 << endl;
		cout << "sports: " << sports << endl;
		callme1(headline1);
		cout << "headline1: " << headline1 << endl;
		callme2(headline2);
		cout << "headline2: " << headline2 << endl;

		cout << "Initialize one object to another:\n";
		StringBad sailor = sports;
		cout << "sailor: " << sailor << endl;

		cout << "Assign one object to another:\n";
		StringBad knot;
		knot = headline1;
		cout << "knot: " << knot << endl;
		cout << "Exitting the block.\n";*/
	}
	
	{
		StringGood headline1("Celery Stalks at Midnight");
		StringGood headline2("Lettuce Prey");
		StringGood sports("Spinash Leaves Bowl for Dollars");
		cout << "headline1: " << headline1 << endl;
		cout << "headline2: " << headline2 << endl;
		cout << "sports: " << sports << endl;
		callme1(headline1);
		cout << "headline1: " << headline1 << endl;
		callme2(headline2);
		cout << "headline2: " << headline2 << endl;

		cout << "Initialize one object to another:\n";
		StringGood sailor = sports;  //�ⲻ�Ǹ�ֵ���ǵ��ø��ƹ��캯����һ���½��Ķ������ǻ���ù��캯����
		cout << "sailor: " << sailor << endl;
		StringGood* psg = new StringGood(sports); //���ַ�ʽҲ�ǵ��ø��ƹ��캯��
		cout << "psg: " << *psg << endl;
		delete psg;

		cout << "Assign one object to another:\n";
		StringGood knot;
		knot = headline1;   //���ø�ֵ��������� operator = (const StringGood& st);
		cout << "knot: " << knot << endl;
		knot = "operator = (const char* s)";//���ø�ֵ��������� operator = (const char* s);
		cout << "knot: " << knot << endl;
		

		StringGood kail = getStringGood();
		cout << "kail: " << kail << endl;
		cout << "Exitting the block.\n";
	}
	{
		DerivedStringGood d("DerivedStringGood");
		DerivedStringGood d2 = d;
		int a = 10;
	}
	system("Pause");
	return 0;
}

void callme1(StringBad & rsb)
{
	cout << "String passed by reference:\n";
	cout <<"    \"" << rsb << "\"\n";
}
void callme2(StringBad sb) //ֵ���ݵ��ø��ƹ��캯�����뿪��������������������κι��ڶ��󶼻�������������������ܶ�������δ�����
{
	cout << "String passed by value:\n";
	cout <<"    \"" << sb << "\"\n";
}
void callme1(StringGood & rsg)
{
	cout << "String passed by reference:\n";
	cout <<"    \"" << rsg << "\"\n";
}
void callme2(StringGood sg)
{
	cout << "String passed by value:\n";
	cout <<"    \"" << sg << "\"\n";
}
StringGood getStringGood()
{
	StringGood str("StringGood");  //�ȹ���str��Ȼ����ø��ƹ��캯�����ظ�Ŀ�������������������
	return str;
}
