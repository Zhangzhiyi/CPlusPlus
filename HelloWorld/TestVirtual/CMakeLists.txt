#set(CMAKE_CXX_STANDARD 20)

#源文件集合
set(TEST_VIRTUAL_SRC
    src/CBase.cpp
        src/CDerived.cpp)

add_executable(TestVirtual main.cpp
                        ${TEST_VIRTUAL_SRC})