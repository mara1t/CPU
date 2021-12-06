#include <stdio.h>
#include <stdlib.h>
#include "..//cmd_enum.h"

#define PRINTF_TXT(d, push)                                 \
            {                                               \
                if (fprintf(new_word_file, d, push) == -1)  \
                                    ERROR(-1);              \
            }                                               \

#define ERROR(a)                                    \
    {                                               \
        free(code);                                 \
        return a;                                   \
    }

int File_size (FILE* og);
int disassemble(FILE* transfile, FILE* new_word_file, const int file_size);