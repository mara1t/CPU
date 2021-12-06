#include "asm_header.h"

#define DEF_CMD(name, num, args, ...)\
    if (STR_EQUAL(buf, #name))\
    args\
    else

int assemble(FILE* inputfile, FILE* transfile)
{
    int ip = 0;
    double *buffer = (double*) calloc(BASE_BUF_SIZE, sizeof(double));

    if (transfile == NULL || inputfile == NULL)
        return -1;

    char buf[14] = "DEDEDEDEDEDED";

    while(1)
    {  

        if (fscanf(inputfile, "%s", buf) != 1)
            break;
        

        #include "..//cmd_def.h"

        break; 
    }
    
    fwrite(buffer, sizeof(double), ip, transfile);

    return 0;
}

#undef DEF_CMD

/*if (STR_EQUAL(buf, "push"))
        /*{
            int ptr = -1; char reg_name[3];
            double a = 0;

            if (fscanf(inputfile, "%lg", &a) == 1)
            {
                buffer[ip++] = CMD_PUSH;
                buffer[ip++] = a;            
            }
            else 
            {
                if (fscanf(inputfile, "%s", reg_name) != 1)
                    return -1;

                if (STR_EQUAL (reg_name, "RAX"))
                    ptr = RAX;

                else if (STR_EQUAL (reg_name, "RBX"))
                    ptr = RBX;

                else if (STR_EQUAL (reg_name, "RCX"))
                    ptr = RCX;

                else if (STR_EQUAL (reg_name, "RDX"))
                    ptr = RDX;

                else {
                   
                    ptr = -1;
                    printf("ERROR in PUSH\n");
                    return -1;
                }         

                buffer[ip++] = CMD_REGPUSH;
                buffer[ip++] = ptr;
            }
        }*/
        /*else if (STR_EQUAL(buf, "pop"))
        {
            int ptr = -1;
            char reg_name[14];

            
            if (fscanf(inputfile, "%s", reg_name) == 1)
            {
                //buffer[ip++] = CMD_ZERO_POP;
                //return 0;
            

                if (STR_EQUAL (reg_name, "RAX"))
                    ptr = RAX;

                else if (STR_EQUAL (reg_name, "RBX"))
                    ptr = RBX;

                else if (STR_EQUAL (reg_name, "RCX"))
                    ptr = RCX;

                else if (STR_EQUAL (reg_name, "RDX"))
                    ptr = RDX;

                else 
                {
                    strcpy (buf, reg_name);
                    buffer[ip++] = CMD_ZERO_POP;
                    pop_using = 1;
                    continue;
                    
                }

                buffer[ip++] = CMD_POP;
                buffer[ip++] = ptr;
            }
            else
            {
                    ptr = -1;
                    printf("ERROR in POP\n");
                    return -1;
            }

        }*/
        /*else if (STR_EQUAL(buf, "mov")) // mov
        {
            buffer[ip++] = CMD_MOV;

            int ptr = -1; double a = 0;
            char reg_name[3];
            
            if (fscanf(inputfile, "%s", reg_name) != 1)
                return -1;

            if (STR_EQUAL (reg_name, "RAX"))
                ptr = RAX;

            else if (STR_EQUAL (reg_name, "RBX"))
                ptr = RBX;

            else if (STR_EQUAL (reg_name, "RCX"))
                ptr = RCX;

            else if (STR_EQUAL (reg_name, "RDX"))
                ptr = RDX;

            else 
                ptr = -1;
    
            buffer[ip++] = ptr;

            if (fscanf(inputfile, "%lg", &a) != 1)
            {
                return -1; printf("ERROR in MOV\n");
            }
            buffer[ip++] = a;
            
        }*/
        /*else if (STR_EQUAL(buf, "out"))
        {
            buffer[ip++] = CMD_OUT;
        }*/
        /*else if (STR_EQUAL(buf, "add"))
        {
            buffer[ip++] = CMD_ADD;
        }*/
        /*else if (STR_EQUAL(buf, "sub"))
        {
            buffer[ip++] = CMD_SUB;
        }*/
        /*else if (STR_EQUAL(buf, "mul"))
        {
            buffer[ip++] = CMD_MUL;
        }*/
        /*else if (STR_EQUAL(buf, "div"))
        {
            buffer[ip++] = CMD_DIV;
        }*/
        /*(else if (STR_EQUAL(buf, "sqrt"))
        {
            buffer[ip++] = CMD_SQRT;
        }*/
        /*else if (STR_EQUAL(buf, "hlt"))
        {
            buffer[ip++] = CMD_HLT;
        }*/
        /*else if (STR_EQUAL(buf, "in"))
        {
            buffer[ip++] = CMD_IN; 
        }*/
       /**else if (STR_EQUAL(buf, "minus"))
        {
            buffer[ip++] = CMD_MINUS;
        }
        else if (STR_EQUAL(buf, "jmp"))
        {
            buffer[ip++] = CMD_JMP;
        }
        else if (STR_EQUAL(buf, "ja"))
        {
            buffer[ip++] = CMD_JA;
        }
        else if (STR_EQUAL(buf, "jae"))
        {
            buffer[ip++] = CMD_JAE;
        }
        else if (STR_EQUAL(buf, "jb"))
        {
            buffer[ip++] = CMD_JB;
        }
        else if (STR_EQUAL(buf, "jbe"))
        {
            buffer[ip++] = CMD_JBE;
        }**/
        
        //else    break;