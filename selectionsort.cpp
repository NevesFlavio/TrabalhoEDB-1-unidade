#include <stdio.h>
#include <iostream>
#include <deque>
#include <chrono>
using namespace std;
#include "headers/selectionsort.h"

deque<int> selectionSort(deque<int> lista)
{
    int tamanho = lista.size();

    for (int i = 0; i < tamanho; i++)
    {
        int indMin = i;

        for (int j = i + 1; j < tamanho; j++)
        {
            if (lista[j] < lista[indMin])
            {
                indMin = j;
            }
        }
        int aux = lista[i];
        lista[i] = lista[indMin];
        lista[indMin] = aux;
    }

    return lista;
}

TamanhoETempo beforeSelectionSort(int vetor[], int tamanho)
{
    deque<int> lista;

    for (int i = 0; i < tamanho; i++)
    {
        lista.push_back(vetor[i]);
    }

    auto tempoInicio = chrono::high_resolution_clock::now();

    lista = selectionSort(lista);

    auto tempoFinal = chrono::high_resolution_clock::now();
    chrono::duration<double> tempo = tempoFinal - tempoInicio;

    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = lista[i];
    }

    return TamanhoETempo{tamanho, tempo.count()};
}
