#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 50
void aumentarLetra(char* frase, char letra);
int main() {
    char frase[TAM], letra;

    printf("Digite uma frase: ");
    fgets(frase, TAM, stdin);
    printf("Digite uma letra: ");
    scanf("%c", &letra);
    do {
        if (isalpha(letra) != 0)
            {
                aumentarLetra(frase, letra);
            }
        else {
            printf("Letra invalida. \n");
            printf("Digite uma letra: ");
            scanf(" %c", &letra);
        }
    }while (isalpha(letra) == 0);
    
    printf("frase: %s", frase);
    return 0;
}

void aumentarLetra(char* frase, char letra) {
    int i;

    for ( i = 0; frase[i] != '\0'; i++)
    {
        if (frase[i] == letra)
        {
            frase[i] = toupper(letra);
        }
    }
}