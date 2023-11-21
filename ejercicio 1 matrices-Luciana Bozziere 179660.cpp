#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void llenarMatriz(int matriz[30][30]) 
{
    srand(time(NULL));
    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 30; ++j) {
            matriz[i][j] = rand() % 10;
        }
    }
}

void mostrarMatriz(int matriz[30][30]) 
{
    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 30; ++j) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void multiplicarMatrices(int matrizA[30][30], int matrizB[30][30], int resultado[30][30]) 
{
    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 30; ++j) {
            resultado[i][j] = 0;
            for (int k = 0; k < 30; ++k) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

int main()
 {
    int matrizA[30][30];
    int matrizB[30][30];
    int resultado[30][30];

    llenarMatriz(matrizA);
    llenarMatriz(matrizB);

    printf("Matriz A:\n");
    mostrarMatriz(matrizA);

    printf("Matriz B:\n");
    mostrarMatriz(matrizB);

    clock_t tic = clock();

    multiplicarMatrices(matrizA, matrizB, resultado);

    clock_t toc = clock();
    double tiempo = ((double)(toc - tic) / CLOCKS_PER_SEC) * 1000.0;

    printf("Resultado de la multiplicación:\n");
    mostrarMatriz(resultado);

    printf("Tiempo de ejecucion: %f milisegundos\n", tiempo);
    return 0;
}

