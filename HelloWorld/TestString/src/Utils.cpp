//
// Created by Wayen on 2024/12/25.
//

#include "Utils.h"
#include <sys/stat.h>
#include <ctype.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "md5.h"

const char* G_CHAR_UTF8 = "UTF-8";

std::string AthUtils::getFileName(const char* filePath) {
    if (filePath == NULL || *filePath == 0) {
        return std::string();
    }
    int pos = strlen(filePath) - 1;

#ifndef _WIN32
    while (pos >=0 && filePath[pos] != '/') {
        --pos;
    }
#else
    while (pos >=0 && (filePath[pos] != '/' && filePath[pos] != '\\')) {
		--pos;
	}
#endif
    std::string s(&filePath[pos + 1]);
    return s;
}

std::string AthUtils::getFileSuffix(const char* filePath) {
    if (filePath == NULL || *filePath == 0) {
        return std::string();
    }

    int pos = strlen(filePath) - 1;
    int size = pos + 1;
    while (pos >=0 && filePath[pos] != '.') {
        --pos;
    }

    if (pos < 0) {
        return std::string();
    }

    std::string s;

    for (int i = pos + 1; i < size; ++i) {
        s.push_back(tolower(filePath[i]));
    }
    return s;
}

std::string AthUtils::getFileNameNoSuffix(const char* filePath) {
    std::string fileName = AthUtils::getFileName(filePath);
    std::string sfx = AthUtils::getFileSuffix(filePath);

    int nameLen = fileName.length() - sfx.length() - 1;
    if (nameLen <= 0) {
        return fileName;
    }
    return fileName.substr(0, nameLen);
}

bool AthUtils::isHtmlFile(const char* filePath) {
    std::string suffix = AthUtils::getFileSuffix(filePath);
    const char* suffix_ch = suffix.data();
    bool bIsXML = false;
    if (suffix_ch) {
        bIsXML = strcmp(suffix_ch, "html") == 0 || strcmp(suffix_ch, "HTML") == 0
                 || strcmp(suffix_ch, "xhtml") == 0 || strcmp(suffix_ch, "XHTML") == 0
                 || strcmp(suffix_ch, "htm") == 0 || strcmp(suffix_ch, "HTM") == 0;
    }
    return bIsXML;
}

bool AthUtils::endWith(const std::string &str, const std::string &tail) {
    if (str.empty() || tail.empty()) {
        return false;
    } else {
        return str.compare(str.size() - tail.size(), tail.size(), tail) == 0;
    }
}

std::string AthUtils::intToStr( int i ) {
    char cs[20];
    sprintf(cs, "%d", i);
    return cs;
}

static inline char* strLastSlash (const char *path) {
    char *slash = strrchr((char*)path, '/');
#ifdef _WIN32
    char *backslash = strrchr((char*)path, '\\');
	if (slash == NULL || (backslash && backslash > slash))
		slash = backslash;
#endif
    return slash;
}

static char* strDirname (const char *file) {
    char* slash = strLastSlash (file);
    if (slash == NULL) {
        char* dir = (char *)malloc(2);
        if (dir) {
            memcpy(dir, ".", 2);
        }
        return dir;
    }
    char* dir = (char *)malloc ((slash - file) + 1);
    if (dir == NULL)
        return NULL;

    memcpy ((char *) dir, (const char *) file, slash - file);
    dir[slash - file] = '\0';

    return dir;
}

bool AthUtils::testDir (const char *dir) {
    if (dir == NULL || *dir == 0)
        return false;

    struct stat buf;
    int cc = stat(dir, &buf);
    if(!cc && (buf.st_mode & S_IFDIR))
        return true;
    return false;
}

bool AthUtils::testFile (const char *path) {
    if (path == NULL || *path == 0)
        return false;

    struct stat buf;
    int cc = stat(path, &buf);
    if(!cc && (buf.st_mode &  S_IFREG))
        return true;
    return false;
}

