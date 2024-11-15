#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 50

int main() {
    char frase [TAM];
    int tamanho, i;

    printf("Insira uma frase: ");
    fgets(frase, TAM, stdin);
    frase[strcspn(frase, "\n")] = '\0';

    tamanho = strlen(frase);

    for (i = 0; i < tamanho; i++)
    {
        printf("%d \n", frase[i]);
    }
    
    return 0;
}