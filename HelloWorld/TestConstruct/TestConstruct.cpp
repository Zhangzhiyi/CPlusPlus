// TestConstruct.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "ClxComplex.h"
#include "ClxString.h"
#include <iostream>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	//�����3�д����ǵȼ۵�
	/*����ǰ������˵�����������ǰ�����ת���ɵ�3�еĴ�����ʵ�ֵġ���Ϊ����д�˹��캯����
	�������Ͱ������ǵĹ��캯����������ʽת����ֱ�Ӱ�һ��double��ֵ��ʽת������һ��ClxComplex�Ķ���
	���ǣ���Щʱ�����ǲ�ϣ��������ʽת����������ʽת������ɴ���*/
	ClxComplex lxTest1 = 2.0;
	lxTest1.show();
	ClxComplex lxTest2 = ClxComplex(2.0);
	lxTest2.show();
	ClxComplex lxTest3 = ClxComplex(2.0, 0.0);
	lxTest3.show();
	
	ClxString lsTest1 = 13;  // ��ͬ��ClxString lsTest1 = ClxString(13);
	ClxString lsTest2 = "ABC";  // ��ͬ��ClxString lsTest2 = ClxString("A");
	ClxString lsTest3 = 'A';	// ��ͬ��ClxString lsTest2 = ClxString(65);�����������������ϣ�������ġ������ʱ�����Ǿ�Ҫ�õ���ʽ���캯����,�����캯��������explicit�Ϳ��Է�ֹ��ʽת��
	cout << lsTest2.getString() << endl;
	system("Pause");
	return 0;
}

