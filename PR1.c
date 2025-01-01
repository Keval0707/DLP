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
//2nd condition a*bb*
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValidString(const char *inputString) {
    int length = strlen(inputString);

    if (length == 0) {
        return false; 
    }

    int i = 0;
    while (i < length && inputString[i] == 'a') {
        i++;
    }

    if (i == length || inputString[i] != 'b') {
        return false;
    }
    while (i < length && inputString[i] == 'b') {
        i++;
    }

    return i == length;
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

