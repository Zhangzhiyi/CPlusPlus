//
// Created by Wayen on 2024/12/25.
//

#include <iostream>
#include "src/Utils.h"

using namespace std;

// 两个字符串保持一致，表示图片标识
unsigned short TBTAGIMGUSTR[] = {'@','_','I','M','G','_','@',0};
char TBTAGIMGLEN = 7;

int main() {
    cout << "Test String !!!" << endl;
    char* p = "012345@_img_@12345";
    cout << "p[1]:" << p[1] << endl;
    char* p2 = &p[1]; // 指向第一个位置
    cout << "*TBTAGIMGUSTR:" << *TBTAGIMGUSTR << endl; // 取当前指针指向元素内容
    if (p[6] == *TBTAGIMGUSTR) {
        cout << "equal" << endl;
    }
    char* ch = "一";
    int chLen = strlen(ch);

    char* utf8Str = "一^@_IMG_@0^二^@_IMG_@1^三";
    int utf8Len = strlen(utf8Str);
    cout << "utf8Str[1]:" << utf8Str[1] << endl;
    int ucs2len = 0;
    unsigned short* ucs = AthUnicodeUtils::utf8ToUcs2(p, strlen(utf8Str), &ucs2len);
    const unsigned short* temp = ucs;
    for (int i = 0; i < ucs2len; ++i, ++temp) {
        if (*temp != 0x5E) {
            continue;
        }

        if (ucs[i++] == *TBTAGIMGUSTR) {
            int a = 0;
        }

    }
    return 0;
}