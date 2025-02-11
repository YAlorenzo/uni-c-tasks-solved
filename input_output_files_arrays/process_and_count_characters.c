#include <stdio.h>

/*
 * Function process_and_count_characters() reads the file "text.txt" character by character and performs the following tasks:
 * 1. It replaces the characters '#' , '$', and '&' with '!' in the input file.
 * 2. It processes specific characters ('X', 'Y', 'x', 'y', and ' ') and prints corresponding messages for each.
 * 3. It counts the number of spaces (' ') encountered in the file.
 * 4. The function stops reading when it encounters the '*' character and prints the count of spaces read.
 *
 * Example:
 * Input: text.txt contains:
 * "X Y x y # & $"
 *
 * Output:
 * The function will print:
 * "Precital som X"
 * "Precital som Y"
 * "Precital som x"
 * "Precital som y"
 * "Precital som riadiaci znak"
 * "Precital som riadiaci znak"
 * "Precital som riadiaci znak"
 * "Koniec"
 * "Pocet precitanych medzier: 1"
 */

void process_and_count_characters() {
    char ch;
    int space_count = 0;  // count of spaces

    FILE *fr = fopen("text.txt", "r");
    if (fr == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Read characters until the '*' is encountered
    while ((ch = fgetc(fr)) != '*') {
        // Replace '#' , '$', and '&' with '!'
        if (ch == '#' || ch == '$' || ch == '&') {
            ch = '!';
        }

        // Process specific characters and print corresponding messages
        switch (ch) {
            case 'X': printf("Precital som X\n"); break;
            case 'Y': printf("Precital som Y\n"); break;
            case 'x': printf("Precital som x\n"); break;
            case 'y': printf("Precital som y\n"); break;
            case '!': printf("Precital som riadiaci znak\n"); break;
            case ' ': space_count++; break;
            default: break;
        }
    }

    // Output the results
    printf("Koniec\n");
    printf("Pocet precitanych medzier: %d\n", space_count);

    fclose(fr);
}

int main() {
    process_and_count_characters();
    return 0;
}
