#include <stdio.h>
#include <string.h>
#define TAM 50

int main() {
    char frase [TAM];
    int tamanho;

    printf("Insira uma frase: ");
    fgets(frase, TAM, stdin);
    frase[strcspn(frase, "\n")] = '\0';

    tamanho = strlen(frase);

    for (int i = tamanho-1; i >= 0; i--)
    {
        printf("%c", frase[i]);
    }
    
    return 0;
}