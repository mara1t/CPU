#include "proc_header.h"
#define DEF_CMD(name, num, argasm, argcp)\
    case CMD_##name:\
        argcp\
        break;


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
    Stack stk = {};
    StackCtor(&stk, BASE_STK_SIZE);
    struct proces registers= {};

    if (transfile == NULL || outputfile == NULL)
        return -1;

    double* code = (double*) calloc(file_size, sizeof(double));

    if (code == NULL)
    {
        printf("NO MEMORY\n");
        ERROR(-1)
    }
    
    if (fread(code, sizeof(double), file_size, transfile) == 0)
    {
        printf("NOT WRITTEN FILE\n");
        ERROR(-1)
    }

    while (ip < BASE_BUF_SIZE)
    {   
        comand = code[ip++];
        double a; double b; int constant;
        int reg_name;
        double num = 0;
        
        switch (comand)
        {

            #include "..//cmd_def.h"
            
            default:
                ERROR(-1)
        };
    
    }
    
    ERROR(0)
}


/*case CMD_PUSH:

                PUSH(code[ip++]);
                break;

            case CMD_REGPUSH:

                
                constant = code[ip++];

                switch (constant)
                {
                    case RAX:

                        PUSH(registers.RX[0]);
                        break;
                    case RBX:

                        PUSH(registers.RX[1]);
                        break;
                    case RCX:
                        
                        PUSH(registers.RX[2]);
                        break;
                    case RDX:

                        PUSH(registers.RX[3]);
                        break;
                    default:

                        printf("ERROR IN PUSH\n");
                        ERROR(-1)
                        break;
                };

                break;

            case CMD_ZERO_POP :
                
                POP;
                break;
            
            case CMD_POP:
                
                
                constant = (int) code[ip++];

                switch (constant)
                {
                    case RAX:

                        registers.RX[0] = POP;
                        break;
                    case RBX:

                        registers.RX[1] = POP;
                        break;
                    case RCX:
                        
                        registers.RX[2] = POP;
                        break;
                    case RDX:

                        registers.RX[3] = POP;
                        break;
                    default:

                        printf("ERROR IN POP\n");
                        ERROR(-1)
                        break;
                };
                
                break;

            case CMD_MOV:
                
                constant = code[ip++];

                switch (constant)
                {
                    case RAX:

                        registers.RX[0] = code[ip++];
                        break;
                    case RBX:

                        registers.RX[1] = code[ip++];
                        break;
                    case RCX:
                        
                        registers.RX[2] = code[ip++];
                        break;
                    case RDX:

                        registers.RX[3] = code[ip++];
                        break;
                    default:

                        printf("ERROR IN MOV\n");
                        ERROR(-1)
                        break;
                };
                
                break;

            case CMD_OUT :
            
                fprintf(outputfile, "%lg\n", POP);
                break;   

            case CMD_ADD :

                PUSH(POP+POP);
                break; 

            case CMD_SUB :

                PUSH(POP - POP);
                break; 

            case CMD_MUL :

                PUSH(POP * POP);
                break; 

            case CMD_DIV :

                a = POP;  b = POP;

                if (b == 0)    ERROR(-1)

                PUSH(a / b);
                break; 

            case CMD_SQRT:

                a = POP;

                if (a < 0)    ERROR(-1)      

                PUSH(sqrt(a));
                break; 

            case CMD_HLT:

                ERROR(0)

            case CMD_IN:

                if (scanf("%lg", &a) == 0)    ERROR(-1)

                PUSH(a);
                break; 

            case CMD_MINUS:
            
                PUSH(-POP);
                break;
*/