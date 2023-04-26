/* Name:        Ashley Eubanks
 * Date:        4/25/23
 * Class:       CS 219
 * Assignment:  Project 3
 * Purpose:     Machine Language Simulator. Using the provided text file as an example input. You will create a program that reads the
                command and performs the operation between the two hexadecimal numbers.
                The result of the operation must be displayed to the terminal. Your code should follow proper
                code commenting and indentation procedures.. 
 * 
*/

#include "operations.h"

uint32_t ADD(uint32_t, uint32_t);
uint32_t AND(uint32_t, uint32_t);
uint32_t ASR(uint32_t, uint32_t);
uint32_t LSR(uint32_t, uint32_t);
uint32_t LSL(uint32_t, uint32_t);
uint32_t NOT(uint32_t, uint32_t);
uint32_t ORR(uint32_t, uint32_t);
uint32_t SUB(uint32_t, uint32_t);
uint32_t XOR(uint32_t, uint32_t);
void withS(string, uint32_t,  uint32_t, uint32_t, bool, bool, bool, bool);

int main(){

    Operations newOperations[100];
    Operations reg;

    uint32_t answer;
    uint32_t num1, num2;
    string operation, rd;
    string strnum1, strnum2;
    int Rd;
    bool N = 0;
    bool Z = 0;
    bool C = 0;
    bool V = 0;    

    int numOps = 0;

    ifstream file;
    file.open("inputFile.txt");
    if(!file.is_open()){
        cout << "Cannot open the file." << endl;
        exit(1);
    }
    else{
        while(file.good()){
            
            file >> operation >> rd >> strnum1 >> strnum2;

            string chars = "#,"; //taking out characters not needed 
            for (char c: chars) {
                rd.erase(std::remove(rd.begin(), rd.end(), c), rd.end());
                strnum1.erase(std::remove(strnum1.begin(), strnum1.end(), c), strnum1.end());
                strnum2.erase(std::remove(strnum2.begin(), strnum2.end(), c), strnum2.end());
            }

            sscanf(strnum1.c_str(), "%x", &num1);
            sscanf(strnum2.c_str(), "%x", &num2); //this converts the string input to num to store in object 

            newOperations[numOps].setOperation(operation);
            newOperations[numOps].setRd(rd); 
            newOperations[numOps].setNum1(strnum1);
            newOperations[numOps].setNum2(strnum2);
            numOps++;
            
        }
    }

    for(int i = 0; i < numOps; i++){
        string whichOp;
        num1 = newOperations[i].getNum1();
        num2 = newOperations[i].getNum2();
        whichOp = newOperations[i].getOperation();
        transform(whichOp.begin(), whichOp.end(), whichOp.begin(), ::toupper);

        if(whichOp == "ADD" || whichOp == "ADDS"){
            answer = ADD(newOperations[i].getNum1(), newOperations[i].getNum2()); 
            reg.setRegester(newOperations[i].getRd(), answer);
            newOperations[i].display();
            reg.displayReg();
            withS(newOperations[i].getOperation(), answer, newOperations[i].getNum1(), newOperations[i].getNum2(), N, Z, C, V);
        }
        else if(whichOp == "AND" || whichOp == "ANDS"){
            answer = AND(newOperations[i].getNum1(), newOperations[i].getNum2());
            reg.setRegester(newOperations[i].getRd(), answer);
            newOperations[i].display();
            reg.displayReg();
            withS(newOperations[i].getOperation(), answer, newOperations[i].getNum1(), newOperations[i].getNum2(), N, Z, C, V);
        }
        else if(whichOp == "TST"){
            answer = AND(newOperations[i].getNum1(), newOperations[i].getNum2());
            newOperations[i].display();
            reg.displayReg();
            withS(newOperations[i].getOperation(), answer, newOperations[i].getNum1(), newOperations[i].getNum2(), N, Z, C, V);
        }
        else if(whichOp == "ASR" || whichOp == "ASRS"){
            answer = ASR(newOperations[i].getNum1(), newOperations[i].getNum2()); 
            reg.setRegester(newOperations[i].getRd(), answer);
            newOperations[i].display();
            reg.displayReg();
            withS(newOperations[i].getOperation(), answer, newOperations[i].getNum1(), newOperations[i].getNum2(), N, Z, C, V);
                   
        }
        else if(whichOp == "LSR" || whichOp == "LSRS"){
            answer = LSR(newOperations[i].getNum1(), newOperations[i].getNum2());
            reg.setRegester(newOperations[i].getRd(), answer);
            newOperations[i].display();
            reg.displayReg();
            withS(newOperations[i].getOperation(), answer, newOperations[i].getNum1(), newOperations[i].getNum2(), N, Z, C, V);
        }
        else if(whichOp == "LSL" || whichOp == "LSLS"){
            answer = LSL(newOperations[i].getNum1(), newOperations[i].getNum2());
            reg.setRegester(newOperations[i].getRd(), answer);
            newOperations[i].display();
            reg.displayReg();
            withS(newOperations[i].getOperation(), answer, newOperations[i].getNum1(), newOperations[i].getNum2(), N, Z, C, V);
        }
        else if(whichOp == "NOT" || whichOp == "NOTS"){
            answer = NOT(newOperations[i].getNum1(), newOperations[i].getNum2()); 
            reg.setRegester(newOperations[i].getRd(), answer);
            newOperations[i].display();
            reg.displayReg();
            withS(newOperations[i].getOperation(), answer, newOperations[i].getNum1(), newOperations[i].getNum2(), N, Z, C, V);             
        }
        else if(whichOp == "ORR" || whichOp == "ORRS"){
            answer = ORR(newOperations[i].getNum1(), newOperations[i].getNum2());
            reg.setRegester(newOperations[i].getRd(), answer);
            newOperations[i].display();
            reg.displayReg();
            withS(newOperations[i].getOperation(), answer, newOperations[i].getNum1(), newOperations[i].getNum2(), N, Z, C, V);
        }
        else if(whichOp == "SUB" || whichOp == "SUBS"){
            answer = SUB(newOperations[i].getNum1(), newOperations[i].getNum2());
            reg.setRegester(newOperations[i].getRd(), answer);
            newOperations[i].display();
            reg.displayReg();
            withS(newOperations[i].getOperation(), answer, newOperations[i].getNum1(), newOperations[i].getNum2(), N, Z, C, V);
        }
        else if(whichOp == "CMP"){
            answer = SUB(newOperations[i].getNum1(), newOperations[i].getNum2());
            newOperations[i].display();
            reg.displayReg();
            withS("CMPS", answer, newOperations[i].getNum1(), newOperations[i].getNum2(), N, Z, C, V);
        }
        else if(whichOp == "XOR" || whichOp == "XORS"){
            answer = XOR(newOperations[i].getNum1(), newOperations[i].getNum2());
            reg.setRegester(newOperations[i].getRd(), answer);
            newOperations[i].display();
            reg.displayReg();
            withS(newOperations[i].getOperation(), answer, newOperations[i].getNum1(), newOperations[i].getNum2(), N, Z, C, V);         
        }
        else if(whichOp == "MOV"){
            reg.setRegester(newOperations[i].getRd(), num1);
            newOperations[i].display();
            reg.displayReg();
            withS(newOperations[i].getOperation(), answer, newOperations[i].getNum1(), newOperations[i].getNum2(), N, Z, C, V);
        }
    }
    return 0;
}

