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
i) Desarrollar una interfaz por consola donde se solicite al usuario la cantidad de
clientes.
ii) Solicitar al usuario la carga de los clientes creados dinámicamente en el paso anterior.
iii) A medida que se dé de alta cada cliente, Generar aleatoriamente la cantidad de
productos asociados al cliente y sus características.
Ej: producto cargado nro. 2
Producto {
ProductoID=2
Cantidad = 1;
*TipoProducto = “Snack”;
PrecioUnitario = 100;
}
iv) Implemente una función que calcule el costo total de un producto. Esta función debe
recibir como parámetro el producto y devolver el resultado de calcular la Cantidad por
el PrecioUnitario.
v) Mostrar por pantalla todo lo cargado. Incluyendo un total a pagar por cliente
(sumatoria del costo de todos los productos)
cadena_destinoPágina 4
Taller de Lenguajes I – 2024
Programador Universitario / Licenciatura en Informática / Ingeniería en Informática
Trabajo Práctico N° 3
5) Modifique el ejercicio nro 3 para que, en lugar de ingresar un número fijo de nombres, el
usuario pueda indicar previamente la cantidad de nombres que ingresará a continuación.
6) ¿Qué es una wiki?¿Para que suele usarse? Investigue, cómo usar la wiki del github. Cargue
en la wiki de su repositorio todas las respuestas.
7) En la Wiki de su repositorio: explique con sus propias palabras cuál es la diferencia entre
memoria dinámica y estática. ¿Cuáles son las características de cada una? ¿En qué casos
se debe usar cada una?
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

int main()
{
    int cantClientes, CantidadProductosAPedir;
    cliente *clientes = (cliente *)malloc(cantClientes * sizeof(cliente));
    return 0;
}