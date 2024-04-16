/*Una empresa necesita simular la producción de los próximos 5 años para tal fin necesita
generar una matriz (estática) de 5x12 donde cada fila corresponde a un año y cada columna
es un mes. Ud. debe realizar las siguientes tareas:
a. Cargue dicha matriz con valores aleatorios entre 10000 y 50000.
b. Muestre por pantalla los valores cargados
c. Saque el promedio de ganancia por año y muestrelos por pantalla
d. Obtenga el valor máximo y el valor mínimo obtenido informando el “año” y el “mes” de
cuándo ocurrió.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILAS 5
#define COLUMNAS 12

int cargarMatriz();
void mostrarMatriz(int filas, int columnas, int matriz[filas][columnas]);
void calcularPromedioAnual(int filas, int columnas, int matriz[filas][columnas]);
int valorMinimo();
int valorMaximo();

int main()
{
    srand(time(NULL));
    int matrizEmpresa[FILAS][COLUMNAS];
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            matrizEmpresa[i][j] = cargarMatriz();
        }
    }
    mostrarMatriz(FILAS, COLUMNAS, matrizEmpresa);
}

int cargarMatriz()
{
    int valor = rand() % (50000 - 10000 + 1) + 10000;
    return valor;
}
void mostrarMatriz(int filas, int columnas, int matriz[filas][columnas])
{
    printf("\n");
    for (int i = 0; i < filas; i++)
    {
        printf("Anio %d:", i + 1);
        for (int j = 0; j < columnas; j++)
        {
            printf("|%6d$ ", matriz[i][j]);
        }
        printf("|\n");
    }
}
void calcularPromedioAnual(int filas, int columnas, int matriz[filas][columnas])
{
    int totalAnual = 0;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            totalAnual = matriz[i][j];

        }
    }
}
int valorMinimo()
{
}
int valorMaximo()
{
}