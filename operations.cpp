/* Name:        Ashley Eubanks
 * Date:        3/31/23
 * Class:       CS 219
 * Assignment:  Project 2
 * Purpose:     Source file for the Operations class, which takes in the operator and the operands from each line of the input file.
 *              Saves and updates the answer to the operation. Displays the operator, operands, and answer as well. 
*/

#include "operations.h"

Operations::Operations(){
    operation = "NONE";
    num1 = -90;
    num2 = 2;
    answer = 23;
    rd = 0;
    for(int i = 0; i < 8; i++){
        regesters[i] = i+1;
    }
}
Operations::Operations(string newOp, uint32_t new1, uint32_t new2){
    operation = newOp;
    setNum1(new1);
    setNum2(new2);
}

uint32_t Operations::getRegester(int location){
    return regesters[location];
}
void Operations::setRegester(int location, uint32_t value){
    regesters[location] = value;
}

int Operations::getRd(){ //temp
    return rd;
}
void Operations::setRd(int location){ //temp
    rd = location;
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
void Operations::setAnswer(int location, uint32_t newAnswer){
    answer = newAnswer;
    regesters[location] = answer;
}

void Operations::display(){
    int width = 5;
    char RD[3];
    char hex1[32];
    char hex2[32];
    char hexAnswer[32];
    string whichOp;
    whichOp = operation;
    transform(whichOp.begin(), whichOp.end(), whichOp.begin(), ::toupper);

    sprintf(RD, "R%X", rd);

    cout << operation << setw(width);
    cout << RD << ", "; // NEED WAY TO PRINT THE OPERANDS EX: R0, #0X12

    if(whichOp == "MOV"){
        sprintf(hex1, "#0x%X", num1);
        cout << hex1 << endl;
    }
    else if(whichOp == "LSRS"){
        sprintf(hex1, "R%X", num1);
        sprintf(hex2, "#%X", num2);
        cout << hex1 << ", " << hex2 << endl;
    }
    else if(whichOp == "CMP" || whichOp == "tst"){
        sprintf(hex1, "R%X", num1);
        cout << hex1 << endl; 
    }
    else{
        sprintf(hex1, "R%X", num1);
        sprintf(hex2, "R%X", num2);
        cout << hex1 << ", " << hex2 << endl;
    }

    sprintf(hexAnswer, "0x%X", regesters[0]);
    cout << "R0: " << hexAnswer << "\t";

    sprintf(hexAnswer, "0x%X", regesters[1]);
    cout << "R1: " << hexAnswer << "\t"; //setw(width);

    sprintf(hexAnswer, "0x%X", regesters[2]);
    cout << "R2: " << hexAnswer << "\t";//setw(width);

    sprintf(hexAnswer, "0x%X", regesters[3]);
    cout << "R3: " << hexAnswer << endl;

    sprintf(hexAnswer, "0x%X", regesters[4]);
    cout << "R4: " << hexAnswer << "\t";//setw(width);

    sprintf(hexAnswer, "0x%X", regesters[5]);
    cout << "R5: " << hexAnswer << "\t";//setw(width);

    sprintf(hexAnswer, "0x%X", regesters[6]);
    cout << "R6: " << hexAnswer << "\t";//setw(width);

    sprintf(hexAnswer, "0x%X", regesters[7]);
    cout << "R7: " << hexAnswer << endl;

    
}
