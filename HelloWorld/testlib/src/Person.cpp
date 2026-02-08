//
// Created by Wayen on 2024/12/14.
//

#include <cstdio>
#include "../include/Person.h"


using namespace std;
Person::Person() {
    age = 30;
}

Person::~Person(){

}

int Person::getAge() {
    return age;
}

void Person::printfAge() {
    printf("age:%d\n", age);
}

void Person::hide() {
    printf("Person::hide()\n");
}

Children::Children() {

}

Children::~Children() {

}