#ifndef QUICKSORT3_H
#define QUICKSORT3_H

#include <time.h>
#include <iostream>
#include <cstdlib> 

void troca3(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int calculaPivo3(int vetor[], int primeiro, int ultimo) 
{
    srand(time(nullptr)); 
    int indiceAleatorio = primeiro + rand() % (ultimo - primeiro + 1);
    troca3(&vetor[indiceAleatorio], &vetor[ultimo]);
    return vetor[ultimo]; 
}
int Particiona3(int vetor[], int primeiro, int ultimo) 
{
    int pivo = calculaPivo3(vetor, primeiro, ultimo);
    int i = primeiro - 1;
    int j = ultimo; 

    while (1) {
        do {
            i++;
        } while (vetor[i] < pivo);

        do {
            j--;
        } while (j >= primeiro && vetor[j] > pivo); 

        if (i >= j) {
            return i; 
        }

        troca3(&vetor[i], &vetor[j]);
    }
}

void QuickSort3(int vetor[], int primeiro, int ultimo) 
{
    while (primeiro < ultimo) 
    {
        int indicePivo = Particiona3(vetor, primeiro, ultimo);

        if (indicePivo - primeiro < ultimo - indicePivo) {
            QuickSort3(vetor, primeiro, indicePivo - 1);
            primeiro = indicePivo + 1;
        } else {
            QuickSort3(vetor, indicePivo + 1, ultimo);
            ultimo = indicePivo - 1;
        }
    }
}

double QuickSort3(int *lista, int n) 
{
    clock_t inicio, fim;
    double tempo;

    inicio = clock();

    QuickSort3(lista, 0, n - 1);

    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    return tempo;
}

#endif
