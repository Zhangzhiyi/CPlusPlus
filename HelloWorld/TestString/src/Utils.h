//
// Created by Wayen on 2024/12/25.
//

#ifndef HELLOWORLD_UTILS_H
#define HELLOWORLD_UTILS_H
#include <iostream>

#include <vector>

#include <map>
#include <list>
#include <cstring>
#include <string>
#include <stdint.h>
#include <ctype.h>

#define ATH_ASCII_COUNT 256
#define ATH_PUNCTION_COUNT 625
#define CJK_PUNC_START 0x3000
#define CJK_PUNC_END 0x303f
#define GENERAL_PUNC_START 0x2000
#define GENERAL_PUNC_END 0x206F
#define FULLWIDTH_PUNC_START 0xFE30
#define FULLWIDTH_PUNC_END 0xFFEF

#define CJK_START 0x4E00
#define CJK_END 0x9FFF
//#define G_CHAR_UTF8 "UTF-8";
// Delete the memory allocated with C++ operator new.
#ifndef SAFE_DELETE
#define SAFE_DELETE(p)              \
        {                           \
            if ((p) != NULL)        \
            {                       \
                delete (p);         \
                (p) = NULL;         \
            }                       \
        }
#endif // SAFE_DELETE


// Delete the memory array allocated with C++ operator new[].
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p)        \
        {                           \
            if ((p) != NULL)        \
            {                       \
                delete [] (p);      \
                (p) = NULL;         \
            }                       \
        }
#endif // SAFE_DELETE_ARRAY


// The size of array
#ifndef ARRAYSIZE
#define ARRAYSIZE(a)       ( sizeof((a)) / sizeof((a)[0]) )
#endif // ARRAYSIZE
// 锁
class AthLock {
private:
    volatile int mLock;
    static bool CAS(int exceptedvalue,int newvalue, volatile int* dest);
public:
    AthLock();
    void unlock();
    void lock();
};

// 自动锁
class AthAutoLock {
private:
    AthLock* mLock;

public:
    explicit AthAutoLock(AthLock* lock) : mLock(lock) {mLock->lock();}
    ~AthAutoLock() {mLock->unlock();}
};

// 文本行读取的类，支持从文件中读，也支持从字符串（char*）中读取一行，以 \r 或 \n结尾
class AthTxtLineReader {
public:
    explicit AthTxtLineReader(FILE *f)
            : file(f), data(0), dataLen(0), offset(0) {}
    AthTxtLineReader(const char *d, int dl)
            : file(0), data(d), dataLen(dl), offset(0) {}

    /*!
     * @brief 从指定的文件或数据字符串中，读取一行数据到 buf 中
     *
     * @param buf 内存容器
     * @param bufSize 内存大小
     */
    char *readLine(char* buf, int bufSize);
private:
    FILE *file;         // 文件
    const char *data;   // 数据
    int dataLen, offset;
};

class AthUtils {
public:
    static std::string getFileName(const char* filePath);
    static std::string getFileSuffix(const char* filePath);
    static std::string getFileNameNoSuffix(const char* filePath);
    static bool isHtmlFile(const char* filePath);

    static std::string detectCode(const char* filePath);
    static std::string detectCode(const char* data, int len);
    static std::string detectHtmlEncoding(const char* data, int len);
    static std::string detectXHtmlEncoding(const char* data, int len);

    static std::string intToStr( int i);
    static bool makeDir (const char *dir);
    static bool testDir (const char *dir);
    static bool testFile (const char *path);
    static std::string MD5_file (const char *path, int md5_len);
    static std::string MD5_bytes (unsigned char *bytes, int bytesLen, int md5_len);

    static int bytesToInt32(unsigned char* bytes);
    static short bytesToInt16(unsigned char* bytes);

    // url加解密, 结果用delete[]释放
    static char* encTBURL(const char* data);
    static char* dencTBURL(const char* data);

    static int urldecode(char* dstBuf, const char *str, int len);
    static void autoUrlDecoding(std::string& str);
    // 判断str字符串是否以tails字符串结尾，目前使用场景：用来获取到的字体名称是否以sc结尾，来判断中文简体的字体，by yinli 2021/04/23
    static bool endWith(const std::string &str, const std::string &tail);
};

