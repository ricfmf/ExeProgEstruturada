#include <stdio.h>

void ordenacao (float *numero1, float *numero2, float *numero3) {

    float aux;

    if (*numero1 >= *numero2 ) {
        aux = *numero1;
        *numero1 = *numero2;
        *numero2 = aux;
    }
    if (*numero2 >= *numero3)
    {
        aux = *numero2;
        *numero2 = *numero3;
        *numero3 = aux;
    }
    if (*numero1 >= *numero2)
    {
        aux = *numero1;
        *numero1 = *numero2;
        *numero2 = aux;
    }
    
    

}



int main () {

    float num1, num2, num3;
    printf("Digite um numero: \n");
    scanf("%f", &num1);
    printf("Digite outro numero: \n");
    scanf("%f", &num2);
    printf("Digite outro numero: \n");
    scanf("%f", &num3);

    ordenacao(&num1, &num2, &num3);
    printf("%f \n", num1);
    printf("%f \n", num2);
    printf("%f \n", num3);

    return 0;
}