#ifndef MERGE_H
#define MERGE_H
#include <time.h>
#include <iostream>

//combina os subarrays
void merges(int vetor[], int comeco, int meio, int fim) 
{
    //percorrer duas metades array 
    int com1 = comeco, com2 = meio + 1, comAux = 0, tam = fim - comeco + 1;
    int *vetAux;

    //armazenar elementos combinados
    vetAux = (int *)malloc(tam * sizeof(int));
    if (vetAux == NULL) 
    {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    //percorre as metadaes e copia o menor 
    while (com1 <= meio && com2 <= fim) 
    { 
        if (vetor[com1] < vetor[com2]) 
        {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }
    //copia em aux 1 metade, se tiver
    while (com1 <= meio)
    {
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    } 
    //copia em aux 2 metade, se tiver 
    while (com2 <= fim)
     {
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }
    //copia vetaux no principal 
    for(comAux = comeco; comAux <= fim; comAux++) 
    {
        vetor[comAux] = vetAux[comAux - comeco];
    }

    free(vetAux); 
}

//divide os subarrays 
void mergeSort(int vetor[], int comeco, int fim)
 {
    if (comeco < fim)
    {
        int meio = (fim + comeco) / 2;

        mergeSort(vetor, comeco, meio); 
        mergeSort(vetor, meio + 1, fim); 

    //combina as duas metades em 1
        merges(vetor, comeco, meio, fim);
    }
}

double MergeSort(int *lista, int n)
{
    clock_t inicio, fim;
    double tempo;

    inicio = clock();

    //função recursiva para ordenar
    mergeSort(lista, 0, n - 1);

    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    return tempo;
}
#endif