#include "StdAfx.h"
#include "ABEntry.h"

ABEntry::ABEntry()
{
	//Ĭ�ϵĹ��캯����Ϊ��ĳ�Ա�������ó�ʼֵ(���Ե���һ����֤)���ڲ����ͳ��⡣��Ϊ�ڲ�����û�г�ʼ���췽����
	//�����ڲ����ͱ���һ��Ҫ��ʽ��ʼ��������Ϳ����ˡ�������Ϊ�����˶���������
	numTimesConsulted = 0;
}
/**
C++�涨������ĳ�Ա������ʼ�����������ڽ��빹�캯������֮ǰ����ABEntry���캯���ڣ�
theName��theAddress��thePhones�����ǳ�ʼ�����Ǹ�ֵ����ʼ��������ʱ����硣
�����������캯������һ���汾�Ĺ��캯��Ч�ʸ��ߡ��ڶ������ڸ�ֵ���캯���汾���ȵ���Ĭ�Ϲ��캯��Ϊ
theName��theAddress��thePhones��ʼ�����ó�ֵ�ˣ�Ȼ�������ٶ����Ǹ�����ֵ��Ĭ�Ϲ��캯����һ����Ϊ����˷��ˡ�
��Ա�б��ֵ���캯���汾��������һ���⡣
**/
ABEntry::ABEntry(const string& name, const string& address, list<PhoneNumber>& phones):
theName(name),    //��Ա�б��ʼ��
theAddress(address),
thePhones(phones),
numTimesConsulted(0)
{
	//���ڣ����캯���������κζ���
}
ABEntry::ABEntry(const string& name, const string& address, list<PhoneNumber>& phones, int num)
{
	//����˹��캯����֮ǰtheName��theAddress��thePhones�Ѿ��ֱ�������Ǹ��Ե�Ĭ�Ϲ��캯����ʼ����
	//����������Щ���Ǹ�ֵ�����ǳ�ʼ���� ���� 
	theName = name;		
	theAddress = address;
	thePhones = phones;
	numTimesConsulted = num;
}




ABEntry::~ABEntry(void)
{
}
