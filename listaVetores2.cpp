#include <stdio.h>
#define TAM 50

void exibirOpcoes ();
void insercao(int* vet, int* qtd, int valor);
int buscaSimples (int* vet, int quant, int valor);
void exibir(int* vetor, int qtd);

void exibirOpcoes () {
    printf ("1 - Inserir valor \n");
    printf ("2 - Exibir valores \n");
    printf("3 - Busca de valor \n");
    printf ("0 - Encerrar programa \n");
    printf ("Informe a opcao desejada: ");
}



void insercao(int* vet, int* qtd, int valor) {

    int retorno;

    if (*qtd == TAM)
    {
        printf("Vetor cheio! Nao e possivel fazer a insercao \n");
    }

    else {
        retorno = buscaSimples(vet, *qtd, valor);
        if (retorno  == -1 || retorno == -2)
        {
        vet[*qtd] = valor;
        *qtd = *qtd + 1;
        printf("Valor inserido! \n");
        }
        
        else {
            printf("Valor nao pode ser inserido \n");
        }

    }
    
}

int buscaSimples (int* vet, int quant, int valor) {
    int i, achou = -1;
    if (quant == 0) {
        return -2;  
    }
    else {
        for (i = 0; i < quant; i++) {
            if (vet[i] == valor) {
                achou = i; 
                break;
            }
        }
        return achou;
    }
}


void exibir(int* vetor, int qtd) {

    int i;
    if (qtd == 0)
    {
        printf("Vetor vazio \n");
    }
    else {
        for ( i = 0; i < qtd; i++)
        {
            printf("%d ", vetor[i]);
        }
        printf("\n");
        
    }
    
}

int main() {

    int vetorA[TAM], vetorB[TAM], quantidadePar = 0,quantidadeImpar = 0, valor, op, choice;

    do
    {
        exibirOpcoes();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Insira o valor: \n");
            scanf("%d", &valor);
            if (valor % 2 == 0)
            {
                insercao(vetorA, &quantidadePar, valor);
            }
            else {
                insercao(vetorB, &quantidadeImpar, valor);
            }    
            break;
        case 2:
            printf("1 - para ver os numeros pares \n");
            printf("2 - para os numeros impares \n");
            scanf("%d", &valor);
            if (valor == 1)
            {
                exibir(vetorA, quantidadePar);
            }
            else if (valor == 2)
            {
                exibir(vetorB, quantidadeImpar);
            }
            else {
                printf("Opcao invalida! ");
            }
            break;
        
        case 3:
            printf("Digite o valor para buscar: \n");
            scanf("%d", &valor);
            if (valor % 2 == 0)
            {
                choice = buscaSimples(vetorA, quantidadePar, valor);
                printf("%d \n", choice);
            }
            else {
                choice = buscaSimples(vetorB, quantidadeImpar, valor);
                printf("%d \n", choice);
            }
            break;
        case 0:
            printf("Saida do programa \n");
            break;
        default:
            printf("Opcao invalida! \n");
            break;
        }
    } while (op != 0);

    return 0;
}