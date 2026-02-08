#源文件集合
set(TEST_STRING_SRC
        src/Utils.cpp
        src/md5.cpp)

add_executable(TestString main.cpp
        ${TEST_STRING_SRC})