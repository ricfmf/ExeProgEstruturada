#include <stdio.h>

int main() {
    float preco;
    int desconto;
    printf ("Qual o preço do produto? \n");
    scanf ("%f", &preco);
    printf ("Qual o percentual de desconto? \n");
    scanf ("%d", &desconto);
    printf ("%f", &preco);
    printf ("%d", &desconto);
    
    return 0;
}