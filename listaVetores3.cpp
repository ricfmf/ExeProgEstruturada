#include <stdio.h>
#define TAM 100

void preencher(float* vetor);
void exibir(float* vetor);
float calculoProdEscalar(float* vetorA, float* vetorB);

int main() {
    float vetA[TAM], vetB[TAM], resultado;

    preencher(vetA);
    preencher(vetB);
    exibir(vetA);
    printf("\n");
    exibir(vetB);
    printf("\n");
    resultado = calculoProdEscalar(vetA, vetB);
    printf("%f", resultado);

    return 0;
}


void preencher(float* vetor) {

    int i;
    float num;

    for ( i = 0; i < TAM; i++)
    {
        printf("Digite um numero: \n");
        scanf("%f", &num);
        vetor[i] = num;
    }
    
}

void exibir(float* vetor) {
    int i;

    for ( i = 0; i < TAM; i++)
    {
        printf("%f ", vetor[i]);
    }
    
}

float calculoProdEscalar(float* vetorA, float* vetorB) {
    int i;
    float resultado = 0;

    for ( i = 0; i < TAM; i++)
    {
        resultado = resultado + (vetorA[i] * vetorB[i]);
    }
    return resultado;
    
}