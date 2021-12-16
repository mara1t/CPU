#include "dis.h"


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
    if (transfile == NULL || new_word_file == NULL || file_size % 8 != 0)
        return -1;

    int ip = 0;

    double* code = (double*) calloc(file_size / sizeof(double), sizeof(double));

    if (fread(code, sizeof(double), file_size / sizeof(double), transfile) == 0)
    {
        printf("NOT WRITTEN FILE\n");
        ERROR(-1)
    }

    while (ip < file_size / 8)
    {   
        int comand = (int) code[ip++];
        int under_comand;

        switch(comand) 
        {
            #include "../cmd_def.h"

            default:
                //#undef DEF_JMP
                //#undef DEF_CMD
                ERROR(0)
        }
    
    }
    
    free(code);
    
    return 0;
}

#undef DEF_JMP
#undef DEF_FUN
#undef DEF_CMD
