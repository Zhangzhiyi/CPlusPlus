// TestVirtualClass.cpp : �������̨Ӧ�ó������ڵ㡣
//���������

#include "stdafx.h"
#include <iostream>
#include "Base.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	/*�ɴ˿�֪���乫������Ĺ��캯��ֻ������һ�Σ����������ڷǻ���Ĺ��캯�����ã����ҷ��֣���������Ķ���obj�ĳ�Ա������ֵֻ��һ����
	���ԣ�����������CBase������Ϊ��������Ȼ����ΪCDerive1��CDerive2�Ĺ������࣬����������CDerive12��Ҳֻ������һ�����ݡ�
	������ϸ�Ƚ�����2�����н����ʲô��ͬ��*/
	CDerive12 obj(100, 200, 300);
	//�õ���CDerive1�̳е�ֵ
	cout << " from CDerive1 : a = " << obj.CDerive1::getValue() << endl;
	//�õ���CDerive2�̳е�ֵ
	cout << " from CDerive2 : a = " << obj.CDerive2::getValue() << endl;
	system("Pause");
	return 0;
}

