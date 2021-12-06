DEF_CMD(push, 1, 
{          
            buffer[ip++] = CMD_push;
            double a = 0;
        
            if (fscanf(inputfile, "%lg", &a) != 1)
            {
                return -1;          
            }
            
            buffer[ip++] = a;
            
},
            PUSH(code[ip++]);
)


DEF_CMD(regpush, 11, 
{
            buffer[ip++] = CMD_regpush;
            int ptr = -1; char reg_name[3];

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
                return -1;
            }     
            
            buffer[ip++] = ptr;    

},
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
)

DEF_CMD(regpop, 3,
{
            buffer[ip++] = CMD_regpop;
            int ptr = -1;
            char reg_name[14];
            
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
            {
                return -1;
                
            }
            
            buffer[ip++] = ptr;
           

},
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
)

DEF_CMD(out, 5,
{
            buffer[ip++] = CMD_out;
},
            fprintf(outputfile, "%lg\n", POP);
)

DEF_CMD(add, 6,
{
            buffer[ip++] = CMD_add;
},
            PUSH(POP+POP);
)

DEF_CMD(sub, 4, 
{
            buffer[ip++] = CMD_sub;
},
            PUSH(POP - POP);
)

DEF_CMD(mul, 2,
{
            buffer[ip++] = CMD_mul;
},
            PUSH(POP * POP);
)

DEF_CMD(div, 7, 
{
            buffer[ip++] = CMD_div;
},
            a = POP;  b = POP;

            if (b == 0)    ERROR(-1)

            PUSH(a / b);
)

DEF_CMD(sqrt, 8, 
{
            buffer[ip++] = CMD_sqrt;
},
            a = POP;
            if (a < 0)    ERROR(-1)      
            PUSH(sqrt(a));
)

DEF_CMD(hlt, -1, 
{
            buffer[ip++] = CMD_hlt;
},
            ERROR(0)
)

DEF_CMD(in, 9, 
{
            buffer[ip++] = CMD_in; 
},
            if (scanf("%lg", &a) == 0)    ERROR(-1)

                PUSH(a);
)
DEF_CMD(minus, 10, 
{
            buffer[ip++] = CMD_minus;
},
            PUSH(-POP);
)

DEF_CMD(mov, 12, 
{
            buffer[ip++] = CMD_mov;

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
            
},
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
)

DEF_CMD(pop, 13,
{
            buffer[ip++] = CMD_pop;
},
            POP;
)


