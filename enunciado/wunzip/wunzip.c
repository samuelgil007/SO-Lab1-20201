#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int byteAint(char numeroByte[4])
{
    //Conversion de array byte a int, metodo sacado de stackoverflow
    int x = (numeroByte[3] << 24) | (numeroByte[2] << 16) | (numeroByte[1] << 8) | numeroByte[0];
    return x;
}


int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }
    
    for (int i = 1; i < argc; i++)
    {
        int count = 1;
        char bin[4];
        char caracter;


        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            printf("wunzip: cannot open file\n");
            exit(1);
        }
        // 3a2b1c
        caracter = fgetc(fp);
        while (EOF != caracter)
        {
            if (count < 5)
            {
                bin[count - 1] = caracter;
            }
            else
            {
                count=0;
                int numeroInt = byteAint(bin);
                int i=0;
                while (i < numeroInt)
                {
                    printf("%c", caracter);
                    i++;
                }
                
                
            }
            caracter = fgetc(fp);
            count++;


        }

        fclose(fp);
    }

    return 0;
}
