#ifndef __ABENTRY_H__
#define __ABENTRY_H__

#include <iostream>
#include <string>
#include <list>
using namespace std;

class PhoneNumber;
class ABEntry
{
public:
	/*
		���ҽ���û�ж����κι��캯��ʱ���������Ż��ṩĬ�Ϲ��캯����������ԱΪ�ඨ���˹��캯���󣬱������Ͳ���Ϊ���ṩĬ�ϵĹ��캯��
		����Ա�ͱ���Ϊ���ṩĬ�Ϲ��캯������������������������ ABEntry entry; ����Ĭ�ϵĹ��캯��ֻ����һ��.
		���磺
				Klunk() {klunk_ct = 0;}	//constructor #1
				Klunk(int n = 0){klunk_ct = n;}	// ambiguous constructor #2

				Klunk kar(10)	//clearly matches Klunt(int n)
				Klunk bus;			//could match either constructor
	*/
	ABEntry();
	ABEntry(const string& name, const string& address, list<PhoneNumber>& phones);
	ABEntry(const string& name, const string& address, list<PhoneNumber>& phones, int num);
	~ABEntry(void);

private:
		string theName;
		string theAddress;
		list<PhoneNumber> thePhones;
		int numTimesConsulted;
};

class PhoneNumber {};

#endif
