#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 20

int checkCode(char* code);

int main() {
    char codigo[TAM];
    int resultado;

    printf("Digite o codigo: ");
    fgets(codigo, TAM, stdin);
    codigo[strcspn(codigo, "\n")] = '\0';
    resultado = checkCode(codigo);

    if (resultado == 1)
    {
        printf("O codigo %s nao e valido. Motivo: quantidade invalida de caracteres. \n", codigo);
    }
    else if (resultado == 2)
    {
        printf("O codigo %s nao e valido. Motivo: formato incorreto. \n", codigo);
    }
    else {
        printf("O codigo %s e valido. ", codigo);
    }


    return 0;
}

int checkCode(char* code) {
    int i, tamanho;
    tamanho = strlen(code);

    if (tamanho != 9)
    {
        return 1;
    }
    else if (code[0] != 'a' && code[0] != 'A')
    {
        return 2;
    }
        
    for ( i = 1; i < 4; i++)
    {
        if (isalpha(code[i]) == 0)
        {
            return 2;
        }
    }
    for ( i = 4; i < 9; i++)
    {
        if (isdigit(code[i]) == 0)
        {
            return 2;
        }
    }
    return 3;

}