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
void valorMinimo(int filas, int columnas, int matriz[filas][columnas]);
void valorMaximo(int filas, int columnas, int matriz[filas][columnas]);

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
    calcularPromedioAnual(FILAS, COLUMNAS, matrizEmpresa);
    valorMinimo(FILAS, COLUMNAS, matrizEmpresa);
    valorMaximo(FILAS, COLUMNAS, matrizEmpresa);
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
    float promedio;
    for (int i = 0; i < filas; i++)
    {
        int totalAnual = 0;
        for (int j = 0; j < columnas; j++)
        {
            totalAnual += matriz[i][j];
        }
        promedio = (float)totalAnual / 12;
        printf("\nEl promedio ganado en el anio %d es: %.2f", i + 1, promedio);
    }
}
void valorMinimo(int filas, int columnas, int matriz[filas][columnas])
{
    int long long minimo = 1000000;
    int valor, mes, anio;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            valor = matriz[i][j];
            if (valor < minimo)
            {
                minimo = valor;
                anio = i + 1;
                mes = j + 1;
            }
        }
    }
    printf("\nEl mes con la menor ganancia fue el mes: %d en el anio: %d con un valor de %d", mes, anio, matriz[anio - 1][mes - 1]);
}
void valorMaximo(int filas, int columnas, int matriz[filas][columnas])
{
    int maximo = 0;
    int valor, mes, anio;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            valor = matriz[i][j];
            if (valor > maximo)
            {
                maximo = valor;
                anio = i + 1;
                mes = j + 1;
            }
        }
    }
    printf("\nEl mes con la mayor ganancia fue el mes: %d en el anio: %d con un valor de %d", mes, anio, matriz[anio - 1][mes - 1]);
}