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
void withS(uint32_t,  uint32_t num1, uint32_t num2, bool, bool, bool, bool);
void regesters();

int main(){

    Operations newOperations[100];

    uint32_t answer;
    uint32_t num1, num2;
    string operation, rd;
    int Rd;
    bool N = 0;
    bool Z = 0;
    bool C = 0;
    bool V = 0;
    uint32_t r0 = 0;
    uint32_t r1 = 0;
    uint32_t r2 = 0;
    uint32_t r3 = 0;
    uint32_t r4 = 0;
    uint32_t r5 = 0;
    uint32_t r6 = 0;
    uint32_t r7 = 0;
    

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
            file >> operation >> rd >> strnum1 >> strnum2;

            string chars = "#Rr,";
 
            for (char c: chars) {
                rd.erase(std::remove(rd.begin(), rd.end(), c), rd.end());
                strnum1.erase(std::remove(strnum1.begin(), strnum1.end(), c), strnum1.end());
                strnum2.erase(std::remove(strnum2.begin(), strnum2.end(), c), strnum2.end());
            }

            sscanf(rd.c_str(), "%x", &Rd);
            sscanf(strnum1.c_str(), "%x", &num1);
            sscanf(strnum2.c_str(), "%x", &num2); //this converts the string input to num to store in object 

            newOperations[numOps].setOperation(operation);
            newOperations[numOps].setRd(Rd); 
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
        transform(whichOp.begin(), whichOp.end(), whichOp.begin(), ::toupper);

        if(whichOp == "ADD" || whichOp == "ADDS"){
            answer = ADD(newOperations[i].getRegester(num1), newOperations[i].getRegester(num2)); 
            newOperations[i].setRegester(newOperations[i].getRd(), answer);
            cout << newOperations[i].getRegester(1) << " + " << newOperations[i].getRegester(2) << " = " << answer << endl;
            newOperations[i].display();
            if(whichOp == "ADDS" ){
                withS(answer, newOperations[i].getRegester(num1), newOperations[i].getRegester(num2), N, Z, C, V);
            }
            else{
                cout << "N: " << N << "\tZ: " << Z << "\tC: " << C << "\tV: " << V << "\n" << endl;
            }
        }
        else if(whichOp == "AND" || whichOp == "ANDS"){
            answer = AND(newOperations[i].getRegester(num1), newOperations[i].getRegester(num2));
            newOperations[i].setRegester(newOperations[i].getRd(), answer);
            newOperations[i].display();
            if(whichOp == "ANDS" ){
                withS(answer, newOperations[i].getRegester(num1), newOperations[i].getRegester(num2), N, Z, C, V);
            }
            else{
                cout << "N: " << N << "\tZ: " << Z << "\tC: " << C << "\tV: " << V << "\n" << endl;
            }
            
        }
        else if(whichOp == "ASR" || whichOp == "ASRS"){
            answer = ASR(newOperations[i].getRegester(num1), num2); 
            newOperations[i].setRegester(newOperations[i].getRd(), answer); //CHECK AGAINST JUST RD
            newOperations[i].display();
            if(whichOp == "ASRS" ){
                withS(answer, newOperations[i].getRegester(num1), newOperations[i].getRegester(num2), N, Z, C, V);
            }
            else{
                cout << "N: " << N << "\tZ: " << Z << "\tC: " << C << "\tV: " << V << "\n" << endl;
            }
                   
        }
        else if(whichOp == "LSR" || whichOp == "LSRS"){
            answer = LSR(newOperations[i].getRegester(num1), num2);
            newOperations[i].setRegester(newOperations[i].getRd(), answer);
            newOperations[i].display();
            if(whichOp == "LSRS"){
                withS(answer, newOperations[i].getRegester(num1), newOperations[i].getRegester(num2), N, Z, C, V);
            }
            else{
                cout << "N: " << N << "\tZ: " << Z << "\tC: " << C << "\tV: " << V << "\n" << endl;
            }                     
        }
        else if(whichOp == "LSL" || whichOp == "LSLS"){
            answer = LSL(newOperations[i].getRegester(num1), num2);
            newOperations[i].setRegester(newOperations[i].getRd(), answer);
            newOperations[i].display();
            if(whichOp == "LSLS"){
                withS(answer, newOperations[i].getRegester(num1), newOperations[i].getRegester(num2), N, Z, C, V);
            }
            else{
                cout << "N: " << N << "\tZ: " << Z << "\tC: " << C << "\tV: " << V << "\n" << endl;
            }                     
        }
        else if(whichOp == "NOT" || whichOp == "NOTS"){
            answer = NOT(newOperations[i].getRegester(num1), newOperations[i].getRegester(num2)); 
            newOperations[i].setRegester(newOperations[i].getRd(), answer);
            newOperations[i].display();
            if(whichOp == "NOTS"){
                withS(answer, newOperations[i].getRegester(num1), newOperations[i].getRegester(num2), N, Z, C, V);
            }
            else{
                cout << "N: " << N << "\tZ: " << Z << "\tC: " << C << "\tV: " << V << "\n" << endl;
            }                  
        }
        else if(whichOp == "ORR" || whichOp == "ORRS"){
            answer = ORR(newOperations[i].getRegester(num1), newOperations[i].getRegester(num2));
            newOperations[i].setRegester(newOperations[i].getRd(), answer);
            newOperations[i].display();
            if(whichOp == "ORRS"){
                withS(answer, newOperations[i].getRegester(num1), newOperations[i].getRegester(num2), N, Z, C, V);
            }
            else{
                cout << "N: " << N << "\tZ: " << Z << "\tC: " << C << "\tV: " << V << "\n" << endl;
            }                 
        }
        else if(whichOp == "SUB" || whichOp == "SUBS"){
            answer = SUB(newOperations[i].getRegester(num1), newOperations[i].getRegester(num2));
            newOperations[i].setRegester(newOperations[i].getRd(), answer);
            newOperations[i].display();
            if(whichOp == "SUBS"){
                withS(answer, newOperations[i].getRegester(num1), newOperations[i].getRegester(num2), N, Z, C, V);
            }
            else{
                cout << "N: " << N << "\tZ: " << Z << "\tC: " << C << "\tV: " << V << "\n" << endl;
            }
        }
        else if(whichOp == "XOR" || whichOp == "XORS"){
            answer = XOR(newOperations[i].getRegester(num1), newOperations[i].getRegester(num2));
            newOperations[i].setRegester(newOperations[i].getRd(), answer);
            newOperations[i].display();
            if(whichOp == "XORS"){
                withS(answer, newOperations[i].getRegester(num1), newOperations[i].getRegester(num2), N, Z, C, V);
            }
            else{
                cout << "N: " << N << "\tZ: " << Z << "\tC: " << C << "\tV: " << V << "\n" << endl;
            }                  
        }
        else if(whichOp == "MOV"){
            newOperations[i].setRegester(newOperations[i].getRd(), num1);
            newOperations[i].display();
            cout << "N: " << N << "\tZ: " << Z << "\tC: " << C << "\tV: " << V << "\n" << endl;
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

void withS(uint32_t answer, uint32_t num1, uint32_t num2, bool N, bool Z, bool C, bool V){
    int32_t flagAnswer = (uint32_t)answer;

    char hex1[32];
    sprintf(hex1, "0x%X", answer);

    if(hex1[2] >= '7'){
        N = true;
        cout << "N: " << N;
    }
    else{
        N = false;
        cout <<"N: " << N;
    }

    if(answer == 0){
        Z = true;
        cout << "\tZ: " << Z;
    }
    else{
        Z = false;
        cout << "\tZ: " << Z;
    }

    if(answer > 0xFFFFFFFF){
        C = true;
        cout << "\tC: " << C;
    }
    else{
        C = false;
        cout << "\tC: " << C;
    }

    if(num1 > 0 && num2 > 0 && answer < 0){
        V = true;
        cout << "\tV: " << V << "\n" << endl;
    }
    else if(num1 < 0 && num2 < 0 && answer > 0){
        V= true;
        cout << "\tV: " << V << "\n" << endl;
    }
    else{
        V = false;
        cout << "\tV: " << V << "\n" << endl;
    }
}

void regesters(){

}