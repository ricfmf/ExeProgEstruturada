#include <stdio.h>

#define TRUE 1
#define FALSE 0

int inputYear();
int verificarAnoBisssexto(int ano);
int determinarDia(int ano);
void calendario(int ano, int dayCode);

int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char* meses[] = 
{
    " ",
    "\n\n\nJaneiro",
    "\n\n\nFevereiro",
    "\n\n\nMarco",
    "\n\n\nAbril",
    "\n\n\nMaio",
    "\n\n\nJunho",
    "\n\n\nJulho",
    "\n\n\nAugusto",
    "\n\n\nSetembro",
    "\n\n\nOutubro",
    "\n\n\nNovembro",
    "\n\n\nDezembro"
};

int main() {
    int ano, dayCode, anoBissexto;

    ano = inputYear();
    dayCode = determinarDia(ano);
    verificarAnoBisssexto(ano);
    calendario(ano, dayCode);
    printf("\n");

    return 0;
}

int inputYear() {
    int ano;
    
    printf("Por favor, digite um ano: \n");
    scanf("%d", &ano);
    return ano;
}

int verificarAnoBisssexto(int ano) {
    if (ano % 4 == FALSE && ano % 100 != FALSE || ano % 400 == FALSE)
    {
        diasNoMes[2] = 29;
    }
    else {
        diasNoMes[2] = 28;
    }
}

int determinarDia(int ano) {
    int diaCode, d1, d2, d3;

    d1 = (ano - 1) % 4;
    d2 = (ano - 1) % 100;
    d3 = (ano - 1) % 400;

    diaCode = (ano + d1 - d2 + d3) % 7;
    return diaCode;
}

void calendario(int ano, int dayCode) {
    int mes, dia;

    for (mes = 1; mes <= 12; mes++)
    {
        printf("%s", meses[mes]);
        printf("\n\nDom  Seg  Ter  Qua  Qui  Sex  Sab\n ");


        for ( dia = 1; dia <= 1 + dayCode * 5; dia++)
        {
            printf(" ");
        }
        
        for ( dia = 1; dia <= diasNoMes[mes]; dia++)
        {
            printf("%d", dia);

            if ((dia + dayCode) % 7 > 0)
            {
                printf("   ");
            }
            else {
                printf("\n ");
            }
        }
        
        dayCode = (dayCode + diasNoMes[mes]) % 7;
    }
    
}