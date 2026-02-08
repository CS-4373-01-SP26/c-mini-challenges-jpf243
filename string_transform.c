#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*transpose_fn)(char *s);

// Reverse the string in-place using pointer arithmetic
void reverse_in_place(char *s) {
    if (!s) return;

    char *left = s;
    char *right = s + strlen(s) - 1;

    while (left < right) {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}

void transform(char *s, transpose_fn fn) {
    if (!s || !fn) return;

    printf("Original: %s\n", s);
    fn(s);
    printf("Transformed: %s\n", s);
}

int main(void) {
    char buffer[1024];

    printf("Enter a string: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return 1;
    }

    // remove newline if present
    buffer[strcspn(buffer, "\n")] = '\0';

    // dynamic allocation: copy input into heap memory
    char *heap_str = malloc(strlen(buffer) + 1);
    if (!heap_str) {
        perror("malloc failed");
        return 1;
    }
    strcpy(heap_str, buffer);

    transform(heap_str, reverse_in_place);

    free(heap_str);
    return 0;
}

