#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "..//cmd_enum.h"

#define STR_EQUAL(buf, push) strcmp(buf, push) == 0
#define CODE_PRINT(CMD_IN) fprintf(transfile, "%d", CMD_IN)

    

const int BASE_BUF_SIZE = 100;

int assemble    (FILE* inputfile, FILE* transfile);
