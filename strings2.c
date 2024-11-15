#include <stdio.h>
#define TAM 100

int calcular(char* frase, char letra);
int main() {
    char frase[TAM], letra;
    int resultado;

    printf("Digite uma frase: ");
    fgets(frase, TAM, stdin);
    printf("Digite uma letra: ");
    scanf("%c", &letra);
    resultado = calcular(frase, letra);
    printf("%d", resultado);
    return 0;
}

int calcular(char* frase, char letra) {
    int i, cont = 0;

    for ( i = 0; i < TAM; i++)
    {
        if (frase[i] == letra)
        {
            cont++;
        }
    }
    return cont;
}