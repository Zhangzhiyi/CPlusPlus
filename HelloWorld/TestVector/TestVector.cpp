// TestVector.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> v1 = vector<int>(10);//ÿ��Ԫ��Ĭ�ϳ�ʼ��0
	int v1Size = v1.size();
	vector<int> v2(10);
	int v2Size = v2.size();

	vector<vector<int>> m (10, vector<int>(10));  //�൱�ڶ�ά����

	vector<char> v3 = vector<char>(10);//ÿ��Ԫ��Ĭ�ϳ�ʼ��0
	vector<string> v4 = vector<string>(10);//ÿ��Ԫ��Ĭ�ϳ�ʼ��""
	system("Pause");
	return 0;
}

