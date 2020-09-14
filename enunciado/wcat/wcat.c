#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    
    FILE *fp;
    char buff[1024];
    for (size_t i = 1; i < argc; i++)
    {
        fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            printf("wcat: cannot open file\n");
            exit(1);
        }
        
        while (fgets(buff, 1024, fp))
        {
            printf("%s", buff);
        }
        fclose(fp);
    }
    return 0;
}