#include <stdio.h>

void preencher (int *vetor) {
    int i, aux;
    for ( i = 0; i < 10; i++)
    {
        printf("Insira um numero: \n");
        scanf("%d", &aux);
        vetor[i] = aux;
    }
    

}


void exibir (int *vetor) {

    int i;
    for ( i = 0; i < 10; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
}

void calculo (int *vetorA, int *vetorB) {

    int i;
    for ( i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            vetorB[i] = vetorA[i] / 2;
        }
        else {

            vetorB[i] = vetorA[i] * 3;
        }
        
    }
    
}

int main() {

    int vetA[10], vetB[10];
    preencher(vetA);
    calculo(vetA, vetB);
    exibir(vetA);
    exibir(vetB);


    return 0;
}