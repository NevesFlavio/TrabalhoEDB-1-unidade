#include <iostream>
#include <chrono>
using namespace std;
#include "headers/buscaSequencial.h" 

int buscaSequencial(int vetor[], int tamanhoVetor, int numeroEscolhido) // Função de busca sequencial
{
    for (int i = 0; i < tamanhoVetor; i++) // Loop para percorrer o vetor
    {
        if (vetor[i] == numeroEscolhido)
        {
            return i;
        }
    }
    return -1;
}

TamanhoETempo beforeBuscaSequencial(int v[], int tamanho, int numeroEscolhido) // Função para contar o tempo da busca sequencial
{
    auto tempoInicio = chrono::high_resolution_clock::now();

    int resultado = buscaSequencial(v, tamanho, numeroEscolhido);

    auto tempoFinal = chrono::high_resolution_clock::now();
    chrono::duration<double> tempo = tempoFinal - tempoInicio;

    return TamanhoETempo{tamanho, tempo.count()};
}