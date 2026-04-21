#include <iostream>
#include <chrono>
using namespace std;
#include "headers/mergesort.h"

void intercalar(int v[], int inicio1, int inicio2, int fim2)
{
    int fim1 = inicio2 - 1;
    int i = inicio1;
    int j = inicio2;
    int k = 0;

    int tamanho = fim2 - inicio1 + 1;
    int *tmp = new int[tamanho];

    while (i <= fim1 && j <= fim2)
    {
        if (v[i] <= v[j])
        {
            tmp[k] = v[i];
            i++;
        }
        else
        {
            tmp[k] = v[j];
            j++;
        }
        k++;
    }

    while (i <= fim1)
    {
        tmp[k] = v[i];
        i++;
        k++;
    }

    while (j <= fim2)
    {
        tmp[k] = v[j];
        j++;
        k++;
    }

    for (int x = 0; x < tamanho; x++)
    {
        v[inicio1 + x] = tmp[x];
    }

    delete[] tmp;
}

void mergeSort(int v[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = (inicio + fim) / 2;

        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);

        intercalar(v, inicio, meio + 1, fim);
    }
}

TamanhoETempo beforeMergeSort(int v[], int inicio, int fim)
{
    const int tamanho = fim + 1;
    auto tempoInicio = chrono::high_resolution_clock::now();

    mergeSort(v, inicio, fim);

    auto tempoFinal = chrono::high_resolution_clock::now();
    const chrono::duration<double> tempo{tempoFinal - tempoInicio};

    return TamanhoETempo{tamanho, tempo.count()};
}
