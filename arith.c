#include <stdio.h>
#include <math.h>
#include <time.h>

static double seconds_since(struct timespec a, struct timespec b) {
    return (b.tv_sec - a.tv_sec) + (b.tv_nsec - a.tv_nsec) / 1e9;
}

int main(void) {

    const long long N = 100000000; // 100M (reduce si tarda mucho)
    volatile double sink = 1.000001;

    struct timespec t0, t1;
    double elapsed;

    // Multiplication
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (long long i = 0; i < N; i++) {
        sink = sink * 1.0000001 + 0.0000001;
    }
    clock_gettime(CLOCK_MONOTONIC, &t1);
    elapsed = seconds_since(t0, t1);
    printf("Multiplication loop time: %.6f sec\n", elapsed);

    // Division
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (long long i = 0; i < N; i++) {
        sink = sink / 1.0000001 + 0.0000001;
    }
    clock_gettime(CLOCK_MONOTONIC, &t1);
    elapsed = seconds_since(t0, t1);
    printf("Division loop time:       %.6f sec\n", elapsed);

    // sqrt
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (long long i = 0; i < N; i++) {
        sink = sqrt(sink) + 1.000001;
    }
    clock_gettime(CLOCK_MONOTONIC, &t1);
    elapsed = seconds_since(t0, t1);
    printf("sqrt() loop time:         %.6f sec\n", elapsed);

    // sin
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (long long i = 0; i < N; i++) {
        sink = sin(sink) + 1.000001;
    }
    clock_gettime(CLOCK_MONOTONIC, &t1);
    elapsed = seconds_since(t0, t1);
    printf("sin() loop time:          %.6f sec\n", elapsed);

    printf("sink (ignore): %.6f\n", sink);

    return 0;
}

