#include <stdio.h>

void preencher(float *vetor) {

    int i, aux;
    for ( i = 0; i < 100; i++)
    {
        printf("Insira um numero: \n");
        scanf("%d", &aux);
        vetor[i] = aux;
    }
    
}


float soma (float *vetor) {

    int i;
    float total = 0;
    for (i = 0; i < 100; i++)
    {
        total = total + vetor[i];
    }
    
    return total;
}


int main() {

    float total;
    float vetX[100], vetY[100];
    preencher(vetX);
    preencher(vetY);
    total = soma(vetX);
    printf("A soma do vetor e: %f \n", total);
    total = soma(vetY);
    printf("A soma do vetor e: %f \n", total);
    

    return 0;
}