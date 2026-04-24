#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>

#include "buscaSequencial.cpp"
#include "buscaBinaria.cpp"
#include "mergesort.cpp"
#include "selectionsort.cpp"
#include "vetores.cpp"

// void vetores(int v[], int tamanho, int i);
TamanhoETempo beforeBuscaSequencial(int v[], int tamanho, int numeroEscolhido);
TamanhoETempo beforeBuscaBinaria(int v[], int tamanho, int numeroEscolhido);
TamanhoETempo beforeMergeSort(int v[], int inicio, int fim);
TamanhoETempo beforeSelectionSort(int v[], int tamanho);

struct ResultadoAlgoritmo // Estrutura para armazenar os resultados de cada algoritmo
{
    string nome;
    vector<double> tempos;
};

using namespace std;

// ---------------------------------------------------------------------------------------------

// Inserir função do professor aqui - Início

int funcaoDoProfessor(int v[], int tamanho)
{
    // beforeBuscaSequencial(v, tamanho, 1); // Exemplo de chamada para testar o funcionamento
    return 0;
}

// Inserir função do professor aqui - Fim

// ---------------------------------------------------------------------------------------------

TamanhoETempo beforeFuncaoDoProfessor(int v[], int tamanho) // Contar os tempos da função do professor
{
    auto inicio = chrono::high_resolution_clock::now();

    int professor = funcaoDoProfessor(v, tamanho); // Função do Professor

    auto fim = chrono::high_resolution_clock::now();

    chrono::duration<double> tempo = fim - inicio;

    return {tamanho, tempo.count()};
}

double diferenca(double a[], double b[], int tamanho) // Função para calcular a diferença entre os tempos do professor e dos algoritmos
{
    double soma = 0;

    for (int i = 0; i < tamanho; i++)
    {
        soma += fabs(a[i] - b[i]);
    }

    return soma;
}

void imprimirLista(int v[], int tamanho, bool ordenacao, bool mergeOuSelection) // Função para imprimir os vetores, indicando se estão ordenados ou desordenados, e qual algoritmo de ordenação foi utilizado
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

string descobrirComplexidade( // Função para descobrir a complexidade da função do professor comparando os tempos com os algoritmos conhecidos
    double prof[],
    double seq[],
    double bin[],
    double merge[],
    double sel[],
    int tamanho)
{

    // Calcula a diferença entre os tempos do professor e dos algoritmos conhecidos
    double dSeq = diferenca(prof, seq, tamanho); 
    double dBin = diferenca(prof, bin, tamanho);
    double dMerge = diferenca(prof, merge, tamanho);
    double dSel = diferenca(prof, sel, tamanho);

    // Encontra o menor valor de diferença para determinar a complexidade mais próxima
    double menor = dSeq;
    string resultado = "O(n) - semelhante a Busca Sequencial";

    if (dBin < menor)
    {
        menor = dBin;
        resultado = "O(log n) - semelhante a Busca Binária";
    }

    if (dMerge < menor)
    {
        menor = dMerge;
        resultado = "O(n log n) - semelhante ao MergeSort";
    }

    if (dSel < menor)
    {
        menor = dSel;
        resultado = "O(n^2) - semelhante ao SelectionSort";
    }

    return resultado;
}

int main()
{
    vector<int> tamanhos = {100, 1000, 10000, 20000}; // Tamanhos dos vetores a serem testados

    // Vetores para armazenar os tempos de cada algoritmo
    double temposProfessor[4];
    double temposBuscaSeq[4];
    double temposBuscaBin[4];
    double temposSelection[4];
    double temposMerge[4];

    for (int i = 0; i < tamanhos.size(); i++) // Loop para testar cada tamanho de vetor
    {
        int n1 = tamanhos[i];

        // Criação dos vetores para cada algoritmo
        int vetorBuscaSequencial[n1];
        int vetorBuscaBinaria[n1];
        int vetorMerge[n1];
        int vetorSelection[n1];
        int vetorProfessor[n1];

        // Função do Professor - Início
        vetores(vetorProfessor, n1, 0);
        beforeFuncaoDoProfessor(vetorProfessor, n1);

        // Função do Professor - Fim

        // Busca Sequêncial - Início
        vetores(vetorBuscaSequencial, n1, 0);

        // imprimirLista(vetorBuscaSequencial, n1, false, false);
        // Imprime o vetor desordenado para busca sequencial

        // Cria o vetor desordenado da Busca Sequencial
        TamanhoETempo resultadoBuscaSequencial = beforeBuscaSequencial(vetorBuscaSequencial, n1, 1);
        temposBuscaSeq[i] = resultadoBuscaSequencial.tempo;

        // Busca Sequêncial - Fim

        // Busca Binária - Início
        vetoresCrescentes(vetorBuscaBinaria, n1, 0);

        // imprimirLista(vetorBuscaBinaria, n1, false, false);
        // Imprime o vetor desordenado para busca binária

        // Cria o vetor desordenado da Busca Binária
        TamanhoETempo resultadoBuscaBinaria = beforeBuscaBinaria(vetorBuscaBinaria, n1, 1);
        temposBuscaBin[i] = resultadoBuscaBinaria.tempo;

        // Busca Binária - Fim

        // MergeSort - Início
        vetores(vetorMerge, n1, 0);

        // imprimirLista(vetorMerge, n1, false, true);
        // Imprime o vetor desordenado do Merge

        TamanhoETempo resultadoMergeSort = beforeMergeSort(vetorMerge, 0, n1 - 1);
        temposMerge[i] = resultadoMergeSort.tempo;

        // imprimirLista(vetorMerge, n1, true, true);
        // Imprime o vetor ordenado do Merge
        // MergeSort - Fim

        // SelectionSort - Início
        vetores(vetorSelection, n1, 0);
        // imprimirLista(vetorSelection, n1, false, false);
        // Imprime o vetor desordenado do Selection

        TamanhoETempo resultadoSelectionSort = beforeSelectionSort(vetorSelection, n1);
        temposSelection[i] = resultadoSelectionSort.tempo;

        // imprimirLista(vetorSelection, n1, true, false);
        // Imprimir o vetor ordenado do Selection
        // SelectionSort - Fim

        cout << "Busca Sequencial - Tamanho da lista: " << resultadoBuscaSequencial.tamanho
             << ", Tempo de execucao: " << resultadoBuscaSequencial.tempo << endl;
        cout << "Busca Binaria - Tamanho da lista: " << resultadoBuscaBinaria.tamanho
             << ", Tempo de execucao: " << resultadoBuscaBinaria.tempo << endl;

        cout << "Merge Sort - Tamanho da lista: " << resultadoMergeSort.tamanho
             << ", Tempo de execucao: " << resultadoMergeSort.tempo << endl;
        cout << "Selection Sort - Tamanho da lista: " << resultadoSelectionSort.tamanho
             << ", Tempo de execucao: " << resultadoSelectionSort.tempo << endl;
    }

    string complexidade = descobrirComplexidade(
        temposProfessor,
        temposBuscaSeq,
        temposBuscaBin,
        temposMerge,
        temposSelection,
        tamanhos.size());

    cout << "\nComplexidade estimada da funcao de entrada: "
         << complexidade << endl;

    return 0;
}