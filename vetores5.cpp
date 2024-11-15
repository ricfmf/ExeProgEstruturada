#include <stdio.h>


void exibeOpcoes () {

    printf("0 - Voto em branco \n");
    printf("1 - Voto em Joao \n");
    printf("2 - Voto em Maria \n");
    printf("3 - Voto em Pedro \n");
    printf("4 - Voto em Luis \n");
    printf("5 - Voto em Ana \n");
    printf("6 - Voto em Luiza \n");
    printf("7 - Voto em Silvia \n");
    printf("8 - Voto em Andre \n");

}

int main() {

    int total[10] = {0};
    int op, i;
    float cont;
    char provoto;

    do
    {
        exibeOpcoes();
        scanf("%d", &op);
        if (op < 0 || op > 8)
        {
            total[9] = total[9] + 1;
            cont++;
        }
        else
        {
            for ( i = 0; i < 9; i++)
            {
                if (i == op)
                {
                    total[op] = total[op] + 1;
                    cont++;
                }
                   
            }
            
        }

        do {
            printf("Ainda ha alguem para votar? 'S' ou 'N' \n");
            scanf("%c", &provoto);

            if (provoto != 'S' && provoto != 's' && provoto != 'N' && provoto != 'n')
            {
                printf("Resposta invalida! \n");
            }
            
        }
            while (provoto != 'S' && provoto != 's' && provoto != 'N' && provoto != 'n');
    }
    while(provoto == 'S' || provoto == 's');


    printf("Total de Votos \n\n");
    printf("Branco  Joao  Maria  Pedro  Luis  Ana  Luiza  Silvia  Andre \n");
    for ( i = 0; i < 10; i++)
    {
        printf("  %d   ", total[i]);
    }
    printf("\n");
    printf("Percentual dos votos \n\n");
    printf("Branco        Joao        Maria        Pedro        Luis        Ana        Luiza        Silvia        Andre \n");
    for ( i = 0; i < 10; i++)
    {
        printf("%f  ", (total[i] / cont) * 100);
    }
    

    return 0;
    }
    
