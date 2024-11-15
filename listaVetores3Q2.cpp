#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int jogarDado();
void realizarSimulacao(int* vetor);
void exibeResultado(int* resultado);

int main() {
    int vetorResultado[6] = {0}; 
    realizarSimulacao(vetorResultado);
    exibeResultado(vetorResultado);

    return 0;
}

int jogarDado() {
    int num;

        srand(time(NULL));
        num = (rand() % 6) + 1;
        return num;

    

}

void realizarSimulacao(int* vetor) {
    int i, resultado;

    for ( i = 0; i < 5; i++)
    {
        resultado = jogarDado();

        switch (resultado)
        {
        case 1:
            vetor[resultado - 1]++;
            break;
        
        case 2:
            vetor[resultado - 1]++;
            break;
        case 3:
            vetor[resultado - 1]++;
            break;
        case 4:
            vetor[resultado - 1]++;
            break;
        case 5:
            vetor[resultado - 1]++;
            break;
        case 6:
            vetor[resultado - 1]++;
            break;
        default:
            break;
        }
    }
    

}

void exibeResultado(int* resultado) {
    int i;

    for ( i = 0; i < 6; i++)
    {
        printf("%d ", resultado[i]);
    }
    
    
}