bool AthUtils::makeDir (const char *dir) {
    if (dir == NULL || *dir == 0)
        return false;

    char* parent = strDirname(dir);

    char* lastSlash = strLastSlash(dir);
    if (lastSlash && lastSlash == dir + strlen(dir) - 1) {
        char* oldParent = parent;
        parent = strDirname(oldParent);
        free(oldParent);
    }
    if (parent == NULL)
        return false;

    bool  ret = false;
    if (access(parent, 0) == 0)
        ret = mkdir(dir, 0755) == 0 && chmod(dir, 0755) == 0;
    else if (access (parent, 0) == -1)
        ret = makeDir (parent) && (mkdir(dir, 0755) == 0) && chmod((char *) dir, 0755) == 0;
    free (parent);

    return ret;
}

std::string AthUtils::MD5_file (const char *path, int md5_len) {
    FILE *fp = fopen (path, "rb");
    MD5_CTX mdContext;
    int bytes;
    unsigned char data[1024];
    char *file_md5;
    int i;
    if (fp == NULL) {
        fprintf (stderr, "fopen %s failed\n", path);
        return std::string();
    }
    MD5Init (&mdContext);
    while ((bytes = fread (data, 1, 1024, fp)) != 0)
    {
        MD5Update (&mdContext, data, bytes);
    }
    MD5Final (&mdContext);

    file_md5 = (char *)malloc((md5_len + 1) * sizeof(char));
    if(file_md5 == NULL)
    {
        fprintf(stderr, "malloc failed.\n");
        fclose(fp);
        return std::string();
    }
    memset(file_md5, 0, (md5_len + 1));

    if(md5_len == 16)
    {
        for(i=4; i<12; i++)
        {
            sprintf(&file_md5[(i-4)*2], "%02x", mdContext.digest[i]);
        }
    }
    else if(md5_len == 32)
    {
        for(i=0; i<16; i++)
        {
            sprintf(&file_md5[i*2], "%02x", mdContext.digest[i]);
        }
    }
    else
    {
        fclose(fp);
        free(file_md5);
        return std::string();
    }

    fclose (fp);

    std::string md5 = file_md5;
    free(file_md5);

    return md5;
}

std::string AthUtils::MD5_bytes (unsigned char *bytes, int bytesLen, int md5_len)
{
    MD5_CTX mdContext;
    char *file_md5;

    MD5Init (&mdContext);
    MD5Update (&mdContext, bytes, bytesLen);
    MD5Final (&mdContext);

    file_md5 = (char *)malloc((md5_len + 1) * sizeof(char));
    memset(file_md5, 0, (md5_len + 1));

    int i;
    if(md5_len == 16)
    {
        for(i=4; i<12; i++)
        {
            sprintf(&file_md5[(i-4)*2], "%02x", mdContext.digest[i]);
        }
    }
    else if(md5_len == 32)
    {
        for(i=0; i<16; i++)
        {
            sprintf(&file_md5[i*2], "%02x", mdContext.digest[i]);
        }
    }
    else
    {
        free(file_md5);
        return std::string();
    }

    std::string md5 = file_md5;
    free(file_md5);

    return md5;
}

int AthUtils::bytesToInt32(unsigned char* bytes) {
    int i = bytes[3];
    i <<= 8; i += bytes[2];
    i <<= 8; i += bytes[1];
    i <<= 8;  i += bytes[0];
    return i;
}

short AthUtils::bytesToInt16(unsigned char* bytes) {
    short i = bytes[1];
    i <<= 8;  i += bytes[0];
    return i;
}


int AthUtils::urldecode(char* dstBuf, const char *str, int len)
{
    if (dstBuf == NULL || str == NULL || len < 0)
        return 0;

    char *dest = dstBuf;
    const char *data = str;

    int value;
    int c;

    while (len--) {
        if (*data == '+') {
            *dest = ' ';
        }
        else if (*data == '%' && len >= 2 && isxdigit((int) *(data + 1))
                 && isxdigit((int) *(data + 2)))
        {

            c = ((unsigned char *)(data+1))[0];
            if (isupper(c))
                c = tolower(c);
            value = (c >= '0' && c <= '9' ? c - '0' : c - 'a' + 10) * 16;
            c = ((unsigned char *)(data+1))[1];
            if (isupper(c))
                c = tolower(c);
            value += c >= '0' && c <= '9' ? c - '0' : c - 'a' + 10;

            *dest = (char)value ;
            data += 2;
            len -= 2;
        } else {
            *dest = *data;
        }
        data++;
        dest++;
    }
    *dest = '\0';
    return dest - str;
}

