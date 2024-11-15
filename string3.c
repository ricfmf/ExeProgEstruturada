#include <stdio.h>
#define TAM 80

void criptografar(char* frase);

int main() {
    char frase[TAM];
    printf("Digite uma frase: ");
    fgets(frase, TAM, stdin);
    criptografar(frase);
    printf("%s", frase);

    return 0;
}

void criptografar(char* frase) {
    for (int i = 0; i < TAM; i++)
    {
        if (frase[i] == 'a' || frase[i] == 'A' || frase[i] == 'e' || frase[i] == 'E' || frase[i] == 'i' || frase[i] == 'I' || frase[i] == 'o' || frase[i] == 'O' || frase[i] == 'u' || frase[i] == 'U')
        {
            frase[i] = '*';
        }
    }
}