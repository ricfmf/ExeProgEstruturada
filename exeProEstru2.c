#include <stdio.h>
#include <math.h>

float volumeCubo (float lado) {
    float volume;
    volume = pow(lado, 3);
    return volume;
}

float volumeParalelepipedo (float altura, float comprimento, float largura) {
    float volume;
    volume = altura * largura * comprimento;
    return volume;
}

float volumeEsfera ( float raio) {
    float volume;
    volume = (4/3)*3.14*(pow(raio, 3));
    return volume;
}

float volumeCilindro (float altura, float raio) {
    float volume;
    volume = 3.14 * (pow(raio, 2)) * altura;
    return volume;
}

void exibeOpcoes () {
    printf("opcoes \n");
    printf("1 - Calcular volume do cubo \n");
    printf("2 - Calcular volume do paralelepipedo \n");
    printf("3 - Calcular volume da esfera \n");
    printf("4 - Calcular volume do cilindro \n");
    printf("0 - Para sair do programa \n");
    printf("Digite a opcao desejada: \n");
}

int main () {
    float vCubo, vParalelepipedo, vEsfera, vCilindro;
    int op;
    do
    {
        exibeOpcoes();
        scanf("%d", &op);
        if (op == 1) {
            float lado;
            printf("Insira o valor do lado do cubo: \n");
            scanf("%f", &lado);
            vCubo = volumeCubo(lado);
            printf("O volume do cubo e de %f \n", vCubo);
        }
        else if ( op == 2)
        {
            float altura, comprimento, largura;
            printf("Insira o valor da altura do paralelepipedo: \n");
            scanf("%f", &altura);
            printf("Insira o valor do comprimento do paralelepipedo: \n");
            scanf("%f", &comprimento);
            printf("Insira o valor da largura do paralelepipedo: \n");
            scanf("%f", &largura);
            vParalelepipedo = volumeParalelepipedo(altura, comprimento, largura);
            printf("O volume do paralelepipedo e de %f \n", vParalelepipedo);
        }
        else if ( op == 3)
        {
            float raio;
            printf("Insira o valor do raio: \n");
            scanf("%f", &raio);
            vEsfera = volumeEsfera(raio);
            printf("O volume da esfera e de %f \n", vEsfera);
        }
        else if ( op == 4)
        {
            float altura, raio;
            printf("Insira o valor da altura do cilindro: \n");
            scanf("%f", &altura);
            printf("Insira o valor do raio do cilindro \n");
            scanf("%f", &raio);
            vCilindro = volumeCilindro(altura, raio);
            printf("O volume do cilindro e de %f \n", vCilindro);
        }
        else if ( op > 4 || op < 0)
        {
            printf("Por favor, insira uma resposta valida \n");
        }
        

    } while ( op != 0);
        

    return 0;
}