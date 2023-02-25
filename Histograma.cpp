#include <stdio.h>

#define NUM_BINS 6
#define MIN_VALUE 0
#define MAX_VALUE 6

int main() {
    int bin_count[NUM_BINS] = {0};
    int bin_maxes[NUM_BINS] = {0};
    int bin_width = (MAX_VALUE - MIN_VALUE) / NUM_BINS;
    int num_values;
    int i, j;

    // ler os valores
    printf("Entre com o número de valores: ");
    scanf("%d", &num_values);

    int values[num_values];
    printf("Entre com os valores separados por espaços:\n");
    for (i = 0; i < num_values; i++) {
        scanf("%d", &values[i]);
    }

    // contar os valores em cada bin
    for (i = 0; i < num_values; i++) {
        int bin = (values[i] - MIN_VALUE) / bin_width;
        bin_count[bin]++;
    }

    // calcular o máximo de cada bin
    for (i = 0; i < NUM_BINS; i++) {
        bin_maxes[i] = MIN_VALUE + bin_width * (i + 1);
    }

    // imprimir o histograma
    for (i = 0; i < NUM_BINS; i++) {
        printf("%2d-%2d | ", MIN_VALUE + i*bin_width, MIN_VALUE + (i+1)*bin_width - 1);
        for (j = 0; j < bin_count[i]; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
