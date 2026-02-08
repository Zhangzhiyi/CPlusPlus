set(SRC_MYLIB
        src/Person.cpp)

message(STATUS "CMAKE_SOURCE_DIR => " ${CMAKE_SOURCE_DIR})

add_library(Mylib STATIC ${SRC_MYLIB})