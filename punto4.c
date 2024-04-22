#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 100

char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
struct Producto
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef producto;

struct Cliente
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    producto *Productos;         // El tamaño de este arreglo depende de la variable "CantidadProductosAPedir"
} typedef cliente;

void cargarClientes(cliente *clientes, int cantidadClientes);
float costoTotalXProducto(cliente *clientes, int cantidadClientes, char *nombreProducto);
void mostrarDatos(cliente *clientes, int cantidadClientes);

int main()
{
    srand(time(NULL));
    int cantClientes, CantidadProductosAPedir;
    float totalXProducto;
    char nombreProducto[15];
    do
    {
        printf("Inserte la cantidad de clientes a atender\n");
        scanf("%d", &cantClientes);
        if (cantClientes > 5)
        {
            printf("Inserte la cantidad de clientes menor o igual a 5");
        }
    } while (cantClientes < 1 || cantClientes > 5);
    fflush(stdin);
    cliente *clientes = (cliente *)malloc(cantClientes * sizeof(cliente));
    cargarClientes(clientes, cantClientes);
    printf("Ingrese el nombre del producto del que desea conocer la ganancia total\n");
    scanf("%s", nombreProducto);
    totalXProducto = costoTotalXProducto(clientes, cantClientes, nombreProducto);
    printf("\nEl costo total del producto %s es: %.2f\n", nombreProducto, totalXProducto);
    mostrarDatos(clientes, cantClientes);
    for (int i = 0; i < cantClientes; i++)
    {
        free(clientes[i].Productos);
        free(clientes[i].NombreCliente);
    }
    free(clientes);
    return 0;
}

void cargarClientes(cliente *clientes, int cantidadClientes)
{
    cliente *auxCliente = clientes;
    char *buff = (char *)malloc(MAX * sizeof(char));
    for (int i = 0; i < cantidadClientes; i++)
    {
        auxCliente->ClienteID = i + 1;
        printf("Ingrese el nombre del cliente %d\n", auxCliente->ClienteID);
        scanf("%s", buff);
        auxCliente->NombreCliente = (char *)malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(auxCliente->NombreCliente, buff);
        auxCliente->CantidadProductosAPedir = rand() % 5 + 1;
        auxCliente->Productos = (producto *)malloc(auxCliente->CantidadProductosAPedir * sizeof(producto));
        for (int j = 0; j < auxCliente->CantidadProductosAPedir; j++)
        {
            auxCliente->Productos->ProductoID = j + 1;
            auxCliente->Productos->Cantidad = rand() % 10 + 1;
            auxCliente->Productos->TipoProducto = TiposProductos[rand() % 5];
            auxCliente->Productos->PrecioUnitario = rand() % 91 + 10;
            auxCliente->Productos++;
        }
        auxCliente->Productos -= auxCliente->CantidadProductosAPedir;
        auxCliente++;
    }
    auxCliente -= cantidadClientes;
    free(buff);
}

float costoTotalXProducto(cliente *clientes, int cantidadClientes, char *nombreProducto)
{
    float total = 0;
    for (int i = 0; i < cantidadClientes; i++)
    {
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            if (strcmp(nombreProducto, clientes[i].Productos[j].TipoProducto) == 0)
            {
                total += clientes[i].Productos[j].Cantidad * clientes[i].Productos[j].PrecioUnitario;
            }
        }
    }
    return total;
}

void mostrarDatos(cliente *clientes, int cantidadClientes)
{
    float totalAPagar = 0;
    for (int i = 0; i < cantidadClientes; i++)
    {
        printf("\nCliente ID: %d\n", clientes[i].ClienteID);
        printf("Nombre: %s\n", clientes[i].NombreCliente);
        printf("Cantidad de Productos a Pedir: %d\n", clientes[i].CantidadProductosAPedir);
        printf("Productos:\n");

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            totalAPagar += clientes[i].Productos[j].PrecioUnitario * clientes[i].Productos[j].Cantidad;
            printf("\tProducto ID: %d\n", clientes[i].Productos[j].ProductoID);
            printf("\tCantidad: %d\n", clientes[i].Productos[j].Cantidad);
            printf("\tTipo: %s\n", clientes[i].Productos[j].TipoProducto);
            printf("\tPrecio Unitario: $%.2f\n", clientes[i].Productos[j].PrecioUnitario);
            printf("\n");
        }
        printf("\tTotal a pagar el cliente %d: %.2f", clientes[i].ClienteID, totalAPagar);
        printf("\n--------------------------------------------------\n");
        totalAPagar = 0;
    }
}
