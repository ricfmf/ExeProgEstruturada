#include <stdio.h>
#include <string.h>

int main () {
    FILE* arq;
    char nomeArq[100], op, nome[30];
    int status;
    printf("Digite o nome do arquivo: ");
    fgets(nomeArq, 100, stdin);
    nomeArq[strcspn(nomeArq, "\n")] = '\0';
    
    arq = fopen(nomeArq, "at");

    if (arq)
    {
        printf("Arquivo %s aberto com sucesso. \n", nomeArq);
        while (1)
        {
            printf("Informe um nome: ");
            fgets(nome, 30, stdin);
            nome[strcspn(nome, "\n")]  = '\0';
            if (strcmp(nome, "") == 0)
            {
                break;
            }
            else
            {
                fputs(nome, arq);
                fputs("\n", arq);
            }
        }
        
        status = fclose(arq);
        if (status == 0)
        {
            printf("Arquivo %s fechado com sucesso. \n", nomeArq);
        }
        else
        {
            printf("Erro ao tentar fechar o aruivo %s. \n", nomeArq);
        }
        
    }
    else
    {
        printf("O arquivo %s nao existe. Gostaria de criar um novo arquivo? (S/N) \n", nomeArq);
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
                while (1)
                {
                    printf("Informe um nome: ");
                    fgets(nome, 30, stdin);
                    nome[strcspn(nome, "\n")]  = '\0';
                    if (strcmp(nome, "\n"))
                    {
                        break;
                    }
                    else
                    {
                        fputs(nome, arq);
                    }
                }
        
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
    }
    

    return 0;
}