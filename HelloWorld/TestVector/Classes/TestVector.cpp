// TestVector.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> v1 = vector<int>(10);//每个元素默认初始化0
	int v1Size = v1.size();
	vector<int> v2(10);
	int v2Size = v2.size();

	vector<vector<int>> m (10, vector<int>(10));  //相当于二维数组

	vector<char> v3 = vector<char>(10);//每个元素默认初始化0
	vector<string> v4 = vector<string>(10);//每个元素默认初始化""
	system("Pause");
	return 0;
}

