#include <stdio.h>
#include <math.h>

void calculo(float a, float b, float c, float *x1, float *x2, int *existe) {

    float delta;
    delta = b*b - 4 * a * c;

    if (delta < 0) {
        *existe = 0;

    }
    else if (delta == 0) {
        *existe = 1;
        *x1 = *x2 -b / 2*a; 
    }
    else if (delta > 0)
    {
        *existe = 1;
        *x1 = (-b + sqrt(delta)) / 2*a;
        *x2 = (-b - sqrt(delta)) / 2*a;
    }
    
}


int main () {

    float a, b, c, x1, x2;
    int existe;

    printf("Digite o coeficiente a: \n");
    scanf("%f", &a);
    printf("Digite o coeficiente b: \n");
    scanf("%f", &b);
    printf("Digite o coeficiente c: \n");
    scanf("%f", &c);

    calculo(a, b, c, &x1, &x2, &existe);

    if (existe == 0) {
        printf("Nao ha raizes reais \n");
    }
    else {
        printf("As raizes sao %f e %f", x1, x2);
    }

    return 0;
}