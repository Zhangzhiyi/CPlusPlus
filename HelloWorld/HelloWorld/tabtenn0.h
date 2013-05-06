#ifndef _TABTENN0_H_
#define _TABTENN0_H_

class TableTennisPlayer
{
private:
	enum {LIM = 20};
	char firstname[LIM];
	char lastname[LIM];
	bool hasTable;
public:
	TableTennisPlayer (const char * fn = "none", const char * ln = "none", bool ht = false);
	void Name()const;
	void HasTable()const;
	void RestTable(bool v);
	void setFirstName(const char * fn);
	virtual ~TableTennisPlayer();
	static int kkk;//���Ǿ�̬���������Գ�ʼ�������ҳ�ʼ��ֻ����ccp�ļ���������뱨��
	static const int kkk2 = 101;

};

class RatePlayer:public TableTennisPlayer
{
private:
	unsigned int rating;
public:
	RatePlayer (unsigned int r, const char * fn, const char * ln, bool ht);
	RatePlayer (unsigned int r, const TableTennisPlayer & tp);
	unsigned int Rating();
	void ResetRating(unsigned int r);
	~RatePlayer();
};
#endif



