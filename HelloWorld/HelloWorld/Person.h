#pragma once
class Person
{
public:
	Person(void);
	~Person(void);
	int age;
	void showAge();
	const static int date = 100;
	void show1();
	void show2();
	virtual void show3();

	void hide();
};
class Children :public Person
{
public:
	Children(void);
	~Children(void);
	//show2()��û�����ظ����show2()����
	void show2();//
	//show3()Ϊperson�����⺯�� ���ۼӲ���virtual������ʵ�ֶ�̬��virtual���η��ᱻ���μ̳�
	virtual void show3();

	void show4();
	//Person��hide()������������,Children�Ķ����ܵ���Person��hide()������ 
	//���ع�������������(ͬ��������ͬ)���෽�������෽���ᱻ����
	void hide(int i);

	void call();
	void call(int i);
};

