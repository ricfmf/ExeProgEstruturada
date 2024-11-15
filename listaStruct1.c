#include <stdio.h>
#include <string.h>
#define TAM 200

typedef struct habitantes
{
    char nome[30];
    float salario;
    int idade;
    char sexo;
    int qtdAbaixo;
} Habitantes;

typedef struct maiorMenor
{
    float maiorHomem, menorHomem, maiorMulher, menorMulher;
} MaiorMenor;

void preencher(Habitantes vetor[]);
float salarioMedioHomensDesem(Habitantes vetor[]);
MaiorMenor funcaoBusca(Habitantes vetor[]);
float calcularPercentualMulheres(Habitantes vetor[]);



int main() {
    Habitantes hab[TAM];
    float mediaIdadeDesem, percMulheres;
    MaiorMenor resultado;

    printf("Preencher os dados dos habitantes \n");
    preencher(hab);
    mediaIdadeDesem = salarioMedioHomensDesem(hab);
    printf("A media de idade dos homens desempregados e de: %.2f \n", mediaIdadeDesem);
    resultado = funcaoBusca(hab);
    printf("O maior salario dos homens e de: %.2f \n", resultado.maiorHomem);
    printf("O menor salario dos homens e de: %.2f \n", resultado.menorHomem);
    printf("O maior salario das mulheres e de: %.2f \n", resultado.maiorMulher);
    printf("O menor salario das mulheres e de: %.2f \n", resultado.menorMulher);

    percMulheres = calcularPercentualMulheres(hab);
    printf("O percentual de mulheres com idade entre 18 e 25 anos e possuem mais de 2 filhos e de: \n", percMulheres);

    return 0;
}

void preencher(Habitantes vetor[]) {
    int i;

    for ( i = 0; i < TAM; i++)
    {
        printf("Insira o nome do habitante: ");
        fgets(vetor[i].nome, 30, stdin);
        vetor[i].nome[strcspn(vetor[i].nome, "\n")] = '\0';
        printf("Insira o salario: ");
        scanf("%f", &vetor[i].salario);
        printf("Insira a idade: ");
        scanf("%d", &vetor[i].idade);
        //while (getchar() != '\n');
        printf("Insira o sexo (M/H): ");
        scanf("%c", &vetor[i].sexo);
        printf("Insira a quantidade de filhos abaixo de 18 anos: ");
        scanf("%d", &vetor[i].qtdAbaixo);
        while (getchar() != '\n');
    }
}

float salarioMedioHomensDesem(Habitantes vetor[]) {
    int i;
    float sum = 0, cont = 0;

    for ( i = 0; i < TAM; i++)
    {
        if (vetor[i].sexo == 'H' && vetor[i].salario == 0)
        {
            sum = sum + vetor[i].idade;
            cont++;
        }
    }
    if (cont > 0)
    {
        return sum/cont;
    }
    else
    {
        return 0;
    }

}

MaiorMenor funcaoBusca(Habitantes vetor[]) {
    float maiorH, menorH, maiorM, menorM;
    int i, numH = 0, numM = 0;
    MaiorMenor resul;

    for ( i = 0; i < TAM; i++)
    {
        if (vetor[i].sexo == 'H')
        {
            if (numH == 0)
            {
                maiorH = vetor[i].salario;
                menorH = vetor[i].salario;
                numH++;
            }
            else
            {
                if (vetor[i].salario > maiorH)
                {
                maiorH = vetor[i].salario;
                }
                else if (vetor[i].salario < menorH)
                {
                menorH = vetor[i].salario;
                }
            }

        }
        else
        {
            if (numM == 0)
            {
                maiorM = vetor[i].salario;
                menorM = vetor[i].salario;
                numM++;
            }
            else
            {
                if (vetor[i].salario > maiorM)
                {
                maiorM = vetor[i].salario;
                }
                else if (vetor[i].salario < menorM)
                {
                menorM = vetor[i].salario;
                }
            }

        }
    }
    resul.maiorHomem = maiorH;
    resul.menorHomem = menorH;
    resul.maiorMulher = maiorM;
    resul.menorMulher = menorM;

    return resul;
}

float calcularPercentualMulheres(Habitantes vetor[]) {
    int i;
    float total = 0, cont = 0;

    for ( i = 0; i < TAM; i++)
    {
        if (vetor[i].sexo == 'M')
        {
            total++;
            if (vetor[i].idade >= 18 && vetor[i].idade <= 25 && vetor[i].qtdAbaixo > 2)
            {
                cont++;
            }
        }
    }
    if (total> 0)
    {
        return (cont/total) * 100;
    }
    else
    {
        return 0;
    }

}
