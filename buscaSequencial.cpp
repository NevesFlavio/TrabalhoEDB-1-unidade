#include <iostream>
#include <chrono>
using namespace std;
#include "headers/buscaSequencial.h" 

int buscaSequencial(int vetor[], int tamanhoVetor, int numeroEscolhido)
{
    for (int i = 0; i < tamanhoVetor; i++)
    {
        if (vetor[i] == numeroEscolhido)
        {
            return i;
        }
    }
    return -1;
}

TamanhoETempo beforeBuscaSequencial(int v[], int tamanho, int numeroEscolhido)
{
    auto tempoInicio = chrono::high_resolution_clock::now();

    int resultado = buscaSequencial(v, tamanho, numeroEscolhido);

    auto tempoFinal = chrono::high_resolution_clock::now();
    chrono::duration<double> tempo = tempoFinal - tempoInicio;

    return TamanhoETempo{tamanho, tempo.count()};
}