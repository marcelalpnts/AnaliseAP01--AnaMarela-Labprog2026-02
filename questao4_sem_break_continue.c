#include <stdio.h>

int main() {
    int numero, soma = 0, contador = 0;
    int parar = 0;

    while (!parar) {
        scanf("%d", &numero);

        if (numero == -1) {
            /* equivalente ao break original */
            parar = 1;
        } else if (numero < 0) {
            /* equivalente ao primeiro continue: nao faz nada,
               apenas volta para o teste do while */
        } else if (numero > 255) {
            /* equivalente ao segundo continue */
        } else {
            soma += numero;
            contador++;
        }
    }

    printf("Soma = %d\n", soma);
    printf("Quantidade = %d\n", contador);

    return 0;
}
