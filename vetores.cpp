#include <stdio.h>

int main ( ) {
    char aux, vet[10];
    int i;
    vet[0] = 'T';
    vet[1] = 'R';
    vet[2] = 'X';
    vet[3] = 'S';
    vet[4] = ' ';
    vet[5] = 'E';
    vet[6] = 'O';
    vet[7] = 'B';
    vet[8] = 'A';
    vet[9] = '!';
    aux = vet[5];
    vet[5] = vet[8];
    vet[8] = aux;
    for (i = 0; i <= 3; i++) {
    aux = vet[i];
    vet[i] = vet[7- i];
    vet[7- i] = aux;
    }
    vet[5] = vet[1];
    for (i = 0; i <= 9; i++) {
    printf("%c", vet[i]);
    }
    printf("\n");
    return 0;
    }