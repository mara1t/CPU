#include "disasm_header.h"

#define DEF_CMD(name, num, argasm, argcp, argdis)   \
    case CMD_##name:                                \
        PRINTF_TXT("%s ", #name)                    \
        argdis                                      \
        break;


int main()
{
    FILE* transfile     = fopen("translated_in.txt", "rb");
    FILE* new_word_file = fopen("reading_file.txt", "w");

    if (new_word_file == NULL || transfile == NULL) 
    {
        printf("translated_file.txt not open = %d\nreading_file.txt not open = %d\n", new_word_file == NULL, transfile == NULL);
    }
    else 
    {
        int file_size = File_size(transfile);
        if (file_size < 0)
            return -1;

        if (disassemble (transfile, new_word_file, file_size) != 0)
        {
            printf("ERROR in disassembler\n");
        }
    }
    fclose(transfile);
    fclose(new_word_file);
    return 0;
}

int File_size (FILE* og) {

    if(og == NULL)
        return -1;

    fseek (og, 0, SEEK_END);
    ssize_t size = ftell (og);
    fseek (og, 0, SEEK_SET);

    return size;
}

int disassemble(FILE* transfile, FILE* new_word_file, const int file_size)
{
    int ip = 0;


    if (transfile == NULL || new_word_file == NULL)
        return -1;
    
    double* code = (double*) calloc(file_size, sizeof(double));

    if (fread(code, sizeof(double), file_size, transfile) == 0)
    {
        printf("NOT WRITTEN FILE\n");
        ERROR(-1)
    }

    while (ip < file_size)
    {   
        int comand = (int) code[ip++];
        int under_comand;

        switch(comand) 
        {
            #include "../cmd_def.h"

            default:
                free(code);
                ERROR(0)
        }
    }
    
    free(code);
    ERROR(0)
}

#undef DEF_CMD
