#include "STACK//stk_header_for_proc.h"
#include <math.h>
#include <stdio.h>
#include "..//cmd_enum.h"


const int BASE_BUF_SIZE = 100;
const int REG_NUMBER = 4;

struct proces { 
    double RX[REG_NUMBER];
    double RAM[100];
};

int File_size   (FILE* og);
int Execute     (FILE* outputfile, FILE* transfile, int file_size);


#define $$$ printf ("in line: %d\n", __LINE__);

#define PUSH(a) StackPush(&stk, a)
#define POP StackPop(&stk)

#define FUNC_PUSH(a) StackPush(&func_stk, a)
#define FUNC_POP StackPop(&func_stk)

#define ERROR(a)                                    \
        free(code);                                 \
        return a;

#define DEF_FUN(name, num, argcp)                   \
    case CMD_##name:                                \
        argcp                                       \
        ip = (int) code[ip];                        \
        break;
  
#define DEF_JMP(name, num, condition, argcp)\
    case CMD_##name:                        \
        if (condition == 1)                 \
        {                                   \
            double a = POP;                 \
            double b = POP;                 \
            if (a argcp b)                  \
                ip = (int) code[ip];        \
            else                            \
                ip++;                       \
        }                                   \
        else                                \
            ip = (int) code[ip];            \
        break;

#define DEF_CMD(name, num, argasm, argcp, ...)\
    case CMD_##name:                          \
        argcp                                 \
        break;
