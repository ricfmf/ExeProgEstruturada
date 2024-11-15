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
    char nomeArq [50];
    char nome [100];
    int count = 0;

    printf ("Informe o nome do arquivo: ");
    fgets(nomeArq,50,stdin);
    nomeArq[strcspn(nomeArq, "\n")] = '\0'; 
    arq = prepararArquivo (nomeArq);
    if (arq == NULL) {
        printf ("Erro ao tentar criar/abrir o arquivo %s \n",  nomeArq);
    }
    else { // arquivo pronto para uso
        while (!feof(arq)) {
            fgets(nome,99,arq);
            if (strstr(nome, "Maria Clara") != NULL)
            {
                count++;
            }
        }
        printf("Neste arquivo, a sequencia \"Maria Clara\" aparece %d vezes.", count);
        liberarArquivo(arq, nomeArq);
    }
}
