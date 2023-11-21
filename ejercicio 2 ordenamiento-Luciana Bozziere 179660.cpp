#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tamano 10000

void insertionsort (int A[], int n) 
{
    int i, key, j;
    for (i = 1; i < n; i++) 
	{
        key = A [i];
        j = i - 1;
        while (j >= 0 && A [j] > key) 
		{
            A [j + 1] = A [j];
            j = j - 1;
        }
        A [j + 1] = key;
    }
}
void quicksort(int A [], int low, int high) 
{
    if (low < high) 
	{
        int pivot = A [high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) 
		{
            if (A [j] < pivot) 
			{
                i++;
                int temp = A [i];
                A [i] = A [j];
                A [j] = temp;
            }
        }
        int temp = A [i + 1];
        A [i + 1] = A [high];
        A [high] = temp;
        int pi = i + 1;
        quicksort(A, low, pi - 1);
        quicksort(A, pi + 1, high);
    }
}
void bubblesort(int A [], int n) 
{
    for (int i = 0; i < n - 1; i++) 
	{
        for (int j = 0; j < n - i - 1; j++) 
		{
            if (A [j] > A [j + 1]) 
			{
                int temp = A [j];
                A [j] = A [j + 1];
                A [j + 1] = temp;
            }
        }
    }
}
void generaarreglo(int A [], int n) 
{
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        A [i] = rand() % tamano;
    }
}
int main() 
{
    int A [tamano];
    clock_t inicio, fin;
    double tiempo;
    generaarreglo(A, tamano);
    double tinsertion[100], tquick[100], tbubble[100];
    printf("Insertion Sort:\n");
    for (int i = 0; i < 100; i++) {
        int temparreglo [tamano];
        for (int j = 0; j < tamano; j++) 
		{
            temparreglo [j] = A [j];
        }
        inicio = clock();
        insertionsort (temparreglo, tamano);
        fin = clock();

        tiempo = ((double)(fin - inicio)) * 1000.0 / CLOCKS_PER_SEC;
        tinsertion[i] = tiempo;
        printf("Ejecucion %d: %f ms\n", i + 1, tiempo);
    }
    printf("\n Quick Sort:\n");
    for (int i = 0; i < 100; i++) 
	{
        int temparreglo [tamano];
        for (int j = 0; j < tamano; j++) 
		{
            temparreglo [j] = A [j];
        }
        inicio = clock();
        quicksort(temparreglo, 0, tamano - 1);
        fin = clock();
        tiempo = ((double)(fin - inicio)) * 1000.0 / CLOCKS_PER_SEC;
        tquick[i] = tiempo;
        printf("Ejecucion %d: %f ms\n", i + 1, tiempo);
    }
    printf("\n Bubble Sort:\n");
    for (int i = 0; i < 100; i++) 
	{
        int temparreglo [tamano];
        for (int j = 0; j < tamano; j++) 
		{
            temparreglo [j] = A [j];
        }
        inicio = clock();
        bubblesort (temparreglo , tamano);
        fin = clock();
        tiempo = ((double)(fin - inicio)) * 1000.0 / CLOCKS_PER_SEC;
        tbubble[i] = tiempo;
        printf("Ejecucion %d: %f ms\n", i + 1, tiempo);
    }
    double sumainsertion = 0, sumaquick = 0, sumabubble = 0;
    double mininsertion = tinsertion[0], minquick = tquick[0], minbubble = tbubble[0];
    double maxinsertion = tinsertion[0], maxquick = tquick[0], maxbubble = tbubble[0];
    for (int i = 0; i < 100; i++) {
        sumainsertion += tinsertion[i];
        sumaquick += tquick[i];
        sumabubble += tbubble[i];
        if (tinsertion[i] < mininsertion) mininsertion = tinsertion[i];
        if (tinsertion[i] > maxinsertion) maxinsertion = tinsertion[i];
        if (tquick[i] < minquick) minquick = tquick[i];
        if (tquick[i] > maxquick) maxquick = tquick[i];
        if (tbubble[i] < minbubble) minbubble = tbubble[i];
        if (tbubble[i] > maxbubble) maxbubble = tbubble[i];
    }
    printf ("\nEstadisticas de cada algoritmo:\n");
    printf ("\n");
    printf ("Insertion Sort:\n");
    printf ("Tiempo promedio: %f ms\n", sumainsertion / 100);
    printf ("Tiempo minimo: %f ms\n", mininsertion);
    printf ("Tiempo maximo: %f ms\n", maxinsertion);
    printf ("\n");
    printf ("Quick Sort:\n");
    printf ("Tiempo promedio: %f ms\n", sumaquick / 100);
    printf ("Tiempo minimo: %f ms\n", minquick);
    printf ("Tiempo maximo: %f ms\n", maxquick);
    printf ("\n");
    printf ("Bubble Sort:\n");
    printf ("Tiempo promedio: %f ms\n", sumabubble / 100);
    printf ("Tiempo minimo: %f ms\n", minbubble);
    printf ("Tiempo maximo: %f ms\n", maxbubble);
    return 0;
}
