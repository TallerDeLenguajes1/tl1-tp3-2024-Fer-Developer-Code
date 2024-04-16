/*
4) Considere la siguiente situación: En una distribuidora necesita implementar la carga de
productos de sus preventistas, los cuales recolectan los productos que sus clientes van
necesitando. El sistema que se utiliza en la empresa es desarrollado por equipos de
programadores donde cada equipo se encarga de una tarea específica. Usted forma parte del
equipo de programación que se encargará de hacer el módulo para los preventistas:
Tareas:
Cada preventista puede visitar hasta 5 clientes, los cuales por cuestiones operativas solo
puede pedir hasta 10 productos
Las estructuras de datos necesarias son las siguientes:
*/
#include <stdio.h>
#include <stdlib.h>

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
    producto *Productos          // El tamaño de este arreglo depende de la variable
    // "CantidadProductosAPedir"
} typedef cliente;

int main(){
    return 0;
}