#include <stdio.h>

int main () {
    float x, y, z;
    printf("Digite um numero real: \n");
    scanf("%f", &x);
    printf("Digite um numero real: \n");
    scanf("%f", &y);
    printf("Digite um numero real: \n");
    scanf("%f", &z);

    float* pointer1 = &x;
    float* pointer2 = &y;
    float* pointer3 = &z;

    *pointer1 = *pointer1 * 4;
    *pointer2 = *pointer2 + 5;
    *pointer3 = *pointer3 / 5;

    printf("%f \n", x);
    printf("%f \n", y);
    printf("%f \n", z);

    return 0;
}