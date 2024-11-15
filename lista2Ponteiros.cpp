#include <stdio.h>

void converter (int mnts, int *horas, int *minutos) {

    *horas = mnts / 60;
    *minutos = mnts % 60;
}


int main () {

    int mnts, horas, minutos;
    printf("Insira o numero de minutos: \n");
    scanf("%d", &mnts);
    converter(mnts, &horas, &minutos);
    printf("%d minutos sao %d horas e %d minutos \n", mnts, horas, minutos);

    
    return 0;
}