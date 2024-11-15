#include <stdio.h>
#include <string.h>
#define TAM 40

typedef struct produtos
{
    char codigo[10];
    char descricao[100];
    float valorUnitario;
    int qtdEstoque;
} Produtos;

void cadastro(Produtos vetor[],int* qtdCadastro, char codigo[10]);
int verificaCodigo(Produtos vetor[], int qtdCadastro, char codigo[10]);
void alterarValor(Produtos vetor[], int qtdCadastro, char codigo[10]);
void venda(Produtos vetor[], int qtdCadastro, char codigo[10], int qtdVenda);
void atualizarQtdEstoque(Produtos vetor[], int qtdCadastro, char codigo[10]);
void exibirTotal(Produtos vetor[], int qtdCadastro);
void exibirEstoqueZero(Produtos vetor[], int qtdCadastro);
void menu();
int main() {
    Produtos produtos[TAM];
    int qtdProdutosCadastrados = 0, op, qtdVenda;
    char codigoCadastro[10];

    do
    {
        menu();
        scanf("%d", &op);
        getchar();  
        switch (op)
        {
        case 1:
            printf("Insira o codigo do produto: ");
            fgets(codigoCadastro, 10, stdin);
            codigoCadastro[strcspn(codigoCadastro, "\n")] = '\0';
            cadastro(produtos, &qtdProdutosCadastrados, codigoCadastro);
            break;
        case 2:
            printf("Insira o codigo do produto: ");
            fgets(codigoCadastro, 10, stdin);
            codigoCadastro[strcspn(codigoCadastro, "\n")] = '\0';
            alterarValor(produtos, qtdProdutosCadastrados, codigoCadastro);
            break;
        case 3:
            printf("Insira o codigo do produto: ");
            fgets(codigoCadastro, 10, stdin);
            codigoCadastro[strcspn(codigoCadastro, "\n")] = '\0';
            printf("Insira a quantidade de venda: ");
            scanf("%d", &qtdVenda);
            venda(produtos, qtdProdutosCadastrados, codigoCadastro, qtdVenda);
            break;
        case 4:
            printf("Insira o codigo do produto: ");
            fgets(codigoCadastro, 10, stdin);
            codigoCadastro[strcspn(codigoCadastro, "\n")] = '\0';
            atualizarQtdEstoque(produtos, qtdProdutosCadastrados, codigoCadastro);
            break;
        case 5:
            exibirTotal(produtos, qtdProdutosCadastrados);
            break;
        case 6:
            exibirEstoqueZero(produtos, qtdProdutosCadastrados);
            break;
        case 0:
            printf("Programa encerrado. \n");
            break;
        default:
            printf("Opcao invalida. \n");
            break;
        }
    } while (op != 0);
    

    return 0;
}

void cadastro(Produtos vetor[],int* qtdCadastro, char codigo[10]) {
    int pos, qtdcadastro, qtdproduto;
    qtdcadastro = *qtdCadastro;
    pos = verificaCodigo(vetor, qtdCadastro, codigo);
    if (qtdCadastro == 40)
    {
        printf("Quantidade maxima de produtos cadastrados ja foi atingida. \n");
    }
    else
    {
        if (pos == -1)
        {
            strcpy(vetor[qtdcadastro].codigo, codigo);
            printf("Insira a descricao do produto: ");
            fgets(vetor[qtdcadastro].descricao, 100, stdin);
            vetor[qtdcadastro].descricao[strcspn(vetor[qtdcadastro].descricao, "\n")] = '\0';
            printf("Insira o valor unitario do produto: ");
            scanf("%f", &vetor[qtdcadastro].valorUnitario);
            printf("Insira a quantidade: ");
            scanf("%d", &qtdproduto);
            vetor[qtdcadastro].qtdEstoque = qtdproduto;
            (*qtdCadastro)++;
        }
        else
        {
            printf("Um produto com esse codigo ja esta cadastrado. \n");
        }
    }
}

int verificaCodigo(Produtos vetor[], int qtdCadastro, char codigo[10]) {
    int i;

    for ( i = 0; i < qtdCadastro; i++)
    {
        if (strcmp(codigo, vetor[i].codigo) == 0)
        {
            return i;
        }
    }
    return -1;
}

void alterarValor(Produtos vetor[], int qtdCadastro, char codigo[10]) {
    int pos, qtdcadastro;
    qtdcadastro = qtdCadastro;
    pos = verificaCodigo(vetor, qtdCadastro, codigo);
    
    if (pos == -1)
    {
        printf("O produto informado nao esta cadastrado. \n");
    }
    else
    {
        printf("Insira o novo valor do produto: ");
        scanf("%f", &vetor[pos].valorUnitario);
    }
}

void venda(Produtos vetor[], int qtdCadastro, char codigo[10], int qtdVenda) {
    int pos;
    char choice;
    pos = verificaCodigo(vetor, qtdCadastro, codigo);

    if (pos == -1)
    {
        printf("O produto informado nao esta cadastrado. \n");
    }
    else
    {
        if (qtdVenda <= vetor[pos].qtdEstoque)
        {
            vetor[pos].qtdEstoque -= qtdVenda;
            printf("O valor a ser pago e de: %.2f \n", vetor[pos].valorUnitario*qtdVenda);
        }
        else if (vetor[pos].qtdEstoque == 0)
        {
            printf("O produto informado esta em falta no estoque. \n");
        }
        else if (qtdVenda >= vetor[pos].qtdEstoque)
        {
            printf("Ha apenas %d produtos no estoque. Gostaria de comprar? S/N\n", vetor[pos].qtdEstoque);
            scanf("%c", &choice);
            if (choice == 'S')
            {
                vetor[pos].qtdEstoque = 0;
                printf("O valor a ser pago e de: %.2f \n", vetor[pos].valorUnitario*qtdVenda);
            }
        }
    }
}

void atualizarQtdEstoque(Produtos vetor[], int qtdCadastro, char codigo[10]) {
    int pos, novoEstoque;
    pos = verificaCodigo(vetor, qtdCadastro, codigo);

    if (pos == -1)
    {
        printf("O produto informado nao esta cadastrado. \n");
    }
    else
    {
        printf("Insira quantidade a ser acrescida ao estoque: ");
        scanf("%d", &novoEstoque);
        vetor[pos].qtdEstoque += novoEstoque;
    }
}

void exibirTotal(Produtos vetor[], int qtdCadastro) {
    int i;

    for ( i = 0; i < qtdCadastro; i++)
    {
        printf("Codigo: %s \n", vetor[i].codigo);
        printf("Descricao: %s \n", vetor[i].descricao);
    }
    
}

void exibirEstoqueZero(Produtos vetor[], int qtdCadastro) {
    int i;

    for ( i = 0; i < qtdCadastro; i++)
    {
        printf("Codigo: %s \n", vetor[i].codigo);
        printf("Descricao: %s \n", vetor[i].descricao);
    }
    
}

void menu() {
    printf("Papelaria Escolar - Informe a opcao desejada. \n");
    printf("1 - Cadastrar produto \n");
    printf("2 - Alterar valor unitario \n");
    printf("3 - Vender um produto \n");
    printf("4 - Atualizar estoque \n");
    printf("5 - Exibir todos os produtos cadastrados \n");
    printf("6 - Exibir todos os produtos com estoque zero \n");
    printf("0 - Encerrar o programa \n");
    printf("Digite a opcao: ");
}
    