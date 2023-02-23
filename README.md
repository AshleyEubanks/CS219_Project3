# CS219_Project1

How to run the code: in terminal type commands:
```
make
./Proj1
```
How the code works:

There are two functions along with main. The first one is AddHex, which takes in the hex numbers to be added and adds them together, returning the sum. The other function is the display function, which takes in a string (the type of operation), and three uint32_t variables (1st number, 2nd number, and the answer). This way if another function were to be added for say, subtraction, it can be displayed by calling a functoin instead of containing its own implementation of the same functionality. In main, after new numbers are assigned to the variables, the AddHex function is called then the display function. 

Output:
The out put is correct because 
```
0x1 + 0x1 = 0x2
0xAAA5555 + 0x555AAAA = 0xFFFFFFF
0xFFFFFFFF + 0x1 = 0x100000000 but the variable uint32_t only holds 32 bits so it prints out 0x0 and has an overflow of 1
0x1234 + 0x8765 = 0x9999
0x72DF9901 + 0x2E0B484A = 0xA0EAE14B

```

Overflow:
Only 0xFFFFFFFF + 0x1 had overflow 

