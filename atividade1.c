#include <stdio.h>

int main() {

    float precoReal, desconto;
    printf ("Qual o preço do produto? \n");
    scanf ("%f", &precoReal);
    printf ("Qual o percentual de desconto? \n");
    scanf ("%f", &desconto);
    printf("Preço real do produto: %f \n", precoReal);
    printf("Quanto você pagará pelo produto: %f \n", precoReal - precoReal*(desconto/100));
    printf("Quanto você está economizando: %f \n", precoReal*(desconto/100));
    
    return 0;
}