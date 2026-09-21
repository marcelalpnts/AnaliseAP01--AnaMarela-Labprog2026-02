#include <stdio.h>

int main() {
    int n, i;
    double x_prev, x_atual, x_prox, y;

    printf("Digite n: ");
    scanf("%d", &n);

    if (n < 3) {
        printf("Nao ha amostras suficientes para calcular a media movel.\n");
        return 0;
    }

    printf("Digite as %d amostras:\n", n);

    /* Le as duas primeiras amostras (x1 e x2) */
    scanf("%lf", &x_prev);
    scanf("%lf", &x_atual);

    /* A cada nova amostra lida (x3, x4, ..., xn), temos um trio
       completo (x_prev, x_atual, x_prox) e podemos calcular um y */
    for (i = 3; i <= n; i++) {
        scanf("%lf", &x_prox);

        y = (x_prev + x_atual + x_prox) / 3.0;
        printf("y%d = %.4f\n", i - 1, y);

        /* "Desliza" a janela para a proxima posicao */
        x_prev = x_atual;
        x_atual = x_prox;
    }

    return 0;
}
