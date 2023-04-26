/* Name:        Ashley Eubanks
 * Date:        4/25/23
 * Class:       CS 219
 * Assignment:  Project 3
 * Purpose:     Source file for the Operations class, which takes in the operator and the operands from each line of the input file.
 *              Saves and updates the answer to the operation. Displays the operator, operands, and all the regester values as well. 
*/

#include "operations.h"

Operations::Operations(){
    operation = "NONE";
    num1 = -9;
    num2 = 2;
    answer = 23;
    rd = "none";
    r0 = 0;
    r1 = 0;
    r2 = 0;
    r3 = 0;
    r4 = 0;
    r5 = 0;
    r6 = 0;
    r7 = 0;
}
Operations::Operations(string newOp, string new1, string new2){
    operation = newOp;
    setNum1(new1);
    setNum2(new2);
}

uint32_t Operations::getRegester(string location){
    if(location == "R0" || location == "r0"){
        return r0;
    }
    else if(location == "R1" || location == "r1"){
        return r1;
    }
    else if(location == "R2" || location == "r2"){
        return r2;
    }
    else if(location == "R3" || location == "r3"){
        return r3;
    }
    else if(location == "R4" || location == "r4"){
        return r4;
    }
    else if(location == "R5" || location == "r5"){
        return r5;
    }
    else if(location == "R6" || location == "r6"){
        return r6;
    }
    else if(location == "R7" || location == "r7"){
        return r7;
    }
    return 0;
}
void Operations::setRegester(string location, uint32_t value){
    if(location == "R0" || location == "r0"){
        r0 = value;
    }
    else if(location == "R1" || location == "r1"){
        r1 = value;
    }
    else if(location == "R2" || location == "r2"){
        r2 = value;
    }
    else if(location == "R3" || location == "r3"){
        r3 = value;
    }
    else if(location == "R4" || location == "r4"){
        r4 = value;
    }
    else if(location == "R5" || location == "r5"){
        r5 = value;
    }
    else if(location == "R6" || location == "r6"){
        r6 = value;
    }
    else if(location == "R7" || location == "r7"){
        r7 = value;
    }
}

string Operations::getRd(){
    return rd;
}
void Operations::setRd(string location){ //takes in string 'R0,' and takes out comma before setting 
    string chars = ",";

    for (char c: chars) {
        location.erase(std::remove(location.begin(), location.end(), c), location.end());
    }

    rd = location;

}

uint32_t Operations::getNum1(){
    return num1;
}
void Operations::setNum1(string new1){ //taking in string number or regester, if it is a regester it will call the getRegester function, if not it converts into uint32_t
    strNum1 = new1; 
    if(new1.find('r'||'R') != string::npos) {
        num1 = getRegester(new1);
    } 
    else{
        sscanf(new1.c_str(), "%x", &num1);
    }
} 

uint32_t Operations::getNum2(){
    return num2;
}
void Operations::setNum2(string new2){ //taking in string number or regester, if it is a regester it will call the getRegester function, if not it converts into uint32_t
    strNum2 = new2;
    if(new2.find('r'||'R') != string::npos) {
        num2 = getRegester(new2);
    } 
    else{
        sscanf(new2.c_str(), "%x", &num2);
    }
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
void Operations::setAnswer(string location, uint32_t newAnswer){
    answer = newAnswer;
    setRegester(location, newAnswer);
}

void Operations::display(){
    int width = 5;
    char RD[3];
    char hex1[32];
    char hex2[32];
    string whichOp;
    whichOp = operation;
    transform(whichOp.begin(), whichOp.end(), whichOp.begin(), ::toupper);

    cout << operation << setw(width);
    cout << rd << ", ";

    if(whichOp == "MOV"){
        sprintf(hex1, "#0x%X", num1);
        cout << hex1 << endl;
    }
    else if(whichOp == "LSRS" || whichOp == "LSLS"){
        sprintf(hex2, "#%X", num2);
        cout << strNum1 << ", " << hex2 << endl;
    }
    else if(whichOp == "CMP" || whichOp == "TST"){
        cout << strNum1 << endl; 
    }
    else{
        cout << strNum1 << ", " << strNum2 << endl;
    }
}


void Operations::displayReg(){
    char hexAnswer[32];
    int width = 5;

    sprintf(hexAnswer, "0x%X", r0);
    cout << "R0: " << hexAnswer << setw(width);

    sprintf(hexAnswer, "0x%X", r1);
    cout << "R1: " << hexAnswer << setw(width);

    sprintf(hexAnswer, "0x%X", r2);
    cout << "R2: " << hexAnswer << setw(width);

    sprintf(hexAnswer, "0x%X", r3);
    cout << "R3: " << hexAnswer << endl;

    sprintf(hexAnswer, "0x%X", r4);
    cout << "R4: " << hexAnswer << setw(width);

    sprintf(hexAnswer, "0x%X", r5);
    cout << "R5: " << hexAnswer << setw(width);

    sprintf(hexAnswer, "0x%X", r6);
    cout << "R6: " << hexAnswer << setw(width);

    sprintf(hexAnswer, "0x%X", r7);
    cout << "R7: " << hexAnswer << endl;
}
