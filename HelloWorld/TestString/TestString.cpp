// TestString.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	string str = "12345";
	cout << str.size() << endl;

	int value[100];// value[i]��ֵ��ȷ����û�г�ʼ��
	value[0] = 1;//value[0]Ϊ1��������ȷ��

	int value2[100] = {1, 2};// value[0]��value[1]��ֵ�ֱ�Ϊ1��2����û�ж���ĳ�ʼ��Ϊ0
	int *pia = new int[10]; // ÿ��Ԫ�ض�û�г�ʼ��
	int *pia2 = new int[10] ();  // ÿ��Ԫ�س�ʼ��Ϊ0

	char pc[10]; //û�г�ʼ����ֵ��ȷ��
	memset(pc, '1', 10); //����ʼ��Ϊ'1'
	pc[9] = '\0'; //�ǵò�0����NULL
	cout << pc << endl;

	char a[] = "abc"; //�ǵú��滹��0Ŷ
	unsigned int length = strlen(a) + 1; //4  �ǵú��滹��0Ŷ������Ҫ + 1
	char *b = new char[length];//û�г�ʼ����ֵ��ȷ��
	strcpy(b, a);    
	cout << b << endl;
	char c[5];//char c[length]����д��������
	strcpy(c, a); //c�����['a', 'b', 'c', 0, '?']  �ɼ��Զ���0��
	cout << c << endl;
	//ע�⣺ʹ��strcpy�����ַ���Ŀ�곤һ��Ҫ����Դ���������������벻���Ĵ���

	char a2[] = "123";
	unsigned int size = strlen(a2) + 1; //4
	char *b2 = new char[size];
	strncpy(b2, a2, size);
	cout << b2 << endl;
	char c2[4];
	strncpy(c2, a2, size);
	cout << c2 << endl;
	char c3[4];
	strncpy(c3, a2, size - 1); //�����Ƶĳ���С��Դ����ʱ��һ��Ҫ�ֶ���0������������������Ľ��
	c3[size - 1] = 0;//�ֶ���0
	cout << c3 << endl;
	//ע�⣺1��ʹ��strncpyĿ�곤�ĳ���һ��Ҫ���ڻ����ָ�����Ȳ������������л����
	//		2����ָ�����Ȳ����ĳ��ȴ��ڵ���Դ����ʱ�򣬻��Զ���0
	//		3����ָ�����Ȳ����ĳ���С��Դ����ʱ��һ��Ҫ�ֶ���0������������������Ľ��

	int arr[5] = {1,2,3,4,5};
	// 20(5��4�ֽ�int,20�ֽ�) | 4(arr[2]��ʾ���ʵ�2���±��int��һ��intռ4���ֽ�)
	cout << sizeof(arr) << " | " << sizeof(arr[2]) << endl;
	char *ps = "12345"; 
	cout << "��ӡָ�������ڴ��ַ:" << &ps << endl;
	cout << "��ӡָ��ָ���ڴ��ַ:" << (int *)ps << endl;
	char p1 = *(ps + 4);  // 5
	char p2 = *(ps + strlen(ps));  // 0 ֤���ַ�ָ�����ҲҪ��'\0'ָʾ����
	//4(ָ����Զ����ռ4���ֽ�) |  1(charռһ���ֽ�)  |  5(�ַ�����)
	cout << sizeof(ps) << " |  "<< sizeof(*ps)<< " | "<< strlen(ps) <<endl;
	char parry[] = "12345";
	//6(5������'\0',sizeof������'\0') | 1 (parry[2]��ʾ�����±�Ϊ2��char)   |  5(strlen��������'\0')
	cout << sizeof(parry) << " | "<< sizeof(parry[2]) << " |  " << strlen(parry) << endl; 
	/*���ۣ�  sizeof(ָ��) ��Զռ4λ����Ϊ������ַ����int��ʾ     
			  sizeof(*ָ��) ָ������ռ��λ��
			  sizeof(ָ������) ָ�������С * ��������ռ��λ����ע���ַ������������'\0'
			  
			  strlen(�ַ�ָ��) ���� strlen(�ַ�ָ������) ������ַ��������ǲ�������'\0'*/
	system("Pause");
	return 0;
}

