#include <iostream>
#include <chrono>
using namespace std;
#include "headers/buscaBinaria.h"

int buscaBinaria(int vetor[], int tamanhoVetor, int numeroEscolhido)
{
    int inicio = 0, fim = tamanhoVetor - 1;
    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;
        if (vetor[meio] == numeroEscolhido)
        {
            return meio;
        }
        else if (vetor[meio] < numeroEscolhido)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }
    return -1;
}

TamanhoETempo beforeBuscaBinaria(int v[], int tamanho, int numeroEscolhido)
{
    auto tempoInicio = chrono::high_resolution_clock::now();

    int resultado = buscaBinaria(v, tamanho, numeroEscolhido);

    auto tempoFinal = chrono::high_resolution_clock::now();
    chrono::duration<double> tempo = tempoFinal - tempoInicio;

    return TamanhoETempo{tamanho, tempo.count()};
}