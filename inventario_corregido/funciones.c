#include <stdio.h>
#include "funciones.h"

// comparacion cadenas
int compararCadenas(char a[], char b[]) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return 0;
        i++;
    }
    return (a[i] == '\0' && b[i] == '\0');
}

// validar nombre sin numeros
int nombreValido(char nombre[]) {
    int i = 0;
    while (nombre[i] != '\0') {
        if (nombre[i] >= '0' && nombre[i] <= '9')
            return 0;
        i++;
    }
    return 1;
}

void ingresarProductos(char nombres[][MAX_NOMBRE], float precios[], int* n) {
    do {
        printf("Cantidad de productos (1-10): ");
        scanf("%d", n);
    } while (*n < 1 || *n > MAX);

    for (int i = 0; i < *n; i++) {
        do {
            printf("Nombre producto %d (solo letras): ", i+1);
            scanf("%s", nombres[i]);
        } while (!nombreValido(nombres[i]));

        printf("Precio producto %d: ", i+1);
        scanf("%f", &precios[i]);
    }
}

float calcularTotal(float precios[], int n) {
    float t = 0;
    for (int i = 0; i < n; i++)
        t += precios[i];
    return t;
}

float calcularPromedio(float precios[], int n) {
    if (n == 0) return 0;
    return calcularTotal(precios, n) / n;
}

int productoMasCaro(float precios[], int n) {
    int idx = 0;
    for (int i = 1; i < n; i++)
        if (precios[i] > precios[idx]) idx = i;
    return idx;
}

int productoMasBarato(float precios[], int n) {
    int idx = 0;
    for (int i = 1; i < n; i++)
        if (precios[i] < precios[idx]) idx = i;
    return idx;
}

int buscarProducto(char nombres[][MAX_NOMBRE], float precios[], int n, char nombreBuscado[]) {
    for (int i = 0; i < n; i++) {
        if (compararCadenas(nombres[i], nombreBuscado))
            return i;
    }
    return -1;
}