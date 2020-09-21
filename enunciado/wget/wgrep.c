#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    
    FILE *fp;
    char buff[1024];
    char* word = argv[1]; //cogemos la palabra
    if(argc < 3){
          printf("wgrep: searchterm [file ...]");
          exit(1);
    }
    
    for (size_t i = 2; i < argc; i++)
    {
        fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            printf("wgrep: cannot open file");
            exit(1);
        }
        
        while (fgets(buff, 1024, fp))
        {   
            if(strstr(buff,word) != NULL){
                printf("%s", buff);
            }
            
        }
        fclose(fp);
    }
    return 0;
}