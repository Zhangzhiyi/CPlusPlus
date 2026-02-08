cmake_minimum_required(VERSION 3.30)

project(HelloWorld VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

if(WIN32)
    set(CMAKE_CXX_COMPILER "MSVC")
elseif(UNIX)
    set(CMAKE_CXX_COMPILER "g++")
endif()

# 与CMake相关的常量
message(STATUS "PROJECT_SOURCE_DIR => " ${PROJECT_SOURCE_DIR})
message(STATUS "PROJECT_BINARY_DIR => " ${PROJECT_BINARY_DIR})
message(STATUS "CMAKE_CURRENT_LIST_FILE => " ${CMAKE_CURRENT_LIST_FILE})
message(STATUS "CMAKE_SOURCE_DIR => " ${CMAKE_SOURCE_DIR})


#需要指定构建类型（如 Debug 或 Release），可以使用 -DCMAKE_BUILD_TYPE 选项  cmake -DCMAKE_BUILD_TYPE=Release ..
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("Debug build")
endif()

# 自定义变量

#字符串
set(test_string "hello, world") # string
message(STATUS ${test_string})
string(APPEND test_string " alibaba")
message(STATUS "test_string after append => " ${test_string})

#列表
set(test_list a;b;c;d;e;f)	# list
message(STATUS ${test_list})
list(APPEND test_list 1;2;3;4)
message("test_list after append => ${test_list}")

option(Debug "Debug Mode" ON) # bool
message(STATUS ${Debug})

function(my_custom_function)
    message(STATUS "This is a custom function!")
endfunction()

my_custom_function()

add_executable(HelloWorld main.cpp)

add_subdirectory(${PROJECT_SOURCE_DIR}/testlib)
#include_directories(${PROJECT_SOURCE_DIR}/testlib/include)
#target_include_directories(HelloWorld PRIVATE ${PROJECT_SOURCE_DIR}/testlib/include)
target_link_libraries(HelloWorld PRIVATE Mylib)

