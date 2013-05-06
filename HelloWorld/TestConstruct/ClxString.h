#pragma once
class ClxString
{
public:
	ClxString(int length);
	//explicit ClxString(int length); //explicit关键字声明显式构造函数,必须显示的调用构造函数ClxString lxTest = ClxString(13);这些代码将不能通过编译。ClxString lxTest = 13; ClxString lxTest = 'A';
	ClxString(const char *pString);
	~ClxString(void);
	char* getString() const{return m_pString;}
private:
	char *m_pString;
};

