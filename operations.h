/* Name:        Ashley Eubanks
 * Date:        2/20/23
 * Class:       CS 219
 * Assignment:  Project 2
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
    int rd;
    uint32_t regesters[8];

    public:
        Operations();
        Operations(string, uint32_t, uint32_t);

        uint32_t getRegester(int);
        void setRegester(int, uint32_t);

        int getRd();
        void setRd(int);

        uint32_t getNum1();
        void setNum1(uint32_t);

        uint32_t getNum2();
        void setNum2(uint32_t);

        string getOperation();
        void setOperation(string);

        uint32_t getAnswer();
        void setAnswer(int, uint32_t);

        void display();

};
#endif 