void AthUtils::autoUrlDecoding(std::string& str)
{
    if (str.find('%') < 0)
        return;

    AthLocalParseBuffer buffer;
    char* dstStr = buffer.getBuffer(str.length());

    urldecode(dstStr, str.c_str(), str.length());

    str = dstStr;
}

bool AthLock::CAS(int exceptedvalue,int newvalue, volatile int* dest) {
#ifdef _IOS
    return OSAtomicCompareAndSwapInt (exceptedvalue, newvalue, dest);
#elif defined(_WIN32)
    return (_InterlockedCompareExchange16((short volatile * )dest, (short)newvalue, (short)exceptedvalue) == (short)exceptedvalue);
#elif defined(_LINUX)
    return __sync_bool_compare_and_swap(dest, exceptedvalue, newvalue);
#else
    return __sync_bool_compare_and_swap(dest, exceptedvalue, newvalue);
    /*
     if (*dest == exceptedvalue) {
     *dest = newvalue;
     return true;
     }
     else {
     return false;
     }*/
#endif
}

char *AthTxtLineReader::readLine(char* buf, int bufSize) {
    // assert(buf && bufSize && hsrc);

    char *cur, *ret = 0;
    int curOffset, endOffset;

    if (file != NULL) {
        ret = fgets(buf, bufSize, file);
        if (ret) {
            int len = strlen(ret);
            while (len > 0) {
                char* end = buf + len - 1;
                if (*end == '\r' || *end == '\n') {
                    *(end--) = 0;
                    --len;
                } else {
                    break;
                }
            }

        }
        return ret;
    }

    // data如果为NULL，不就会存在问题吗？
    curOffset = offset;
    cur = ((char *)data) + curOffset;

    endOffset = dataLen;
    if (endOffset > offset + bufSize - 1) {
        endOffset = offset + bufSize - 1;
    }

    for (; curOffset <= endOffset; ++cur, ++curOffset) {
        bool isBreak = (*cur == '\r' || *cur == '\n');
        if (((curOffset < endOffset) ^ isBreak) != 0) {
            continue;
        }

        memcpy(buf, data + offset, curOffset - offset);
        buf[curOffset - offset] = 0;
        ret = buf;

        offset = curOffset + 1;
        break;
    }

    return ret;
}

AthLock::AthLock() : mLock(0) {
}

void AthLock::lock() {
    while(!AthLock::CAS(0/*LOCK_IS_FREE*/, 1/*LOCK_IS_TAKEN*/, &mLock))  {
#ifdef _WIN32
        Sleep(10);
#else
        usleep(10);
#endif
    }
}
void AthLock::unlock() {
    mLock = 0;
}

int AthUnicodeUtils::ucs2Length(const char *utf8str, int utf8len) {
    if (utf8str == NULL || utf8len <= 0)
        return  0;

    const char *last = utf8str + utf8len;
    int counter = 0;
    while (utf8str < last) {
        if ((*utf8str & 0x80) == 0) {
            ++utf8str;
        } else if ((*utf8str & 0x20) == 0) {
            utf8str += 2;
        } else if ((*utf8str & 0x10) == 0) {
            utf8str += 3;
        } else {
            utf8str += 4;
        }
        ++counter;
    }
    return counter;
}

int AthUnicodeUtils::utf8Length(const unsigned short* ucs2str, int ucs2len) {
    if (ucs2str == NULL || ucs2len <= 0)
        return  0;

    unsigned short ch;
    int length = 0;
    for (int i = 0; i < ucs2len; ++i) {
        ch = ucs2str[i];
        if (ch < 0x80) {
            ++length;
        } else if (ch < 0x800) {
            length += 2;
        } else {
            length += 3;
        }
    }
    return length;
}

