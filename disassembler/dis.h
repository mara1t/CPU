#include <stdio.h>
#include <stdlib.h>
#include "..//cmd_enum.h"


int File_size   (FILE* og);
int disassemble (FILE* transfile, FILE* new_word_file, const int file_size);


#define DEF_CMD(name, num, argasm, argcp, argdis)                       \
    case CMD_##name:                                                    \
        if (CMD_##name == CMD_regpush || CMD_##name == CMD_oppush)      \
            fprintf(new_word_file, "push ");                            \
        else if (CMD_##name == CMD_regpop || CMD_##name == CMD_oppop)   \
            fprintf(new_word_file, "pop ");                             \
        else                                                            \
            PRINTF_TXT("%s ", #name)                                    \
        argdis                                                          \
        break;

#define DEF_JMP(name, ...)                          \
    case CMD_##name:                                \
        PRINTF_TXT("%s ", #name)                    \
        PRINTF_TXT("%lg\n", code[ip++])             \
        break;

#define DEF_FUN(name, ...)                          \
    case CMD_##name:                                \
        PRINTF_TXT("%s ", #name)                    \
        PRINTF_TXT("%lg\n", code[ip++])             \
        break;

#define ERROR(a)                                    \
    {                                               \
        free(code);                                 \
        if (a == -1)                                \
        printf("ERROR in line %d", __LINE__);       \
        return a;                                   \
    }

#define PRINTF_TXT(d, push)                         \
    {                                               \
        if (fprintf(new_word_file, d, push) == -1)  \
            ERROR(-1)                               \
    }
