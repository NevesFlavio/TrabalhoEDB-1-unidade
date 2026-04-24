void vetores(int v[], int tamanho, int i) { // Função para criar vetores decrescentes
    if (i == tamanho) return;

    v[i] = tamanho - i;
    vetores(v, tamanho, i + 1);
}

void vetoresCrescentes(int v[], int tamanho, int i) { // Função para criar vetores crescentes
    if (i == tamanho) return;

    v[i] = i + 1;
    vetoresCrescentes(v, tamanho, i + 1);
} 