void AthUnicodeUtils::validateUtf8(unsigned char* utf8, int* utf8Len) {
    if (utf8 == NULL || utf8Len == NULL || *utf8Len <= 0)
        return;

    unsigned char *last = utf8 + *utf8Len;
    while (utf8 < last) {
        if ((*utf8 & 0x80) == 0) {
            ++utf8;
        } else if ((*utf8 & 0x20) == 0) {
            if ((0xC0 & *(utf8 + 1)) == 0x80) {
                utf8 += 2;
            } else {
                break;
            }
        } else if ((*utf8 & 0x10) == 0) {
            if ((0xC0 & *(utf8 + 1)) == 0x80 && (0xC0 & *(utf8 + 2)) == 0x80) {
                utf8 += 3;
            } else {
                break;
            }
        } else {
            break;
        }
    }
    *utf8Len -= (last - utf8);
    *utf8 = 0;
}

unsigned int* AthUnicodeUtils::utf8ToUcs4(const char *from, int len, int* ucs4Len) {
    if (from == NULL || len == 0)
        return NULL;

    int bufLen = ucs2Length(from, len) + 1;

    unsigned int* ucs4str = new unsigned int[bufLen];
    const char *last = from + len;
    int offset = 0;
    long ch;
    for (const char *ptr = from; ptr < last;) {
        if ((*ptr & 0x80) == 0) {
            ucs4str[offset++] = (*ptr);
            ++ptr;
        } else if ((*ptr & 0x20) == 0) {
            ch = *ptr & 0x1f;
            ++ptr;
            ch <<= 6;
            ch += *ptr & 0x3f;
            ucs4str[offset++] = ch;
            ++ptr;
        } else if ((*ptr & 0x10) == 0) {
            ch = *ptr & 0x0f;
            ++ptr;
            ch <<= 6;
            ch += *ptr & 0x3f;
            ++ptr;
            ch <<= 6;
            ch += *ptr & 0x3f;
            ucs4str[offset++] = ch;
            ++ptr;
        } else {
            // symbol number is > 0xffff, we use a special character for layout
            ucs4str[offset++] = 0x25a1;
            ptr += 4;
        }
    }
    ucs4str[offset] = 0;
    if (ucs4Len) {
        (*ucs4Len) = offset;
    }
    return ucs4str;
}

unsigned short* AthUnicodeUtils::utf8ToUcs2(const char *from, int len, int* ucs2Len) {
    if (from == NULL || len <= 0)
        return NULL;

    int bufLen = ucs2Length(from, len) + 1;

    unsigned short* ucs2str = new unsigned short[bufLen];
    const char *last = from + len;
    int offset = 0;
    unsigned short ch;
    for (const char *ptr = from; ptr < last;) {
        if ((*ptr & 0x80) == 0) {
            ucs2str[offset++] = (*ptr);
            ++ptr;
        } else if ((*ptr & 0x20) == 0) {
            ch = *ptr & 0x1f;
            ++ptr;
            ch <<= 6;
            ch += *ptr & 0x3f;
            ucs2str[offset++] = ch;
            ++ptr;
        } else if ((*ptr & 0x10) == 0) {
            ch = *ptr & 0x0f;
            ++ptr;
            ch <<= 6;
            ch += *ptr & 0x3f;
            ++ptr;
            ch <<= 6;
            ch += *ptr & 0x3f;
            ucs2str[offset++] = ch;
            ++ptr;
        } else {
            // symbol number is > 0xffff, we use a special character for layout
            ucs2str[offset++] = 0x25a1;
            ptr += 4;
        }
    }
    ucs2str[offset] = 0;
    if (ucs2Len) {
        (*ucs2Len) = offset;
    }
    return ucs2str;
}

int AthUnicodeUtils::ucs2CharToUtf8(char *to, int ch) {
    assert(to);
    if (ch < 0x80) {
        *to = (char)ch;
        return 1;
    } else if (ch < 0x800) {
        *to = (char)(0xC0 | (ch >> 6));
        *(to + 1) = (char)(0x80 | (ch & 0x3F));
        return 2;
    } else {
        *to = (char)(0xE0 | ch >> 12);
        *(to + 1) = (char)(0x80 | ((ch >> 6) & 0x3F));
        *(to + 2) = (char)(0x80 | (ch & 0x3F));
        return 3;
    }
}

