#include<stdio.h>

char conceitoAluno(float media) {
    char conceito;
    if (media >= 0 && media < 5) {
        conceito = 'D';
        return conceito;
    }
    else if (media >= 5 && media < 7) {
        conceito = 'C';
        return conceito;
    }
    else if (media >= 7 && media < 9) 
    {
        conceito = 'B';
        return conceito;
    }
    else if (media >= 9 && media <= 10) {
        conceito = 'A';
        return conceito;
    }
    else {
        printf("Por favor, insira uma resposta valida \n");
    }
}

float mediaAluno (float primeiraNota, float segundaNota) {
    float media;
    char conceito;
    media = (primeiraNota + segundaNota) / 2;
    conceito = conceitoAluno(media);
    printf("A media e de %f \n", media);
    printf("O conceito e de %c \n", conceito); 
}

int main () {
    float nota1, nota2;
    int cont = 0;
    do
    {
        printf("Digite a primeira nota: \n");
        scanf("%f", &nota1);
        if (nota1 < 0 || nota1 > 10)
        {
            printf("Nota invalida \n");
            continue;
        }
        printf("Digite a segunda nota: \n");
        scanf("%f", &nota2);
        if (nota2 < 0 || nota2 > 10)
        {
            printf("Nota invailda \n");
            continue;
        }
        
        mediaAluno(nota1, nota2);
        cont = cont+1;
    } while (cont < 5);
    

    return 0;
}