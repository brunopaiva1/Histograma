#include <stdio.h>

#define NUM_BINS 6
#define min_meas 0
#define max_meas 6

int main() {
    int bin_count[NUM_BINS] = {0};
    int bin_maxes[NUM_BINS] = {0};
    int bin_width = (max_meas - min_meas) / NUM_BINS;
    int data_count;
    int b, j;

    // ler os valores
    printf("Entre com o número de valores: ");
    scanf("%d", &data_count);

    int values[data_count];
    printf("Entre com os valores separados por espaços:\n");
    for (b = 0; b < data_count; b++) {
        scanf("%d", &values[b]);
    }

    // contar os valores em cada bin
    for (b = 0; b < data_count; b++) {
        int bin = (values[b] - min_meas) / bin_width;
        bin_count[bin]++;
    }

    // calcular o máximo de cada bin
    for (b = 0; b < NUM_BINS; b++) {
        bin_maxes[b] = min_meas + bin_width * (b + 1);
    }

    // imprimir o histograma
    for (b = 0; b < NUM_BINS; b++) {
        printf("%2d-%2d | ", min_meas + b*bin_width, min_meas + (b+1)*bin_width - 1);
        for (j = 0; j < bin_count[b]; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
