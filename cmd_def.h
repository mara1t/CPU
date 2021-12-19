DEF_FUN(call, 23,
            FUNC_PUSH(ip + 1);
)

DEF_CMD(ret, 24,
            char end_symb = 0;
            sscanf(each_str[str_num].str, "%*s %c", &end_symb);
            if (end_symb != '\0')
            {
                printf("Something is underflow in one string\n");
                ERROR(-1)   
            }
            buffer[ip++] = CMD_ret;
,
            ip = (int) FUNC_POP;  
,
            fprintf(new_word_file, "\n");
)

DEF_JMP(jmp, 14, 0, ==)

DEF_JMP(ja, 15, 1, >)

DEF_JMP(jae, 16, 1, >=)

DEF_JMP(jb, 17, 1, <)

DEF_JMP(jbe, 18, 1, <=)

DEF_JMP(je, 19, 1, ==)

DEF_JMP(jne, 20, 1, !=)



DEF_CMD(push, 1,
            
            double a = 0;
            int symb = 0;
            int ptr = -1;
            char reg_name[4];
            char *ptr_open;
            if (sscanf(each_str[str_num].str, "%*s %lg", &a) == 1)
            {
                char end_symb = 0;
                sscanf(each_str[str_num].str, "%*s %*lg %c", &end_symb);
                if (end_symb != '\0')
                {
                    printf("Something is underflow in one string\n");
                    ERROR(-1)   
                }
                buffer[ip++] = CMD_push; 
                CHECK_ERR
                buffer[ip++] = a;
            }
            else if ((ptr_open = strchr(each_str[str_num].str, '[')) != NULL)
            { 
                int ram_ip = 0;
                char *ptr_close;

                if ((ptr_close = strchr(each_str[str_num].str, ']')) != NULL)
                {
                    buffer[ip++] = CMD_oppush;
                    CHECK_ERR
                    if (pass == 1)
                    {
                        *ptr_open = *ptr_close = ' ';
                        if (sscanf(each_str[str_num].str, "%*s %d", &ram_ip) == 0)
                        {
                            ERROR(-1)
                        }
                        buffer[ip++] = ram_ip;
                        char end_symb = 0;
                        sscanf(each_str[str_num].str, "%*s %*d %*c %c", &end_symb);
                        if (end_symb != '\0')
                        {
                            printf("Something is underflow in one string\n");
                            ERROR(-1)   
                        }
                    }
                    else
                        buffer[ip++] = -1;
                }
                else 
                {
                    printf("ERROR IN OPPUSH");
                    ERROR(-1)
                }

            }      
            else if (sscanf(each_str[str_num].str, "%*s %s", reg_name) == 1)   
            {
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
                    printf("ERROR IN REGPUSH\n");
                    ERROR(-1)
                }  
                char end_symb = 0;
                sscanf(each_str[str_num].str, "%*s %*s %c", &end_symb);
                if (end_symb != '\0')
                {
                    printf("Something is underflow in one string\n");
                    ERROR(-1)   
                }
                buffer[ip++] = CMD_regpush;
                CHECK_ERR
                buffer[ip++] = ptr;  
            }
            else
            {
                printf("ERROR IN PUSH\n");
                ERROR(-1)
            }
,
            PUSH(code[ip++]);
,
            PRINTF_TXT("%lg\n", code[ip++])
)


DEF_CMD(regpush, 11,
            ERROR(-1)
,
            constant = code[ip++];
            switch (constant)
            {
                case RAX:
                    $$$
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

                    printf("ERROR IN REGPUSH\n");
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
            {
                printf("ERROR IN PUSH\n");
                ERROR(-1)
            }
)

DEF_CMD(oppush, 21,
            ERROR(-1)
,
            PUSH(registers.RAM[(int)code[ip++]]);
,
            PRINTF_TXT("[%lg]\n", code[ip++])
)

DEF_CMD(pop, 3,
            char reg_name[4];
            char *ptr_open;
            int b = 0;
            if ((ptr_open = strchr(each_str[str_num].str, '[')) != NULL)
            { 
                int ram_ip = 0;
                char *ptr_close;
                if ((ptr_close = strchr(each_str[str_num].str, ']')) != NULL)
                {
                    buffer[ip++] = CMD_oppop;
                    CHECK_ERR
                    if (pass == 1)
                    {
                        *ptr_open = ' ';
                        *ptr_close = ' ';
                        if (sscanf(each_str[str_num].str, "%*s %d", &ram_ip) == 0)
                        {
                            ERROR(-1)
                        }
                        char end_symb = 0;
                        sscanf(each_str[str_num].str, "%*s %*d %c %c", &end_symb);
                        if (end_symb != '\0')
                        {
                            printf("Something is underflow in one string\n");
                            ERROR(-1)   
                        }
                        buffer[ip++] = ram_ip;
                    }
                    else 
                    {
                        buffer[ip++] = -1;
                    }                
                }
                else 
                {
                    printf("ERROR IN OPPUSH");
                    ERROR(-1)
                }
                b = 1;

            }
            else if (sscanf(each_str[str_num].str, "%*s %s", reg_name))
            {
                int ptr = -1;
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
                    printf("ERROR IN REGPOP\n");
                    ERROR(-1)
                    
                }
                char end_symb = 0;
                sscanf(each_str[str_num].str, "%*s %*s %c", &end_symb);
                if (end_symb != '\0')
                {
                    printf("Something is underflow in one string\n");
                    ERROR(-1)   
                }
                buffer[ip++] = CMD_regpop;
                CHECK_ERR
                buffer[ip++] = ptr;

            }
            else 
            {
                char end_symb = 0;
                sscanf(each_str[str_num].str, "%*s %c", &end_symb);
                if (end_symb != '\0')
                {
                    printf("Something is underflow in one string\n");
                    ERROR(-1)   
                }
                buffer[ip++] = CMD_pop;
            }
,
            POP;
, 
            fprintf(new_word_file, "\n");
)


