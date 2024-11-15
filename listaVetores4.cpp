#include <stdio.h>
#define TAM 100

void inserir(float* vetor, int* qtd,float num);
int buscaMelhorada(float* vetor, int qtd, float valor);
void remover(float* vetor, int* qtd, float valor);
void exibir (float* vet, int quant);
void exibirOpcoes ();

int main() {
    float vetorOrdenado[TAM] = {0}, valor;
    int quantidade = 0, op;

    do {
        exibirOpcoes();
        scanf ("%d",&op);
        switch(op) {
            case 1: printf ("Informe o valor: ");
                    scanf ("%f", &valor);
                    inserir (vetorOrdenado, &quantidade, valor);
                    break;
            case 2: exibir (vetorOrdenado, quantidade);
                    break;
            case 3: printf ("Informe o valor: ");
                    scanf ("%f", &valor);
                    remover (vetorOrdenado, &quantidade, valor);
                    break;
            case 0: printf ("Bye bye \n");
                    break;
            default: printf ("Opção inválida\n");
        }
    } while (op != 0);

    return 0;
}

void inserir(float* vetor, int* qtd,float num) {
    int retorno;

    if (*qtd == TAM)
    {
        printf("Vetor Cheio! Nao pode ser realizada a insercao. \n");
    }
    else
    {
        retorno = buscaMelhorada(vetor, *qtd, num);
        if (retorno == -2)
        {
            vetor[0] = num;
            (*qtd)++;
            printf("Valor inserido! \n");
        }
        else if (retorno == -1)
        {
            vetor[*qtd] = num;
            (*qtd)++;
            printf("Valor inserido! \n");
        }
        else {
            if (vetor[retorno] == num)
            {
                printf("Valor repetido! Insercao nao realizada. \n");
            }
            else {
                for (int i = *qtd; i > retorno; i--)
                {
                    vetor[i] = vetor[i-1];
                }
                vetor[retorno] = num;
                (*qtd)++;
                printf("Valor inserido! \n");
            }
        }
    }
}

int buscaMelhorada(float* vetor, int qtd, float valor) {
    int i, retorno = -1;

    if (qtd == 0)
    {
        return -2;
    }
    else
    {
        for ( i = 0; i < qtd; i++)
        {
            if (vetor[i] <= valor)
            {
                retorno = i;
                break;
            }
        }
        return retorno;
    }
}

void remover(float* vetor, int* qtd, float valor) {
    int retorno;

    retorno = buscaMelhorada(vetor, *qtd, valor);
    if (retorno == -2 || retorno == -1)
    {
        printf("O valor nao esta presente no vetor! \n");
    }
    else {
        if (vetor[retorno] == valor)
        {
            for (int i = retorno; i < *qtd-1; i++)
            {
                vetor[i] = vetor[i+1];
            }
            (*qtd)--;
            printf("Remocao feita com sucesso! \n");
        }
        else {
            printf("O valor nao esta presente no vetor! \n");
        }
    }
}

void exibir (float* vet, int quant) {
    int i;
    if (quant == 0) {
        printf ("Vetor vazio! \n");
    }
    else {
        for (i = 0; i < quant; i++) {
            printf ("%f ", vet[i]);
        }
        printf ("\n");
    }
}

void exibirOpcoes () {
    printf ("1 - Inserir valor \n");
    printf ("2 - Exibir valores \n");
    printf ("3 - Remover valor \n");
    printf ("0 - Encerrar programa \n");
    printf ("Informe a opção desejada: ");
}

int buscaMelhorada (int* vet, int quant, int valor) {
    int i, pos = -1;
    if (quant == 0) {
        return -2;  
    }
    else {
        for (i = 0; i < quant; i++) {
            if (vet[i] >= valor) {
                pos = i; 
                break;
            }       
        }
        return pos;
    }
}

