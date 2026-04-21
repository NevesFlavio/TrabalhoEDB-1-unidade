#include <stdio.h>
#include <iostream>
#include <deque>
#include <chrono>
using namespace std;
#include "interfaces.h"

typedef struct
{
    int tamanho;
    double tempo;
} TamanhoETempo;

deque<int> selectionSort(deque<int> lista)
{
    int tamanho = lista.size();

    for (int i = 0; i < tamanho; i++)
    {
        int indMin = i;

        for (int j = i + 1; j < tamanho; j++)
        {
            if (lista[j] < lista[i])
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
    deque<int> lista = {};

    for (int i = 0; i < tamanho; i++)
    {
        lista.push_back(vetor[i]);
    }

    const auto start{std::chrono::steady_clock::now()};

    lista = selectionSort(lista);

    const auto finish{chrono::steady_clock::now()};
    const chrono::duration<double> tempo{finish - start};

    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = lista[i];
    }

    return TamanhoETempo{tamanho, tempo.count()};
}
