#include <iostream>
#include "testlib/include/Person.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int b; //全局变量,会被自动初始化为0
int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the
    // <b>lang</b> variable name to see how CLion can help you rename it.
    auto lang = "C++";
    std::cout << "Hello and welcome to " << lang << "!\n";

    for (int i = 1; i <= 5; i++) {
        // TIP Press <shortcut actionId="Debug"/> to start debugging your code.
        // We have set one <icon src="AllIcons.Debugger.Db_set_breakpoint"/>
        // breakpoint for you, but you can always add more by pressing
        // <shortcut actionId="ToggleLineBreakpoint"/>.
        std::cout << "i = " << i << std::endl;
    }
    static int c; //函数内的静态变量，未初始化，默认值为0
    int a;// a 是一个局部变量，它的值是不确定的
    Person person;
    std::cout << "pserson age:" << person.getAge() << std::endl;
    person.printfAge();

    unsigned short temp = '0' + 1;
    std::cout << "temp:" << temp << std::endl;

    char *ps = "12345";
    std::cout << "打印指针自身内存地址:" << &ps << std::endl;
    std::cout << "打印指针指向内存地址:" << (int *)ps << std::endl;
    char p1 = *(ps + 4);  // 5
    char p2 = *(ps + strlen(ps));  // '\0' 证明字符指针后面也要有'\0'指示结束
    std::cout << "p1:" << p1 << std::endl;
    std::cout << "p2:" << p2 << std::endl;
    //4或者8(32位系统返回4，64位系统返回8) |  1(char占一个字节)  |  5(字符个数)
    std::cout << sizeof(ps) << " |  "<< sizeof(*ps)<< " | "<< strlen(ps) <<std::endl;

    char parry[] = "12345";
    //6(5后面有'\0',sizeof方法算'\0') | 1 (parry[2]表示访问下标为2的char)   |  5(strlen方法不算'\0')
    std::cout << sizeof(parry) << " | "<< sizeof(parry[2]) << " |  " << strlen(parry) << std::endl;

    /** 结论： sizeof(指针) 永远占4或者8位，因为制作地址是用int表示
			  sizeof(*指针) 指针类型占的位数
			  sizeof(指针数组) 指针数组大小 * 数组类型占的位数，注意字符串数组后面有'\0'
			  strlen(字符指针) 或者 strlen(字符指针数组) 计算的字符个数都是不算最后的'\0'
     **/
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.