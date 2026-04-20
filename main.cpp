#include <iostream>
#include <chrono>

using namespace std;

void mergeSort(int v[], int inicio, int fim);
void vetores(int v[], int tamanho, int i);

int main() {
    
    int v1[10];
    int v2[100];
    int v3[1000];
    int v4[10000];
    
    int n1 = 10;
    int n2 = 100;
    int n3 = 1000;
    int n4 = 10000;       

    vetores(v1, 10, 0);
    vetores(v2, 100, 0);
    vetores(v3, 1000, 0);
    vetores(v4, 10000, 0);

    cout << "Vetor 10 (DESORDENADO):\n";
    for (int i = 0; i < n1; i++) cout << v1[i] << " ";
    cout << "\n\n";

    cout << "Vetor 100 (DESORDENADO):\n";
    for (int i = 0; i < n2; i++) cout << v2[i] << " ";
    cout << "\n\n";

    cout << "Vetor 1000 (DESORDENADO):\n";
    for (int i = 0; i < n3; i++) cout << v3[i] << " ";
    cout << "\n\n";

    cout << "Vetor 10000 (DESORDENADO):\n";
    for (int i = 0; i < n4; i++) cout << v4[i] << " ";
    cout << "\n\n";

 
    mergeSort(v1, 0, n1 - 1);
    mergeSort(v2, 0, n2 - 1);
    mergeSort(v3, 0, n3 - 1);
    mergeSort(v4, 0, n4 - 1);

    auto start = std::chrono::high_resolution_clock::now();

    cout << "Vetor 10 (ORDENADO):\n";
    for (int i = 0; i < n1; i++) cout << v1[i] << " ";
    cout << "\n\n";

    cout << "Vetor 100 (ORDENADO):\n";
    for (int i = 0; i < n2; i++) cout << v2[i] << " ";
    cout << "\n\n";

    cout << "Vetor 1000 (ORDENADO):\n";
    for (int i = 0; i < n3; i++) cout << v3[i] << " ";
    cout << "\n\n";

    cout << "Vetor 10000 (depois):\n";
    for (int i = 0; i < n4; i++) cout << v4[i] << " ";
    cout << "\n";

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    
    
    
    cout << "Tempo de execucao total: " << duration.count() << "ms" << endl;
   
    return 0;
}