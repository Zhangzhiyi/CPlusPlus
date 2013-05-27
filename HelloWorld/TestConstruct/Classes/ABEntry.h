#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;

class PhoneNumber;
class ABEntry
{
public:
	//���ҽ���û�ж����κι��캯��ʱ���������Ż��ṩĬ�Ϲ��캯����Ϊ�ඨ���˹��캯���󣬳���Ա�ͱ���Ϊ���ṩĬ�Ϲ��캯�������������������������� ABEntry entry;
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
