#include <stdio.h>

float FtoC (float f) {
    float res;
    res = (f - 32) / 18;
    return res;
}

float CtoF (float c) {
    float res;
    res = (c *1.8 + 32);
    return res;
}

void exibeOpcoes () {
    printf("opções \n");
    printf("1 - Converter celsius para fahrenheit \n");
    printf("2 - Converter fahrenheit para celsius \n");
    printf("0 - Encerrar programa \n");
    printf("Digite a opção desejada: ");
}

int main() {

    float tc, tf;
    do
    {
        exibeOpcoes ();
        scanf ("%d", &op);
        if (op == 1) {
            printf("Informe a temperatura: \n");
            scanf("%f", &tc);
            tf = Ctof (tc);
            printf("Temperatura em fahrenheit = %f \n", tf);
        }
        else if (op == 2) 
        {
            printf("Informe a temperatura: \n");
            scanf("%f", &tf);
            tc = FtoC(tf);
            printf("Temperatura em celsius = %f \n", tc);
        }
        
    } while( op != 0);
    

    return 0;
}