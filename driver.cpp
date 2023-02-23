/* Name:        Ashley Eubanks
 * Date:        2/20/23
 * Class:       CS 219
 * Assignment:  Project 1
 * Purpose:     Machine Language Simulator. Must take in 2 hex numbers and ADD them for part 1. 
 * 
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

uint32_t AddHex(uint32_t, uint32_t);

void display(string, uint32_t, uint32_t, uint32_t);


int main(){

    int width = 20;
    uint32_t answer;

    uint32_t num1, num2;
    num1 = 0x1;
    num2 = 0x1;
    answer = AddHex(num1, num2);
    display("ADD", num1, num2, answer);
    

    num1 = 0xAAA5555;
    num2 = 0x555AAAA;
    answer = AddHex(num1, num2);
    display("ADD", num1, num2, answer);

    num1 = 0xFFFFFFFF;
    num2 = 0x1;
    answer = AddHex(num1, num2);
    display("ADD", num1, num2, answer);

    num1 = 0x1234;
    num2 = 0x8765;
    answer = AddHex(num1, num2);
    display("ADD", num1, num2, answer);

    num1 = 0x72DF9901;
    num2 = 0x2E0B484A;
    answer = AddHex(num1, num2);
    display("ADD", num1, num2, answer);


    return 0;
}

uint32_t AddHex(uint32_t num1, uint32_t num2){
    uint32_t sum;
    sum = num1 + num2;
    return sum;
}


void display(string operation, uint32_t num1, uint32_t num2, uint32_t answer){
    int width = 20;
    char hex1[32];
    char hex2[32];
    char hexAnswer[32];

    sprintf(hex1, "0x%X", num1);
    sprintf(hex2, "0x%X", num2);
    sprintf(hexAnswer, "0x%X", answer);

    cout << operation << setw(width);
    cout << hex1 << setw(width);
    cout << hex2 << ":" << setw(width);
    cout << hexAnswer << endl;
}