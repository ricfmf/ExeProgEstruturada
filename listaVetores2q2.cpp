#include <stdio.h>
#define TAM 60

void preencher(float* vetor);
void calcularMedias(float* notas1, float* notas2, float* medias);
void exibir(float* notas);
void avaliacao(float* medias, int* situacoes);
void percentualAlunos(int* situacoes, float* perDireto, float* perRecu, float* perRepro);
float menorAvg(float* medias);
float maiorAvg(float* medias);
float mediaTotal(float* medias);
int qtdAbaixo(float* medias, float mediaTurma);

int main() {

    float primeirasNotas[TAM], segundasNotas[TAM], medias[TAM], percentualAprovados, percentualRecuperacao, percentualReprovados, menorMedia, maiorMedia, mediaTurma;
    int situacao[TAM], alunosAbaixo;

    preencher(primeirasNotas);
    preencher(segundasNotas);    
    calcularMedias(primeirasNotas, segundasNotas, medias);
    exibir(primeirasNotas);
    exibir(segundasNotas);
    exibir(medias);
    avaliacao(medias, situacao);
    percentualAlunos(situacao, &percentualAprovados, &percentualRecuperacao, &percentualReprovados);
    printf("%f  ", percentualAprovados);
    printf("%f  ", percentualRecuperacao);
    printf("%f  ",percentualReprovados);
    printf("\n");
    menorMedia = menorAvg(medias);
    printf("%f ", menorMedia);
    maiorMedia = maiorAvg(medias);
    printf("%f ", maiorMedia);
    mediaTurma = mediaTotal(medias);
    printf("%f ", mediaTurma);
    printf("\n");
    alunosAbaixo = qtdAbaixo(medias, mediaTurma);
    printf("%d \n", alunosAbaixo);

    return 0;
}


void preencher(float* vetor) {

    int i;
    float nota;

for ( i = 0; i < TAM; i++)
{
    do
    {
        printf("Digite a nota: ");
        scanf("%f", &nota);
        printf("\n");
        if (nota < 0 || nota > 10)
        {
            printf("Nota invalida! Por favor, digite uma nota valida. \n");
        }
        else {
            vetor[i] = nota;
            printf("\n");
        }
        
    } while (nota < 0 || nota > 10);
    
}



}

void calcularMedias(float* notas1, float* notas2, float* medias) {

    int i;
    float media;
    for ( i = 0; i < TAM; i++)
    {
        media = (notas1[i] * 2 + notas2[i] * 3) / 5;
        medias[i] = media; 
    }
    
}

void exibir(float* notas) {

    int i;
    for ( i = 0; i < TAM; i++)
    {
        printf("%f ", notas[i]);
    }
    printf("\n");
    
}



void avaliacao(float* medias, int* situacoes) {

    int i;
    for ( i = 0; i < TAM; i++)
    {
        if (medias[i] >= 7)
        {
            situacoes[i] = 1;
        }
        else if (medias[i] >= 3 && medias[i] < 7)
        {
            situacoes[i] = 2;
        }
        else {
            situacoes[i] = 3;
        }
        
    }
    

}

void percentualAlunos(int* situacoes, float* perDireto, float* perRecu, float* perRepro) {

    int i;
    float numDireto = 0, numRecu = 0, numRepro = 0;

        for ( i = 0; i < TAM; i++)
        {
            if (situacoes[i] == 1)
            {
                numDireto = numDireto + 1;
            }
            else if (situacoes[i] == 2)
            {
                numRecu = numRecu + 1;
            }
            else {
                numRepro = numRepro + 1;
            }
            
    }
    *perDireto = (numDireto / TAM) * 100;
    *perRecu = (numRecu / TAM) * 100;
    *perRepro = (numRepro / TAM) * 100;

}

float menorAvg(float* medias) {
    int i;
    float menorMed = 10;
    for ( i = 0; i < TAM; i++)
    {
        if (medias[i] < menorMed)
        {
            menorMed = medias[i];
        }
        
    }
    return menorMed;
}

float maiorAvg(float* medias) {
    int i;
    float maiorMed = 0;

    for ( i = 0; i < TAM; i++)
    {
        if (medias[i] > maiorMed)
        {
            maiorMed = medias[i];
        }
        
    }
    return maiorMed;

}

float mediaTotal(float* medias) {
    int i;
    float total = 0;
    for ( i = 0; i < TAM; i++)
    {
        total = total + medias[i];
    }
    total = total / TAM;
    return total;
}

int qtdAbaixo(float* medias, float mediaTurma) {
    int i, alunosAbaixo = 0;
    for ( i = 0; i < TAM; i++)
    {
        if (medias[i] < mediaTurma)
        {
            alunosAbaixo = alunosAbaixo + 1;
        }
        
    }
    return alunosAbaixo;

}