/* Name:        Ashley Eubanks
 * Date:        2/20/23
 * Class:       CS 219
 * Assignment:  Project 1
 * Purpose:     Machine Language Simulator. Must take in 2 hex numbers and ADD them for part 1. 
 * 
*/

// #include <iostream>
// #include <fstream>
// #include <iomanip>
// #include <string>
// using namespace std;

#include "operations.h"

uint32_t ADD(uint32_t, uint32_t, bool);
uint32_t AND(uint32_t, uint32_t, bool);
uint32_t ASR(uint32_t, uint32_t, bool);
uint32_t LSR(uint32_t, uint32_t, bool);
uint32_t LSL(uint32_t, uint32_t, bool);
uint32_t NOT(uint32_t, uint32_t, bool);
uint32_t ORR(uint32_t, uint32_t, bool);
uint32_t SUB(uint32_t, uint32_t, bool);
uint32_t XOR(uint32_t, uint32_t, bool);
int readInputFile(Operations);

//void HexToBin(uint32_t);

void display(Operations, int);


int main(){

    Operations newOperations[100];
    //Operations Op;
    uint32_t answer;
    uint32_t num1, num2;
    string operation;
    //int numOps;
    //numOps = readInputFile(newOperations);

    int numOps = 0, index = 0;
    //string operation;
    //uint32_t num1, num2;

    ifstream file;
    file.open("inputFile.txt");
    if(!file.is_open()){
        cout << "Cannot open the file." << endl;
        exit(1);
    }
    else{
        while(file.good()){
            string strnum1, strnum2;
           // getline(file, operation);
            file >> operation >> strnum1 >> strnum2;
            //num1 = stoul(strnum1, nullptr, 16);
            //num2 = atoi(strnum2.c_str());
            sscanf(strnum1.c_str(), "0x%x", &num1);
            sscanf(strnum2.c_str(), "0x%x", &num2);

            newOperations[numOps].setOperation(operation);
            newOperations[numOps].setNum1(num1);
            newOperations[numOps].setNum2(num2);
            numOps++;
        }
    }
    //numOps = index;
    cout << numOps << endl;
    //cout << newOperations[0].getOperation() << endl;

    // for(int i = 0; i < numOps; i++){
    //     cout << newOperations[i].getOperation() << " " << newOperations[i].getNum1() << " " << newOperations[i].getNum2() << endl;

    // }

    for(int i = 0; i < numOps; i++){
        string whichOp;
        num1 = newOperations[i].getNum1();
        num2 = newOperations[i].getNum2();
        whichOp = newOperations[i].getOperation();

        if(whichOp == "ADD" || whichOp == "ADDS"){
            if(whichOp == "ADDS"){
                //bool true 
                answer = ADD(num1, num2, true);
            }
            //bool false
            answer = ADD(num1, num2, false);
        }
        else if(whichOp == "AND" || whichOp == "ANDS"){
            if(whichOp == "ANDS"){
                answer = AND(num1, num2, true);
            }
            answer = AND(num1, num2, false);
        }
        else if(whichOp == "ASR" || whichOp == "ASRS"){
            if(whichOp == "ASRS"){
                answer = ASR(num1, num2, true);
            }
            answer = ASR(num1, num2, false);        
        }
        else if(whichOp == "LSR" || whichOp == "LSRS"){
            if(whichOp == "LSRS"){
                answer = LSR(num1, num2, true);
            }
            answer = LSR(num1, num2, false);         
        }
        else if(whichOp == "LSL" || whichOp == "LSLS"){
            if(whichOp == "LSLS"){
                answer = LSL(num1, num2, true);
            }
            answer = LSL(num1, num2, false);         
        }
        else if(whichOp == "NOT" || whichOp == "NOTS"){
            if(whichOp == "NOTS"){
                answer = NOT(num1, num2, true);
            }
            answer = NOT(num1, num2, false);        
        }
        else if(whichOp == "ORR" || whichOp == "ORRS"){
            if(whichOp == "ORRS"){
                answer = ORR(num1, num2, true);
            }
            answer = ORR(num1, num2, false);      
        }
        else if(whichOp == "SUB" || whichOp == "SUBS"){
            if(whichOp == "SUBS"){
                answer = SUB(num1, num2, true);
            }
            answer = SUB(num1, num2, false);
        }
        else if(whichOp == "XOR" || whichOp == "XORS"){
            if(whichOp == "XORS"){
                answer = XOR(num1, num2, true);
            }
            answer = AND(num1, num2, false);       
        }
        newOperations[i].setAnswer(answer);
        newOperations[i].display();
    }


    // num1 = 0x1;
    // num2 = 0x1;
    // answer = ADD(num1, num2, false);
    // display("ADD", num1, num2, answer);
    

    // num1 = 0xAAA5555;
    // num2 = 0x555AAAA;
    // answer = ADD(num1, num2, false);
    // display("ADD", num1, num2, answer);

    // num1 = 0xFFFFFFFF;
    // num2 = 0x1;
    // answer = ADD(num1, num2, false);
    // display("ADD", num1, num2, answer);

    // num1 = 0x1234;
    // num2 = 0x8765;
    // answer = ADD(num1, num2, false);
    // display("ADD", num1, num2, answer);

    // num1 = 0x72DF9901;
    // num2 = 0x2E0B484A;
    // answer = ADD(num1, num2, false);
    // display("ADD", num1, num2, answer);


    return 0;
}

