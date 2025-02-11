#include <stdio.h>

/*
 * Function read_and_process_file() prompts the user to input a character.
 * It then processes the contents of the file "znak.txt" and performs the following:
 * 1. If the user inputs 's', the characters from the file are written to a new file "novy.txt".
 * 2. If the user inputs any other character, the contents of the file are printed to the console.
 *
 * The function handles errors in opening the files and closes them properly at the end.
 *
 * Example:
 * Input: 's'
 * Output: The characters from "znak.txt" are copied to "novy.txt".
 *
 * Example:
 * Input: 'a'
 * Output: The characters from "znak.txt" are printed to the console.
 */

int read_and_process_file() {
    char ch;
    char f_ch;
    char file_char[1000];
    int i = 0;
    FILE *fr = fopen("znak.txt", "r");
    FILE *fw = fopen("novy.txt", "w");

    if (fr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    if (fw == NULL) {
        printf("Error opening file!\n");
        fclose(fr);
        return 1;
    }

    printf("Input a character: ");
    scanf(" %c", &ch);

    // Read the file contents
    while ((f_ch = fgetc(fr)) != EOF) {
        file_char[i] = f_ch;
        i++;
    }

    // Process the file contents
    for (int j = 0; j < i; j++) {
        if (ch == 's') {
            fprintf(fw, "%c", file_char[j]);  // Write to the new file if 's' is entered
        } else {
            printf("%c", file_char[j]);  // Print to the console otherwise
        }
    }

    fclose(fw);
    fclose(fr);
    return 0;
}

int main() {
    read_and_process_file();
    return 0;
}
