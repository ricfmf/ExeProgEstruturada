#include <stdio.h>
#include <string.h>
FILE* prepararArquivo(char* nome) {
    FILE* aux;
    aux = fopen (nome,"r");
    return aux;
}

void liberarArquivo (FILE* arquivo, char* nome) {
    int status;
    status = fclose (arquivo);
    if (status == 0) {
        printf ("Arquivo %s fechado com sucesso! \n", nome);
    }
    else {
        printf ("Erro ao tentar fechar o arquivo %s.\n", nome);
    }
}

int main () {
    FILE* arq;
    char nomeArq [50], caractere;
    int count = 0;

    printf ("Informe o nome do arquivo: ");
    fgets(nomeArq,50,stdin);
    nomeArq[strcspn(nomeArq, "\n")] = '\0'; 
    arq = prepararArquivo (nomeArq);
    if (arq == NULL) {
        printf ("Erro ao tentar criar/abrir o arquivo %s \n",  nomeArq);
    }
    else { // arquivo pronto para uso
        while (caractere = fgetc(arq) != EOF) {            
            count++;
        }
        printf("Total de linhas no arquivo: %d", count);
        liberarArquivo(arq, nomeArq);
    }
}
