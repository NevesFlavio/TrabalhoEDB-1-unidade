#include <iostream>
#include <chrono>
using namespace std;
#include "headers/mergesort.h"

void intercalar(int v[], int inicio1, int inicio2, int fim2) // Função para intercalar os dois subvetores durante o MergeSort
{
    int fim1 = inicio2 - 1;
    int i = inicio1;
    int j = inicio2;
    int k = 0;

    int tamanho = fim2 - inicio1 + 1; // Tamanho do vetor temporário para armazenar os elementos intercalados
    int *tmp = new int[tamanho]; // Aloca um vetor temporário para armazenar os elementos intercalados

    while (i <= fim1 && j <= fim2) // Enquanto houver elementos em ambos os subvetores
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

    while (i <= fim1) // Se ainda houver elementos no primeiro subvetor, adiciona-os ao vetor temporário
    {
        tmp[k] = v[i];
        i++;
        k++;
    }

    while (j <= fim2) // Se ainda houver elementos no segundo subvetor, adiciona-os ao vetor temporário
    {
        tmp[k] = v[j];
        j++;
        k++;
    }

    for (int x = 0; x < tamanho; x++) // Copia os elementos intercalados de volta para o vetor original
    {
        v[inicio1 + x] = tmp[x];
    }

    delete[] tmp;
}

void mergeSort(int v[], int inicio, int fim) // Função recursiva para realizar o MergeSort
{
    if (inicio < fim)
    {
        int meio = (inicio + fim) / 2;

        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);

        intercalar(v, inicio, meio + 1, fim);
    }
}

TamanhoETempo beforeMergeSort(int v[], int inicio, int fim) // Função para medir o tempo gasto pelo MergeSort e retornar o tamanho do vetor e o tempo gasto
{
    const int tamanho = fim + 1;

    auto tempoInicio = chrono::high_resolution_clock::now();

    mergeSort(v, inicio, fim);

    auto tempoFinal = chrono::high_resolution_clock::now();

    chrono::duration<double> tempo = tempoFinal - tempoInicio;

    return TamanhoETempo{tamanho, tempo.count()};
}
