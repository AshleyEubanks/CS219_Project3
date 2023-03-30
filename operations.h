#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Operations{
    string operation;
    uint32_t num1, num2, answer;

    public:
        Operations();
        Operations(string, uint32_t, uint32_t);

        uint32_t getNum1();
        void setNum1(uint32_t);

        uint32_t getNum2();
        void setNum2(uint32_t);

        string getOperation();
        void setOperation(string);

        uint32_t getAnswer();
        void setAnswer(uint32_t);

        void display();

};
#endif 