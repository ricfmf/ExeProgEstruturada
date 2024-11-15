#include <stdio.h>
#include <string.h>
#define TAM 100

typedef struct produto
{
    char codigo[10];
    char descricao[100];
    char nomeFornecedor[50];
    int qtdMinima;
    int qtdReal;
} Produto;

void cadastro(Produto vetor[]);
void pesquisa(Produto vetor[]);
int main() {
    Produto produto[TAM];

    cadastro(produto);
    pesquisa(produto);

    return 0;
}

void cadastro(Produto vetor[]) {
    int i;

    for ( i = 0; i < TAM; i++)
    {
        printf("Insira o codigo : ");
        fgets(vetor[i].codigo, 10, stdin);
        vetor[i].codigo[strcspn(vetor[i].codigo, "\n")] = 0;
        printf("Insira a sua descricao: ");
        fgets(vetor[i].descricao, 100, stdin);
        vetor[i].descricao[strcspn(vetor[i].descricao, "\n")] = 0;
        printf("Insira o nome do fornecedor: ");
        fgets(vetor[i].nomeFornecedor, 50, stdin);
        vetor[i].nomeFornecedor[strcspn(vetor[i].nomeFornecedor, "\n")] = 0;
        printf("Insira a quantidade minima em estoque do produto: ");
        scanf("%d", &vetor[i].qtdMinima);
        printf("Insira a quantidade real em estoque do produto: ");
        scanf("%d", &vetor[i].qtdReal);
        getchar();
    }
    
}


void pesquisa(Produto vetor[]) {
    int i;

    for ( i = 0; i < TAM; i++)
    {
        if (vetor[i].qtdReal < vetor[i].qtdMinima)
        {
            printf("Codigo: %s \n", vetor[i].codigo);
            printf("Descricao: %s \n", vetor[i].descricao);
            printf("Fonecedor: %s \n", vetor[i].nomeFornecedor);
        }
        
    }
    
}