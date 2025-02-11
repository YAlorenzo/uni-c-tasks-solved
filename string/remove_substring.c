#include <stdio.h>
#include <string.h>


/*
 * Function remove_substring() prompts the user to enter a string (max 50 characters)
 * and a substring (2 to 5 characters) to remove from the main string.
 * It performs the following tasks:
 * 1. Reads a string and a substring from the user.
 * 2. Validates that the substring length is between 2 and 5 characters.
 * 3. Searches for occurrences of the substring in the main string.
 * 4. Removes all occurrences of the substring by shifting characters left.
 * 5. Prints the modified string.
 *
 * Example:
 * Input: "HelloWorld" "lo"
 * Output: "HelWorld"
 */



void remove_substring() {
    char str[50]; // Main string
    char del[5];  // Substring to delete

    printf("Enter a string (max 50 characters): ");
    scanf("%s", str);
    printf("Enter a substring to delete (2 to 5 characters): ");
    scanf("%s", del);

    int len_str = strlen(str); // Length of main string
    int len_del = strlen(del); // Length of substring
    int j = 0;
    int k = 0;

    // Validate substring length
    if (len_del < 2 || len_del > 5) {
        printf("Substring length must be between 2 and 5 characters!\n");
        return;
    }

    for (int i = 0; i < len_str; i++) {
        // Check for substring match
        while (j < len_del) {
            if (str[i + j] != del[j]) {
                break;
            }
            j++;
        }

        // Remove substring if match is found
        if (j == len_del) {
            k = i;
            while (str[k + len_del] != '\0') {
                str[k] = str[k + len_del]; // Shift characters left
                k++;
            }
            str[k] = '\0'; // Null terminate the string
            len_str -= len_del; // Update string length
            i--; // Adjust index for correct checking
        }

        j = 0;
    }

    printf("Modified string: %s\n", str);
}

int main() {
    remove_substring();
    return 0;
}
