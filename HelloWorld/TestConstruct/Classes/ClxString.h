#pragma once
class ClxString
{
public:
	ClxString(int length);
	//explicit ClxString(int length); //explicit�ؼ���������ʽ���캯��,������ʾ�ĵ��ù��캯��ClxString lxTest = ClxString(13);��Щ���뽫����ͨ�����롣ClxString lxTest = 13; ClxString lxTest = 'A';
	ClxString(const char *pString);
	~ClxString(void);
	char* getString() const{return m_pString;}
private:
	char *m_pString; // ������ָ���Ա�����ǵ�д�Լ��ĸ��ƹ��캯���͸�ֵ����������
	int m_length;
	static int num_strings;
	enum {NumTurns = 5}; //��ö�ٴ��泣������#defines
	int cout[NumTurns];
	static const int Numbers = 10; 
	int scroes[Numbers];
	
};

