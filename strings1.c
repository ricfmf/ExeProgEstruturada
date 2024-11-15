#include <stdio.h>
#define TAM 50

int calcularVogais(char* frase);

int main() {
    char frase[TAM];
    int resultado;
    printf("Digite uma frase: ");
    fgets(frase, TAM, stdin);
    resultado =  calcularVogais(frase);
    printf("%d", resultado);
    return 0;
}

int calcularVogais(char* frase) {
    int cont = 0;
    for (int i = 0; i < TAM; i++)
    {
        if (frase[i] == 'a' || frase[i] == 'A' || frase[i] == 'e' || frase[i] == 'E' || frase[i] == 'i' || frase[i] == 'I' || frase[i] == 'o' || frase[i] == 'O' || frase[i] == 'u' || frase[i] == 'U')
        {
            cont++;
        }
    }
    return cont;
}