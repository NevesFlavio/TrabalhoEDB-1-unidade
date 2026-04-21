#include <iostream>
#include <chrono>
#include "interfaces.h"

void vetores(int v[], int tamanho, int i);
TamanhoETempo beforeMergeSort(int v[], int inicio, int fim);
TamanhoETempo beforeSelectionSort(int v[], int tamanho);

using namespace std;

void imprimirLista(int v[], int tamanho, bool ordenacao)
{
    if (ordenacao)
    {
        cout << "Vetor " << tamanho << " (DESORDENADO):\n";
    }
    else
    {
        cout << "Vetor " << tamanho << " (ORDENADO):\n";
    }

    for (int j = 0; j < tamanho; j++)
            cout << v[j] << " ";
        cout << "\n\n";
}

int main()
{
    // int tamanhos[4] = {10, 100, 1000, 10000};
    int tamanhos[4] = {10, 10, 10, 10};

    for (int i = 0; i < 4; i++)
    {

        int v1[tamanhos[i]];
        int n1 = tamanhos[i];

        vetores(v1, n1, 0);

        imprimirLista(v1, n1, false);

        // TamanhoETempo resultadoMergeSort = beforeMergeSort(v1, 0, n1 - 1);
        TamanhoETempo resultadoSelectionSort = beforeSelectionSort(v1, n1);

        imprimirLista(v1, n1, true);
    }

    return 0;
}