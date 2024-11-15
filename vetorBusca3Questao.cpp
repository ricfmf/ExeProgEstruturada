#include <stdio.h>
#define TAM 100

void inserir(float* vetor, int* qtd, float valor);
int buscaBinaria(float* vetor, int qtd, float valor);
void exibir(float* vetor, int qtd);
void remover(float* vetor, int* qtd, float valor);
void exibirOpcoes();

int main() {
    float vetorPositivo[TAM], vetorNegativo[TAM], temp;
    int op, busca, quantidadePositiva = 0, quantidadeNegativa = 0;

    do
    {
        exibirOpcoes();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Informe o valor da temperatura: ");
            scanf("%f", &temp);
            if (temp >= 0)
            {
                inserir(vetorPositivo, &quantidadePositiva, temp);
            }
            else {
                inserir(vetorNegativo, &quantidadeNegativa, temp);
            }
            break;
        case 2:
            printf("Informe o valor a ser buscado: ");
            scanf("%f", &temp);
            if (temp >= 0)
            {
                busca = buscaBinaria(vetorPositivo, quantidadePositiva, temp);
                printf("%d", busca);
            }
            else {
                busca = buscaBinaria(vetorNegativo, quantidadeNegativa, temp);
                printf("%d", busca);
            }
            break;
        case 3:
            exibir(vetorPositivo, quantidadePositiva);
            break;
        case 4:
            exibir(vetorNegativo, quantidadeNegativa);
            break;
        case 5:
            printf("Insira o valor de temperatura a ser removido: ");
            scanf("%f", &temp);
            if (temp >= 0)
            {
                remover(vetorPositivo, &quantidadePositiva, temp);
            }
            else {
                remover(vetorNegativo, &quantidadeNegativa, temp);
            }
            break;
        case 0:
            printf("Tchau. \n");
            break;
        default:
            printf("Opcao invalida. \n");
            break;
        }
    } while (op != 0);
    

    return 0;
}

void inserir(float* vetor, int* qtd, float valor) {
    int retorno;

    if (*qtd == TAM)
    {
        printf("Vetor cheio! Insercao nao realizada. \n");
    }
    else {
        retorno = buscaBinaria(vetor, *qtd, valor);
        if (retorno == -2)
        {
            vetor[0] = valor;
            (*qtd)++;
            printf("Valor inserido! \n");
        }
        else if (retorno == -1)
        {
            vetor[*qtd] = valor;
            (*qtd)++;
            printf("Valor inserido! \n");
        }
        else {
            if (vetor[retorno] == valor)
            {
                printf("Valor repetido! Insercao nao realizada. \n");
            }
            else {
                for (int i = *qtd; i > retorno; i--)
                {
                    vetor[i] = vetor[i-1];
                }
                vetor[retorno] = valor;
                (*qtd)++;
                printf("Valor inserido! \n");
            }
        }

    }
    
}

int buscaBinaria(float* vetor, int qtd, float valor) {
    int inicio = 0, meio, final = qtd - 1, retorno = -1;

    if (qtd == 0)
    {
        retorno = -2;
        return retorno;
    }
    
    else {
        while (inicio <= final)
        {
            meio = (inicio + final) / 2;
            if (vetor[meio] == valor)
            {
                return meio;
            }
            else if (vetor[meio] < valor)
            {
                inicio = meio + 1;
                meio = (inicio + final) / 2;
            }
            else {
                final = meio - 1;
                meio = (inicio + final) / 2;
            }
        }
        return retorno;
    }
}

void exibir(float* vetor, int qtd) {
    if (qtd == 0)
    {
        printf("Vetor vazio! \n");
    }
    else {
        for (int i = 0; i < qtd; i++)
        {
            printf("%f ", vetor[i]);
        }
        printf("\n");
    }
}

void remover(float* vetor, int* qtd, float valor) {
    int retorno;
    retorno = buscaBinaria(vetor, *qtd, valor);

    if (retorno == -1 || retorno == -2)
    {
        printf("O valor nao esta presente no vetor. \n");
    }
    else {
        for (int i = retorno; i < *qtd-1; i++)
        {
            vetor[i] = vetor[i+1];
        }
        (*qtd)--;
        printf("Remocao feita com sucesso! \n");
    }
}

void exibirOpcoes() {
    printf("MENU PRINCIPAL \n\n");
    printf ("1 - Inserir novo valor de temperatura \n");
    printf ("2 - Procurar valor de temperatura \n");
    printf ("3 - Exibir temperaturas positivas \n");
    printf ("4 - Exibir temperaturas negativas \n");
    printf ("5 - Remover valor de temperatura \n");
    printf ("0 - Encerrar programa \n");
    printf ("Informe a opcao desejada: ");
}
