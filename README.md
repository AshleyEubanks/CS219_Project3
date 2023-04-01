# CS219_Project1

How to run the code: in terminal type commands:
```
make
./Proj2 inputFile.txt
```
How the code works:

The driver consists of main, all of the functions for the operations, and a function that changes the flags if the operation ends in s. Main first reads the input file and saves each line as an object array. Then for each array, it checks the operation and calls the appropriate function for that operation then calls the hasS function if the operation ends in 'S'. If the operation does not end in 'S' it will display the flags as 0. All of the operation functions take in two uint32_t values, performs the operation, then returns the answer as an uint32_t. After the function call, the answer will be saved to the object array so that it can be displayed. 

Functions:

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

```
The status flag values are changed by checking if the MSB is greater than or equal to 7 for N and if the number is equal to 0 for Z. To check the MSB, the uint32_t value is saved into a char array. 

Output:

The input file is based on the examples provided for easy comparison and to ensure the arithmetic works correctly.
Below is a copy of the results from the terminal after running the code. 

```
ADDS           0xAAA5555           0x555AAAA:           0xFFFFFFF
N: 1    Z: 0
ADD          0xFFFFFFFF                 0x1:                 0x0
N: 0    Z: 0
ADDS              0x1234              0x8765:              0x9999
N: 1    Z: 0
ADD          0x72DF9901          0x2E0B484A:          0xA0EAE14B
N: 0    Z: 0
ANDS           0xAAA5555           0x555AAAA:                 0x0
N: 0    Z: 1
AND          0xFFFFFFFF                 0x1:                 0x1
N: 0    Z: 0
ANDS              0x1234              0x8765:               0x224
N: 0    Z: 0
AND          0x72DF9901          0x2E0B484A:          0x220B0800
N: 0    Z: 0
ASRS           0xAAA5555                 0x1:           0x5552AAA
N: 0    Z: 0
ASR          0xFFFFFFFF                 0x2:          0xFFFFFFFF
N: 0    Z: 0
ASRS              0x1234                 0x3:               0x91A
N: 1    Z: 0
ASR          0x72DF9901                 0x4:          0x396FCC80
N: 0    Z: 0
LSRS           0xAAA5555                 0x1:           0x5552AAA
N: 0    Z: 0
LSR          0xFFFFFFFF                 0x2:          0x3FFFFFFF
N: 0    Z: 0
LSRS              0x1234                 0x3:               0x246
N: 0    Z: 0
LSR          0x72DF9901                 0x4:           0x72DF990
N: 0    Z: 0
LSL           0xAAA5555                 0x1:          0x1554AAAA
N: 0    Z: 0
LSLS          0xFFFFFFFF                 0x2:          0xFFFFFFFC
N: 1    Z: 0
LSL              0x1234                 0x3:              0x91A0
N: 0    Z: 0
LSLS          0x72DF9901                 0x4:          0x2DF99010
N: 0    Z: 0
NOT           0xAAA5555                 0x0:          0xF555AAAA
N: 0    Z: 0
NOTS          0xFFFFFFFF                 0x0:                 0x0
N: 0    Z: 1
NOT              0x8765                 0x0:          0xFFFF789A
N: 0    Z: 0
NOTS          0x2E0B484A                 0x0:          0xD1F4B7B5
N: 1    Z: 0
ORR           0xAAA5555           0x555AAAA:           0xFFFFFFF
N: 0    Z: 0
ORRS          0xFFFFFFFF                 0x1:          0xFFFFFFFF
N: 1    Z: 0
ORR              0x1234              0x8765:              0x9775
N: 0    Z: 0
ORRS          0x72DF9901          0x2E0B484A:          0x7EDFD94B
N: 1    Z: 0
SUB           0xAAA5555           0x555AAAA:           0x554AAAB
N: 0    Z: 0
SUBS          0xFFFFFFFF                 0x1:          0xFFFFFFFE
N: 1    Z: 0
SUB              0x8765              0x1234:              0x7531
N: 0    Z: 0
SUBS          0x72DF9901          0x2E0B484A:          0x44D450B7
N: 0    Z: 0
XOR           0xAAA5555           0x555AAAA:           0xFFFFFFF
N: 0    Z: 0
XORS          0xFFFFFFFF                 0x1:          0xFFFFFFFE
N: 1    Z: 0
XOR              0x8765              0x1234:              0x9551
N: 0    Z: 0
XORS          0x72DF9901          0x2E0B484A:          0x5CD4D14B
N: 0    Z: 0

```


