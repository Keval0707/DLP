#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValidString(const char *inputString) {
    int length = strlen(inputString);
    if (length < 2) {
        return false;
    }
    if (inputString[length - 1] != 'b' || inputString[length - 2] != 'b') {
        return false;
    }
    for (int i = 0; i < length - 2; i++) {
        if (inputString[i] != 'a') {
            return false;
        }
    }

    return true;
}

int main() {
    char userInput[100];
    char userChoice;

    do {
        printf("Enter a string: ");
        scanf("%s", userInput);

        if (isValidString(userInput)) {
            printf("%s: Valid String\n", userInput);
        } else {
            printf("%s: Invalid String\n", userInput);
        }

        printf("Do you want to enter another string? (y/n): ");
        scanf(" %c", &userChoice);
    } while (userChoice == 'y' || userChoice == 'Y');

    return 0;
}
