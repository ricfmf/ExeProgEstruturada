#include <stdio.h>

void preencher (int *vetor) {
    int i, aux;
    for ( i = 0; i < 5; i++)
    {
        printf("Insira um numero: \n");
        scanf("%d", &aux);
        vetor[i] = aux;
    }
    

}

void exibir (int *vetor) {

    int i;
    for ( i = 0; i < 5; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
}

void soma (int *vetorA, int *vetorB, int *vetorC) {

    int i;
    for ( i = 0; i < 5; i++)
    {
        vetorC[i] = vetorA[i] + vetorB[i];
    }
    

}

int main() {

    int vetA[5], vetB[5], vetC[5];
    preencher(vetA);
    exibir(vetA);
    preencher(vetB);
    exibir(vetB);
    soma(vetA, vetB, vetC);
    exibir(vetC);

    return 0;
}