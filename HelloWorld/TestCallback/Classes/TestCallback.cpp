// TestCallback.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Person.h"

//���庯��ָ�룬���ǳ�Ա����ָ��
//��ȡ����ָ��ܼ򵥣�ֻҪʹ�ú�����(���治������)���ɡ�Ҳ����˵�����print(int)��һ����������print���Ǹú����ĵ�ַ
typedef void (*FUNC_PRINTF)(int);
void print(int x);
void print(char *str);
void estimate(void (*pc)(char*));
int _tmain(int argc, _TCHAR* argv[])
{
	Student *pStudent = new Student("Join",20); 
	Person *pPerson = new Person();
	pStudent->registerCallback(pPerson, &Person::callBack); //��Ա����ָ�벻��ȱ��&
	//pStudent->registerCallback(pPerson, callFunc_selector(Person::callBack));
	pStudent->say();

	//����ָ�� ȡ��ַ�����&���Ǳ���ģ���Ϊ����һ��������ʶ���ͱ�ű�ʾ�����ĵ�ַ
	FUNC_PRINTF pFunc = print;
	//FUNC_PRINTF pFunc = &print;
	//�������ֺ���ָ����ú���������һ��
	pFunc(1000);  
	(*pFunc)(10000);

	void (*ps)(int);
	ps = print;
	ps(111);
	(*ps)(222);

	void (*pc)(char *);
	pc = print; //���Զ��ҵ����ʲ����ĺ���
	pc("method point");

	estimate(pc);
	system("Pause");
	return 0;
}

void print(int x)
{
	cout << "x = "<< x << endl;
}
void print(char *str)
{
	cout << "str = "<< str << endl;
}
void estimate(void (*pc)(char*))
{
	pc("estimate");

}