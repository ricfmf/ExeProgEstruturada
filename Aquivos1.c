#include <stdio.h>
#include <string.h>

int main () {
    FILE* arq;
    char nomeArq[100], op;
    int status;
    printf("Digite o nome do arquivo: ");
    fgets(nomeArq, 100, stdin);
    nomeArq[strcspn(nomeArq, "\n")] = '\0';
    
    arq = fopen(nomeArq, "r");

    if (arq)
    {
        printf("O arquivo %s ja existe. Gostaria de apagar as informacoes e criar um novo arquivo? (S/N) \n", nomeArq);
        scanf(" %c", &op);
        if (op == 'S') 
        {
            arq = fopen(nomeArq, "w+t");
            if (arq == NULL)
            {
                printf("Erro ao tentar criar o arquivo %s. \n", nomeArq);
            }
            else
            {
                printf("Arquivo %s criado com sucesso. \n", nomeArq);
                status = fclose(arq);
                if (status == 0)
                {
                    printf("Arquivo %s fechado com sucesso. \n", nomeArq);
                }
                else
                {
                    printf("Erro ao tentar fechar o arquivo %s. \n", nomeArq);
                }
            
            }
        }
        else
        {
            printf("Programa encerrado. \n");
            return 0;
        }
        
        fclose(arq);
    }
    else 
    {
        arq = fopen(nomeArq, "w+t");
        if (arq == NULL)
        {
            printf("Erro ao tentar criar o arquivo %s. \n", nomeArq);
        }
        else
        {
            printf("Arquivo %s criado com sucesso. \n", nomeArq);
            status = fclose(arq);
            if (status == 0)
            {
                printf("Arquivo %s fechado com sucesso. \n", nomeArq);
            }
            else
            {
                printf("Erro ao tentar fechar o arquivo %s. \n", nomeArq);
            }
            
        }
        
        
    }
    

    return 0;
}