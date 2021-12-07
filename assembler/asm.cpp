#include "asm_header.h"

#define DEF_CMD(name, num, args, ...) \
    if (STR_EQUAL(buf, #name)) {      \
        buffer[ip++] = CMD_##name;    \
        args                          \
    }                                 \
    else

int assemble(FILE* inputfile, FILE* transfile)
{
    int ip = 0;
    double *buffer = (double*) calloc(BASE_BUF_SIZE, sizeof(double));
    char *buf = (char*) calloc(14, sizeof(char));


    if (transfile == NULL || inputfile == NULL)
        return -1;
    

    while (ip < BASE_BUF_SIZE)
    {  

        if (fscanf(inputfile, "%s", buf) != 1)
            break;
        

        #include "..//cmd_def.h"

        break; 
    }
    
    fwrite(buffer, sizeof(double), ip, transfile);

    free(buffer);
    free(buf);
    return 0;
}

#undef DEF_CMD
