#include "proc_header.h"

int main()
{
    FILE* outputfile = fopen("output.txt", "w");
    FILE* transfile  = fopen("translated_in.txt", "rb");

    if (outputfile == NULL || transfile == NULL)
        printf("output.txt not open = %d\ntranslated_file.txt not open = %d\n", outputfile == NULL, transfile == NULL);

    else
    {
        int file_size = File_size(transfile);

        if (Execute (outputfile, transfile, file_size) != 0)
            printf("ERROR in Executer\n");
    }


    fclose(transfile);
    fclose(outputfile);
    return 0;
}