DEF_CMD(regpop, 13,
            ERROR(-1)
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

                    printf("ERROR IN REGPOP\n");
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
            {
                printf("ERROR IN REGPOP\n");
                ERROR(-1)
            }
)

DEF_CMD(oppop, 22,
            ERROR(-1)
,
            registers.RAM[(int) code[ip++]] = POP;
,
            PRINTF_TXT("[%lg]\n", code[ip++])
)

DEF_CMD(out, 5,
            char end_symb = 0;
            sscanf(each_str[str_num].str, "%*s %c", &end_symb);
            if (end_symb != '\0')
            {
                printf("Something is underflow in one string\n");
                ERROR(-1)   
            }
            buffer[ip++] = CMD_out;
,
            fprintf(outputfile, "%lg\n", POP);
, 
            fprintf(new_word_file, "\n");
)

DEF_CMD(add, 6,
            char end_symb = 0;
            sscanf(each_str[str_num].str, "%*s %c", &end_symb);
            if (end_symb != '\0')
            {
                printf("Something is underflow in one string\n");
                ERROR(-1)   
            }
            buffer[ip++] = CMD_add;

,
            PUSH(POP + POP);
, 
            fprintf(new_word_file, "\n");
)

DEF_CMD(sub, 4, 
            char end_symb = 0;
            sscanf(each_str[str_num].str, "%*s %c", &end_symb);
            if (end_symb != '\0')
            {
                printf("Something is underflow in one string\n");
                ERROR(-1)   
            }
            buffer[ip++] = CMD_sub;
,
            PUSH(POP - POP);
, 
            fprintf(new_word_file, "\n");
)

DEF_CMD(mul, 2,
            char end_symb = 0;
            sscanf(each_str[str_num].str, "%*s %c", &end_symb);
            if (end_symb != '\0')
            {
                printf("Something is underflow in one string\n");
                ERROR(-1)   
            }
            buffer[ip++] = CMD_mul;
,
            PUSH(POP * POP);
, 
            fprintf(new_word_file, "\n");
)

DEF_CMD(div, 7, 
            char end_symb = 0;
            sscanf(each_str[str_num].str, "%*s %c", &end_symb);
            if (end_symb != '\0')
            {
                printf("Something is underflow in one string\n");
                ERROR(-1)   
            }
            buffer[ip++] = CMD_div;
,
            a = POP;  b = POP;

            if (b == 0) 
            {
                printf("ERROR IN DIV\n");
                ERROR(-1)
            }

            PUSH(a / b);
, 
            fprintf(new_word_file, "\n");
)

DEF_CMD(sqrt, 8, 
            char end_symb = 0;
            sscanf(each_str[str_num].str, "%*s %c", &end_symb);
            if (end_symb != '\0')
            {
                printf("Something is underflow in one string\n");
                ERROR(-1)   
            }
            buffer[ip++] = CMD_sqrt;
,
            a = POP;
            if (a < 0) 
            {
                printf("ERROR IN SQRT\n");
                ERROR(-1)
            }      
            PUSH(sqrt(a));
, 
            fprintf(new_word_file, "\n");
)

DEF_CMD(hlt, -1, 
            char end_symb = 0;
            sscanf(each_str[str_num].str, "%*s %c", &end_symb);
            if (end_symb != '\0')
            {
                printf("Something is underflow in one string\n");
                ERROR(-1)   
            }
            buffer[ip++] = CMD_hlt;
,
            ERROR(0)
, 
            fprintf(new_word_file, "\n");
)

DEF_CMD(in, 9, 
            char end_symb = 0;
            sscanf(each_str[str_num].str, "%*s %c", &end_symb);
            if (end_symb != '\0')
            {
                printf("Something is underflow in one string\n");
                ERROR(-1)   
            }
            buffer[ip++] = CMD_in;
,
            if (scanf("%lg", &a) == 0) 
            {   
                printf("ERROR IN IN\n");
                ERROR(-1)
            }
            //printf("%lg", a);

            PUSH(a);
, 
            fprintf(new_word_file, "\n");
)

DEF_CMD(minus, 10, 
            char end_symb = 0;
            sscanf(each_str[str_num].str, "%*s %c", &end_symb);
            if (end_symb != '\0')
            {
                printf("Something is underflow in one string\n");
                ERROR(-1)   
            }
            buffer[ip++] = CMD_minus;
,
            PUSH(-POP);
, 
            fprintf(new_word_file, "\n");
)



DEF_CMD(mov, 12, 

            int ptr = -1; double a = 0;
            char reg_name[3];
            
            if (sscanf(each_str[str_num].str, "%*s%s", reg_name) != 1)
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
                printf("ERROR IN MOV\n");
                ERROR(-1)
            }
            buffer[ip++] = CMD_mov;
            CHECK_ERR
            buffer[ip++] = ptr;

            if (sscanf(each_str[str_num].str, "%*s%*s%lg", &a) != 1)
            {
                printf("ERROR in MOV\n");
                ERROR(-1)
            }
            char end_symb = 0;
            sscanf(each_str[str_num].str, "%*s %*s %*lg %c", &end_symb);
            if (end_symb != '\0')
            {
                printf("Something is underflow in one string\n");
                ERROR(-1)   
            }
            CHECK_ERR
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
                        printf("ERROR IN MOV\n");
                        ERROR(-1)
                        
                }

                PRINTF_TXT("%lg\n", code[ip++])
)
