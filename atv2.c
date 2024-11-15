#include <stdio.h>

int main() {
    float valor, taxa;
    int ano;
    printf("Qual o ano de fabricação do veículo? \n");
    scanf("%d", &ano);
    printf("Qual o valor do veículo? \n");
    scanf("%f", &valor);

    if (ano < 2000) {
        taxa = (valor * 0.01);
        printf("A taxa a ser paga no momento da transferência é de %f \n", taxa);
    }
    else {
        taxa = (valor * 0.015);
        printf("A taxa a ser paga no momento da transferência é de %f \n", taxa);
    }

    return 0;
}