uint32_t ADD(uint32_t num1, uint32_t num2, bool hasS){
    uint32_t sum;
    sum = num1 + num2;
    return sum;

    if(hasS == true){

    }
}

uint32_t AND(uint32_t num1, uint32_t num2, bool hasS){
    uint32_t output;
    output = num1 & num2;
    return output;

    if(hasS == true){
        
    }
}

uint32_t ASR(uint32_t num1, uint32_t num2, bool hasS){ //treat values as signed 
    uint32_t output;
    if (num1 < 0){
        output =  num1 >> 1 | ~(~0U >> 1); //resource: stackoverflow https://stackoverflow.com/questions/7622/are-the-shift-operators-arithmetic-or-logical-in-c
        return output;
    }
    output = num1 >> 1;
    return output;

    if(hasS == true){
        
    }
}

uint32_t LSR(uint32_t num1, uint32_t num2, bool hasS){
    uint32_t output;
    output  = num1 >> 1;
    return output;

    if(hasS == true){
        
    }
}

uint32_t LSL(uint32_t num1, uint32_t num2, bool hasS){
    uint32_t output;
    output = num1 << 1;
    return output;

    if(hasS == true){
        
    }
}

uint32_t NOT(uint32_t num1, uint32_t num2, bool hasS){
    uint32_t output;
    output = ~num1;
    return output;

    if(hasS == true){
        
    }
}

uint32_t ORR(uint32_t num1, uint32_t num2, bool hasS){
    uint32_t output;
    output = num1 | num2;
    return output;

    if(hasS == true){
        
    }
}

uint32_t SUB(uint32_t num1, uint32_t num2, bool hasS){
    uint32_t output;
    output = num1 - num2;
    return output;

    if(hasS == true){
        
    }
}

uint32_t XOR(uint32_t num1, uint32_t num2, bool hasS){
    uint32_t output;
    output = num1 ^ num2;
    return output;

    if(hasS == true){
        
    }
}


void display(Operations newOperations[], int numOps){
    for(int i = 0; i < numOps; i++){
        newOperations[i].display();
    }
}

// int readInputFile(Operations newOperations[]){
//     int numOps;
//     string operation;
//     uint32_t num1, num2, i = 0;

//     ifstream file("inputFile.txt");
//     if(!file.is_open()){
//         cout << "Cannot open the file." << endl;
//         exit(0);
//     }

//     while(file >> operation >> num1 >> num2){
//         newOperations[i].setOperation(operation);
//         newOperations[i].setNum1(num1);
//         newOperations[i].setNum2(num2);
//         i++;
//     }
//     numOps = i;
//     return numOps;

// }



// void HexToBin(uint32_t hexNum){
//     int i = 0;
    
//     std::string hexString = std::to_string(hexNum);

//     while(hexString[i]){
//         switch(hexString[i]){
//             case '0':
//                 cout << "0000";
//                 break;
//             case '1':
//                 cout << "0001";
//                 break;
//             case '2':
//                 cout << "0010";
//                 break;
//             case '3':
//                 cout << "0011";
//                 break;
//             case '4':
//                 cout << "0100";
//                 break;
//             case '5':
//                 cout << "0101";
//                 break;
//             case '6':
//                 cout << "0110";
//                 break;
//             case '7':
//                 cout << "0111";
//                 break;
//             case '8':
//                 cout << "1000";
//                 break;
//             case '9':
//                 cout << "1001";
//                 break;
//             case 'A':
//                 cout << "1010";
//                 break;
//             case 'B':
//                 cout << "1011";
//                 break;
//             case 'C':
//                 cout << "1100";
//                 break;
//             case 'D':
//                 cout << "1101";
//                 break;
//             case 'E':
//                 cout << "1110";
//                 break;
//             case 'F':
//                 cout << "1111";
//                 break;
//             default:
//                 cout << "invalid hex" << endl;
//         }
//         i++;
//     }
// }