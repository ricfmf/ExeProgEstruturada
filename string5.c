#include <stdio.h>
#include <string.h>
#define TAM 80

void criptografar(char* frase, char* fraseInversa);

int main() {
    char frase[TAM], fraseCriptografada[TAM];
    
    printf("Digite uma frase: ");
    fgets(frase, TAM, stdin);
    criptografar(frase, fraseCriptografada);
    printf("%s", fraseCriptografada);

    return 0;
}

void criptografar(char* frase, char* fraseInversa) {
    int i, cont = 0;

    for (i = strlen(frase)-1; i >= 0; i--)
    {
        if(frase[i] != 'a' && frase[i] != 'A' &&  frase[i] != 'e' && frase[i] != 'E' && frase[i] != 'i' && frase[i] != 'I' && frase[i] != 'o' && frase[i] != 'O' && frase[i] != 'u' && frase[i] != 'U' && frase[i] != ' ')
        {
            frase[i] = '#';
            fraseInversa[cont] = frase[i];
            cont++;
        }
        else {
            fraseInversa[cont] = frase[i];
            cont++;
        }
    }
}