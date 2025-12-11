#ifndef QUICKSORT2_H
#define QUICKSORT2_H
#include <time.h>
#include <iostream>

void troca2(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int CalculaPivo2(int vetor[], int primeiro, int ultimo) 
{
    int meio = primeiro + (ultimo - primeiro) / 2;
    int pivo = vetor[meio];
    return pivo;
}

int Particiona2(int vetor[], int primeiro, int ultimo) 
{
    int pivo = CalculaPivo2(vetor, primeiro, ultimo);
    int i = primeiro - 1;
    int j = ultimo + 1;

    while (1) 
    {
        do 
        {
            i++;
        } while (vetor[i] < pivo);

        do {
            j--;
        } while (vetor[j] > pivo);

        if (i >= j) 
        {
            return j;
        }

        troca2(&vetor[i], &vetor[j]);
    }
}
void QuickSort2(int vetor[], int primeiro, int ultimo) 
{
    while (primeiro < ultimo) 
    {
        int indicePivo = Particiona2(vetor, primeiro, ultimo);

        if (indicePivo - primeiro < ultimo - indicePivo)
        {
            QuickSort2(vetor, primeiro, indicePivo);
            primeiro = indicePivo + 1;
        } else {
            QuickSort2(vetor, indicePivo + 1, ultimo);
            ultimo = indicePivo;
        }
    }
}
double QuickM(int *lista, int n)
 {
    clock_t inicio, fim;
    double tempo;

    inicio = clock(); // Marca o tempo de início

    QuickSort2(lista, 0, n - 1); // Chama a função de ordenação

    fim = clock(); // Marca o tempo de fim
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC; 

    return tempo;
}
#endif