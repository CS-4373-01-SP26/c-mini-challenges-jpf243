#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s mv.txt\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    int rows, cols;
    fscanf(file, "%d %d", &rows, &cols);

    // Allocate matrix dynamically (1D contiguous)
    int *matrix = malloc(rows * cols * sizeof(int));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(file, "%d", &matrix[i * cols + j]);
        }
    }

    int vec_len;
    fscanf(file, "%d", &vec_len);

    if (vec_len != cols) {
        printf("Vector length does not match matrix columns\n");
        return 1;
    }

    int *vector = malloc(vec_len * sizeof(int));

    for (int i = 0; i < vec_len; i++) {
        fscanf(file, "%d", &vector[i]);
    }

    fclose(file);

    int *result = calloc(rows, sizeof(int));

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    // Matrix-vector multiplication
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i] += matrix[i * cols + j] * vector[j];
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    double elapsed = (end.tv_sec - start.tv_sec)
                   + (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("Result vector:\n");
    for (int i = 0; i < rows; i++) {
        printf("%d\n", result[i]);
    }

    printf("Computation time: %.10f seconds\n", elapsed);

    free(matrix);
    free(vector);
    free(result);

    return 0;
}

