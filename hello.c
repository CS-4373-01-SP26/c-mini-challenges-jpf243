#include <stdio.h>
#include <string.h>

int main(void) {
    char name[128];

    printf("Enter your name: ");
    if (fgets(name, sizeof(name), stdin) == NULL) {
        return 1;
    }

    // Remove trailing newline if present
    name[strcspn(name, "\n")] = '\0';

    printf("Hello, %s\n", name);
    return 0;
}

