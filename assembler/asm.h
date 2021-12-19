#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "..//cmd_enum.h"
#include "header_og.h"

int assemble    (FILE* inputfile, FILE* transfile);


const int BASE_BUF_SIZE = 100;

#define $$$ printf ("in line: %d\n", __LINE__);

struct labl {
    char *str_label;
    int to_ip;
};

#define STR_EQUAL(buf, push) strcmp(buf, push) == 0
#define CODE_PRINT(CMD_IN) fprintf(transfile, "%d", CMD_IN)

#define CHECK_ERR               \
    if (ip >= BASE_BUF_SIZE)    \
        ERROR(-1)               \

#define ERROR(a)                                    \
    {                                               \
        if (a == -1)                                \
        printf("ERROR in line %d\n", __LINE__);     \
        free(buffer);                               \
        free(buf);                                  \
        return a;                                   \
    }
    
#define DEF_FUN(name, ...)                                                          \
    if (STR_EQUAL(buf, #name))                                                      \
    {                                                                               \
        buffer[ip++] = CMD_##name;                                                  \
        int i = 0;                                                                  \
        int count = 0;                                                              \
        if (sscanf(each_str[str_num].str, "%*s %s", buf) != 1)                      \
            ERROR(-1)                                                               \
                                                                                    \
        if (pass == 1)                                                              \
        {                                                                           \
            while (i < labl_mass_counter)                                           \
            {                                                                       \
                if (strcmp(buf, labl_mass[i].str_label) == 0)                       \
                {                                                                   \
                    count = 1;                                                      \
                    buffer[ip++] = labl_mass[i].to_ip;                              \
                    break;                                                          \
                }                                                                   \
                i++;                                                                \
            }                                                                       \
            if (count == 0)                                                         \
                ERROR(-1)                                                           \
        }                                                                           \
        else if (pass == 0)                                                         \
        {                                                                           \
            char end_symb = 0;                                                      \
            sscanf(each_str[str_num].str, "%*s %*s %c", &end_symb);                 \
            if (end_symb != '\0')                                                   \
            {                                                                       \
                printf("Something is underflow in one string\n");                   \
                ERROR(-1)                                                           \
            }                                                                       \
            buffer[ip++] = -1;                                                      \
        }                                                                           \
                                                                                    \
        ++str_num;                                                                  \
        count = 0;                                                                  \
    }                                                                               \
    else

#define DEF_JMP(name, ...)                                                          \
    if (STR_EQUAL(buf, #name))                                                      \
    {                                                                               \
        buffer[ip++] = CMD_##name;                                                  \
        int i = 0;                                                                  \
        int count = 0;                                                              \
        if (sscanf(each_str[str_num].str, "%*s %s", buf) != 1)                      \
            ERROR(-1)                                                               \
                                                                                    \
        if (pass == 1)                                                              \
        {                                                                           \
            while (i < labl_mass_counter)                                           \
            {                                                                       \
                if (strcmp(buf, labl_mass[i].str_label) == 0)                       \
                {                                                                   \
                    count = 1;                                                      \
                    buffer[ip++] = labl_mass[i].to_ip;                              \
                    break;                                                          \
                }                                                                   \
                i++;                                                                \
            }                                                                       \
            if (count == 0)                                                         \
                ERROR(-1)                                                           \
        }                                                                           \
        else if (pass == 0)                                                         \
        {                                                                           \
            char end_symb = 0;                                                      \
            sscanf(each_str[str_num].str, "%*s %*s %c", &end_symb);                 \
            if (end_symb != '\0')                                                   \
            {                                                                       \
                printf("Something is underflow in one string\n");                   \
                ERROR(-1)                                                           \
            }                                                                       \
            buffer[ip++] = -1;                                                      \
        }                                                                           \
        ++str_num;                                                                  \
        count = 0;                                                                  \
    }                                                                               \
    else

#define DEF_CMD(name, num, args, ...)   \
    if (STR_EQUAL(buf, #name)) {        \
            args                        \
        str_num++;                      \
    }                                   \
    else



