#include <stdio.h>
#define N 10

int main (){

    unsigned char anterior, atual, proximo;
    unsigned char suavizado;

    puts("Insira o valor da variavel x1");
    scanf("%hhu", &anterior);
    puts("Insira o valor da variavel x2");
    scanf("%hhu", &atual);

    for(int i = 2; i <= N; i++){
        printf("Insira o valor de x%d\n",i+1);
        scanf("%hhu", &proximo);

        suavizado = (anterior + atual + proximo)/3;

        printf("O sinal suavizado y%d = %hhu\n", i-1, suavizado);

        anterior = atual;
        atual = proximo;
    }
    return 0;
}
