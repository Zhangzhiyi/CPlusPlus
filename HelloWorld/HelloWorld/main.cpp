// HelloWorld.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "Person.h"
#include "tabtenn0.h"

int num ;
using namespace std;
void show(){
	num ++;
	printf("show:%d\n", num);
}
void increase(int *_i)
{
	*_i = *_i + 1 ;
	cout << "increase *:" << *_i << endl;
}
void increase(int &_i)
{
	_i = _i + 1 ;
	cout << "increase &:" << _i << endl;
}
char* getPointChar()
{
	char *c = "getChar()";
	return c;
}
char* getPointCharArray()
{
	char p[] = "hi";
	return p; //��������p���ͷŵ���
}
int* getPointInt(int num) //����ᾯ�棺���ؾֲ���������ʱ�����ĵ�ַ ����Զ��Ҫ�Ӻ����з��ؾֲ��Զ������ĵ�ַ��
{
	int i = 100 * num;
	return &i;
}
int & getReferenceInt()
{
	int i = 999;
	return i;
}
//�������ݶ�������൱��ֵ���ݣ��������Զ�������ʱ��������RatePlayer�����������ں������ڶ�ratePlayer�޸Ĳ�Ӱ��ʵ��ԭ����ֵ
//����RatePlayer *ratePlayer ���� RatePlayer &ratePlayer
void setRate(RatePlayer ratePlayer)//��������������û�е��ù��캯�����ǵ���Ĭ�ϸ��ƹ��캯��
{
	ratePlayer.ResetRating(20);//����������������������ͷŶ���
}
TableTennisPlayer getTableTennisPlayer() //���ض���
{
	TableTennisPlayer player("zhang", "zhiyi", true);
	return player; //player�����Ƹ���ֵ��ͻ���ͷŵ�,������������
}
TableTennisPlayer getTableTennisPlayer(const TableTennisPlayer & player)//���ض���
{
	TableTennisPlayer test = player; // ���ø�ֵ������Ҳ�ǵ���Ĭ�ϵĸ��ƺ���
	return player; //���ض��󽫵���Ĭ�ϸ��ƹ��캯��
}
TableTennisPlayer & getRefTableTennisPlayer(TableTennisPlayer & player)
{
	return player;//�������ò�����ø��ƹ��캯�������Ч��
}
TableTennisPlayer * getPointTableTennisPlayer()
{
	TableTennisPlayer *player = new TableTennisPlayer("wang", "qianqian", true);
	return player; //new�Ķ������ڶѴ洢��Ҫ�ֶ��ͷţ�����playerû�и��ͷŵ�
}
RatePlayer & getRatePlayer() //���ؾֲ��������� �������ܷ����ں����д�������ʱ��������ã�����������ʱ������ʧ
{
	RatePlayer rplayer(9999, "zhang", "zhiyi", true);
	return rplayer; //����������rplayer�ڴ����ʧ�ˣ����������ǷǷ��ģ��������
}
//int Person::date = 20;
int TableTennisPlayer::kkk = 100;
int _tmain(int argc, _TCHAR* argv[])
{
	num = 10;
	
	char c = 'c';
	int y = 1;
	int result = M;
	printf("%d\n", result);
	show();

	TableTennisPlayer player1 ("Chunk", "Blizzard", true);
	RatePlayer rplayer1(1140, player1);
	player1.Name();
	cout << "Rating:" << rplayer1.Rating() << endl; //1140
	setRate(rplayer1); //��ֵ����,�������޸Ĳ�Ӱ��ԭ����ֵ
	cout << "Rating:" << rplayer1.Rating() << endl; //1140 
	//������ľ�̬��Ա
	cout << "TableTennisPlayer static:" << TableTennisPlayer::kkk<< endl;
	cout << "TableTennisPlayer static const:" << TableTennisPlayer::kkk2<< endl;
	
	//ָ�������������޸ĺ�Ӱ����val��ֵ
	int val = 999;
	int *_int = &val;
	cout << "*_int:" << *_int << endl;
	increase(_int);
	cout << "val:" << val << endl;
	//���������������޸���ҲӰ����val2��ֵ
	int val2 = 999;
	int &_int2 = val2;
	cout << "&_int2:" << _int2 << endl;
	increase(_int2);
	cout << "val2:" << val2 << endl;
	
	RatePlayer &rplayer2  = getRatePlayer(); //�õ��ֲ��������ã���ϧ�����Ѿ��ͷŵ���
	cout << "Rating:" << rplayer2.Rating() << endl; //���������ȷ�Ľ��

	TableTennisPlayer player2 = getTableTennisPlayer();//�õ���ȷ����ĸ���
	player2.Name();

	TableTennisPlayer *player3 = getPointTableTennisPlayer();//�õ�new�Ķ�����������ȷ
	player3->Name();

	TableTennisPlayer player4 = getTableTennisPlayer(*player3); //debug���Թ۲쵽player3��player4�ڴ��ַ��һ��
	
	TableTennisPlayer &player5 = getRefTableTennisPlayer(*player3);//�õ�ԭ���Ķ������ã�ͬ���޸�
	player5.setFirstName("ETET");
	player5.Name(); //ETET
	player3->Name(); //ETET

	TableTennisPlayer player6 = getRefTableTennisPlayer(*player3);//��Ȼ���û�ȡ���õķ����������������ͨ�������ͣ������������ͣ��õ��Ļ��Ǹ��Ƶĸ���
	player6.setFirstName("BABA");
	player6.Name(); //BABA
	player3->Name(); //ETET


	char *ps = "12345"; 
	char *ps2 = ps;
	char **ps3 = &ps;  //ָ��ָ��ָ��
	cout << ps2 << endl;
	cout << *ps3 << endl;

	int* mi1 = getPointInt(10);//���������ȷ�Ľ��
	cout << *mi1 << endl;
	int* mi2 = getPointInt(100);//���������ȷ�Ľ��
	cout << *mi2 << endl;
	int & mi3 = getReferenceInt();
	cout << mi3 << endl;
	char* mc = getPointChar();//���������ȷ�Ľ��
	cout << mc << endl;
	char* pa = getPointCharArray(); //�������������ȷ�Ľ�� (�ѵ�������Ÿ���������ˣ�)
	cout << pa << endl;

	system("Pause");
	return 0;
}



