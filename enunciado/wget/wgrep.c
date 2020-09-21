#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

    FILE *fp;
    char buff[1024];
    char *word = argv[1]; //cogemos la palabra
    if (argc < 2)
    {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }
    if (argc < 3)
    {
            fp = stdin;
            fscanf(fp, "%s", buff);
            while (fgets(buff, 1024, fp))
            {
                if (strstr(buff, word) != NULL)
                {
                    printf("%s", buff);
                }
            }
    }

    if (strstr(" ", word) == NULL)
    {
        for (size_t i = 2; i < argc; i++)
        {
            fp = fopen(argv[i], "r");
            if (fp == NULL)
            {
                printf("wgrep: cannot open file\n");
                exit(1);
            }

            while (fgets(buff, 1024, fp))
            {
                if (strstr(buff, word) != NULL)
                {
                    printf("%s", buff);
                }
            }
            fclose(fp);
        }
    }

    return 0;
}
