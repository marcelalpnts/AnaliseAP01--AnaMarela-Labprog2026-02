#include <stdio.h>

int main() {
    int R, G, B, M;

    printf("Digite R, G, B e M: ");
    scanf("%d %d %d %d", &R, &G, &B, &M);

    /* Limpa o bit 0 (LSB) de cada componente de cor */
    R = R & ~1;
    G = G & ~1;
    B = B & ~1;

    /* Extrai os bits de M (bit 2, bit 1 e bit 0) e os insere
       no bit 0 de R, G e B, respectivamente */
    R = R | ((M >> 2) & 1);
    G = G | ((M >> 1) & 1);
    B = B | (M & 1);

    printf("R = %d\n", R);
    printf("G = %d\n", G);
    printf("B = %d\n", B);

    return 0;
}
