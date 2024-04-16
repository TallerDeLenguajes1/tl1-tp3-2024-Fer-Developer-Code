#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *v[5], *buff;
    buff = (char *)malloc(100 * sizeof(char));
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre que ira en la posicion %d\n", i + 1);
        gets(buff);
        fflush(stdin);
        v[i] = (char *)malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(v[i], buff);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("Nombre %d:", i+1);
        puts(v[i]);
    }
    free(buff);
    for (int i = 0; i < 5; i++)
    {
        free(v[i]);
    }
    return 0;
}