// HelloWorld.cpp : 定义控制台应用程序的入口点。
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
	return p; //函数结束p给释放掉了
}
int* getPointInt(int num) //编译会警告：返回局部变量或临时变量的地址 （永远不要从函数中返回局部自动变量的地址）
{
	int i = 100 * num;
	return &i;
}
int & getReferenceInt()
{
	int i = 999;
	return i;
}
//这样传递对象参数相当于值传递，函数将自动产生临时变量复制RatePlayer副本，所以在函数体内对ratePlayer修改不影响实参原来的值
//区别RatePlayer *ratePlayer 或者 RatePlayer &ratePlayer
void setRate(RatePlayer ratePlayer)//产生变量副本并没有调用构造函数，是调用默认复制构造函数
{
	ratePlayer.ResetRating(20);//函数结束会调用析构函数释放对象
}
TableTennisPlayer getTableTennisPlayer() //返回对象
{
	TableTennisPlayer player("zhang", "zhiyi", true);
	return player; //player对象复制给左值后就会给释放掉,调用析构函数
}
TableTennisPlayer getTableTennisPlayer(const TableTennisPlayer & player)//返回对象
{
	TableTennisPlayer test = player; // 引用赋值给对象也是调用默认的复制函数
	return player; //返回对象将调用默认复制构造函数
}
TableTennisPlayer & getRefTableTennisPlayer(TableTennisPlayer & player)
{
	return player;//返回引用不会调用复制构造函数，提高效率
}
TableTennisPlayer * getPointTableTennisPlayer()
{
	TableTennisPlayer *player = new TableTennisPlayer("wang", "qianqian", true);
	return player; //new的对象是在堆存储，要手动释放，所以player没有给释放掉
}
RatePlayer & getRatePlayer() //返回局部变量引用 函数不能返回在函数中创建的临时对象的引用，函数结束临时引用消失
{
	RatePlayer rplayer(9999, "zhang", "zhiyi", true);
	return rplayer; //函数结束后rplayer内存就消失了，所以这样是非法的，后果严重
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
	setRate(rplayer1); //按值传递,函数内修改不影响原来的值
	cout << "Rating:" << rplayer1.Rating() << endl; //1140 
	//调用类的静态成员
	cout << "TableTennisPlayer static:" << TableTennisPlayer::kkk<< endl;
	cout << "TableTennisPlayer static const:" << TableTennisPlayer::kkk2<< endl;
	
	//指针作函数参数修改后影响了val的值
	int val = 999;
	int *_int = &val;
	cout << "*_int:" << *_int << endl;
	increase(_int);
	cout << "val:" << val << endl;
	//引用作函数参数修改了也影响了val2的值
	int val2 = 999;
	int &_int2 = val2;
	cout << "&_int2:" << _int2 << endl;
	increase(_int2);
	cout << "val2:" << val2 << endl;
	
	RatePlayer &rplayer2  = getRatePlayer(); //得到局部变量引用，可惜引用已经释放掉了
	cout << "Rating:" << rplayer2.Rating() << endl; //输出不是正确的结果

	TableTennisPlayer player2 = getTableTennisPlayer();//得到正确对象的副本
	player2.Name();

	TableTennisPlayer *player3 = getPointTableTennisPlayer();//得到new的对象，输出结果正确
	player3->Name();

	TableTennisPlayer player4 = getTableTennisPlayer(*player3); //debug可以观察到player3与player4内存地址不一样
	
	TableTennisPlayer &player5 = getRefTableTennisPlayer(*player3);//得到原来的对象引用，同步修改
	player5.setFirstName("ETET");
	player5.Name(); //ETET
	player3->Name(); //ETET

	TableTennisPlayer player6 = getRefTableTennisPlayer(*player3);//虽然调用获取引用的方法，但是左边是普通变量类型，不是引用类型，得到的还是复制的副本
	player6.setFirstName("BABA");
	player6.Name(); //BABA
	player3->Name(); //ETET


	char *ps = "12345"; 
	char *ps2 = ps;
	char **ps3 = &ps;  //指针指向指针
	cout << ps2 << endl;
	cout << *ps3 << endl;

	int* mi1 = getPointInt(10);//这里输出正确的结果
	cout << *mi1 << endl;
	int* mi2 = getPointInt(100);//这里输出正确的结果
	cout << *mi2 << endl;
	int & mi3 = getReferenceInt();
	cout << mi3 << endl;
	char* mc = getPointChar();//这里输出正确的结果
	cout << mc << endl;
	char* pa = getPointCharArray(); //这里输出不是正确的结果 (难道是数组才给立马回收了？)
	cout << pa << endl;

	system("Pause");
	return 0;
}



