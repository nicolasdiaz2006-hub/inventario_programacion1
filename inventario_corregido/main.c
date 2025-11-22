#include <stdio.h>
#include "funciones.h"

int main() {
    char nombres[MAX][MAX_NOMBRE];
    float precios[MAX];
    int n;

    ingresarProductos(nombres, precios, &n);

    printf("\n--- RESULTADOS DEL INVENTARIO ---\n");

    printf("Precio total inventario: %.2f\n", calcularTotal(precios, n));
    printf("Precio promedio: %.2f\n", calcularPromedio(precios, n));

    int caro = productoMasCaro(precios, n);
    int barato = productoMasBarato(precios, n);

    printf("Producto mas caro: %s (%.2f)\n", nombres[caro], precios[caro]);
    printf("Producto mas barato: %s (%.2f)\n", nombres[barato], precios[barato]);

    char buscado[MAX_NOMBRE];
    printf("\nBuscar producto: ");
    scanf("%s", buscado);

    int pos = buscarProducto(nombres, precios, n, buscado);

    if (pos == -1)
        printf("No existe.\n");
    else
        printf("Precio de %s: %.2f\n", nombres[pos], precios[pos]);

    return 0;
}