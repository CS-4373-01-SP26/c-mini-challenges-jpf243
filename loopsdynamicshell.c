#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
  int i, j;
  int n = 128;
  double sum;
  clock_t start, end;

  if (argc == 2) {
    n = atoi(argv[1]);
  }

  if (n <= 0) {
    printf("Please use a positive n.\n");
    return 1;
  }

  double *arr = malloc((size_t)n * (size_t)n * sizeof(double));
  if (!arr) {
    perror("malloc failed");
    return 1;
  }

  // Fill matrix
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      arr[i * n + j] = (double) rand() / RAND_MAX;

  // ROW-MAJOR
  sum = 0;
  start = clock();
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      sum += arr[i * n + j];
  end = clock();
  printf("Dynamic Row Major:    n=%d sum=%lf ticks=%ld\n", n, sum, (long)(end - start));

  // COLUMN-MAJOR
  sum = 0;
  start = clock();
  for (j = 0; j < n; j++)
    for (i = 0; i < n; i++)
      sum += arr[i * n + j];
  end = clock();
  printf("Dynamic Column Major: n=%d sum=%lf ticks=%ld\n", n, sum, (long)(end - start));

  free(arr);
  return 0;
}


