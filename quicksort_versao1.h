#ifndef QUICKSORT1_H
#define QUICKSORT1_H
#include <time.h>
#include <iostream>


void troca(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int CalculaPivo(int vetor[], int primeiro, int ultimo) 
{
    return vetor[primeiro];
}
int Particiona(int vetor[], int primeiro, int ultimo) 
{
    int pivo = CalculaPivo(vetor, primeiro, ultimo);
    int i = primeiro - 1;
    int j = ultimo + 1;

    while (1) {
        do {
            i++;
        } while (vetor[i] < pivo);

        do {
            j--;
        } while (vetor[j] > pivo);

        if (i >= j) {
            return j;
        }

        troca(&vetor[i], &vetor[j]);
    }
}

// Função QuickSort com recursão de cauda
void QuickSort1(int vetor[], int primeiro, int ultimo) {
    while (primeiro < ultimo) {
        int indicePivo = Particiona(vetor, primeiro, ultimo);

        if (indicePivo - primeiro < ultimo - indicePivo) {
            QuickSort1(vetor, primeiro, indicePivo);
            primeiro = indicePivo + 1;
        } else {
            QuickSort1(vetor, indicePivo + 1, ultimo);
            ultimo = indicePivo;
        }
    }
}
double Quick1(int *lista, int n)
 {
    clock_t inicio, fim;
    double tempo;

    inicio = clock(); // Marca o tempo de início

    QuickSort1(lista, 0, n - 1); // Chama a função de ordenação

    fim = clock(); // Marca o tempo de fim
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo em segundos

    return tempo;
}
#endif