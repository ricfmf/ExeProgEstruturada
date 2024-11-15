#include <stdio.h>
#include <string.h>
#define TAM 50

typedef struct funcionario
{
    char nome[30];
    char matricula[10];
    int grauEscolar;
    int tempoServ;
    float salario;

} Funcionario;

void preencher(Funcionario vetor[]);
void atualizarSalario(Funcionario vetor[]);
void exibir(Funcionario vetor[]);

int main() {
    Funcionario funcionario[TAM];

    preencher(funcionario);
    exibir(funcionario);
    atualizarSalario(funcionario);
    exibir(funcionario);

    return 0;
}

void preencher(Funcionario vetor[]) {
    int i;

    for ( i = 0; i < TAM; i++)
    {
        printf("Insira o nome do funcionario: ");
        fgets(vetor[i].nome, 30, stdin);
        vetor[i].nome[strcspn(vetor[i].nome, "\n")] = '\0';
        printf("Insira a matricula: ");
        fgets(vetor[i].matricula, 10, stdin);
        vetor[i].matricula[strcspn(vetor[i].matricula, "\n")] = '\0';
        printf("Insira o grau de escolaridade: ");
        scanf("%d", &vetor[i].grauEscolar);
        printf("Insira o tempo de servico: ");
        scanf("%d", &vetor[i].tempoServ);
        printf("Insira o salario: ");
        scanf("%f", &vetor[i].salario);
        getchar();
    }
    
}

void atualizarSalario(Funcionario vetor[]) {
    int i;

    for ( i = 0; i < TAM; i++)
    {
        if (vetor[i].grauEscolar == 3 && vetor[i].tempoServ >= 5 && vetor[i].salario < 1000)
        {
            vetor[i].salario = (vetor[i].salario * 0.2) + vetor[i].salario;
        }
        
    }
    
}

void exibir(Funcionario vetor[]) {
    int i;

    for ( i = 0; i < TAM; i++)
    {
        printf("Nome: %s \n", vetor[i].nome);
        printf("Matricula: %s \n", vetor[i].matricula);
        printf("Grau de escolaridade: %d \n", vetor[i].grauEscolar);
        printf("Tempo de servico: %d \n", vetor[i].tempoServ);
        printf("Salario: %f \n", vetor[i].salario);
    }
    

}