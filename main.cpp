#include <iostream>
#include <chrono>
// #include "interfaces.h"

#include "mergesort.cpp"
#include "selectionsort.cpp"
#include "vetores.cpp"

void vetores(int v[], int tamanho, int i);
TamanhoETempo beforeMergeSort(int v[], int inicio, int fim);
TamanhoETempo beforeSelectionSort(int v[], int tamanho);

using namespace std;

void imprimirLista(int v[], int tamanho, bool ordenacao, bool mergeOuSelection)
{
    if (ordenacao)
    {
        if (mergeOuSelection)
        {
            cout << "Vetor " << tamanho << " (ORDENADO com MergeSort):\n";
        }
        else
        {
            cout << "Vetor " << tamanho << " (ORDENADO com SelectionSort):\n";
        }
    }
    else
    {
        cout << "Vetor " << tamanho << "(DESORDENADO):\n";
    }

    for (int j = 0; j < tamanho; j++)
        cout << v[j] << " ";
    cout << "\n\n";
}

int main()
{
    int tamanhos[4] = {100, 1000, 10000, 20000};
    // int tamanhos[4] = {10, 10, 100, 100};

    for (int i = 0; i < 4; i++)
    {

        int vetorMerge[tamanhos[i]];
        int vetorSelection[tamanhos[i]];
        int n1 = tamanhos[i];

        // Busca Sequêncial - Início

        // Busca Sequêncial - Fim

        // Busca Binária - Início

        // Busca Binária - Fim

        // MergeSort - Início
        vetores(vetorMerge, n1, 0); // Cria o vetor desordenado do Merge

        // imprimirLista(vetorMerge, n1, false, true); // Imprime o vetor desordenado do Merge

        TamanhoETempo resultadoMergeSort = beforeMergeSort(vetorMerge, 0, n1 - 1); // Retorna o tempo de execução e o tamanho do vetor

        // imprimirLista(vetorMerge, n1, true, true); // Imprime o vetor ordenado do Merge
        // MergeSort - Fim

        // SelectionSort - Início
        vetores(vetorSelection, n1, 0);                  // Cria o vetor desordenado do Selection
        // imprimirLista(vetorSelection, n1, false, false); // Imprime o vetor desordenado do Selection

        TamanhoETempo resultadoSelectionSort = beforeSelectionSort(vetorSelection, n1); // Retorna o tempo de execução e o tamanho do vetor

        // imprimirLista(vetorSelection, n1, true, false); // Imprimir o vetor ordenado do Selection
        // SelectionSort - Fim

        cout << "Merge Sort - Tamanho da lista: " << resultadoMergeSort.tamanho << ", Tempo de execução: " << resultadoMergeSort.tempo << endl;
        cout << "Selection Sort - Tamanho da lista: " << resultadoSelectionSort.tamanho << ", Tempo de execução: " << resultadoSelectionSort.tempo << endl;
    }

    return 0;
}