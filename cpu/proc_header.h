//#include "C://Users//User//Desktop//proc//cpu//STACK//stk_header_for_proc.h"
#include "STACK//stk_header_for_proc.h"
#include <math.h>
#include <stdio.h>
//#include "C://Users//User//Desktop//proc//enum.h"
#include "..//cmd_enum.h"

#define PUSH(a) StackPush(&stk, a)
#define POP StackPop(&stk)

#define ERROR(a)                                    \
    {                                               \
        free(code);                                 \
        return a;                                   \
    }

const int BASE_BUF_SIZE = 100;
const int REG_NUMBER = 4;

struct proces { 
    double RX[REG_NUMBER];
};

int File_size (FILE* og);
int Execute (FILE* outputfile, FILE* transfile, int file_size);

