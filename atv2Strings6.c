#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define TAM 20

void preencher(char* pwd);
int validacao(char* pwd);
int main() {
    char pwd[TAM];
    int resultado;

    preencher(pwd);
    resultado = validacao(pwd);

    if (resultado == 0)
    {
        printf("Senha Invalida.");
    }
    else
    {
        printf("Senha Valida.");
    }

    return 0;
}

void preencher(char* pwd) {
    int i = 0;
    char c;

    while (i < TAM - 1)
    {
        c = getch();
        if(c == '\n')
        {
            break;
        }
        pwd[i] = c;
        printf("*");
        i++;
    }
    pwd[i] = '\0';
}

int validacao(char* pwd) {
    int i, size;
    int upper = 0, lower = 0, digit = 0, sym = 0;

    size = strlen(pwd);

    if (size < 8 || size > 20)
    {
        return 0;
    }
    else
    {
        for ( i = 0; pwd[i] != '\0'; i++)
        {
            if (isupper(pwd[i]))
            {
                upper++;
            }
            else if (islower(pwd[i]))
            {
                lower++;
            }
            else if (isdigit(pwd[i]))
            {
                digit++;
            }
            else if (pwd[i] == '$' || pwd[i] == '%' || pwd[i] == '&' || pwd[i] == '@' || pwd[i] == '#' || pwd[i] == '*' || pwd[i] == '?' || pwd[i] == ':')
            {
                sym++;
            }
            else
            {
                return 0;
            }
        }
        if (upper < 1 || lower < 1 || digit < 1 || sym < 1)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }


}