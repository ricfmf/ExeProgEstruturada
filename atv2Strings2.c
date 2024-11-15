#include <stdio.h>
#include <ctype.h>
#define TAM 100

int qtdConsoantes(char* frase);
int main() {
    char frase[TAM];
    int resultado;

    printf("Digite uma frase: ");
    fgets(frase, TAM, stdin);
    resultado = qtdConsoantes(frase);
    printf("A quantidade de consoantes na frase e de %d", resultado);
    return 0;
}

int qtdConsoantes(char* frase) {
    int i, cont = 0;

    for ( i = 0; i != '\0'; i++)
    {
        if (isalpha(frase[i]) != 0)
        {
            if (frase[i] != 'a' && frase[i] != 'A' && frase[i] != 'e' && frase[i] != 'E' && frase[i] != 'i' && frase[i] != 'I' && frase[i] != 'o' && frase[i] != 'O' && frase[i] != 'u' && frase[i] != 'U')
            {
                cont++;
            }
        }
    }
    return cont;
}