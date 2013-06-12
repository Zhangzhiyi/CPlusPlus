#ifndef _DERIVED_STRINGGOOD_H__
#define _DERIVED_STRINGGOOD_H__

#include "StringGood.h"

using namespace std;
class DerivedStringGood : public StringGood
{
public:
	DerivedStringGood();
	DerivedStringGood(char* name);
	~DerivedStringGood();

	DerivedStringGood(const DerivedStringGood& dsg); //�������д��Ĭ�ϵĸ��ƹ��캯��Ҳ�ǻ����StringGood��д�ĺ���
	DerivedStringGood & operator = (const DerivedStringGood& dsg);

private:
	char* m_name; //������������Աָ���������ҪΪ���������±�д���ƹ��캯���͸�ֵ�����������������ֲ���ȫ����
};
#endif