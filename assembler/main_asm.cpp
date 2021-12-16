#include "asm.h"


int main()
{
    FILE* inputfile = fopen("input.txt", "r");
    FILE* transfile = fopen("translated_in.txt", "wb");

    if (inputfile == NULL || transfile == NULL)
        printf("input.txt not open = %d\n\
                translated_file.txt not open = %d\n", inputfile == NULL, transfile == NULL);
    
    else if (assemble (inputfile, transfile) != 0)
        printf("ERROR in assembler\n");

    
    fclose(transfile);
    fclose(inputfile);
    return 0;
}
