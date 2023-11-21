
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generarArregloOrdenado(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i * 2;  
    }
}

double buscarSecuencial(int arr[], int n, int clave) {
    clock_t inicio, fin;
    inicio = clock();

    for (int i = 0; i < n; i++) {
        if (arr[i] == clave) {
            break;
        }
    }

    fin = clock();
    return ((double)(fin - inicio) / CLOCKS_PER_SEC) * 1000.0;
}

double buscarBinaria(int arr[], int n, int clave) {
    clock_t inicio, fin;
    inicio = clock();

    int izquierda = 0, derecha = n - 1;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (arr[medio] == clave) {
            break;
        }

        if (arr[medio] < clave) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }

    fin = clock();
    return ((double)(fin - inicio) / CLOCKS_PER_SEC) * 1000.0;
}

int main() {
    const int tamano = 50000;
    const int repeticiones = 100;
    int arreglo[tamano];

    generarArregloOrdenado(arreglo, tamano);

    
    printf("Busqueda Secuencial:\n");
    double tiempoTotalSecuencial = 0;
    double tiempoMinSecuencial = __DBL_MAX__;
    double tiempoMaxSecuencial = 0;

    for (int i = 0; i < repeticiones; i++) {
        int clave = rand() % (tamano * 2);  
        double tiempo = buscarSecuencial(arreglo, tamano, clave);

        tiempoTotalSecuencial += tiempo;
        tiempoMinSecuencial = (tiempo < tiempoMinSecuencial); tiempo1 : tiempoMinSecuencial;
        tiempoMaxSecuencial = (tiempo > tiempoMaxSecuencial); tiempo2 : tiempoMaxSecuencial;

        printf("Tiempo Secuencial %d: %f ms\n", i + 1, tiempo);
    }

    printf("\nEstadisticas Busqueda Secuencial:\n");
    printf("Tiempo promedio: %f ms\n", tiempoTotalSecuencial / repeticiones);
    printf("Tiempo minimo: %f ms\n", tiempoMinSecuencial);
    printf("Tiempo maximo: %f ms\n\n", tiempoMaxSecuencial);

    printf("Busqueda Binaria:\n");
    double tiempoTotalBinaria = 0;
    double tiempoMinBinaria = __DBL_MAX__;
    double tiempoMaxBinaria = 0;

    for (int i = 0; i < repeticiones; i++) {
        int clave = rand() % (tamano * 2);  
        double tiempo = buscarBinaria(arreglo, tamano, clave);

        tiempoTotalBinaria += tiempo;
        tiempoMinBinaria = (tiempo < tiempoMinBinaria);tiempo3 : tiempoMinBinaria;
        tiempoMaxBinaria = (tiempo > tiempoMaxBinaria);tiempo4 : tiempoMaxBinaria;

        printf("Tiempo Binario %d: %f ms\n", i + 1, tiempo);
    }

    printf("\nEstadisticas Busqueda Binaria:\n");
    printf("Tiempo promedio: %f ms\n", tiempoTotalBinaria / repeticiones);
    printf("Tiempo minimo: %f ms\n", tiempoMinBinaria);
    printf("Tiempo maximo: %f ms\n\n", tiempoMaxBinaria);

    return 0;
}