char* AthUnicodeUtils::ucs2ToUtf8(const unsigned short* from, int len, int* utf8len) {
    if (from == NULL || len <= 0)
        return NULL;

    int bufLen = utf8Length(from, len) + 1;
    char* utf8str = new char[bufLen];
    const unsigned short* last = from + len;
    int offset = 0;
    unsigned short ch;

    for (const unsigned short*ptr = from; ptr < last; ++ptr) {
        ch = *ptr;
        if (ch < 0x80) {
            utf8str[offset++] = (char)ch;
        } else if (ch < 0x800) {
            utf8str[offset++] = (char)(0xC0 | (ch >> 6));
            utf8str[offset++] = (char)(0x80 | (ch & 0x3F));
        } else {
            utf8str[offset++] = (char)(0xE0 | ch >> 12);
            utf8str[offset++] = (char)(0x80 | ((ch >> 6) & 0x3F));
            utf8str[offset++] = (char)(0x80 | (ch & 0x3F));
        }
    }
    utf8str[offset] = 0;
    if (utf8len) {
        (*utf8len) = offset;
    }

    return utf8str;
}

const char* AthUnicodeUtils::localUcs2ToUtf8(AthLocalParseBuffer* bufMgr,const unsigned short* from, int len, bool htmlEscape)
{
    if (from == 0 || len <= 0 || bufMgr == NULL) {
        return NULL;
    }
    char* utf8str = bufMgr->getBuffer(len * 8);
    if (utf8str == NULL) {
        return NULL;
    }
    const unsigned short* last = from + len;
    int offset = 0;
    unsigned short ch;

    for (const unsigned short*ptr = from; ptr < last; ++ptr) {
        ch = *ptr;
        if (ch >= 0x800) {
            utf8str[offset++] = (char)(0xE0 | ch >> 12);
            utf8str[offset++] = (char)(0x80 | ((ch >> 6) & 0x3F));
            utf8str[offset++] = (char)(0x80 | (ch & 0x3F));
            continue;
        }
        if (htmlEscape) {
            switch (ch) {
                // &nbsp; &lt; &gt;  &amp; &quot; &copy; &reg; &times; &divide;
                case 160: case 60: case 62: case 38: case 34:
                case 169: case 174: case 215: case 247: {
                    char tmpBuf[20];
                    sprintf(tmpBuf, "&#%u;",ch);
                    int escapeLen = strlen(tmpBuf);
                    memcpy(utf8str + offset, tmpBuf, escapeLen);
                    offset += escapeLen;
                    continue;
                }
                default:
                    break;
            }
        }
        if (ch < 0x80) {
            utf8str[offset++] = (char)ch;
        } else {
            utf8str[offset++] = (char)(0xC0 | (ch >> 6));
            utf8str[offset++] = (char)(0x80 | (ch & 0x3F));
        }
    }
    utf8str[offset] = 0;
    const char* dstStr = utf8str;
    while (*dstStr && AthUnicodeUtils::isSpace(*dstStr)) {
        ++dstStr;
    }
    return dstStr;
}

void AthUnicodeUtils::deleteAllMark(std::string &s, const std::string &mark) {
    size_t nSize = mark.size();
    while(true) {
        size_t pos = s.find(mark);
        if(pos == std::string::npos) {
            return;
        }
        s.erase(pos, nSize);
    }
}

char* AthUnicodeUtils::copyStdstrIfNotEmpty(std::string str) {
    int length = str.length();
    if (length == 0) {
        return NULL;
    }

    char* dest = new char[length + 1];
    memcpy(dest, str.c_str(), length);
    dest[length] = 0;
    return dest;
}

char* AthUnicodeUtils::copyIfNotNull(const char* data) {
    if (data == NULL) {
        return NULL;
    }
    int length = strlen(data);
    char* dest = new char[length + 1];
    memcpy(dest, data, length + 1);
    return dest;
}

char* AthUnicodeUtils::copyIfNotEmpty(const char* data) {
    if (data == NULL || *data == 0) {
        return NULL;
    }
    int length = strlen(data);
    char* dest = new char[length + 1];
    memcpy(dest, data, length + 1);
    return dest;
}

char* AthUnicodeUtils::copy(const char* data) {
    assert(data);
    int length = strlen(data);
    char* dest = new char[length + 1];
    memcpy(dest, data, length + 1);
    return dest;
}

