#include <stdio.h>

int main() {
    int n, i;
    double x, xmin, xmax, xlinha;

    printf("Digite n: ");
    scanf("%d", &n);

    printf("Digite os %d valores de intensidade:\n", n);

    /* Le o primeiro pixel e usa como referencia inicial de min e max */
    scanf("%lf", &x);
    xmin = x;
    xmax = x;

    /* Le os demais pixels, atualizando min e max sem guardar tudo em memoria */
    for (i = 2; i <= n; i++) {
        scanf("%lf", &x);
        if (x < xmin) xmin = x;
        if (x > xmax) xmax = x;
    }

    printf("xmin = %.2f\n", xmin);
    printf("xmax = %.2f\n", xmax);

    printf("Digite a intensidade x a ser normalizada: ");
    scanf("%lf", &x);

    xlinha = (x - xmin) / (xmax - xmin);
    printf("x' = %.4f\n", xlinha);

    return 0;
}
