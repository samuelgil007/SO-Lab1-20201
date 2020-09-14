#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    for (size_t i = 1; i < argc; i++)
    {
        char lectura[1024];
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            printf("wcat: cannot open file\n");
            exit(1);
        }
        // del archivo fp leda todo el texto a lectura hasta el final (\r)
        fscanf(fp, " %[^\r]", lectura);
        printf("%s\n", lectura);

        fclose(fp);
    }
    return 0;
}