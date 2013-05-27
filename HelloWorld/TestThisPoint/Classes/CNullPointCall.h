#pragma once
class CNullPointCall
{
public:
	CNullPointCall(void);
	~CNullPointCall(void);

	static void Test1();
	void Test2();
	void Test3(int iTest);
	void Test4();
private:
	static int m_iStatic;
	int m_iTest;
};

