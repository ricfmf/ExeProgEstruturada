#include <stdio.h>

int main() {
    int idade, votantes = 0, naoVotantes = 0;
    int total = 100;
    int cont = 0;

    do {
        printf("Digite a idade da pessoa %d: ", cont + 1);
        scanf("%d", &idade);

        if (idade < 0 || idade > 120) {
            printf("Idade inválida. Digite uma idade entre 0 e 120.\n");
            continue;
        }

        if (idade >= 18 && idade <= 90) {
            printf("Esta pessoa tem %d anos e pode votar.\n", idade);
            votantes++;
        } else {
            printf("Esta pessoa tem %d anos e não pode votar.\n", idade);
            naoVotantes++;
        }

        cont++;
    } while (cont < total);

    float percVotantes = (votantes / (float)total) * 100;
    float percNaoVotantes = (naoVotantes / (float)total) * 100;

    printf("\nTotal de votantes: %d (%f)\n", votantes, percVotantes);
    printf("Total de não votantes: %d (%f)\n", naoVotantes, percNaoVotantes);

    return 0;
}