#include <stdio.h>

int main() {
    char str[100];
    int words = 0, newline = 0, characters = 0;

    printf("Enter a string (up to 99 characters): \n");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t') {
            // Count spaces and tabs as word separators.
            words++;
        } else if (str[i] == '\n') {
            newline++;
        } else if (str[i] != ' ' && str[i] != '\n') {
            // Count non-space and non-newline characters.
            characters++;
        }
    }

    // Adjust word count if there are characters.
    if (characters > 0) {
        words++;
    }

    printf("Total number of Words: %d\n", words);
    printf("Total number of lines: %d\n", newline);
    printf("Total number of characters: %d\n", characters);

    return 0;
}
