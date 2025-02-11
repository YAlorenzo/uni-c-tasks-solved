#include <stdio.h>
#include <ctype.h>

/*
 * Function toUpper() converts all characters in a string to uppercase.
 * It performs the following tasks:
 * 1. Loops through each character in the string.
 * 2. Uses the toupper() function to convert each character to uppercase.
 *
 * Input: A string with lowercase and uppercase characters.
 * Output: A string with all characters converted to uppercase.
 *
 * Example:
 * Input: "hello"
 * Output: "HELLO"
 */
void toUpper(char *string) {
    int i = 0;
    while (string[i] != '\0') {
        string[i] = toupper(string[i]);
        i++;
    }
}

/*
 * Function sifruj() encrypts a given text using a cipher based on a keyword.
 * It performs the following tasks:
 * 1. Converts both the text (sprava) and the keyword (heslo) to uppercase.
 * 2. Encrypts the text by shifting each character based on the corresponding character in the keyword.
 * 3. If the end of the keyword is reached, it wraps around and starts again from the beginning.
 *
 * Input:
 * - sprava: The plaintext to be encrypted (a string of uppercase letters).
 * - heslo: The keyword used for encryption (a string of uppercase letters).
 * Output:
 * - A string containing the encrypted text.
 *
 * Example:
 * Input: "HELLO", "KEY"
 * Output: "RIJVS"
 */
char *sifruj(char *sprava, char *heslo) {
    int i = 0, j = 0;
    int sifer;

    // Convert text and key to uppercase
    toUpper(sprava);
    toUpper(heslo);

    // Encrypt the text using the key
    while (sprava[i] != '\0') {
        if (heslo[j] != '\0') {
            sifer = heslo[j] - 'A' + 1; // Get shift from key (A = 1, B = 2, ...)
            sprava[i] = ((sprava[i] - 'A' + sifer) % 26) + 'A'; // Encrypt the character
            j++;
        } else {
            j = 0; // If the key ends, restart from the beginning
        }

        i++; // Move to the next character in the text
    }

    return sprava;
}

/*
 * Main function to test the sifruj() encryption.
 * It prompts the user to enter the plaintext and the keyword,
 * then prints the encrypted text using the sifruj() function.
 */
int main() {
    char text[100], keyword[100];

    printf("Enter text to encrypt (only uppercase letters): ");
    scanf("%s", text);
    printf("Enter keyword (only uppercase letters): ");
    scanf("%s", keyword);

    // Encrypt the text
    printf("Encrypted text: %s\n", sifruj(text, keyword));

    return 0;
}
