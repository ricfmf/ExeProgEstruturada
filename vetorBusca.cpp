#include <stdio.h>
#define TAM 12

void preencher(float* vetor);
void calcularLucros(float* vetorGanhos, float* vetorGastos, float* vetorLucros);
void exibir(float* vetor);

int main() {
    float vetGanhos[TAM], vetGastos[TAM], vetLucros[TAM];

    preencher(vetGanhos);
    preencher(vetGastos);

    calcularLucros(vetGanhos, vetGastos, vetLucros);

    exibir(vetGanhos);
    printf("\n");
    exibir(vetGastos);
    printf("\n");
    exibir(vetLucros);
    printf("\n");

    return 0;
}

void preencher(float* vetor) {
    int i;
    for ( i = 1; i < 13; i++)
    {
        printf("Insira os dados do %d mes: ", i);
        scanf("%f", &vetor[i-1]);
    }
}

void calcularLucros(float* vetorGanhos, float* vetorGastos, float* vetorLucros) {
    int i;
    for ( i = 0; i < 12; i++)
    {
        vetorLucros[i] = vetorGanhos[i] - vetorGastos[i];
    }
}

void exibir(float* vetor) {
    int i;
    for ( i = 0; i < 12; i++)
    {
        printf("%f ", vetor[i]);
    }
}