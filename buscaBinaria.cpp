#include <iostream>
#include <chrono>
using namespace std;
#include "headers/buscaBinaria.h"

int buscaBinaria(int vetor[], int tamanhoVetor, int numeroEscolhido) // Função de busca binária
{
    int inicio = 0, fim = tamanhoVetor - 1;
    while (inicio <= fim) // Enquanto o início for menor ou igual ao fim
    {
        int meio = inicio + (fim - inicio) / 2;
        if (vetor[meio] == numeroEscolhido) // Se o elemento do meio for igual ao número escolhido, retorna o índice
        {
            return meio;
        }
        else if (vetor[meio] < numeroEscolhido) // Se o elemento do meio for menor que o número escolhido, move o início para a direita
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

TamanhoETempo beforeBuscaBinaria(int v[], int tamanho, int numeroEscolhido) // Função para medir o tempo da busca binária
{
    auto tempoInicio = chrono::high_resolution_clock::now();

    int resultado = buscaBinaria(v, tamanho, numeroEscolhido);

    auto tempoFinal = chrono::high_resolution_clock::now();
    chrono::duration<double> tempo = tempoFinal - tempoInicio;

    return TamanhoETempo{tamanho, tempo.count()};
}