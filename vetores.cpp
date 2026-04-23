void vetores(int v[], int tamanho, int i) {
    if (i == tamanho) return;

    v[i] = tamanho - i;
    vetores(v, tamanho, i + 1);
}