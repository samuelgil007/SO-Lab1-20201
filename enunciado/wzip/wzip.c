#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void escritura(int contador, char anterior)
{
    fwrite(&contador, 1, sizeof(contador), stdout);
    printf("%c", anterior);
}

int main(int argc, char *argv[])
{
    char anterior;
    char actual;
    int contador = 1;
    int esPrimero = 1;
    FILE *fp;

    if (argc == 1)
    {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++)
    {
        fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            exit(1);
        }

        actual = fgetc(fp);
        while (actual != EOF)
        {
            if (actual != anterior)
            {
                if (esPrimero != 1)
                {
                    escritura(contador, anterior);
                }
                contador = 1;
            }
            else
            {
                contador += 1;
            }
            anterior = actual;
            actual = fgetc(fp);
            esPrimero = 0;
        }
        fclose(fp);
    }
    escritura(contador, anterior);
    return 0;
}

