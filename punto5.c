#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int cantidadNom;
    printf("Ingrese la cantidad de nombres que va a escribir\n");
    scanf("%d", &cantidadNom);
    fflush(stdin);
    char **v, *buff;
    v = (char **)malloc(cantidadNom * sizeof(char *));
    buff = (char *)malloc(100 * sizeof(char));
    for (int i = 0; i < cantidadNom; i++)
    {
        printf("Ingrese el nombre que ira en la posicion %d\n", i + 1);
        gets(buff);
        fflush(stdin);
        v[i] = (char *)malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(v[i], buff);
    }
    for (int i = 0; i < cantidadNom; i++)
    {
        printf("Nombre %d:", i+1);
        puts(v[i]);
    }
    free(buff);
    for (int i = 0; i < cantidadNom; i++)
    {
        free(v[i]);
    }
    free(v);
    return 0;
}