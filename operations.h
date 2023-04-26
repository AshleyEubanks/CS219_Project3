/* Name:        Ashley Eubanks
 * Date:        4/24/23
 * Class:       CS 219
 * Assignment:  Project 3
 * Purpose:     Header file for the operations class. 
 */

#ifndef OPERATIONS_H
#define OPERATIONS_H
#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Operations{
    string operation;
    uint32_t num1, num2, answer;
    string rd, strNum1, strNum2;
    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r4;
    uint32_t r5;
    uint32_t r6;
    uint32_t r7;

    public:
        Operations();
        Operations(string, string, string);

        uint32_t getRegester(string);
        void setRegester(string, uint32_t);

        string getRd();
        void setRd(string);

        uint32_t getNum1();
        void setNum1(string);

        uint32_t getNum2();
        void setNum2(string);

        string getOperation();
        void setOperation(string);

        uint32_t getAnswer();
        void setAnswer(string, uint32_t);

        void display();
        void displayReg();

};
#endif 