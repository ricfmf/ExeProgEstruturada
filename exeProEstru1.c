#include <stdio.h>

float credito (float saldo) {
    float credito;
    if (saldo > 0 && saldo <= 200) {
        credito = saldo * 0.1;
        return credito;
    } 
    else if (saldo <= 300) {
        credito = saldo * 0.2;
        return credito;
    }
    else if (saldo <= 400) {
        credito = saldo * 0.25;
        return credito;
    }
    else if (saldo > 400)
    {
        credito = saldo *0.3;
        return credito;
    }
     else {
        printf("O cliente nao tera direito ao beneficio \n");
     }
     return credito;
}

void exibeOpcoes () {
    printf("Deseja efetuar um novo calculo? \n");
    printf("Digite 'S' para continuar \n");
    printf("Digite 'N' para sair \n");
}

int main() {
    float saldo, res;
    char op;
        
    do
    {
        exibeOpcoes();
        scanf("%c", &op);
        if (op == 'S') {
            printf("Qual o saldo medio no ultimo ano? \n");
            scanf("%f", &saldo);
            res = credito(saldo);
            printf("O credito sera de %f \n", res);
        }
        else if (op != 'S' && op != 'N' ){
            printf("Por favor, digite uma resposta valida \n");
        }
        
    } while ( op != 'N');
    
    return 0;
}