#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 50

typedef struct agenda
{
    char nome[30];
    char email[25];
    char telefone[11];
} Agenda;

void cadastrar(Agenda vetor[], int *qtdCadastrada, char nome[30]);
void exibirTotal(Agenda vetor[], int qtdCadastrada);
int pesquisa(Agenda vetor[], int qtdCadastrada, char nome[30]);
void exibirDados(Agenda vetor[], int qtdCadastrada, char nome[30]);
void alterarDados(Agenda vetor[], int qtdCadastrada, char nome[30]);
void remover(Agenda vetor[], int *qtdCadastrada, char nome[30]);
void menu();
int main() {
    Agenda agenda[TAM];
    int qtdContatosCadastrados = 0, op;
    char nome[30];

    do
    {
        menu();
        scanf("%d", &op);
        getchar();
        switch (op)
        {
        case 1:
            printf("Insira o nome: ");
            fgets(nome, 30, stdin);
            nome[strcspn(nome, "\n")] = '\0';
            cadastrar(agenda, &qtdContatosCadastrados, nome);
            break;
        case 2:
            exibirTotal(agenda, qtdContatosCadastrados);
            break;
        case 3:
            printf("Insira o nome: ");
            fgets(nome, 30, stdin);
            nome[strcspn(nome, "\n")] = '\0';
            exibirDados(agenda, qtdContatosCadastrados, nome);
            break;
        case 4:
            printf("Insira o nome: ");
            fgets(nome, 30, stdin);
            nome[strcspn(nome, "\n")] = '\0';
            alterarDados(agenda, qtdContatosCadastrados, nome);
            break;
        case 5:
            printf("Insira o nome: ");
            fgets(nome, 30, stdin);
            nome[strcspn(nome, "\n")] = '\0';
            remover(agenda, &qtdContatosCadastrados, nome);
            break;
        default:
            printf("Opcao invalida. \n");
            break;
        }
    } while (op != 0);
    


    return 0;
}

void cadastrar(Agenda vetor[], int *qtdCadastrada, char nome[30]) {
    int i;
    char temp[30];

    if (*qtdCadastrada >= TAM)
    {
        printf("Agenda cheia. \n");
        return;
    }
    


    for ( i = 0; i < *qtdCadastrada; i++)
    {
        if (strcmp(vetor[i].nome, nome) == 0)
        {
            printf("Nome ja existe na agenda. \n");
             return;
        }
        if (strcmp(nome, vetor[i].nome) < 0)
        {
            break;
        }
    }

    for (int j = *qtdCadastrada; j > i; j--)
            {
                strcpy(vetor[j].nome, vetor[j-1].nome);
                strcpy(vetor[j].email, vetor[j-1].email);
                strcpy(vetor[j].telefone, vetor[j-1].telefone);
            }
    strcpy(vetor[i].nome, nome);
    printf("Insira o email: ");
    fgets(vetor[i].email, 25, stdin);
    vetor[i].email[strcspn(vetor[i].email, "\n")] = '\0';
    printf("Insira o telefone: ");
    fgets(vetor[i].telefone, 11, stdin);
    vetor[i].telefone[strcspn(vetor[i].telefone, "\n")] = '\0';
    (*qtdCadastrada)++;
}


void exibirTotal(Agenda vetor[], int qtdCadastrada) {
    int i;
    
    for ( i = 0; i < qtdCadastrada; i++)
    {
        printf("Nome: %s \n", vetor[i].nome);
        printf("Email: %s \n", vetor[i].email);
        printf("Telefone: %s \n", vetor[i].telefone);
    }
    
}

int pesquisa(Agenda vetor[], int qtdCadastrada, char nome[30]) {
    int inicio = 0, meio, fim = qtdCadastrada-1, achou = 0;

    do
    {
        meio = (inicio + fim) / 2;
        if (strcmp(vetor[meio].nome, nome) == 0)
        {
            achou = 1;
            break;
        }
        else if (strcmp(vetor[meio].nome, nome) < 0)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
        
    } while (inicio <= fim);
    if (achou == 1)
    {
        return meio;
    }
    else
    {
        return -1;
    }
}

void exibirDados(Agenda vetor[], int qtdCadastrada, char nome[30]) {
    int resultado;

    resultado = pesquisa(vetor, qtdCadastrada, nome);

    if (resultado == -1)
    {
        printf("Um contato com esse nome nao exite na agenda. \n");
    }
    else
    {
        printf("Nome: %s \n", nome);
        printf("Email: %s \n", vetor[resultado].email);
        printf("Telefone: %s \n", vetor[resultado].telefone);
    }
}

void alterarDados(Agenda vetor[], int qtdCadastrada, char nome[30]) {
    int resultado;

    resultado = pesquisa(vetor, qtdCadastrada, nome);

    if (resultado == -1)
    {
        printf("Um contato com esse nome nao exite na agenda. \n");
    }
    else
    {
        printf("Insira o novo email do contato: ");
        fgets(vetor[resultado].email, 25, stdin);
        vetor[resultado].email[strcspn(vetor[resultado].email, "\n")] = '\0';
        printf("Insira o novo telefone do contato: ");
        fgets(vetor[resultado].telefone, 11, stdin);
        vetor[resultado].telefone[strcspn(vetor[resultado].telefone, "\n")] = '\0';
    }


}

void remover(Agenda vetor[], int *qtdCadastrada, char nome[30]) {
    int resultado;

    resultado = pesquisa(vetor, *qtdCadastrada, nome);

    if (resultado == -1)
    {
        printf("Um contato com esse nome nao exite na agenda. \n");
    }
    else
    {
        for (int i = resultado; i < *qtdCadastrada-1; i++)
        {
            strcpy(vetor[i].nome, vetor[i+1].nome);
            strcpy(vetor[i].email, vetor[i+1].email);
            strcpy(vetor[i].telefone, vetor[i+1].telefone);
        }
        (*qtdCadastrada)--;
    }
}


void menu() {
    printf("Agenda de contatos - Informe a opcao desejada. \n");
    printf("1 - Cadastrar um novo contato \n");
    printf("2 - Exibir todos os contatos \n");
    printf("3 - Exibir dados (email e telefone) de um contato \n");
    printf("4 - Alterar dados (email e telefone) de um contato \n");
    printf("5 - Excluir um contato \n");
    printf("0 - Encerrar o programa \n");
}