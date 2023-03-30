#include "operations.h"

Operations::Operations(){
    operation = "NONE";
    num1 = -90;
    num2 = 2;
    answer = 23;
}
Operations::Operations(string newOp, uint32_t new1, uint32_t new2){
    operation = newOp;
    setNum1(new1);
    setNum2(new2);
}

uint32_t Operations::getNum1(){
    return num1;
}
void Operations::setNum1(uint32_t new1){
    num1 = new1;
}

uint32_t Operations::getNum2(){
    return num2;
}
void Operations::setNum2(uint32_t new2){
    num2 = new2;
}

string Operations::getOperation(){
    return operation;
}
void Operations::setOperation(string newOp){
    operation = newOp;
}

uint32_t Operations::getAnswer(){
    return answer;
}
void Operations::setAnswer(uint32_t newAnswer){
    answer = newAnswer;
}

void Operations::display(){
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

// void display(string operation, uint32_t num1, uint32_t num2, uint32_t answer){
//     int width = 20;
//     char hex1[32];
//     char hex2[32];
//     char hexAnswer[32];

//     sprintf(hex1, "0x%X", num1);
//     sprintf(hex2, "0x%X", num2);
//     sprintf(hexAnswer, "0x%X", answer);

//     cout << operation << setw(width);
//     cout << hex1 << setw(width);
//     cout << hex2 << ":" << setw(width);
//     cout << hexAnswer << endl;
// }