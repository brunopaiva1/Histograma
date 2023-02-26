#include <stdio.h>

#define NUM_BINS 6
#define min_meas 0
#define max_meas 6

int main() {
    int bin_count[NUM_BINS] = {0};
    int bin_maxes[NUM_BINS] = {0};
    int bin_width = (max_meas - min_meas) / NUM_BINS;
    int data_count;
    int i, j;

    // ler os valores
    printf("Entre com o número de valores: ");
    scanf("%d", &data_count);

    int values[data_count];
    printf("Entre com os valores separados por espaços:\n");
    for (i = 0; i < data_count; i++) {
        scanf("%d", &values[i]);
    }

    // contar os valores em cada bin
    for (i = 0; i < data_count; i++) {
        int bin = (values[i] - min_meas) / bin_width;
        bin_count[bin]++;
    }

    // calcular o máximo de cada bin
    for (i = 0; i < NUM_BINS; i++) {
        bin_maxes[i] = min_meas + bin_width * (i + 1);
    }

    // imprimir o histograma
    for (i = 0; i < NUM_BINS; i++) {
        printf("%2d-%2d | ", min_meas + i*bin_width, min_meas + (i+1)*bin_width - 1);
        for (j = 0; j < bin_count[i]; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
