#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 50

int comparar(char vetor[], char vetor2[]);

int main() {
    char string1 [TAM];
    char string2 [TAM];
    int resultado;

    printf("Insira a primeira frase: \n");
    fgets(string1, TAM, stdin);
    string1[strcspn(string1, '\n')] = "\0";

    printf("Insira a segunda frase: \n");
    fgets(string2, TAM, stdin);
    string2[strcspn(string2, '\n')] = "\0";

    resultado = comparar(string1, string2);

    if (resultado == 1)
    {
        printf("%s \n", string2);
        printf("%s", string1);
    }
    else 
    {
        printf("%s \n", string1);
        printf("%s", string2);
    }
    

    return 0;
}


int comparar(char vetor[], char vetor2[]) {
   for (int i = 0; i < TAM; i++)
   {
    if (vetor[i] > vetor2[i])
    {
        return 1;     
    }
    return -1;
   }
   
}