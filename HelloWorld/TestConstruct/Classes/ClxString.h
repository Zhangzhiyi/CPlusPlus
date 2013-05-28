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
	char *m_pString; // 像这种指针成员变量记得写自己的复制构造函数和赋值操作符函数
	int m_length;
	static int num_strings;
	enum {NumTurns = 5}; //用枚举代替常量或者#defines
	int cout[NumTurns];
	static const int Numbers = 10; 
	int scroes[Numbers];
	
};

