#include <stdio.h>
#include <math.h>
#define TAM 6

char calculoDigito(char* conta);

int main() {
    char conta[TAM], digito, resultado;

    printf("Digite a sua conta: ");
    scanf("%s", conta);
    printf("Digite o digito: ");
    scanf(" %c", &digito);

    resultado = calculoDigito(conta);
    
    if (digito == resultado)
    {
        printf("Digito verificador valido");
    }
    else {
        printf("Digito verificador invalido");
    }

    return 0;
}

char calculoDigito(char* conta) {
    int soma = 0, i, resto;
    char digito;

    for (i = 0; i < TAM; i++)
    {
        soma = soma + ((conta[i] - '0') * (pow(2, i)));
    }
    resto = soma % 11;
    if (resto >= 0 && resto <= 9)
    {
        digito = '0' + resto;
    }
    else if (resto == 10)
    {
        digito = 'X';
    }
    

    return digito;
}
