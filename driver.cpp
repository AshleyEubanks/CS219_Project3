/* Name:        Ashley Eubanks
 * Date:        3/31/23
 * Class:       CS 219
 * Assignment:  Project 2
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
void withS(uint32_t);

int main(){

    Operations newOperations[100];

    uint32_t answer;
    uint32_t num1, num2;
    string operation;

    int numOps = 0, index = 0;

    ifstream file;
    file.open("inputFile.txt");
    if(!file.is_open()){
        cout << "Cannot open the file." << endl;
        exit(1);
    }
    else{
        while(file.good()){
            string strnum1, strnum2;
            file >> operation >> strnum1 >> strnum2;
            sscanf(strnum1.c_str(), "0x%x", &num1);
            sscanf(strnum2.c_str(), "0x%x", &num2);

            newOperations[numOps].setOperation(operation);
            newOperations[numOps].setNum1(num1);
            newOperations[numOps].setNum2(num2);
            numOps++;
        }
    }

    for(int i = 0; i < numOps; i++){
        string whichOp;
        num1 = newOperations[i].getNum1();
        num2 = newOperations[i].getNum2();
        whichOp = newOperations[i].getOperation();

        if(whichOp == "ADD" || whichOp == "ADDS"){
            answer = ADD(num1, num2);
            newOperations[i].setAnswer(answer);
            newOperations[i].display();
            if(whichOp == "ADDS"){
                withS(answer);
            }
            else{
                cout << "N: 0 \tZ: 0" << endl;
            }
        }
        else if(whichOp == "AND" || whichOp == "ANDS"){
            answer = AND(num1, num2);
            newOperations[i].setAnswer(answer);
            newOperations[i].display();
            if(whichOp == "ANDS"){
                withS(answer);
            }
            else{
                cout << "N: 0 \tZ: 0" << endl;
            }
            
        }
        else if(whichOp == "ASR" || whichOp == "ASRS"){
            answer = ASR(num1, num2); 
            newOperations[i].setAnswer(answer);
            newOperations[i].display();
            if(whichOp == "ASRS"){
                withS(answer);
            }
            else{
                cout << "N: 0 \tZ: 0" << endl;
            }
                   
        }
        else if(whichOp == "LSR" || whichOp == "LSRS"){
            answer = LSR(num1, num2);
            newOperations[i].setAnswer(answer);
            newOperations[i].display();
            if(whichOp == "LSRS"){
                withS(answer);
            }
            else{
                cout << "N: 0 \tZ: 0" << endl;
            }                     
        }
        else if(whichOp == "LSL" || whichOp == "LSLS"){
            answer = LSL(num1, num2);
            newOperations[i].setAnswer(answer);
            newOperations[i].display();
            if(whichOp == "LSLS"){
                withS(answer);
            }
            else{
                cout << "N: 0 \tZ: 0" << endl;
            }                     
        }
        else if(whichOp == "NOT" || whichOp == "NOTS"){
            answer = NOT(num1, num2); 
            newOperations[i].setAnswer(answer);
            newOperations[i].display();
            if(whichOp == "NOTS"){
                withS(answer);
            }
            else{
                cout << "N: 0 \tZ: 0" << endl;
            }                  
        }
        else if(whichOp == "ORR" || whichOp == "ORRS"){
            answer = ORR(num1, num2);
            newOperations[i].setAnswer(answer);
            newOperations[i].display();
            if(whichOp == "ORRS"){
                withS(answer);
            }
            else{
                cout << "N: 0 \tZ: 0" << endl;
            }                 
        }
        else if(whichOp == "SUB" || whichOp == "SUBS"){
            answer = SUB(num1, num2);
            newOperations[i].setAnswer(answer);
            newOperations[i].display();
            if(whichOp == "SUBS"){
                withS(answer);
            }
            else{
                cout << "N: 0 \tZ: 0" << endl;
            }
        }
        else if(whichOp == "XOR" || whichOp == "XORS"){
            answer = XOR(num1, num2);
            newOperations[i].setAnswer(answer);
            newOperations[i].display();
            if(whichOp == "XORS"){
                withS(answer);
            }
            else{
                cout << "N: 0 \tZ: 0" << endl;
            }                  
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

void withS(uint32_t answer){
    int32_t flagAnswer = (uint32_t)answer;
    bool flag = false;

    char hex1[32];
    sprintf(hex1, "0x%X", answer);

    if(hex1[2] >= '7'){
        flag = true;
        cout << "N: " << flag;
    }
    else{
        flag = false;
        cout <<"N: " << flag;
    }

    if(answer == 0){
        flag = true;
        cout << "\tZ: " << flag << endl;
    }
    else{
        flag = false;
        cout << "\tZ: " << flag << endl;
    }
}
