#include <stdio.h>
#include <ctype.h>


/*
 * Function odsifruj() decrypts a given text using a cipher based on a keyword.
 * It performs the following tasks:
 * 1. Converts both the text (sprava) and the keyword (heslo) to uppercase.
 * 2. Decrypts the text by shifting each character based on the corresponding character in the keyword.
 * 3. If the end of the keyword is reached, it wraps around and starts again from the beginning.
 *
 * Input:
 * - sprava: The ciphertext to be decrypted (a string of uppercase letters).
 * - heslo: The keyword used for decryption (a string of uppercase letters).
 * Output:
 * - A string containing the decrypted text.
 *
 * Example:
 * Input: "RIJVS", "KEY"
 * Output: "HELLO"
 */


void toUpper(char *string) {
    int i = 0;
    while (string[i] != '\0') {
        string[i] = toupper(string[i]);
        i++;
    }
}


char *odsifruj(char *sprava, char *heslo) {
    int i = 0, j = 0;
    int sifer;

    // Convert text and key to uppercase
    toUpper(sprava);
    toUpper(heslo);

    // Decrypt the text using the key
    while (sprava[i] != '\0') {
        if (heslo[j] != '\0') {
            sifer = heslo[j] - 'A' + 1; // Get shift from key (A = 1, B = 2, ...)
            sprava[i] = ((sprava[i] - 'A' - sifer + 26) % 26) + 'A'; // Decrypt the character
            j++;
        } else {
            j = 0; // If the key ends, restart from the beginning
        }

        i++; // Move to the next character in the text
    }

    return sprava;
}

/*
 * Main function to test the odsifruj() decryption.
 * It prompts the user to enter the encrypted text and the keyword,
 * then prints the decrypted text using the odsifruj() function.
 */
int main() {
    char text[100], keyword[100];

    printf("Enter encrypted text (only uppercase letters): ");
    scanf("%s", text);
    printf("Enter keyword (only uppercase letters): ");
    scanf("%s", keyword);

    // Decrypt the text
    printf("Decrypted text: %s\n", odsifruj(text, keyword));

    return 0;
}
