#include <stdio.h>
#include <string.h>
#define TAM 100

void criptografar(char* frase, char* fraseInversa);

int main() {
    char frase[TAM], fraseInversa[TAM];

    printf("Digite uma frase: ");
    fgets(frase, TAM, stdin);
    criptografar(frase, fraseInversa);
    printf("%s", fraseInversa);

    return 0;
}

void criptografar(char* frase, char* fraseInversa) {
    int cont = 0;
    for (int i = strlen(frase)-1; i >= 0; i--)
    {
        fraseInversa[cont] = frase[i];
        cont++;
    }
    
}