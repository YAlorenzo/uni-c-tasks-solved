#include <stdio.h>

/*
 * Function longest_repetition() finds the longest sequence of consecutive repeating characters
 * in a given string and returns its length.
 *
 * It performs the following tasks:
 * 1. Iterates through the string to find sequences of repeating characters.
 * 2. Keeps track of the longest sequence found.
 * 3. Stores the character that appears most frequently in a row.
 * 4. Returns the length of the longest sequence.
 *
 * Example:
 * Input: "aaabbcddddee"
 * Output: 4 (for 'd')
 */



int longest_repetition(char x[], int pocet, char *znak) {
    int prev_dlzka = 0;
    int dlzka = 0;

    for (int i = 0; x[i] != '\0'; i++) {
        if (x[i] == x[i + 1]) {
            prev_dlzka++;
        } else {
            if (prev_dlzka > dlzka) {
                dlzka = prev_dlzka;
                *znak = x[i];
            }
            prev_dlzka = 0;
        }
    }
    return dlzka + 1; // Adding 1 to include the first occurrence of the character
}

int main() {
    char str[] = "aaabbcddddee";
    char znak;
    int length = longest_repetition(str, sizeof(str), &znak);
    printf("Longest sequence length: %d for character '%c'\n", length, znak);
    return 0;
}