char* AthUnicodeUtils::copyStdstr(std::string str) {
    int length = str.length();
    char* dest = new char[length + 1];
    if (length > 0) {
        memcpy(dest, str.c_str(), length);
    }
    dest[length] = 0;
    return dest;
}

char* AthUnicodeUtils::copySubStr(const char* data, int length) {
    assert(data);
    char* dest = new char[length + 1];
    memcpy(dest, data, length);
    dest[length] = 0;
    return dest;
}

char* AthUnicodeUtils::copyStdstrSubStr(std::string str, int length) {
    if (str.length() < length) {
        length = str.length();
    }
    char* dest = new char[length + 1];
    if (length > 0) {
        memcpy(dest, str.c_str(), length);
    }
    dest[length] = 0;
    return dest;
}

const char* AthUnicodeUtils::trimUtf8Space(const char* data, int* len) {
    if (data == NULL || len == NULL || *len <= 0)
        return NULL;

    int curLen = *len;
    *len = 0;

    // trim start space
    unsigned char* tmpCh = (unsigned char*)(data + curLen - 1);
    while(curLen > 0) {
        short next = 0;
        if ((*tmpCh & 0x80) == 0) {
            if (isspace(*tmpCh)) {
                next = -1;
            }
        } else {
            if (*tmpCh == 0xa0) {
                if (curLen >= 2 && (*(tmpCh - 1)) == 0xc2) {
                    next = -2;
                }
            } else if (*tmpCh == 0x80) {
                if (curLen >= 3 && (*(tmpCh - 1)) == 0x80 && (*(tmpCh - 2)) == 0xe3 ) {
                    next = -3;
                }
            }
        }
        if (!next) break;
        curLen += next;
        tmpCh += next;
    }

    // trim end  space
    char* newHead = (char*)data;
    tmpCh = (unsigned char*)data;
    while(curLen > 0) {
        short next = 0;
        if ((*tmpCh & 0x80) == 0) {
            if (isspace(*tmpCh)) {
                next = 1;
            }
        } else {
            if (*tmpCh == 0xc2) {
                if (curLen >= 2 && (*(tmpCh + 1)) == 0xa0) {
                    next = 2;
                }
            } else if (*tmpCh == 0xe3) {
                if (curLen >= 3 && (*(tmpCh + 1)) == 0x80 && (*(tmpCh + 2)) == 0x80 ) {
                    next = 3;
                }
            }
        }
        if (!next) break;
        newHead += next;
        curLen -= next;
        tmpCh += next;
    }

    *len = curLen;
    return newHead;
}

std::vector<char*>* AthUnicodeUtils::split(char* data, const char* deli) {
    if (data == NULL) {
        return NULL;
    }

    std::vector<char*>* tokens = new std::vector<char*>();
    if (deli == NULL || *(deli) == 0) {
        tokens->push_back(data);
        return tokens;
    }

    char *token = NULL, *saveptr= NULL;
    for (; ; data = NULL) {
#ifdef _WIN32
        saveptr;
        token = strtok(data, deli);
#else
        token = strtok_r(data, deli, &saveptr);
#endif
        if (token == NULL) {
            break;
        } else {
            tokens->push_back(token);
        }
    }

    return tokens;
}
void AthUnicodeUtils::escape(char* data, int length) {
    if (data == NULL || length <= 0)
        return;

    int offset = 0, i = 0, t, decode;
    while (i < length) {
        if (data[i] == '%') {
            if (i < length - 2 && isHex(data[i + 1]) && isHex(data[i + 2])) {
                t = data[i + 3];
                data[i + 3] = 0;
                decode = strtol(&data[i + 1], 0, 16);
                data[i + 3] = t;

                if (decode < 0x80) {
                    data[offset++] = decode;
                    i += 3;
                } else {
                    data[offset++] = data[i++];
                    data[offset++] = data[i++];
                    data[offset++] = data[i++];
                }
            } else {
                data[offset++] = data[i++];
            }
        } else {
            data[offset++] = data[i++];
        }
    }

    if (offset < length) {
        data[offset] = 0;
    }
}

inline bool AthUnicodeUtils::isHex(char c) {
    return (c <= 'F' && c >='A') ||
           (c <= 'f' && c >='a') ||
           (c <= '9' && c >='0');
}

