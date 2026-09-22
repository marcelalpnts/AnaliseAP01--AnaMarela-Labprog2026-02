#include <stdio.h>
#define N 5
int main (){

    unsigned char intensidade, X;
    unsigned char Xmax = 0, Xmin = 255;
    float Xnormalizado;

    for (int i = 1; i <= N; i++){
        printf("Insira uma intensidade x%d\n", i);
        scanf("%hhu", &intensidade);

        if (Xmax < intensidade) Xmax = intensidade;
        if (Xmin > intensidade) Xmin = intensidade;
        
    }

    printf("Insira o pixel a ser normalizado no intervalo [%hhu,%hhu]\n", Xmin, Xmax);
    scanf("%hhu", &X);

    Xnormalizado = (float)(X - Xmin) / (Xmax-Xmin);

    printf("O pixel %hhu normalzado é = %.2f\n", X, Xnormalizado);

    return 0;
}
