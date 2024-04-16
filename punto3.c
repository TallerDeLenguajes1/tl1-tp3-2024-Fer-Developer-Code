#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CONSTANTE 5

int main()
{
    char **v, *buff;
    v = (char **)malloc(CONSTANTE * sizeof(char *));
    buff = (char *)malloc(100 * sizeof(char));
    for (int i = 0; i < CONSTANTE; i++)
    {
        printf("Ingrese el nombre que ira en la posicion %d\n", i + 1);
        gets(buff);
        fflush(stdin);
        v[i] = (char *)malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(v[i], buff);
    }
    for (int i = 0; i < CONSTANTE; i++)
    {
        printf("Nombre %d:", i+1);
        puts(v[i]);
    }
    free(buff);
    for (int i = 0; i < CONSTANTE; i++)
    {
        free(v[i]);
    }
    free(v);
    return 0;
}