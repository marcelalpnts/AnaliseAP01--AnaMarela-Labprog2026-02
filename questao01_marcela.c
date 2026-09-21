#include <stdio.h>

int main (){

    unsigned char R, G, B;
    unsigned char M;
    unsigned char b2,b1,b0;

    puts("Entre com os valores de R, G e B");
    scanf("%hhu %hhu %hhu", &R, &G, &B);
    puts("Agora entre com o valor de M (0 a 7)");
    scanf("%hhu", &M);

    b2 = (M >> 2) & 1;
    b1 = (M >> 1) & 1;
    b0 = M & 1;

    R = (R & 254) | b2;
    G = (G & 254) | b1;
    B = (B & 254) | b0;

    printf("R = %hhu, G = %hhu, B = %hhu.\n", R, G, B);

    return 0;
}