uint32_t ADD(uint32_t num1, uint32_t num2){
    uint32_t sum;
    sum = num1 + num2;
    return sum;
}

uint32_t AND(uint32_t num1, uint32_t num2){
    uint32_t output;
    output = num1 & num2;
    return output;
}

uint32_t ASR(uint32_t num1, uint32_t num2){ //treat values as signed 
    uint32_t output;
    int32_t tempNum = (int32_t)num1;
    if (tempNum < 0){
        output =  num1 >> 1 | ~(~0U >> 1); //resource: stackoverflow https://stackoverflow.com/questions/7622/are-the-shift-operators-arithmetic-or-logical-in-c
        return output;
    }
    output = num1 >> 1;
    return output;
}

uint32_t LSR(uint32_t num1, uint32_t num2){
    uint32_t output;
    output  = num1 >> num2;
    return output;
}

uint32_t LSL(uint32_t num1, uint32_t num2){
    uint32_t output;
    output = num1 << num2;
    return output;
}

uint32_t NOT(uint32_t num1, uint32_t num2){
    uint32_t output;
    output = ~num1;
    return output;
}

uint32_t ORR(uint32_t num1, uint32_t num2){
    uint32_t output;
    output = num1 | num2;
    return output;
}

uint32_t SUB(uint32_t num1, uint32_t num2){
    uint32_t output;
    output = num1 - num2;
    return output;
}

uint32_t XOR(uint32_t num1, uint32_t num2){
    uint32_t output;
    output = num1 ^ num2;
    return output;
}

void withS(string operation, uint32_t answer, uint32_t num1, uint32_t num2, bool N, bool Z, bool C, bool V){
    if(&operation.back() == "s" || &operation.back() == "S"){
        int32_t flagAnswer = (uint32_t)answer;
        char hex1[32];
        char hexNum1[32];
        char hexNum2[32];
        sprintf(hex1, "0x%X", answer);
        sprintf(hexNum1, "0x%X", num1);
        sprintf(hexNum2, "0x%X", num2);

        //checking for negative 
        if(hex1[2] >= '7'){
            N = true;
        }
        else{
            N = false;
        }

        // checking for zero 
        if(answer == 0){
            Z = true;
        }
        else{
            Z = false;
        }

        // checking for carry
        if(answer > 0xFFFFFFFF){
            C = true;
        }
        else{
            C = false;
        }

        // checking for overflow 
        if(hexNum1[2] >= '7' && hexNum2[2] >= '7' && hex1[2] < '7'){
            V = true;
        } 
        else if(hexNum1[2] < '7' && hexNum2[2] < '7' && hex1[2] >= '7'){
            V = true;
        }
        else{
            V = false;
        }
    }
    
    cout << "N: " << N << "\tZ: " << Z << "\tC: " << C << "\tV: " << V << "\n" << endl;

}
