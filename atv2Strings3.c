#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define TAM 50

int checkName(char* nome);
int main() {
    char nome[TAM];
    int resultado = 0;

    do
    {
        printf("Qual o seu nome? ");
        fgets(nome, TAM, stdin);
        nome[strcspn(nome, "\n")] = '\0';
        resultado = checkName(nome);

        if (resultado == 1)
        {
            printf("Ola, %s, prazer em te conhecer! \n", nome);
        }
         else{
            printf("Nome invalido: Digite novamente.");
        }    
    } while (resultado != 1);
    
    return 0;
}

int checkName(char* nome) {
    int i;

    for ( i = 0; nome[i] != '\0'; i++)
    {
        if (isalpha(nome[i]) == 0 && isspace(nome[i]) == 0)
        {
            return 0;
        }
    }
    return 1;
}