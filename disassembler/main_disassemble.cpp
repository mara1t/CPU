#include "disasm_header.h"

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
        int comand = (int)code[ip];
        ++ip;
        double under_comand;

        switch(comand) 
        {

            case CMD_PUSH:
            
                PRINTF_TXT("%s ", "push")
                PRINTF_TXT("%lg\n", code[ip++])
                break;
            
            case CMD_REGPUSH:
            
                PRINTF_TXT("%s ", "push")

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
                break;
            case CMD_MOV:

                PRINTF_TXT("%s ", "mov")
                under_comand = code[ip++];

                if (under_comand == RAX) {
                    PRINTF_TXT("%s ", "RAX")
                }
                else if (under_comand == RBX) {
                    PRINTF_TXT("%s ", "RBX")
                }
                else if (under_comand == RCX) {
                    PRINTF_TXT("%s ", "RCX")
                }
                else if (under_comand == RDX) {
                    PRINTF_TXT("%s ", "RDX")
                }
                else
                    ERROR(-1);

                PRINTF_TXT("%lg\n", code[ip++])
                break;
            case CMD_POP:

                PRINTF_TXT("%s ", "pop")
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
                    
                break;
            case CMD_ZERO_POP:
            
                PRINTF_TXT("%s\n", "pop")
                break;

            case CMD_OUT:
            
                PRINTF_TXT("%s\n", "out")
                break;
            case CMD_ADD:
            
                PRINTF_TXT("%s\n", "add")
                break;
            case CMD_SUB:
            
                PRINTF_TXT("%s\n", "sub")
                break;
            case CMD_MUL:
            
                PRINTF_TXT("%s\n", "mul")
                break;
            case CMD_DIV:
            
                PRINTF_TXT("%s\n", "divh")
                break;
            case CMD_SQRT:
            
                PRINTF_TXT("%s\n", "sqrt")
                break;
            case CMD_HLT:
            
                PRINTF_TXT("%s\n", "hlt")
                return 0;
            case CMD_IN:
            
                PRINTF_TXT("%s\n", "in") 
                break;
            case CMD_MINUS:
            
                PRINTF_TXT("%s\n", "minus")
                break;
            default:    ERROR(-1)
        }
    }
    
    ERROR(0)
}
