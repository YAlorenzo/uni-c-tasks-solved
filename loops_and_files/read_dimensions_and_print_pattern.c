#include <stdio.h>

/*
 * Function read_dimensions_and_print_pattern() reads two integers (rows and columns) from a file.
 * It performs the following tasks:
 * 1. Opens the file "rozmery.txt" and reads two integers (row and col).
 * 2. If the file cannot be opened, an error message is displayed.
 * 3. If the file contains "0 0", it prints a message indicating no numbers are available.
 * 4. Otherwise, it prints a pattern where each row starts with its index and contains decreasing stars.
 *
 * Output:
 * 1. A pattern of stars, where each row starts with its index, followed by a decreasing number of '*' characters.
 *
 * Example:
 * File Content (rozmery.txt):
 * 4 5
 *
 * Console Output:
 * 1: *****
 * 2: ****
 * 3: ***
 * 4: **
*/

void read_dimensions_and_print_pattern() {
    int row, col;
    FILE *file = fopen("rozmery.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file for reading.\n");
        return;
    }

    fscanf(file, "%d %d", &row, &col);

    if (row == 0 && col == 0) {
        printf("No numbers available in the file!\n");
        fclose(file);
        return;
    }

    for (int i = 1; i <= row; i++) {
        printf("%d: ", i);
        for (int j = col; j > 0; j--) {
            printf("*");
        }
        col--;  // Decrease the number of stars for the next row
        printf("\n");
    }

    fclose(file);
}

int main(){
    read_dimensions_and_print_pattern();
    return 0;
}
