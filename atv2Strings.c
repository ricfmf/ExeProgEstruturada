#define TAM 100 
#define QTD 30
#include <stdio.h>
#include <string.h>
void preencher (char turma [QTD][TAM]) {
    int i;
    for (i = 0; i < QTD; i++) {
        printf ("Informe o nome do aluno %d: ", i+1);
        fgets(turma[i],TAM,stdin);
    }
}
void exibir (char turma [QTD][TAM]) {
    int i;
    for (i = 0; i < QTD; i++) {
        printf ("Aluno %d: %s \n", i+1, turma[i]);
    }
}

void bubblesort (char turma [][TAM], int n) {
    int i, pos, fim;
    char chave[TAM];
    int troca;
    fim = n-2;
    pos = 0;

    do
    {
        troca = 0;
        for ( i = 0; i <= fim; i++)
        {
            if (strcmp(turma[i], turma[i+1]) > 0)
            {
                strcpy(chave, turma[i]);
                strcpy(turma[i], turma[i+1]);
                strcpy(turma[i+1], chave);
                pos = i;
                troca = 1;
            }
        }
        fim = pos-1;
    } while (troca == 1);
}

int main () {
    char turma [QTD][TAM];
    printf ("Preencher os dados dos alunos \n");
    preencher (turma);
    bubblesort (turma, QTD);
    printf ("Alunos da turma: \n");
    exibir (turma);

    return 0;
}