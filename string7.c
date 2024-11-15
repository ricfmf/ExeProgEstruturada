#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 100

void calcular(char* frase, int* qtd1, int* qtd2, int* qtd3, int* qtd4);

int main() {
    char frase[TAM];
    int qtdLetras = 0, qtdNum = 0, qtdSpace = 0, qtdSimb = 0;

    printf("Digite uma frase: ");
    fgets(frase, TAM, stdin);

    calcular(frase, &qtdLetras, &qtdNum, &qtdSpace, &qtdSimb);
    printf("A quantidade de letras e %d \n", qtdLetras);
    printf("A quantidade de numeros e %d \n", qtdNum);
    printf("A quantidade de espacos e %d \n", qtdSpace-1);
    printf("A quantidade de simbolos e %d \n", qtdSimb);

    return 0;
}

void calcular(char* frase, int* qtd1, int* qtd2, int* qtd3, int* qtd4) {
    int i;

    for ( i = 0; frase[i] != '\0'; i++)
    {
        if (isalpha(frase[i]) != 0)
        {
            (*qtd1)++;
        }
        else if (isdigit(frase[i]) != 0)
        {
            (*qtd2)++;
        }
        else if (isspace(frase[i]) != 0)
        {
            (*qtd3)++;
        }
        else {
            (*qtd4)++;
        }
    }
}

