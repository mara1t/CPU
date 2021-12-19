#include <stdio.h>
#include <assert.h>
#include "header_og.h"
#include <ctype.h>
#include <stdlib.h>

void free_member(struct Line* mystr, char *buffer, FILE* file_onegin, FILE* file_output) {

    free(mystr);
    free(buffer);
    free(file_output);
    fclose(file_onegin);
}

int File_size (FILE* og) {

    assert(og != NULL);

    fseek (og, 0, SEEK_END);
    ssize_t size = ftell (og);
    fseek (og, 0, SEEK_SET);

    return size;
}

char* file_read (const int file_size, FILE* og) {

    assert(og != NULL && file_size >= 1);

    char* buffer = (char *) calloc(file_size + 1, sizeof(char));
    if (buffer == NULL)
    {
        printf("ERROR, No free member");
        return NULL;
    }
    else
    {
        if (fread (buffer, sizeof(char), file_size, og) == 0)
        {
            printf("ERROR, No symbols in text file");
            abort();
        }
        buffer[file_size] = '\0';
        return buffer;
    }
}

void line_pointer_len (const int file_size, char *buffer, struct Line* mystr) {

    assert(buffer != NULL && file_size >= 1 && mystr != NULL);

    int symb_counter = 0, str = 0, len_counter = 0;
    for (str = 0; symb_counter < file_size; str++)
    {
        while ((buffer[symb_counter] == '\n' || buffer[symb_counter] == '\0' || buffer[symb_counter] == '\r') && symb_counter <= file_size)
        {
            symb_counter++;
            
        }
        
        if (symb_counter > file_size)
        {
            return;
        }
            
        len_counter = 0;
        mystr[str].str = buffer+symb_counter;

        
        while ( buffer[symb_counter] != '\n' && buffer[symb_counter] != '\0' && buffer[symb_counter] != '\r')
        {
            symb_counter++;
            len_counter++;
        }
        
        buffer[symb_counter] = '\0';
        symb_counter++;
        len_counter++;
        mystr[str].len = len_counter;
    }
}

int Nstr (const int file_size, const char *buffer) {

    assert(buffer != NULL && file_size >= 1);

    int symb_num = 0, n_str = 0, str_num = 0;

    for (str_num = 0; symb_num < file_size; str_num++)
    {
        while ((buffer[symb_num] == '\n' || buffer[symb_num] == '\r') && symb_num <= file_size)
        {
            symb_num++;
        }
        if (symb_num > file_size)
            break;

        while (buffer[symb_num] != '\n' && buffer[symb_num] != '\r' && symb_num < file_size)
            symb_num++;

        symb_num++;
        if (buffer[symb_num] == '\0')
            break;
    }
   
    n_str = str_num + 1;
    return n_str;
}

void output_txt (FILE* file_output, const int n_str, const struct Line* mystr) {

    assert(file_output != NULL && n_str >= 1 && mystr != NULL);

    for (int str_num = 0; str_num < n_str; str_num++)
    {
            fputs(mystr[str_num].str, file_output);
            fprintf(file_output, "\n");
    }

    for (int i = 0; i < 40; i++)
        fprintf(file_output, "*");

    fprintf(file_output, "\n");

}

int compare_begin (const void* stract1, const void* stract2) 
{
    int elem_num_one = -1, elem_num_two = -1;

    do
    {
        elem_num_one++;
        elem_num_two++;

        while (!isalpha(( (Line*) stract1)->str[elem_num_one]) && (( ( (Line*) stract1)->len) > elem_num_one))
            elem_num_one++;

        while (!isalpha(( (Line*) stract2)->str[elem_num_two]) && ((( (Line*) stract2)->len) > elem_num_two))   //(const struct Line*)
            elem_num_two++;

        if ((elem_num_one >= (( (Line*) stract1)->len)) || (elem_num_two >= (( (Line*) stract2)->len)))
            return -(elem_num_one >= (( (Line*) stract1)->len)) + (elem_num_two >= (( (Line*) stract2)->len));

    } while (( (Line*) stract1)->str[elem_num_one] ==  ( (Line*) stract2)->str[elem_num_two]);

    return ( (Line*) stract1)->str[elem_num_one] - ( (Line*) stract2)->str[elem_num_two];
}

int compare_end (const void* stract1, const void* stract2) 
{
    int elem_num_one = -1, elem_num_two = -1;

    do
    {
        elem_num_one++;
        elem_num_two++;

        while (!isalpha(( (Line*) stract1)->str[( (Line*) stract1)->len - 1 - elem_num_one]) && (( (Line*) stract1)->len > elem_num_one))
            elem_num_one++;

        while (!isalpha(( (Line*) stract2)->str[( (Line*) stract2)->len - 1 - elem_num_two]) && (( (Line*) stract2)->len > elem_num_two))
            elem_num_two++;

        if ((elem_num_one >= (( (Line*) stract1)->len)) || (elem_num_two >= (( (Line*) stract2)->len)))
            return -(elem_num_one >= (( (Line*) stract1)->len) ) + (elem_num_two >= (( (Line*) stract2)->len) );

    } while ( ( (Line*) stract1)->str[( (Line*) stract1)->len - 1 - elem_num_one] ==  ( (Line*) stract2)->str[( (Line*) stract2)->len - 1 - elem_num_two]);

    return ( (Line*) stract1)->str[( (Line*) stract1)->len - 1 - elem_num_one] -  ( (Line*) stract2)->str[( (Line*) stract2)->len - 1 - elem_num_two];
}

