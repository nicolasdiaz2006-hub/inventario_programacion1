#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX 10
#define MAX_NOMBRE 30

void ingresarProductos(char nombres[][MAX_NOMBRE], float precios[], int* n);
float calcularTotal(float precios[], int n);
float calcularPromedio(float precios[], int n);
int productoMasCaro(float precios[], int n);
int productoMasBarato(float precios[], int n);
int buscarProducto(char nombres[][MAX_NOMBRE], float precios[], int n, char nombreBuscado[]);
int compararCadenas(char a[], char b[]);
int nombreValido(char nombre[]);

#endif