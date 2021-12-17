#include "proc.h"


int File_size (FILE* og) {

    assert(og != NULL);

    fseek (og, 0, SEEK_END);
    ssize_t size = ftell (og);
    fseek (og, 0, SEEK_SET);

    return size;
}

int Execute(FILE* outputfile, FILE* transfile, int file_size)
{
    int comand = 0, ip = 0;
    Stack stk = {}; //TODO in struct
    Stack func_stk = {};
    StackCtor(&stk, BASE_STK_SIZE);
    StackCtor(&func_stk, BASE_STK_SIZE);
    struct proces registers = {};

    if (transfile == NULL || outputfile == NULL)
        return -1;

    double* code = (double*) calloc(file_size / sizeof(double), sizeof(double));

    if (code == NULL)
    {
        printf("NO MEMORY\n");
        ERROR(-1)
    }
    
    if (fread(code, sizeof(double), file_size / sizeof(double), transfile) == 0)
    {
        printf("NOT WRITTEN FILE\n");
        ERROR(-1)
    }

    while (ip < BASE_BUF_SIZE)
    {   
        comand = (int) code[ip++];
        double a, b, num = 0; 
        int constant, reg_name;
        
        switch (comand)
        {

            #include "..//cmd_def.h"
            
            default:
                printf("ip=%d\n", ip);
                break;
                //ERROR(-1)
        };
    
    }
    
    free(code);

    return 0;
}

#undef DEF_FUN
#undef DEF_JMP
#undef DEF_CMD
