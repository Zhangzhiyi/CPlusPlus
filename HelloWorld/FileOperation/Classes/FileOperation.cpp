// FileOperation.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>    
#include <io.h>    
#include <direct.h>    
#include <string>    
#include <vector>    
#include <iomanip>    
#include <ctime>
#include <array>
#include <fstream>
#include <sstream>

using namespace std;
void getFiles( string path, vector<string>& files );
void copyFiles(const char* src, const char* dest);
static vector<_finddata_t> _finddata_ts;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "djaljf" << endl ;
	//��ȡ�ļ���С
	FILE* file = fopen("F:\\1.jpg", "rb");
	if (file)
	{
		int size = filelength(fileno(file));
		cout<<size<<endl;
		fclose(file);
	}
	//mkdir("F:\\cocos2dx\\1");
	
	//copyFiles("F:\\1.jpg", "F:\\cocos2dx\\2.jpg");
	//ofstream of;
	//of.open("F:\hello\filename");//����ļ������� ���Զ�����һ���ļ�
	if (access("F:\\filelist.txt", 0) != -1)
	{
		cout << "�ļ�����" << endl;
	}
	char mystring[100];
	FILE* filelist = fopen("F:\\filelist.txt", "r");
	if (filelist)
	{
		while(fgets(mystring, 100, filelist))
		{
			
			char* split = strtok(mystring, ",");
			cout << mystring << ":len = " << strlen(mystring) << endl;
			stringstream ss(mystring);
			string sub;
			while(getline(ss, sub, ',')){
				cout << sub << endl;
			}
		}
	}
	vector<string> files;    
	
	//getFiles( "F:", files );  

	// print the files get  
	for (int  j=0; j<files.size(); ++j)  {  
		cout << files[j] << endl;   
	} 
	system("Pause");
	return 0;
}
void getFiles( string path, vector<string>& files ) {  
    //�ļ����    
    long   hFile   =   0;    
    //�ļ���Ϣ    
    struct _finddata_t fileinfo;    
  
    string p;  
  
    if ((hFile = _findfirst(p.assign(path).append("/*").c_str(),&fileinfo)) != -1)  {    
  
        do  {    
            //�����Ŀ¼,����֮  
            //�������,�����б�  
            if   ((fileinfo.attrib & _A_SUBDIR)) {    
                if   (strcmp(fileinfo.name,".") != 0 && strcmp(fileinfo.name,"..") != 0)    
                    getFiles(p.assign(path).append("/").append(fileinfo.name), files );    
            }  else  {    
				_finddata_ts.push_back(fileinfo);
				char size[30] = "";
				sprintf(size, "%lu", fileinfo.size);
                files.push_back(p.assign(path).append("/").append(fileinfo.name).append(" size:").append(size));  
            }    
        }   while(_findnext(hFile,   &fileinfo)   ==   0);    
  
        _findclose(hFile);    
    }  
}
void copyFiles(const char* src, const char* dest){
	FILE* infile = fopen(src, "rb");
	FILE* outfile = fopen(dest, "wb+");
	char* buffer;
	if (infile && outfile)
	{
		fseek(infile, 0L, SEEK_END);
		unsigned long len = ftell(infile);
		rewind(infile);
		buffer = new char[len];
		fread(buffer, 1, len, infile);
		fwrite(buffer, 1, len, outfile);
		fclose(infile);
		fclose(outfile);
	}
}
vector<string> split(string str,string pattern)
{
	string::size_type pos;
	vector<std::string> result;
	str+=pattern;//��չ�ַ����Է������
	int size=str.size();
	for(int i=0; i<size; i++)
	{
		pos=str.find(pattern,i);
		if(pos<size)
		{
			string s=str.substr(i,pos-i);
			result.push_back(s);
			i=pos+pattern.size()-1;
		}
	}
	return result;
}
