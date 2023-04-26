# **CS219_Project1**

### **How to run the code:** 

in terminal type commands:
```
make
./Proj3 inputFile.txt
```
### **How the code works:**

The driver consists of main, all of the functions for the operations, and a function that changes the flags if the OPCODE ends in 's'. Main first reads the input file and saves each line as an object array. Then for each element of the array, it checks the OPCODE and calls the appropriate function for that OPCODE then calls the hasS function, which then determines if the OPCODE has an 's'. If the OPCODE does not end in 'S' it will display the flags as 0. All of the operation functions take in two uint32_t values, performs the operation, then returns the answer as an uint32_t. After the function call, the answer will be saved to the object array so that it can be displayed. 

### **Functions:**

The operation functions consist of:
```
ADD     op1 + op2
AND     op1 & op2
ASR     op1 >> 1 | ~(~0U >> 1)
LSR     op1 >> 1
LSL     op1 << 1
NOT     ~op1
ORR     op1|op2
SUB     op1 - op2
XOR     op1 ^ op2
CMP     op1 - op2 (discarding result, affecting flags)
TST     op1 & op2 (discarding result, affecting flags)
MOV     setting the Rd to #IMM

```
The function that changes the status flags works by checking if OPCODE ends in 's', then going through each flag, otherwise it just prints out the values that were previously loaded. It checks that the MSB is greater than or equal to 7 for N and if the number is equal to 0 for Z. To check the MSB, the uint32_t value is saved into a char array. For C it checks if the answer is greater than 0xFFFFFFFF, and for V it checks the signs of the operands to the sign of the result that would indicate an overflow. 

### **Output:**

The input file is based on the examples provided for easy comparison.
Below is a copy of the results from the terminal after running the code. 

```
MOV   R1, #0x72DF9901
R0: 0x0 R1: 0x72DF9901 R2: 0x0 R3: 0x0
R4: 0x0 R5: 0x0 R6: 0x0 R7: 0x0
N: 0    Z: 0    C: 0    V: 0

MOV   R2, #0x2E0B484A
R0: 0x0 R1: 0x72DF9901 R2: 0x2E0B484A R3: 0x0
R4: 0x0 R5: 0x0 R6: 0x0 R7: 0x0
N: 0    Z: 0    C: 0    V: 0

ADDS   R3, R1, R2
R0: 0x0 R1: 0x72DF9901 R2: 0x2E0B484A R3: 0xFFFFFFF9
R4: 0x0 R5: 0x0 R6: 0x0 R7: 0x0
N: 0    Z: 0    C: 0    V: 0

SUBS   R4, R3, R2
R0: 0x0 R1: 0x72DF9901 R2: 0x2E0B484A R3: 0xFFFFFFF9
R4: 0xFFFFFFF5 R5: 0x0 R6: 0x0 R7: 0x0
N: 0    Z: 0    C: 0    V: 0

mov   r0, #0xAAA5555
R0: 0xAAA5555 R1: 0x72DF9901 R2: 0x2E0B484A R3: 0xFFFFFFF9
R4: 0xFFFFFFF5 R5: 0x0 R6: 0x0 R7: 0x0
N: 0    Z: 0    C: 0    V: 0

ands   r0, r0, r4
R0: 0x2 R1: 0x72DF9901 R2: 0x2E0B484A R3: 0xFFFFFFF9
R4: 0xFFFFFFF5 R5: 0x0 R6: 0x0 R7: 0x0
N: 0    Z: 0    C: 0    V: 0

orr   r0, r2, r3
R0: 0xFFFFFFF7 R1: 0x72DF9901 R2: 0x2E0B484A R3: 0xFFFFFFF9
R4: 0xFFFFFFF5 R5: 0x0 R6: 0x0 R7: 0x0
N: 0    Z: 0    C: 0    V: 0

xor   r5, r3, r4
R0: 0xFFFFFFF7 R1: 0x72DF9901 R2: 0x2E0B484A R3: 0xFFFFFFF9
R4: 0xFFFFFFF5 R5: 0xFFFFFFF5 R6: 0x0 R7: 0x0
N: 0    Z: 0    C: 0    V: 0

MOV   R6, #0xFFFFFFFF
R0: 0xFFFFFFF7 R1: 0x72DF9901 R2: 0x2E0B484A R3: 0xFFFFFFF9
R4: 0xFFFFFFF5 R5: 0xFFFFFFF5 R6: 0xFFFFFFFF R7: 0x0
N: 0    Z: 0    C: 0    V: 0

lsrs   R7, R6, #2
R0: 0xFFFFFFF7 R1: 0x72DF9901 R2: 0x2E0B484A R3: 0xFFFFFFF9
R4: 0xFFFFFFF5 R5: 0xFFFFFFF5 R6: 0xFFFFFFFF R7: 0x3FFFFFFD
N: 0    Z: 0    C: 0    V: 0

LSLS   R6, R7, #1
R0: 0xFFFFFFF7 R1: 0x72DF9901 R2: 0x2E0B484A R3: 0xFFFFFFF9
R4: 0xFFFFFFF5 R5: 0xFFFFFFF5 R6: 0xFFFFFFEE R7: 0x3FFFFFFD
N: 0    Z: 0    C: 0    V: 0

CMP   R6, R7
R0: 0xFFFFFFF7 R1: 0x72DF9901 R2: 0x2E0B484A R3: 0xFFFFFFF9
R4: 0xFFFFFFF5 R5: 0xFFFFFFF5 R6: 0xFFFFFFEE R7: 0x3FFFFFFD
N: 0    Z: 0    C: 0    V: 0

tst   R3, R4
R0: 0xFFFFFFF7 R1: 0x72DF9901 R2: 0x2E0B484A R3: 0xFFFFFFF9
R4: 0xFFFFFFF5 R5: 0xFFFFFFF5 R6: 0xFFFFFFEE R7: 0x3FFFFFFD
N: 0    Z: 0    C: 0    V: 0

```

## **Comments On Output**
The output was able to keep the updated regesters, however if you compare the values to the example output, you will see that they do not match. This I had difficulty finding the issue of. Since the arithmatic was sourced from my code for project 2 which worked correctly, I was confident that the arithmatic worked, and spent a long time finding the source of the problem. I found that the reason for the incorrect values is not because of the arithmatic, but because the Rn and Rm (num1 and num2 in the code) would not translate properly from text file to object array for all of the instructions that were not MOV. The value for Rn is stuck at 4294967287 and Rm is stuck at 2 if it had a register and not a value in the instruction. If you assume those values for each of the instructions, you will see that the arithmatic works as it should. The flags also worked properly in my project 2 code, the only thing I changed was where the OPCODE was checked for 's' and where the cout statements were. 

