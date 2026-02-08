#include <stdio.h>
#include <math.h>
#include <time.h>

int main(void) {

    struct timespec start, end;

    printf("n\tpi_inscribed\tpi_circumscribed\tTime (sec)\n");

    for (int n = 6; n <= 100; n *= 2) {

        clock_gettime(CLOCK_MONOTONIC, &start);

        double pi_in = n * sin(M_PI / n);
        double pi_out = n * tan(M_PI / n);

        clock_gettime(CLOCK_MONOTONIC, &end);

        double elapsed = (end.tv_sec - start.tv_sec)
                       + (end.tv_nsec - start.tv_nsec) / 1e9;

        printf("%d\t%.10f\t%.10f\t%.10f\n",
               n, pi_in, pi_out, elapsed);
    }

    return 0;
}

