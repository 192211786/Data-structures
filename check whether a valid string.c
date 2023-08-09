#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
bool isValidString(const char *str) {
    while (*str != '\0') {
        if (!isalpha(*str)) {
            return false; // Not a valid character
        }
        str++;
    }
    return true; // All characters are valid
}

int main() {
    char input[100]; // Assuming maximum input length of 100 characters

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove the newline character from input if present
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    if (isValidString(input)) {
        printf("The input string is valid.\n");
    } else {
        printf("The input string is not valid.\n");
    }

    return 0;
}
