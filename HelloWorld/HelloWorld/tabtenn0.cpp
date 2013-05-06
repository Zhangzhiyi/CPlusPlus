#include "StdAfx.h"
#include "tabtenn0.h"
#include <cstring>
#include <iostream>

using namespace std;
//int TableTennisPlayer::kkk = 100;
TableTennisPlayer::TableTennisPlayer(const char * fn, const char * ln, bool ht)
{
	cout << "construct from TableTennisPlayer" << endl;
	strncpy(firstname, fn , LIM - 1);
	firstname[LIM - 1] = '\0';
	strncpy(lastname, ln, LIM - 1);
	lastname[LIM - 1] = '\0';
	hasTable = ht;
	
}
void TableTennisPlayer::Name()const
{
	cout<< lastname << "," << firstname << endl;
}
void TableTennisPlayer::setFirstName(const char * fn)
{
	strncpy(firstname, fn , LIM - 1);
	firstname[LIM - 1] = '\0';
}
TableTennisPlayer::~TableTennisPlayer()
{
	cout << "delete from TableTennisPlayer" << endl;
}
//派生类的构造函数
RatePlayer::RatePlayer(unsigned int r, const char * fn, 
	const char * ln, bool ht):TableTennisPlayer(fn, ln, ht) //基类的构造函数
{
	cout << "construct from RatePlayer" << endl;
	rating = r;
}
RatePlayer::RatePlayer(unsigned int r, const TableTennisPlayer & tp)
	:TableTennisPlayer(tp), rating(r)
{
	cout << "construct from RatePlayer" << endl;
}
unsigned int RatePlayer::Rating()
{
	return rating;
}
void RatePlayer::ResetRating(unsigned int r)
{
	rating = r;
}
RatePlayer::~RatePlayer()
{
	cout << "delete from RatePlayer" << endl;
}