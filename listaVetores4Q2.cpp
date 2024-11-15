#include <stdio.h>
#define TAM 10

int main() {

    return 0;
}

void inserir (int* vet, int* quant, int valor, int* vetB) {
    int retorno, i;
    if (*quant == TAM) {
        printf ("Vetor cheio! Inserção não realizada! \n");
    }
    else {
        retorno = buscaMelhorada (vet, *quant, valor, vetB);
        if (retorno == -2) { // vetor vazio
            vet[0] = valor;
            *quant = *quant + 1;
            printf ("Valor inserido! \n");
        }
        else if (retorno == -1) { // Inserção no final do vetor!
            vet[*quant] = valor;
            *quant = *quant + 1;
            printf ("Valor inserido! \n");
        }
        else {
            if (vet[retorno] == valor) {
                for (i = *quant; i > retorno; i--) { // Mover valores para liberar a posição para inserção
                    vet[i] = vet[i-1];
                }
                vet[retorno] = valor;
                *quant = *quant + 1;
                printf ("Valor inserido! \n");
            }
            else {
                for (i = *quant; i > retorno; i--) { // Mover valores para liberar a posição para inserção
                    vet[i] = vet[i-1];
                }
                vet[retorno] = valor;
                *quant = *quant + 1;
                printf ("Valor inserido! \n");
            }
        }
    }
}

void exibir (int* vet, int quant) {
    int i;
    if (quant == 0) {
        printf ("Vetor vazio! \n");
    }
    else {
        for (i = 0; i < quant; i++) {
            printf ("%d ", vet[i]);
        }
        printf ("\n");
    }
}

void remover (int* vet, int* quant, int valor, int* vetB) {
    int pos, i;
    pos = buscaMelhorada (vet, *quant, valor, vetB);
    if (pos == -2) {
        printf ("Vetor está vazio! \n");
    }
    else if (pos == -1) {
        printf ("Valor não encontrado! \n!");
    }
    else { // achou!!!!
        for (i = pos; i < *quant- 1;i++) { // mover os valores uma posição à frente
            vet[i] = vet[i+1];
        }
        (*quant)--;
        printf ("Remoção efetuada! \n!");
    }
}

void exibirOpcoes () {
    printf ("1 - Inserir valor \n");
    printf ("2 - Exibir valores \n");
    printf ("3 - Remover valor \n");
    printf ("0 - Encerrar programa \n");
    printf ("Informe a opção desejada: ");
}

