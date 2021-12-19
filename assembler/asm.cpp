#include "asm.h"


int assemble(FILE* inputfile, FILE* transfile)
{
    if (transfile == NULL || inputfile == NULL)
        return -1;
    int ip = 0, counter_moving = 0;
    int str_num = 0;
    double *buffer = (double*) calloc(BASE_BUF_SIZE, sizeof(double));
    char *buf = (char*) calloc(100, sizeof(char));
    int *labels = (int*) calloc(100, sizeof(int));


    int onegin_size  = File_size(inputfile);
    char *onegin_buf = file_read(onegin_size , inputfile);
    int n_str        = Nstr (onegin_size, onegin_buf);

    struct Line* each_str = (struct Line*) calloc(n_str, sizeof(struct Line));

    line_pointer_len (onegin_size, onegin_buf, each_str);

    struct labl *labl_mass = (struct labl *) calloc(100, sizeof(struct labl));
    int labl_mass_counter = 0;

    for (int pass = 0; pass < 2; pass++)
    {   
        ip = 0;
        str_num = 0;

        while (ip >= 0 && ip < BASE_BUF_SIZE && str_num < n_str)
        {
            
            if (sscanf(each_str[str_num].str, "%s", buf) != 1)
                break;
                
            /*if (*buf == '\0')//buf[0] == '\0')
            {
                $$$
                str_num++;
                printf("YESSSS");
                continue;
            }*/
            
            if (buf[0] == ':' && pass == 0)
            {
                labl_mass[labl_mass_counter].str_label = (char*) calloc(100, sizeof(char));
                labl_mass[labl_mass_counter].str_label = strcpy(labl_mass[labl_mass_counter].str_label, buf);
                                
                labl_mass[labl_mass_counter].to_ip = ip;

                str_num++; 
                labl_mass_counter++;
                
                continue;
                        
            }
            else if (buf[0] == ':' && pass == 1)
            {
                str_num++;
                continue;
            }
            
            #include "..//cmd_def.h"
            
            {
                break;
            }
            
        }
        
    }

    fwrite(buffer, sizeof(double), ip, transfile);
    

    for (int free_count = 0; free_count < labl_mass_counter; free_count++)
        free(labl_mass[free_count].str_label);
        
    free(labels);
    free(labl_mass);
    free(onegin_buf);
    free(each_str);
    free(buffer);
    free(buf);

    return 0;
}

#undef DEF_FUN
#undef DEF_CMD
#undef DEF_JMP
