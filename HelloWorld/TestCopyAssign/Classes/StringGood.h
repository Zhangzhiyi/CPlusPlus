#ifndef __STRINGGOOD_H__
#define __STRINGGOOD_H__
#include <iostream>
using namespace std;
class StringGood
{
public:
	
	StringGood();
	~StringGood();
	StringGood(const char* s);
	StringGood(const StringGood& st);  //���ƹ��캯��
	StringGood & operator = (const StringGood& st);//��ֵ�����
	StringGood & operator = (const char* s);//��ֵ�����


	friend ostream & operator<<(ostream & os, const StringGood & st);
private:
	char* str;	// ������ָ���Ա�����ǵ�д�Լ��ĸ��ƹ��캯���͸�ֵ����������
	int len;
	static int num_strings;
};
#endif