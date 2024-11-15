#include <stdio.h>
#define TAM 12

void preencher(float* vetor);
void calcularLucros(float* vetorGanhos, float* vetorGastos, float* vetorLucros);
void exibir(float* vetor);
float somar(float* resultado);
float calcularLucroMedioMensal(float* resultado);
void calcularMesesAbaixo(float* vetLucros, float lucroMedio);

int main() {
    float vetGanhos[TAM], vetGastos[TAM], vetLucros[TAM];
    float somaGanhos, somaGastos, somaLucros, lucroMedio;

    preencher(vetGanhos);
    preencher(vetGastos);

    calcularLucros(vetGanhos, vetGastos, vetLucros);

    exibir(vetGanhos);
    printf("\n");
    exibir(vetGastos);
    printf("\n");
    exibir(vetLucros);
    printf("\n");
    somaGanhos = somar(vetGanhos);
    printf("A soma dos ganhos no ano foi de %f ", somaGanhos);
    printf("\n");
    somaGastos = somar(vetGastos);
    printf("A soma dos gastos no ano foi de %f ", somaGastos);
    printf("\n");
    somaLucros = somar(vetLucros);
    printf("A soma dos lucros no ano foi de %f \n", somaLucros);
    lucroMedio = calcularLucroMedioMensal(vetLucros);
    printf("O lucro medio foi de %f \n", lucroMedio);
    calcularMesesAbaixo(vetLucros, lucroMedio);

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

float somar(float* resultado) {
    int i;
    float soma = 0;

    for ( i = 0; i < TAM; i++)
    {
        soma = soma + resultado[i];
    }
    return soma;
}

float calcularLucroMedioMensal(float* resultado) {
    float soma, lucroMedio;
    soma = somar(resultado);

    lucroMedio = soma / 12;

    return lucroMedio;
}

void calcularMesesAbaixo(float* vetLucros, float lucroMedio) {
    int i;

    for ( i = 0; i < TAM; i++)
    {
        if (vetLucros[i] < lucroMedio)
        {
            printf("O mes %d foi abaixo da media mensal. \n", i+1);
        }
    }

}