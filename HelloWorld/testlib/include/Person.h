//
// Created by Wayen on 2024/12/14.
//

#ifndef HELLOWORLD_PERSON_H
#define HELLOWORLD_PERSON_H

class Person {
private:
    int age;

public:
    Person();
    ~Person();
    int getAge();
    void printfAge();
    void hide();
};

class Children : Person {
public:
    Children();
    ~Children();
};

#endif //HELLOWORLD_PERSON_H