class AthLocalParseBuffer;
class AthUnicodeUtils {
public:
    static void strToLower(char* p) {if (p) { for (; *p; p++) *p = tolower(*p);}}
    static void deleteStr(char*& str) { if (str) {delete[] str; str = 0; } }
    static bool isCJK(int ch) { return (ch >= CJK_START && ch <= CJK_END); }
    static bool isAscii(int ch) { return (ch >= 0x00 && ch < ATH_ASCII_COUNT); }
    /**
     * @brief 是否标点符号
     * @param ch 字符
     * @return 是否是标点符号
     */
    static bool isPunc(int ch) {
        return (ch >= CJK_PUNC_START && ch <= CJK_PUNC_END)		// CJK_PUNC
               || (ch >= GENERAL_PUNC_START && ch <= GENERAL_PUNC_END)		// GENERAL_PUNC
               || (ch >= FULLWIDTH_PUNC_START && ch <= FULLWIDTH_PUNC_END);}		// FULLWIDTH_PUNC

    static bool isSpace(int ch) {
        return (ch < 0x80) ? isspace((unsigned char)ch) : (ch == 0xa0 || ch == 0x3000);
    }

public:
    static int ucs2Length(const char *utf8str, int utf8len);
    static int utf8Length(const unsigned short* ucs2str, int ucs2len);

    static void validateUtf8(unsigned char* utf8, int* utf8Len);

    static unsigned int* utf8ToUcs4(const char *from, int len, int* ucs4Len = 0);
    static unsigned short* utf8ToUcs2(const char *from, int len, int* ucs2Len = 0);
    static char* ucs2ToUtf8(const unsigned short* from, int len, int* utf8len = 0);
    static int ucs2CharToUtf8(char *to, int ch);

    static char* copyIfNotNull(const char* data); // 非null就拷贝
    static char* copyIfNotEmpty(const char* data); //只有长度大于0的才拷贝

    static char* copy(const char* data);
    static char* copySubStr(const char* data, int length);

    static char* copyStdstrIfNotEmpty(std::string str); // 只有长度大于0的才拷贝
    static char* copyStdstr(std::string str);
    static char* copyStdstrSubStr(std::string str, int length);

    static void escape(char* data, int length);
    static std::vector<char*>* split(char* data, const char* deli);

    static char* allocedDataToUtf8(char* data, int* len, const char* encoding);
    static const char* trimUtf8Space(const char* data, int* len);

    static const char* localUcs2ToUtf8(AthLocalParseBuffer* bufMgr,const unsigned short* from, int len, bool htmlEscape);
    static void deleteAllMark(std::string &s, const std::string &mark);

    static char* copyWithSpaceIgnoredOrCombined(const char* data);
    static const char* copyWithSpaceIgnoredOrCombinedUserBufferMgr(AthLocalParseBuffer* bufMgr,const char* data);

private:
    static bool isHex(char c);
    static int doCopyToBuffer(char* destBuffer,const char* data);
};

// 解析本地缓存大小
#define PARSELOCALBUFFERSIZE 480

// 解析buffer类
class AthLocalParseBuffer {
public:
    AthLocalParseBuffer() : mNewBuffer(0) {
        memset(mLocalBuffer, 0, sizeof(mLocalBuffer));
    }
    ~AthLocalParseBuffer() { autoFreeBuffer(); }

    void autoFreeBuffer() {
        SAFE_DELETE_ARRAY(mNewBuffer);
    };

    char* getBuffer(unsigned int size) {
        if (size <= PARSELOCALBUFFERSIZE) {
            return mLocalBuffer;
        }
        autoFreeBuffer();
        mNewBuffer = new char[size];
        return mNewBuffer;
    };

    char* copyStrToBuf(const char* str, int len = -1) {
        if (len < 0) { len = str ? strlen(str) : 0; }
        char* buffer = getBuffer(len + 1);
        if (str) { memcpy(buffer, str, len); }
        buffer[len] = 0;
        return buffer;
    }

    char* copyUTF16StrToBuf(const unsigned short* str, int len) {
        if (str == NULL) return NULL;
        char* buffer = getBuffer(len + 1);
        if (str) {
            for (int i = 0; i < len; ++i) {
                buffer[i] = (unsigned char)(str[i]);
            }
        }
        buffer[len] = 0;
        return buffer;
    }

private:
    char mLocalBuffer[PARSELOCALBUFFERSIZE];
    char* mNewBuffer;
};

#define PARSESEPSTRMAXCOUNT 50

class AthStrSeparator {
public:
    AthStrSeparator() { memset(mPointers, 0, sizeof(mPointers)); }
    short sepStrBySpace(char* str, short maxCt = -1);
    short sepStrByCharArr(char* str, const char* byArr, short byCt, short maxCt = -1);
    char** getSepArray() { return (char**)mPointers; }
    static char* trimSpace(char* cur);
private:
    char* mPointers[PARSELOCALBUFFERSIZE];
};

#endif //HELLOWORLD_UTILS_H
