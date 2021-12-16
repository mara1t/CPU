#include "dis.h"


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
            printf("ERROR in disassembler\n");
        
    }
    
    fclose(transfile);
    fclose(new_word_file);
    return 0;
}
