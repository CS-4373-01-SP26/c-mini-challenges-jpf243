#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
  int i, j;
  int n = 128;
  double sum;
  clock_t start, end;

  // IMPORTANT: static array must have compile-time size
  // We'll allocate the maximum size we plan to test (adjust if needed)
  static double arr[2048][2048];

  if (argc == 2) {
    n = atoi(argv[1]);
  }

  if (n <= 0 || n > 2048) {
    printf("Please use n between 1 and 2048 for static version.\n");
    return 1;
  }

  // Fill matrix
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      arr[i][j] = (double) rand() / RAND_MAX;

  // ROW-MAJOR
  sum = 0;
  start = clock();
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      sum += arr[i][j];
  end = clock();
  printf("Static Row Major:    n=%d sum=%lf ticks=%ld\n", n, sum, (long)(end - start));

  // COLUMN-MAJOR
  sum = 0;
  start = clock();
  for (j = 0; j < n; j++)
    for (i = 0; i < n; i++)
      sum += arr[i][j];
  end = clock();
  printf("Static Column Major: n=%d sum=%lf ticks=%ld\n", n, sum, (long)(end - start));

  return 0;
}

