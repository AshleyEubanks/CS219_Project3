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

uint32_t ADD(uint32_t, uint32_t, bool);
uint32_t AND(uint32_t, uint32_t, bool);
uint32_t ASR(uint32_t, uint32_t, bool);
uint32_t LSR(uint32_t, uint32_t, bool);
uint32_t LSL(uint32_t, uint32_t, bool);
uint32_t NOT(uint32_t, uint32_t, bool);
uint32_t ORR(uint32_t, uint32_t, bool);
uint32_t SUB(uint32_t, uint32_t, bool);
uint32_t XOR(uint32_t, uint32_t, bool);

void HexToBin(uint32_t);

void display(string, uint32_t, uint32_t, uint32_t);


int main(){

    int width = 20;
    uint32_t answer;

    uint32_t num1, num2;
    num1 = 0x1;
    num2 = 0x1;
    answer = ADD(num1, num2, false);
    display("ADD", num1, num2, answer);
    

    num1 = 0xAAA5555;
    num2 = 0x555AAAA;
    answer = ADD(num1, num2, false);
    display("ADD", num1, num2, answer);

    num1 = 0xFFFFFFFF;
    num2 = 0x1;
    answer = ADD(num1, num2, false);
    display("ADD", num1, num2, answer);

    num1 = 0x1234;
    num2 = 0x8765;
    answer = ADD(num1, num2, false);
    display("ADD", num1, num2, answer);

    num1 = 0x72DF9901;
    num2 = 0x2E0B484A;
    answer = ADD(num1, num2, false);
    display("ADD", num1, num2, answer);


    return 0;
}

uint32_t ADD(uint32_t num1, uint32_t num2, bool hasS){
    uint32_t sum;
    sum = num1 + num2;
    return sum;
}

uint32_t AND(uint32_t num1, uint32_t num2, bool hasS){
    uint32_t output;
    return output;
}

uint32_t ASR(uint32_t num1, uint32_t num2, bool hasS){ //treat values as signed 
    uint32_t output;
    return output;
}

uint32_t LSR(uint32_t num1, uint32_t num2, bool hasS){
    uint32_t output;
    return output;
}

uint32_t LSL(uint32_t num1, uint32_t num2, bool hasS){
    uint32_t output;
    return output;
}

uint32_t NOT(uint32_t num1, uint32_t num2, bool hasS){
    uint32_t output;
    return output;
}

uint32_t ORR(uint32_t num1, uint32_t num2, bool hasS){
    uint32_t output;
    return output;
}

uint32_t SUB(uint32_t num1, uint32_t num2, bool hasS){
    uint32_t output;
    return output;
}

uint32_t XOR(uint32_t num1, uint32_t num2, bool hasS){
    uint32_t output;
    return output;
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

void HexToBin(uint32_t hexNum){
    int i = 0;
    
    std::string hexString = std::to_string(hexNum);

    while(hexString[i]){
        switch(hexString[i]){
            case '0':
                cout << "0000";
                break;
            case '1':
                cout << "0001";
                break;
            case '2':
                cout << "0010";
                break;
            case '3':
                cout << "0011";
                break;
            case '4':
                cout << "0100";
                break;
            case '5':
                cout << "0101";
                break;
            case '6':
                cout << "0110";
                break;
            case '7':
                cout << "0111";
                break;
            case '8':
                cout << "1000";
                break;
            case '9':
                cout << "1001";
                break;
            case 'A':
                cout << "1010";
                break;
            case 'B':
                cout << "1011";
                break;
            case 'C':
                cout << "1100";
                break;
            case 'D':
                cout << "1101";
                break;
            case 'E':
                cout << "1110";
                break;
            case 'F':
                cout << "1111";
                break;
            default:
                cout << "invalid hex" << endl;
        }
        i++;
    }
}