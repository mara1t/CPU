#include <stdio.h>
//#define $$$ printf ("in line: %d\n", __LINE__);


struct Line
{
    int len;
    char* str;
};
char* file_read        (const int file_size, FILE* og);

int   File_size        (FILE* og);
int   Nstr             (const int file_size, const char *buffer);
void  line_pointer_len (const int file_size, char *buffer, struct Line* mystr);

int   compare_begin    (const void* stract1, const void* stract2); 
int   compare_end      (const void* stract1, const void* stract2);

void  free_member      (struct Line* mystr, char *buffer, FILE* file_onegin, FILE* file_output);
void  output_txt       (FILE* file_output, const int n_str, const struct Line* mystr);