int AthUnicodeUtils::doCopyToBuffer(char* destBuf,const char* data) {
    // assert(destBuffer && data);

    bool lastSpace = true;
    char* dst = destBuf;
    const char* src = data;
    for(; *src != 0; ++src) {
        const char cur = *src;
        switch(cur) {
            case '\xe3':
                if (*(src+1) == (char)('\x80') && *(src+2) == (char)('\x80')) {
                    if (!lastSpace) {
                        *dst++ = ' ';
                        lastSpace = true;
                    }
                    src+=2;
                    continue;
                }
                break;
            case ' ':
            case '\t':
            case '\r':
            case '\n':
                if (!lastSpace) {
                    *dst++ = ' ';
                    lastSpace = true;
                }
                continue;
                break;
            default:
                lastSpace = false;
                break;
        }
        *dst++ = *src;
    }

    if (lastSpace && dst > destBuf) {
        --dst;
    }
    *dst = 0;
    return dst - destBuf;
}

char* AthUnicodeUtils::copyWithSpaceIgnoredOrCombined(const char* data) {
    if (data == NULL || *data == 0) {
        return NULL;
    }
    int length = strlen(data);
    if (length <= 0) {
        return NULL;
    }

    char* destBuf = new char[length + 1];
    if (destBuf == NULL) {
        return NULL;
    }

    int retLen = doCopyToBuffer(destBuf, data);
    if (retLen <= 0) {
        delete[] destBuf;
        return NULL;
    }
    return destBuf;
}

const char* AthUnicodeUtils::copyWithSpaceIgnoredOrCombinedUserBufferMgr(AthLocalParseBuffer* bufMgr,const char* data)
{
    if (bufMgr == NULL || data == NULL || *data == 0) {
        return NULL;
    }
    int length = strlen(data);
    if (length <= 0) {
        return NULL;
    }

    char* destBuf = bufMgr->getBuffer(length + 1);
    if (destBuf == NULL) {
        return NULL;
    }

    int retLen = doCopyToBuffer(destBuf, data);
    if (retLen <= 0) {
        return NULL;
    }
    return destBuf;
}

short AthStrSeparator::sepStrBySpace(char* str, short maxCt) {
    if (str == NULL || *(str) == 0) {
        return 0;
    }

    if (maxCt < 0) {
        maxCt = PARSESEPSTRMAXCOUNT;
    }

    short sepCt = 0;
    bool lastMark = true;
    char* cur = str;

    for (; *cur; cur++) {
        if (isspace((unsigned char)*cur)) {
            lastMark = true;
            *cur = 0;
        } else {
            if (lastMark) {
                if (sepCt < maxCt) {
                    mPointers[sepCt++] = cur;
                }
                lastMark = false;
            }
        }
    }
    return sepCt;
};

char* AthStrSeparator::trimSpace(char* cur) {
    if (cur == NULL)
        return NULL;

    unsigned char *start = (unsigned char *)cur;
    unsigned char *end = (unsigned char *)(cur + strlen(cur) - 1);
    while (isspace(*start)) {
        start++;
    }
    while (isspace(*end)) {
        *end-- = 0;
    }
    return (char*)start;
}

short AthStrSeparator::sepStrByCharArr(char* str, const char* byArr, short byCt, short maxCt) {
    if (str == NULL || *(str) == 0) {
        return 0;
    }

    if (byArr == NULL || byCt == 0) {
        mPointers[0] = trimSpace(str);
        return 1;
    }

    if (maxCt < 0) {
        maxCt = PARSESEPSTRMAXCOUNT;
    }

    short sepCt = 0, i = 0;
    bool lastMark = true;
    char* cur = str;

    for (; *cur; cur++) {
        for (i = 0; i < byCt; i++) {
            if (*cur == byArr[i]) {
                lastMark = true;
                *cur = 0;
                break;
            }
        }
        if (*cur && lastMark) {
            if (sepCt < maxCt) {
                mPointers[sepCt++] = cur;
            }
            lastMark = false;
        }
    }

    for (int i = 0; i < sepCt; i++)
        mPointers[i] = trimSpace(mPointers[i]);

    return sepCt;
};