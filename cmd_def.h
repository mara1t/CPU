DEF_CMD(push, 1,
            double a = 0;
        
            if (fscanf(inputfile, "%lg", &a) != 1)
            {
                return -1;          
            }
            
            buffer[ip++] = a;
            
,
            PUSH(code[ip++]);
,
            PRINTF_TXT("%lg\n", code[ip++])
)


DEF_CMD(regpush, 11,
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

,
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
,
            under_comand = code[ip++];

            if (under_comand == RAX) {
                PRINTF_TXT("%s\n", "RAX")
            }
            else if (under_comand == RBX) {
                PRINTF_TXT("%s\n", "RBX")
            }
            else if (under_comand == RCX) {
                PRINTF_TXT("%s\n", "RCX")
            }
            else if (under_comand == RDX) {
                PRINTF_TXT("%s\n", "RDX")
            }
            else
                ERROR(-1);
)

DEF_CMD(regpop, 3,
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
           

,
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
,
            under_comand = code[ip++];

            if (under_comand == RAX) {
                PRINTF_TXT("%s\n", "RAX")
            }
            else if (under_comand == RBX) {
                PRINTF_TXT("%s\n", "RBX")
            }
            else if (under_comand == RCX) {
                PRINTF_TXT("%s\n", "RCX")
            }
            else if (under_comand == RDX) {
                PRINTF_TXT("%s\n", "RDX")
            }
            else
                ERROR(-1);
)

DEF_CMD(out, 5,
,
            fprintf(outputfile, "%lg\n", POP);
, 
            fprintf(new_word_file, "\n");
)

DEF_CMD(add, 6,
,
            PUSH(POP+POP);
, 
            fprintf(new_word_file, "\n");
)

DEF_CMD(sub, 4, 
,
            PUSH(POP - POP);
, 
            fprintf(new_word_file, "\n");
)

DEF_CMD(mul, 2,
,
            PUSH(POP * POP);
, 
            fprintf(new_word_file, "\n");
)

DEF_CMD(div, 7, 
,
            a = POP;  b = POP;

            if (b == 0)    ERROR(-1)

            PUSH(a / b);
, 
            fprintf(new_word_file, "\n");
)

DEF_CMD(sqrt, 8, 
,
            a = POP;
            if (a < 0)    ERROR(-1)      
            PUSH(sqrt(a));
, 
            fprintf(new_word_file, "\n");
)

DEF_CMD(hlt, -1, 
,
            ERROR(0)
, 
            fprintf(new_word_file, "\n");
)

DEF_CMD(in, 9, 
,
            if (scanf("%lg", &a) == 0)    ERROR(-1)

            PUSH(a);
, 
            fprintf(new_word_file, "\n");
)

DEF_CMD(minus, 10, 
,
            PUSH(-POP);
, 
            fprintf(new_word_file, "\n");
)

DEF_CMD(mov, 12, 

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
            
,
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
,
                under_comand = (int) code[ip++];
                
                switch(under_comand)
                {
                    case RAX:
                        PRINTF_TXT("%s ", "RAX")
                        break;

                    case RBX:
                        PRINTF_TXT("%s ", "RAX")
                        break;

                    case RCX:
                        PRINTF_TXT("%s ", "RAX")
                        break;

                    case RDX:
                        PRINTF_TXT("%s ", "RAX")
                        break;
                    
                    default:
                        ERROR(-1)
                        break;

                }

                PRINTF_TXT("%lg\n", code[ip++])
)

DEF_CMD(pop, 13,
,
            POP;
, 
            fprintf(new_word_file, "\n");
)

/*DEF_CMD(jae, 14,

            if (fscanf(inputfile, "%s", buf) != 1)
                return -1;
            

,
,
)*/


